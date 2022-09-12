//
//  BSEngine.h
//  BSAudioEngine - Static Library
//
//  Created by BeeSting on 18/03/2022.
//

#include "BSInterface.h"

long TestFunction(long a, long b)
{
    return a * b;
}

void testtestFunct( std::function<void (int)> testFuncccc)
{
    testFuncccc(112233);
}

void BSSetMetronomeSound(std::string absoluteFilePathDown, std::string absoluteFilePathUp)
{
    juce::File file = juce::String(absoluteFilePathDown);
    juce::AudioBuffer<float>* bufferpPtr = &engine->metronomeDownBuffer;

    if (file.exists())
    {
        engine->metronomeDownFilePath = absoluteFilePathDown;
        readFile(file, bufferpPtr);
    }
    else
    {
        engine->metronomeDownBuffer.makeCopyOf(juce::AudioBuffer<float>(0, 0));
    }

    file = juce::String(absoluteFilePathUp);
    bufferpPtr = &engine->metronomeUpBuffer;

    if (file.exists())
    {
        engine->metronomeUpFilePath = absoluteFilePathUp;
        readFile(file, bufferpPtr);
    }
    else
    {
        engine->metronomeUpBuffer.makeCopyOf(juce::AudioBuffer<float>(0, 0));
    }
}

void BSWriteMixdownFlac(CallbackWrapper *callback)
{
    juce::AudioBuffer<float>* mixdown = engine->mainBus->getBakedEffectBufferPointer();

    juce::File flacFile = engine->tempDirectory.getChildFile("mixdown.flac");
    writeCompressedFlacFile(flacFile, mixdown);
    callback->writeMixdownCallback(flacFile.getFullPathName().toStdString());
}

void BSReadMixdownFlac()
{
    juce::File flacFile = engine->tempDirectory.getChildFile("mixdown.flac");
    juce::AudioBuffer<float>* bufferPtr = &engine->mixdownBuffer;

    if (flacFile.exists())
        readFile(flacFile, bufferPtr);
}

// a call to prove that we can get the device initilised.
// Will be redundatnt and should be ignored when there are event and callback wrappers working for android
bool BSInitialiseDevice()
{
    if (engine != nullptr)
    {
        delete engine;
        engine = nullptr;
    }

    engine = new BSEngine;

    engine->audioDeviceManager.initialiseWithDefaultDevices(2, 2);

//    juce::AudioDeviceManager::AudioDeviceSetup setup = engine->audioDeviceManager.getAudioDeviceSetup();
//    juce::Array<int> bufferSizes = engine->audioDeviceManager.getCurrentAudioDevice()->getAvailableBufferSizes();
//    juce::Array<double> sampleRates = engine->audioDeviceManager.getCurrentAudioDevice()->getAvailableSampleRates();
//    setup.bufferSize = bufferSizes.getFirst();
//    setup.sampleRate = sampleRates.getLast();
//
//    engine->audioDeviceManager.setAudioDeviceSetup(setup, false);

    // successful
    if (engine->audioDeviceManager.getCurrentAudioDevice())
    {
        // create local directory in temp to store all files so all can be removed on shutdown
        auto dir = juce::File::getSpecialLocation(juce::File::tempDirectory).getChildFile("BSAudioEngineTemp");
        engine->tempDirectory = dir;

        // if it already exists as a directory, read files into the buffers
        if(dir.exists() && dir.isDirectory())
        {
            for (int i = 0; i < engine->trackArray.size(); i++)
            {
                for (int j = 0; j < engine->trackArray.getReference(i)->getTakesSize(); j++)
                {
                    juce::File file = flacFilePathFromTrackNumber(i, j);
                    juce::AudioBuffer<float>* bufferPtr = engine->trackArray.getReference(i)->getTakeBufferPointer(j);
                    readFile(file, bufferPtr);
                }
            }
            BSSetMetronomeSound(engine->metronomeDownFilePath, engine->metronomeUpFilePath);
        }
        else
        {
            dir.createDirectory();
        }

        engine->samplesPerBeat = engine->sampleRate/(engine->bpm / 60);
        engine->metronomeModulo = engine->samplesPerBeat;
        engine->resetEmitThrottleCount();  // emitting throttling
        engine->engineStopped = true;
        engine->engineActive = true;

        return true;
    }
    else
    {
//        // unsuccessful
        engine->engineActive = false;
        return false;
    }
}

