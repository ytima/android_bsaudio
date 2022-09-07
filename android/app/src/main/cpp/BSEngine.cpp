//
//  BSEngine.cpp
//  BSAudioEngine - Static Library
//  Created by BeeSting on 18/03/2022.
//

#include "BSEngine.h"

BSEngine* engine = nullptr;
//BSOutputDeviceFlag outputDeviceFlag;  // keeps track bluetooth headphones, set by JUCE "juce_ios_Audio.cpp"

BSEngine::BSEngine()
{
    // add 4 (default amount) tracks to the track array
    for (int i = 0; i < 4; i++)
        trackArray.add(new Track());

    // add mainbus track
    mainBus = new Track();

    // set engine variables
    samplesPerBeat = sampleRate/(bpm / 60);
    mainPanChannelGainArray.add(1.0f, 1.0f);
    tempDirectory = juce::File::getSpecialLocation(juce::File::tempDirectory).getChildFile("BSAudioEngineTemp");

    // startBackgroundThread for writing
    backgroundThread.startThread();

    // Create the message manager
    juce::MessageManager::getInstance();

    // Set up the audio device Callback
    audioDeviceManager.addAudioCallback(this);

}


BSEngine::~BSEngine()
{
    // stop all potentially running processes
    stopTimer();
    stop();
    backgroundThread.stopThread(0);
}

// Writing audio to disk using background thread
void BSEngine::startRecording(const juce::File& file)
{
    // stop current writing that may be happening
    stop();
    
    // wee check to make sure the engine has variables somewhat
    if (sampleRate > 0)
    {
        // delete the file passed, to make sure its empty
        file.deleteFile();

        // Create an OutputStream to write to our destination file
        if (auto fileStream = std::unique_ptr<juce::FileOutputStream> (file.createOutputStream()))
        {
            // Now create a WAV writer object that writes to our output stream
            juce::FlacAudioFormat flacFormat;
            if (auto writer = flacFormat.createWriterFor(fileStream.get(), sampleRate, m_numInputChannels, 16, {}, 0))
            {
                fileStream.release();  // (passes responsibility for deleting the stream to the writer object that is now using it)

                // Now we'll create one of these helper objects which will act as a FIFO buffer, and will
                // write the data to disk on our background thread.
                threadedWriter.reset (new juce::AudioFormatWriter::ThreadedWriter (writer, backgroundThread, 12000));

                // And now, swap over our active writer pointer so that the audio callback will start using it..
                const juce::ScopedLock sl(writerLock);
                activeWriter = threadedWriter.get();
            }
        }
    }
}

// Stop writing to disk
void BSEngine::stop()
{
    // First, clear this pointer to stop the audio callback from using our writer object..
    {
        const juce::ScopedLock sl(writerLock);
        activeWriter = nullptr;
    }

    // Now we can delete the writer object. It's done in this order because the deletion could
    // take a little time while remaining data gets flushed to disk, so it's best to avoid blocking
    // the audio callback while this happens.
    threadedWriter.reset();
}

// Simple checker function for writing
bool BSEngine::isRecording()
{
    return activeWriter.load() != nullptr;
}