void BSRecordTrack(long startAtMicros, int currentTrackNumber, int currentTakeNumber, CallbackWrapper* callback)
{
    if (!engine->recordTrack && currentTakeNumber <= engine->trackArray.getReference(currentTrackNumber)->getTakesSize())
    {

        if (currentTakeNumber+1 > engine->trackArray.getReference(currentTrackNumber)->getTakesSize())
            engine->trackArray.getReference(currentTrackNumber)->newTake();

        engine->trackArray.getReference(currentTrackNumber)->setCurrentTakeNumber(currentTakeNumber);
        engine->trackArray.getReference(currentTrackNumber)->getCurrentTakeBufferPointer()->clear();
        juce::File flacFile = flacFilePathFromTrackNumber(currentTrackNumber, currentTakeNumber);
        engine->startRecording(flacFile);
        engine->engineStopped = false;
        engine->metronomeModulo = engine->samplesPerBeat;
        engine->currentTrackNumber = currentTrackNumber;
        engine->setInputBufferPos(microsToSamples(startAtMicros));
        engine->recordStoppedCallbackPointer = callback;
        if (startAtMicros > 0)
            engine->offsetRecording(microsToSamples(startAtMicros));
        engine->recordTrack = true;
    }
}

void BSPlayTrack(long startAtMicros, int currentTrackNumber, int currentTakeNumber, CallbackWrapper *callback)
{
    engine->engineStopped = false;
    engine->metronomeModulo = microsToSamples(startAtMicros) % engine->samplesPerBeat;
    engine->playTrackFinishedCallbackPointer = callback;
    engine->playTrack = true;
    engine->currentTrackNumber = currentTrackNumber;
    engine->setOutputBufferPos(microsToSamples(startAtMicros));
}

void BSSetTake(int trackNumber, int takeNumber)
{
    engine->trackArray.getReference(trackNumber)->setCurrentTakeNumber(takeNumber);
}

void BSSetLoopMode(int trackNum, bool status)
{
    engine->trackArray.getReference(trackNum)->setLoopMode(status);
}

bool BSGetLoopMode(int trackNum)
{
    return engine->trackArray.getReference(trackNum)->getLoopMode();
}


void BSClearAllUnusedTrackTakes()
{
    for (int trackNum = 0; trackNum < engine->trackArray.size(); trackNum++)
    {
        Track* track = engine->trackArray.getReference(trackNum);
        for (int takeNum = track->getTakesSize()-1; takeNum >= 0; takeNum--)
        {
            if (takeNum != track->getCurrentTakeNumber())
            {
                track->removeTake(takeNum);
                juce::File file = flacFilePathFromTrackNumber(trackNum, takeNum);
                file.deleteFile();
            }
        }

        // selected take is now only take in directory, but has wrong name
        juce::File selectedFile = flacFilePathFromTrackNumber(trackNum, track->getCurrentTakeNumber());
        selectedFile.moveFileTo(flacFilePathFromTrackNumber(trackNum, 0));
        track->setCurrentTakeNumber(0);
    }
}

void BSClearAllTrackTakes()
{
    for (int trackNum = 0; trackNum < engine->trackArray.size(); trackNum++)
        engine->clearTrackTakes(trackNum);
}

void BSClearTrackTakes(int trackNum)
{
    engine->clearTrackTakes(trackNum);
}


void BSDeleteTake(int trackNum, int takeNum)
{
    engine->deleteTake(trackNum, takeNum);
}

void BSDeleteTrack(int trackNum)
{
    engine->deleteTrack(trackNum);
}

void BSMultitrackPlay(long startAtMicros, CallbackWrapper *callback)
{
    engine->engineStopped = false;
    engine->metronomeModulo = microsToSamples(startAtMicros) % engine->samplesPerBeat;
    engine->multitrackPlay = true;
    engine->multitrackFinished = false;
    engine->multitrackPlayFinishedCallbackPointer = callback;
    engine->setOutputBufferPos(microsToSamples(startAtMicros));
}

void BSMultitrackRecord(long startAtMicros, int currentTrackNumber, int currentTakeNumber, CallbackWrapper *recordCallback)
{
    if (!engine->recordTrack && currentTakeNumber <= engine->trackArray.getReference(currentTrackNumber)->getTakesSize())
    {

        if (currentTakeNumber+1 > engine->trackArray.getReference(currentTrackNumber)->getTakesSize())
            engine->trackArray.getReference(currentTrackNumber)->newTake();

        engine->trackArray.getReference(currentTrackNumber)->setCurrentTakeNumber(currentTakeNumber);
        engine->trackArray.getReference(currentTrackNumber)->getCurrentTakeBufferPointer()->clear();
        juce::File flacFile = flacFilePathFromTrackNumber(currentTrackNumber, currentTakeNumber);
        engine->startRecording(flacFile);
        engine->engineStopped = false;
        engine->metronomeModulo = engine->samplesPerBeat;
        engine->currentTrackNumber = currentTrackNumber;
        engine->setInputBufferPos(microsToSamples(startAtMicros));
        engine->recordStoppedCallbackPointer = recordCallback;
        if (startAtMicros > 0) engine->offsetRecording(microsToSamples(startAtMicros));
        engine->recordTrack = true;
    }
    // pass nullptr. only 1 callback allowed from each function and record is the important one
    BSMultitrackPlay(startAtMicros, nullptr);
}

void BSPlayMixdown(long startAtMicros)
{
    engine->engineStopped = false;
    engine->metronomeModulo = microsToSamples(startAtMicros) % engine->samplesPerBeat;
    engine->setOutputBufferPos(microsToSamples(startAtMicros));
    engine->mixdownPlay = true;
}

void BSStop()
{
    engine->stopRecording();
}

bool BSShutDown()
{
    BSStop();
    engine->metronomeStatus = false;
    clearAllBuffers();
    // t=just keep the files there unless they are deleted by user?
//    engine->tempDirectory.deleteRecursively();
    engine->audioDeviceManager.closeAudioDevice();
    // successful, returns false for frontend.
    if (!engine->audioDeviceManager.getCurrentAudioDevice())
    {
        engine->engineActive = false;
        return false;
    }
    // unsuccessful
    return true;
}

bool BSRestartAudioEngine()
{
    // BSShutdown returns false if successful
    if (!BSShutDown())
        // true if success
//        return BSInitialiseDevice(engine->eventWrapper);
        return BSInitialiseDevice();
    else
        return false;
}

void BSSetTrackGain(int track, float gain)
{
    engine->trackArray.getReference(track)->gain = gain;
}

void BSSetTrackPan(int track, float pan)
{
    engine->trackArray.getReference(track)->panChannelGainArray.getReference(0) = channelGainFromPan(pan, 0);
    engine->trackArray.getReference(track)->panChannelGainArray.getReference(1) = channelGainFromPan(pan, 1);
}

void BSSetMainGain(float gain)
{
    engine->mainGain = gain;
}

void BSSetMainPan(float pan)
{
    engine->mainPanChannelGainArray.getReference(0) = channelGainFromPan(pan, 0);
    engine->mainPanChannelGainArray.getReference(1) = channelGainFromPan(pan, 1);
}

void BSSetInputMonitoringGain(float gain)
{
    engine->setInputMonitoringGain(gain);
}

void BSSetInputGain(float gain)
{
    engine->setInputGain(gain);
}

bool BSMixdown()
{
    juce::AudioBuffer<float>* mixdownBufferPtr = &engine->mixdownBuffer;
    mixdownBufferPtr->clear();
    int numMixdownSamples = 0;

    // get the longest non-sampleLoop buffer size
    for (auto track : engine->trackArray)
    {
        if (!track->isSampleLoop() &&
            track->getCurrentTakeBufferPointer()->getNumSamples() > numMixdownSamples)
        {
            numMixdownSamples = track->getCurrentTakeBufferPointer()->getNumSamples();
        }
    }

    // if the numMixdownSamples is still 0, all tracks are sampleLoops.
    // set the numMixdownSamples to maximum file length allowed
    if (numMixdownSamples == 0) { numMixdownSamples = engine->maxFileLengthSamples; }

    mixdownBufferPtr->setSize(2, numMixdownSamples);

    // bake effect to each track and add to buffer
    for (auto& track : engine->trackArray)
    {
        juce::AudioBuffer<float> tempBuffer;

        track->bakeEffect();
        tempBuffer.makeCopyOf(track->getBakedEffectBuffer());

        // if sampleloop, trim buffer to length of longest non-sampleloop buffer
        if (track->isSampleLoop())
        {
            tempBuffer.setSize(2, numMixdownSamples, true);
            if (tempBuffer.getNumSamples()> 1024)
            {
                tempBuffer.applyGainRamp(0, tempBuffer.getNumSamples()-1024, 1024, 1.0f, 0.0f);
            }
        }

        mixdownBufferPtr->addFrom(0, 0, tempBuffer, 0, 0, tempBuffer.getNumSamples(),
                                  track->panChannelGainArray.getUnchecked(0)*track->gain);
        mixdownBufferPtr->addFrom(1, 0, tempBuffer, 1, 0, tempBuffer.getNumSamples(),
                                  track->panChannelGainArray.getUnchecked(1)*track->gain);
    }

    engine->mainBus->getCurrentTakeBufferPointer()->makeCopyOf(*mixdownBufferPtr);
    engine->mainBus->bakeEffect();

    if (engine->mixdownBuffer.getNumSamples() > 0)
        return true;
    else
        return false;
}