// Audiocallback is where the processing of this library happens
void BSEngine::audioDeviceIOCallback(const float **inputChannelData, int numInputChannels, float **outputChannelData, int numOutputChannels, int numSamples)
{
    // wrap incoming data, no allocations/copies, just references input data!
    juce::AudioBuffer<float> inputBuffer(const_cast<float**>(inputChannelData), numInputChannels, numSamples);
    juce::AudioBuffer<float> outBuffer(numOutputChannels, numSamples);  // add all data for output to the outBuffer
    juce::MidiBuffer midiBuffer;  // an empty midiMessage buffer to shut the effect processor up
    m_numInputChannels = numInputChannels;
    m_throttleAudioCallbackCycles = sampleRate / numSamples / 60;
    int currentLatency = m_countInSamples + m_inputLatency + m_outputLatency + (2*numSamples);
    
    // clear any leftovers or junk
    outBuffer.clear();
    midiBuffer.clear();
    
    // input level value to emit
    m_currentInputLevel = inputBuffer.getMagnitude(0, numSamples);
    
    // override the latency value
    if (m_manualLatencyOverride)
        currentLatency = m_countInSamples + m_manualLatency + (2*numSamples);

    // set input gain, if values is somewhat reasnoble
    if (m_inputGain >= 0.0f && m_inputGain <= 2.0f)
        inputBuffer.applyGain(m_inputGain);

    // Record Track branch
    if (recordTrack && maxFileLengthSamples > m_inputBufferPos - currentLatency)
    {
        // bufferpos is more than total internal latency and the count in, to account for latency.
        if (activeWriter.load() != nullptr && (m_inputBufferPos + numSamples) >= currentLatency)
        {
            // countin complete callback
            if (countInFinishedCallbackPointer != nullptr)
            {
                countInFinishedCallbackPointer->countInFinished();
                countInFinishedCallbackPointer = nullptr;
            }
            
            // get the number samples to write
            int inputPosInBlock = juce::jmax(currentLatency - m_inputBufferPos, 0);
            int blockSize = numSamples - inputPosInBlock;
            juce::AudioBuffer<float> littleBuffer(inputBuffer.getNumChannels(), blockSize);
            littleBuffer.copyFrom(0, 0, inputBuffer, 0, inputPosInBlock, blockSize);
            // write that to disk
            activeWriter.load()->write(littleBuffer.getArrayOfReadPointers(), blockSize);
            
            // advance the write samples counter
            m_writeNumSamples += littleBuffer.getNumSamples();
            trackOutputLevels[currentTrackNumber] = littleBuffer.getMagnitude(0, blockSize);
            
//            // if reasnoble monitoring gain value, apply it
//            if (m_inputMonitoringGain <= 2 && m_inputMonitoringGain >= 0)
//                inputBuffer.applyGain(m_inputMonitoringGain);

            // monitor input, only if wired headphones device
//            if (outputDeviceFlag.isHeadphonesDevice())
//            {
//                for (int ch = 0; ch < numOutputChannels; ch++)
//                {
//                    if (ch < numInputChannels)
//                        outBuffer.addFrom(ch, 0, inputBuffer, ch, 0, numSamples);
//                    else
//                        outBuffer.addFrom(ch, 0, inputBuffer, 0, 0, numSamples);
//                }
//            }
        }

        // advance input buffer position
        m_inputBufferPos += numSamples;
        
        // stop the recording if beyond max length
        if (maxFileLengthSamples <=  m_inputBufferPos - currentLatency)
            stopRecording();
    }

    // Playing a single track branch
    if (playTrack)
    {
        Track* currentTrack = trackArray.getReference(currentTrackNumber);
        juce::AudioBuffer<float>* bufferPtr = currentTrack->getCurrentTakeBufferPointer();
        juce::AudioBuffer<float> effectBuffer(2, numSamples);
        juce::AudioBuffer<float> mixBuffer(2, numSamples);
        float gain = currentTrack->gain;
        int bufferPos;
        
        if (currentTrack->getLoopMode())
            bufferPos = currentTrack->getLoopBufferPos();
        else
            bufferPos = m_outputBufferPos;
        
        // track scope lock
        const juce::ScopedLock myScopedLock (currentTrack->objectLock);

        if (bufferPtr->getNumSamples() > bufferPos + numSamples)
        {
            // buffers are always stereo. if the input file was mono, channel 0 was copied to channel 1 when read
            // if mono output, the buffers should ignore panning and half gain
            // if stereo output, the buffers should be full gain but have pannig applied.

            mixBuffer.copyFrom(0, 0, *bufferPtr, 0, bufferPos, numSamples);
            mixBuffer.copyFrom(1, 0, *bufferPtr, 1, bufferPos, numSamples);
            mixBuffer.applyGain(1.0f - currentTrack->getMixValue());
            
            // mono output
            if (numOutputChannels < 2)
            {
                // both channels to mono channel. ignore panning and half the gain
                    effectBuffer.copyFrom(0, 0, *bufferPtr, 0, bufferPos, numSamples);
                    effectBuffer.copyFrom(1, 0, *bufferPtr, 1, bufferPos, numSamples);
                    currentTrack->processorGraph->processBlock(effectBuffer, midiBuffer);
                    mixBuffer.addFrom(0, 0, effectBuffer, 0, 0, numSamples, currentTrack->getMixValue());
                    mixBuffer.addFrom(1, 0, effectBuffer, 1, 0, numSamples, currentTrack->getMixValue());
                    outBuffer.addFrom(0, 0, mixBuffer, 0, 0, numSamples, gain/2);
                    outBuffer.addFrom(0, 0, mixBuffer, 1, 0, numSamples, gain/2);
            }
            else
            {
                // stereo output
                   effectBuffer.copyFrom(0, 0, *bufferPtr, 0, bufferPos, numSamples);
                   effectBuffer.copyFrom(1, 0, *bufferPtr, 1, bufferPos, numSamples);
                   currentTrack->processorGraph->processBlock(effectBuffer, midiBuffer);
                   mixBuffer.addFrom(0, 0, effectBuffer, 0, 0, numSamples, currentTrack->getMixValue());
                   mixBuffer.addFrom(1, 0, effectBuffer, 1, 0, numSamples, currentTrack->getMixValue());
                   outBuffer.addFrom(0, 0, mixBuffer, 0, 0, numSamples, gain * currentTrack->panChannelGainArray.getUnchecked(0));
                   outBuffer.addFrom(1, 0, mixBuffer, 1, 0, numSamples, gain * currentTrack->panChannelGainArray.getUnchecked(1));
            }

            trackOutputLevels[currentTrackNumber] = bufferPtr->getMagnitude(bufferPos, numSamples) * gain;

        }
        else if (playTrackFinishedCallbackPointer != nullptr && !currentTrack->getLoopMode())
        {
            playTrackFinishedCallbackPointer->playTrackFinishedCallback();
            playTrackFinishedCallbackPointer = nullptr;
        }
        
        // move the loop buffer pos forward if buffer big enough, else reset to 0
        if (bufferPtr->getNumSamples() > bufferPos + numSamples)
            currentTrack->setLoopBufferPos(bufferPos + numSamples);
        else
            currentTrack->setLoopBufferPos(0);
    }

    
    // Playback of multiple different tracks, summed to output
    if (multitrackPlay)
    {
        // make sure the count in has passed
        if (m_outputBufferPos > m_countInSamples)
        {

            juce::AudioBuffer<float> summedBuffer(2, numSamples);  // sum all audio data from each track buffer to this buffer
            long bufferPos = m_outputBufferPos-m_countInSamples;  // account for the sample delay due to count in
            int numLoopedTracks = 0;
            int numFinishedBuffers = 0;
            summedBuffer.clear();

            // recordtrack is false, so countInFinishedCallback has not been sent by the recording process
            if (!recordTrack && countInFinishedCallbackPointer != nullptr)
            {
                countInFinishedCallbackPointer->countInFinished();
                countInFinishedCallbackPointer = nullptr;
            }

            // for each track in engine track array
            for (int i = 0; i < trackArray.size(); i++)
            {
                Track* currentTrack = trackArray.getReference(i);
                juce::AudioBuffer<float>* bufferPtr = currentTrack->getCurrentTakeBufferPointer();
                juce::AudioBuffer<float> effectBuffer(2, numSamples);  // buffer for writing effect chain to
                juce::AudioBuffer<float> mixBuffer(2, numSamples);  // buffer for writing mix of wet and dry signal to
                juce::Array<float> panGainArray = currentTrack->panChannelGainArray;
                float gain = currentTrack->gain;
                float currentMixValue = currentTrack->getMixValue();
                const juce::ScopedLock myScopedLock (currentTrack->objectLock);  // track scope lock

                // if the track is looped and the playhead is not beyond a max length
                if (currentTrack->getLoopMode() && bufferPos < maxFileLengthSamples)
                {
                    bufferPos = currentTrack->getLoopBufferPos();
                    numLoopedTracks++;
                }
                else
                {
                    bufferPos = m_outputBufferPos-m_countInSamples;
                }
                
                if (bufferPtr->getNumSamples() > bufferPos + numSamples)
                {
                    // buffers are always stereo. if the input file was mono, channel 0 was copied to channel 1.

                    // fill the effect buffer with the input data (will always be stereo)
                    effectBuffer.copyFrom(0, 0, *bufferPtr, 0, bufferPos, numSamples);
                    effectBuffer.copyFrom(1, 0, *bufferPtr, 1, bufferPos, numSamples);
                    // gain the effect buffer with gainlevel (effects are post gain)
                    effectBuffer.applyGain(gain);
                    // copy that to the mix buffer so it has dry signal before effect processing
                    mixBuffer.makeCopyOf(effectBuffer);
                    // gain the mixBuffer with dry signal level, (1 - wet mix value)
                    mixBuffer.applyGain(1.0f - currentMixValue);
                    // process block through effect chain
                    currentTrack->processorGraph->processBlock(effectBuffer, midiBuffer);
                    // add processed audio to mix buffer with wet mix value
                    mixBuffer.addFrom(0, 0, effectBuffer, 0, 0, effectBuffer.getNumSamples(), currentMixValue);
                    mixBuffer.addFrom(1, 0, effectBuffer, 1, 0, effectBuffer.getNumSamples(), currentMixValue);

                    // if mono output, the buffers should ignore panning and half gain
                    // if stereo output, the buffers should be full gain but have pannig applied
                    if (numOutputChannels < 2)
                    {
                        // mono output
                        // add mixBuffer to outbut buffer. both channels to mono channel. ignore panning and half the gain
                        outBuffer.addFrom(0, 0, mixBuffer, 0, 0, mixBuffer.getNumSamples(), 0.5f);
                        outBuffer.addFrom(0, 0, mixBuffer, 1, 0, mixBuffer.getNumSamples(), 0.5f);

                    }
                    else
                    {
                        // stereo output
                        // add mixBuffer to output buffer with panGain
                        outBuffer.addFrom(0, 0, mixBuffer, 0, 0, mixBuffer.getNumSamples(), panGainArray.getUnchecked(0));
                        outBuffer.addFrom(1, 0, mixBuffer, 1, 0, mixBuffer.getNumSamples(), panGainArray.getUnchecked(1));
                    }

                    trackOutputLevels[i] = mixBuffer.getMagnitude(0, numSamples);
                }
                else
                {
                    numFinishedBuffers++;  // this buffer has less samples than current bufferPos, so its finished.
                }

                // move the loop buffer pos forward if buffer big enough, else reset to 0
                if (bufferPtr->getNumSamples() > bufferPos + numSamples)
                    currentTrack->setLoopBufferPos(bufferPos + numSamples);
                else
                    currentTrack->setLoopBufferPos(0);
            }
            
            // all buffers are finished playing
            if (numLoopedTracks == 0 && numFinishedBuffers == trackArray.size())
            {
                multitrackFinished = true;
                multitrackPlay = false;
            }
        }
    }

    // Play Mixdown buffer branch
    if (mixdownPlay)
    {
        if (mixdownBuffer.getNumSamples() > m_outputBufferPos + numSamples)
            for (int ch = 0; ch < numOutputChannels; ch++)
                outBuffer.addFrom(ch, 0, mixdownBuffer, ch, m_outputBufferPos, numSamples);  // mixdownBuffer always 2 channels
    }

    // metronome click branch
    if (metronomeStatus && !engineStopped)
    {
        int currentMetronomeModulo = -1;

        // if recording track, its the input buffer pos that is increasing not output buffer pos!
        if (recordTrack)
            currentMetronomeModulo = m_inputBufferPos % samplesPerBeat;
        else
            currentMetronomeModulo = m_outputBufferPos % samplesPerBeat;

        if (currentMetronomeModulo >= 0)
        {
            if (currentMetronomeModulo < metronomeModulo || currentMetronomeModulo == 0)
            {
                if (emitterListeners) eventWrapper->sendOnMetronomeBeat();
                m_metronomeBufferPos = 0;
                m_metronomeToggle = true;
                // find if the beat is the first of the bar
                m_metronomoeCounter++;
                m_metronomoeCounter = m_metronomoeCounter % timeSignature.getUnchecked(0);
            }
        }

        if (m_metronomeToggle) {
            juce::AudioBuffer<float> metronomeSound;
            if (m_metronomoeCounter == 0)
            {
                metronomeSound.makeCopyOf(metronomeUpBuffer);
            }
            else
            {
                metronomeSound.makeCopyOf(metronomeDownBuffer);
            }
            
            if (metronomeSound.getNumSamples() > m_metronomeBufferPos) {

                // mono output
                if (numOutputChannels < 2)
                {
                    // both channels to mono channel, half the gain
                    for (int ch = 0; ch < metronomeSound.getNumChannels() && metronomeSound.getNumSamples() > m_metronomeBufferPos + numSamples; ch++)
                        outBuffer.addFrom(0, 0, metronomeSound, ch, m_metronomeBufferPos, numSamples, m_metronomeLevel);
                }
                else
                {
                    // stereo output
                    for (int ch = 0; ch < metronomeSound.getNumChannels() && metronomeSound.getNumSamples() > m_metronomeBufferPos + numSamples; ch++)
                        outBuffer.addFrom(ch, 0, metronomeSound, ch, m_metronomeBufferPos, numSamples, m_metronomeLevel);
                }

                m_metronomeBufferPos += numSamples;
            } else {
                m_metronomeToggle = false;
            }
        }

        metronomeModulo = currentMetronomeModulo;
    }

    // send throgh mainBus effects
    juce::AudioBuffer<float> mainEffectBuffer;
    mainEffectBuffer.makeCopyOf(outBuffer);
    mainBus->processorGraph->processBlock(mainEffectBuffer, midiBuffer);
    outBuffer.applyGain(1.0f - mainBus->getMixValue());
    outBuffer.addFrom(0, 0, mainEffectBuffer, 0, 0, numSamples, mainBus->getMixValue());
    outBuffer.addFrom(1, 0, mainEffectBuffer, 1, 0, numSamples, mainBus->getMixValue());

    // set main pan for stereo output
    if (numOutputChannels > 1)
    {
        outBuffer.applyGain(0, 0, numSamples, mainPanChannelGainArray.getReference(0));
        outBuffer.applyGain(1, 0, numSamples, mainPanChannelGainArray.getReference(1));
    }

    // apply main output gain
    outBuffer.applyGain(mainGain);

    // current progress for emitting
    int currentMicros;
    if (recordTrack)
        currentMicros = (float) m_inputBufferPos/sampleRate * 1000000.00;
    else
        currentMicros = (float) m_outputBufferPos/sampleRate * 1000000.00;

    // call multitrack finished callback
    if (multitrackFinished && multitrackPlayFinishedCallbackPointer != nullptr)
    {
        multitrackPlayFinishedCallbackPointer->multitrackPlayFinishedCallback();
        multitrackPlayFinishedCallbackPointer = nullptr;
    }
    
    // throttle emitting
    m_throttleCount++;  // always should iterate, even on first cycle, because computer maths.
    if (m_throttleCount >= m_throttleAudioCallbackCycles)
    {
        m_throttleCount = 0;
        // dont't send if no listeners or JS will complain
        if (emitterListeners)
        {
            // emit everything to javascript through the emit wrapper
            eventWrapper->sendTrackOutputLevels(trackOutputLevels);
            eventWrapper->sendPlaybackProgress(currentMicros);
            eventWrapper->sendMainOutputLevel(outBuffer.getMagnitude(0, numSamples));
            eventWrapper->sendInputLevel(m_currentInputLevel);
//            eventWrapper->sendBluetoothConnected(outputDeviceFlag.isBluetoothDevice());
        }
    }

    // Test Tone output
    // Android has a total incapacity to have a stable callback size...
    // everything will need to be buffered and handled manually?
    juce::AudioSourceChannelInfo testToneSourceInfo(outBuffer);
    testTone.getNextAudioBlock(testToneSourceInfo);

    // move along outputBuffer
    if (playTrack || multitrackPlay || mixdownPlay)
        m_outputBufferPos += numSamples;

    // get the read pointers and output the data on the outBuffer.
    auto readPtrs = outBuffer.getArrayOfReadPointers();
    for (int sample = 0; sample < numSamples; sample++)
        for (int ch = 0; ch < numOutputChannels; ch++)
            outputChannelData[ch][sample] = readPtrs[ch][sample];
}