void BSAnalyseTrack1(std::string absoluteFilePath, void recordingStoppedCallback(std::string filePath)){

}

void BSAnalyseTrack(std::string absoluteFilePath, CallbackWrapper* callback)
{
    juce::File file(absoluteFilePath);
    if (file.exists())
    {
        juce::FlacAudioFormat flacFormat;
        juce::AudioFormatReader* reader = flacFormat.createReaderFor(new juce::FileInputStream(file), true);

        long lengthInSamples = reader->lengthInSamples;
        int sampleRate = reader->sampleRate;
        int numChannels = reader->numChannels;
        int bitdepth = reader->bitsPerSample;
        long lengthInMicros = lengthInSamples / sampleRate * 1000000.00;  // this needs corrected

        callback->analyseTrackCallback(lengthInSamples, sampleRate, bitdepth, lengthInMicros);
    }
}

void BSSetCompressionValues(int sampleRate, int bitDepth, int compressionValue)
{
    engine->writeSampleRate = sampleRate;
    engine->writeBitdepth = bitDepth;
    engine->writeCompressionValue = compressionValue;
}

void BSCompressFiles(CallbackWrapper* callback)
{
    std::vector<std::string> compressedFilepaths;
    for (int i = 0; i < engine->trackArray.size(); i++)
    {
        Track* track = engine->trackArray.getReference(i);
        if (track->getTakesSize() > 0)
        {
            juce::String filename = "compressedTrack";
            filename = filename+=i;
            filename = filename+=".flac";
            juce::String legalFilename = juce::File::createLegalFileName(filename);
            juce::File flacFile = engine->tempDirectory.getChildFile(legalFilename);
            juce::AudioBuffer<float>* bufferPtr = track->getCurrentTakeBufferPointer();
            writeCompressedFlacFile(flacFile, bufferPtr);
            compressedFilepaths.push_back(flacFile.getFullPathName().toStdString());
        }
    }

    // array of paths to callback!
    callback->compressFilesCallback(compressedFilepaths);
}

void BSCompressFile(std::string absoluteFilePath, CallbackWrapper* callback)
{
    juce::File file = juce::String(absoluteFilePath);
    juce::AudioBuffer<float> bufferToCompress;
    juce::AudioBuffer<float>* bufferPtr = &bufferToCompress;
    if (file.exists())
    {
        // read file to that buffer.
        readFile(file, bufferPtr);
        // write out with ccompressed appended to name and correct compression values for database.
        juce::String filename = "compressed";
        filename = file.getFileNameWithoutExtension()+=filename;
        filename = filename+=".flac";
        juce::String legalFilename = juce::File::createLegalFileName(filename);
        juce::File flacFile = engine->tempDirectory.getChildFile(legalFilename);
        writeCompressedFlacFile(flacFile, bufferPtr);
        callback->compressFileCallback(flacFile.getFullPathName().toStdString());
    }
}