void BSEngine::stopRecording()
{
    if (recordTrack && engineActive)
    {
        startTimer(5);
        stop();
    }
    engineStopped = true;
    // stop all processes
    recordTrack = false;
    playTrack = false;
    multitrackPlay = false;
    mixdownPlay = false;
    setInputBufferPos(0);
    setOutputBufferPos(0);
    m_countInSamples = 0;
    
    for (auto track : trackArray)
        track->resetEffects();
}

void BSEngine::clearTrackTakes(int trackNum)
{
    Track* track = trackArray.getReference(trackNum);
    track->removeAllTakes();
    track->setCurrentTakeNumber(0);
    juce::String trackDirString("track"+juce::String(trackNum));
    juce::File trackDir = engine->tempDirectory.getChildFile(trackDirString);
    trackDir.deleteRecursively();
}

void BSEngine::deleteTake(int trackNum, int takeNum)
{
    trackArray.getReference(trackNum)->removeTake(takeNum);
}

void BSEngine::deleteTrack(int trackNum)
{
    clearTrackTakes(trackNum);
    trackArray.getReference(trackNum)->resetTrack();
}

// Effects
void BSEngine::removeTrackEffects(int trackNum)
{
    trackArray.getReference(trackNum)->removeEffects(sampleRate, bufferSize);
}

void BSEngine::addTrackEffect(int trackNum, std::string effectName)
{
    effectPreset effectPreset;
    if (effectName == "compressor") {
        effectPreset = compressorEffect();
    } else if (effectName == "reverbShort") {
        effectPreset = reverbShortEffect();
    } else if (effectName == "reverbLong") {
        effectPreset = reverbLongEffect();
    } else if (effectName == "delaySlapback") {
        effectPreset = delaySlapbackEffect();
    } else if (effectName == "delayLong") {
        effectPreset = delayLongEffect();
    } else {
        effectPreset = defaultEffect();
    }

    trackArray.getReference(trackNum)->addEffectChain(effectPreset, sampleRate, bufferSize);
    trackArray.getReference(trackNum)->setCurrentEffectChain(effectPreset);
}

void BSEngine::addMainBusEffect(std::string effectName)
{
    effectPreset effectPreset;
    if (effectName == "main") {
        effectPreset = mainBusEffect();
    } else if (effectName == "alternate") {
        effectPreset = alteredMainBusEffect();
    } else {
        effectPreset = defaultEffect();
    }

    mainBus->addEffectChain(effectPreset, sampleRate, bufferSize);
    mainBus->setCurrentEffectChain(effectPreset);
}

void BSEngine::resetMainBusEffect()
{
    mainBus->removeEffects(sampleRate, bufferSize);
}

void BSEngine::setMixValueMainBusEffect(float mixValue)
{
    mainBus->setMixValue(mixValue);
}