void BSReadFile(std::string filePath, int trackNum, int takeNum, bool sampleLoop, CallbackWrapper* callback)
{
    juce::File file = juce::String(filePath);
    juce::AudioBuffer<float>* bufferPtr = engine->trackArray.getReference(trackNum)->getTakeBufferPointer(takeNum);
    readFile(file, bufferPtr);
    engine->trackArray.getReference(trackNum)->setSampleLoop(sampleLoop);

    // callback info
    int sampleRate = engine->sampleRate;
    std::string newFilePath = flacFilePathFromTrackNumber(trackNum, takeNum).getFullPathName().toStdString();
    long recLen = bufferPtr->getNumSamples();

    // write the bufferPtr to disk
    if (file.exists() && bufferPtr->getNumSamples() > 0)
    {
        juce::File flacFile = flacFilePathFromTrackNumber(trackNum, takeNum);
        writeFlacFile(flacFile, bufferPtr);  // write new read buffer to the device
        std::vector<float> waveform = waveformArray(bufferPtr);
        callback->readFileCallback(recLen, sampleRate, newFilePath, waveform);
    }
    else
    {
        engine->trackArray.getReference(trackNum)->getTakeBufferPointer(takeNum)->clear();
        engine->trackArray.getReference(trackNum)->getTakeBufferPointer(takeNum)->setSize(0, 0);
        std::vector<float> emptyVector = { 0.0f, 0.9f, 1.0f };
        callback->readFileCallback(recLen, sampleRate, newFilePath, emptyVector);
    }
}

bool BSMonitor()
{
    engine->recordingMonitor = !engine->recordingMonitor;
    return engine->recordingMonitor;
}

void BSSetBPM(float bpm)
{
    engine->bpm = bpm;
    engine->samplesPerBeat = engine->sampleRate/(bpm / 60);
    setCountInLengthInSamples();
}

void BSSetMetronomeStatus(bool status)
{
    engine->metronomeStatus = status;
    setCountInLengthInSamples();
}

void BSSetMetronomeLevel(float level)
{
    engine->setMetronomeLevel(level);
}

void BSSetHeadphonesConnected(bool connected)
{
    engine->setHeadphonesConnected(connected);
}

void BSSetCountInBars(int bars, CallbackWrapper *callback)
{
    if (bars > 0) engine->countInFinishedCallbackPointer = callback;
    engine->countInBars = bars;
    setCountInLengthInSamples();
}

void BSSetMetronomeTimeSignature(int nominator, int denominator)
{
    engine->timeSignature.set(0, nominator);
    engine->timeSignature.set(1, denominator);
    setCountInLengthInSamples();
}

void BSListener(bool listener)
{
    engine->emitterListeners = listener;
}

void BSAddTrackEffect(int trackNum, std::string effectName)
{
    engine->addTrackEffect(trackNum, effectName);
}

void BSRemoveTrackEffects(int trackNum)
{
    engine->removeTrackEffects(trackNum);
}

void BSSetEffectMixValue(int trackNum, float mixValue)
{
    engine->trackArray.getReference(trackNum)->setMixValue(mixValue);
}

void BSAddMainBusEffect(std::string effectName)
{
    engine->addMainBusEffect(effectName);
}

void BSResetMainBusEffect()
{
    engine->resetMainBusEffect();
}

void BSSetMainBusMixValue(float mixValue)
{
    engine->setMixValueMainBusEffect(mixValue);
}

void BSSetManualLatencyOverride(bool state)
{
    engine->setManualLatencyOverride(state);
}

void BSSetManualLatency(int samples)
{
    engine->setManualLatency(samples);
}

// timer is started when recording finishes
// repeatedly called until the file recorded to disk is read to engine buffer.
void BSEngine::timerCallback()
{
    if (engineActive)
    {
        // read the file into appropriate engine buffer
        int currentTakeNumber = trackArray.getReference(currentTrackNumber)->getCurrentTakeNumber();
        juce::File file = flacFilePathFromTrackNumber(currentTrackNumber, currentTakeNumber);
        juce::AudioBuffer<float>* bufferPtr = trackArray.getReference(currentTrackNumber)->getCurrentTakeBufferPointer();
        readFile(file, bufferPtr);

        // if the recording was not made from the start, offset it by appropriate number of samples
        if (offsetStartOfRecording)
        {
            bufferPtr->setSize(bufferPtr->getNumChannels(), bufferPtr->getNumSamples()+offsetNumSamples, true);

            for (int ch = 0; ch < bufferPtr->getNumChannels(); ch++)
            {
                // move samples from position in buffer to position + offsetNumSamples
                for (int index = bufferPtr->getNumSamples()-1; index >= offsetNumSamples; index--)
                {
                    float sample = bufferPtr->getSample(ch, index-offsetNumSamples);
                    bufferPtr->setSample(ch, index, sample);
                }
                bufferPtr->clear(ch, 0, offsetNumSamples);  // set the start of the file to silence
            }
            bufferPtr->applyGainRamp(offsetNumSamples, 1024, 0, 1);  // fade in to offset
            offsetStartOfRecording = false;
        }

        // fade in and out
        if (bufferPtr->getNumSamples() > 2048)
        {
            bufferPtr->applyGainRamp(0, 1024, 0.0f, 1.0f);
            bufferPtr->applyGainRamp(bufferPtr->getNumSamples()-1024, 1024, 1.0f, 0.0f);
            writeFlacFile(file, bufferPtr);
        }

        trackArray.getReference(currentTrackNumber)->setWaveformArray(waveformArray(bufferPtr));

        if (file.exists() && bufferPtr->getNumSamples() > 0)
        {
            if (engine->recordStoppedCallbackPointer)
            {
                stoppedRecordingCallback();
                engine->recordStoppedCallbackPointer = nullptr;
            }
            engine->stopTimer();
        }
    }

    // clean up
    m_writeNumSamples = 0;
    offsetNumSamples = 0;
}

void BSEngine::audioDeviceAboutToStart(juce::AudioIODevice *device)
{
    // when connecting bluetooth headphones, the device samplerate changes.
    // this should handle that change by rereading and resampling the files on device at new samplerate.
    // any playback bool that has been set true will still be true at this point. Theoretically this means that the playback will resume.

    if (device->getCurrentSampleRate() != sampleRate || device->getCurrentBufferSizeSamples() != bufferSize)
    {

        if (m_outputBufferPos > 0)
            setOutputBufferPos((m_outputBufferPos/sampleRate) * device->getCurrentSampleRate());

        maxFileLengthSamples = maxFileLengthSeconds * device->getCurrentSampleRate();

        juce::AudioDeviceManager::AudioDeviceSetup setup = engine->audioDeviceManager.getAudioDeviceSetup();
        juce::Array<int> bufferSizes = engine->audioDeviceManager.getCurrentAudioDevice()->getAvailableBufferSizes();
        juce::Array<double> sampleRates = engine->audioDeviceManager.getCurrentAudioDevice()->getAvailableSampleRates();
        setup.bufferSize = bufferSizes.getFirst();
        setup.sampleRate = sampleRates.getLast();
        audioDeviceManager.setAudioDeviceSetup(setup, false);

        sampleRate = device->getCurrentSampleRate();
        bufferSize = device->getCurrentBufferSizeSamples();

        // initialise processorGraph
        for (auto& track : trackArray)
            track->initialiseEffectProcessorGraph(sampleRate, bufferSize);

        // initialise mainBus graph
        mainBus->initialiseEffectProcessorGraph(sampleRate, bufferSize);

        // engineActive, this is not initial start up
        // files on the device need resampled into track buffers
        if (engineActive)
        {
            for (int i = 0; i < trackArray.size(); i++)
            {
                for (int j = 0; j < trackArray.getReference(i)->getTakesSize(); j++)
                {
                    juce::File file = flacFilePathFromTrackNumber(i, j);
                    juce::AudioBuffer<float>* bufferPtr = trackArray.getReference(i)->getTakeBufferPointer(j);
                    readFile(file, bufferPtr);
                }
            }
            BSReadMixdownFlac();
            BSSetMetronomeSound(metronomeDownFilePath, metronomeUpFilePath);
        }
    }

    // latency always need to be accounted for
    m_inputLatency = device->getInputLatencyInSamples();
    m_outputLatency = device->getOutputLatencyInSamples();
    m_bluetoothLatency = microsToSamples(m_bluetoothLatencyMS);

    //Test tone output
    testTone.prepareToPlay(bufferSize, sampleRate);

    std::cout << "bufferSize: " << bufferSize << " sampleRate: " << sampleRate << std::endl;
    std::cout << "inputLatency: " << m_inputLatency << " outputLatency: " << m_outputLatency << std::endl;
}

void BSEngine::audioDeviceStopped()
{
    // if device is stopped, stop the recording - which sends the recording callback to frontend.
    if (recordTrack)
        BSStop();

    mainBus->processorGraph->reset();

    for (auto& track : trackArray)
        track->resetEffectGraph();
}
