//
//  BSInternal.cpp
//  BSAudioEngine - Static Library
//
//  Created by BeeSting on 18/04/2022.
//

#include "BSInternal.h"

#include <string>

void writeFlacFile(juce::File file, juce::AudioBuffer<float> *buffer)
{
    // clear the old file and write out at engine sample rate
    file.deleteFile();
    juce::FlacAudioFormat flacFormat;
    
    // writer, at engine samplerate, 24 bitdepth and 0 compression level
    juce::AudioFormatWriter* writer = flacFormat.createWriterFor(new juce::FileOutputStream(file.getFullPathName()), engine->sampleRate, buffer->getNumChannels(), 24, {}, 0);

    // write
    if (writer != nullptr)
    {
        writer->writeFromAudioSampleBuffer(*buffer, 0, buffer->getNumSamples());
        writer->flush();
        delete writer;
    }
}

void writeCompressedFlacFile(juce::File file, juce::AudioBuffer<float> *buffer)
{
    // clear the old file if it exists
    file.deleteFile();
    
    
    // set resampling up
    double outSamplerate = engine->writeSampleRate;
    double sampleRatio = static_cast<double>(engine->sampleRate) / outSamplerate;
    juce::FlacAudioFormat flacFormat;
    // second argument of MemoryAudioSource makes sure input is copied 
    juce::ResamplingAudioSource resampler(new juce::MemoryAudioSource(*buffer, true), true);
    
    // resample
    resampler.setResamplingRatio(sampleRatio);
    resampler.prepareToPlay(buffer->getNumSamples()*(1/sampleRatio), outSamplerate);
    
    // writer
    juce::AudioFormatWriter* writer = flacFormat.createWriterFor(new juce::FileOutputStream(file.getFullPathName()), outSamplerate, buffer->getNumChannels(), engine->writeBitdepth, {}, engine->writeCompressionValue);

    // write
    if (writer != nullptr)
    {
        writer->writeFromAudioSource(resampler, buffer->getNumSamples()*(1/sampleRatio));
        writer->flush();
        delete writer;
    }
}

void clearAllBuffers()
{
    // clear all the data on all takes on all tracks
    for (auto& track : engine->trackArray)
        for (int i = 0; i < track->getTakesSize(); i++)
        {
            track->getTakeBufferPointer(i)->clear();
        }
}

void readFile(juce::File file, juce::AudioBuffer<float>* bufferPtr)
{
    if (file.exists() && file.getSize() > 0)
    {
        // format manager to read all formats supported (flac, wav, ogg, mp3 etc...)
        juce::AudioFormatManager formatManager;
        formatManager.registerBasicFormats();
        juce::AudioFormatReader* reader = formatManager.createReaderFor(file);
        
        if (reader != nullptr)
        {
            // resample to the engine's samplerate
            double sampleRatio = reader->sampleRate / engine->sampleRate;
            
            bufferPtr->setSize(reader->numChannels, reader->lengthInSamples*(1/sampleRatio));
            juce::ResamplingAudioSource resampler(new juce::AudioFormatReaderSource(reader, true), true);
            resampler.setResamplingRatio(sampleRatio);
            resampler.prepareToPlay(reader->lengthInSamples, engine->sampleRate);
            resampler.getNextAudioBlock(juce::AudioSourceChannelInfo(*bufferPtr));

            // the file was mono,so the buffer is mono! make the buffer stereo, leave the file as mono
            if (bufferPtr->getNumChannels() == 1)
            {
                bufferPtr->setSize(2, bufferPtr->getNumSamples(), true);
                bufferPtr->copyFrom(1, 0, *bufferPtr, 0, 0, bufferPtr->getNumSamples());
            }
            
            // file is over 1 min long. Trim to 1 min and add fadeout to stop clicks
            if (bufferPtr->getNumSamples() > engine->maxFileLengthSamples)
            {
                bufferPtr->setSize(2, engine->maxFileLengthSamples, true, true);
                bufferPtr->applyGainRamp(bufferPtr->getNumSamples()-1024, 1024, 1.0f, 0.0f);
            }
            
        }
    }
}

juce::File flacFilePathFromTrackNumber(int trackNum, int takeNum)
{
    
    // create track directory, if it doesn't already exist
    juce::String dirName("track"+juce::String(trackNum));
    juce::String legalDirName = juce::File::createLegalFileName(dirName);
    juce::File trackDir = engine->tempDirectory.getChildFile(legalDirName);
    if (!trackDir.exists()) trackDir.createDirectory();
    
    // create filePath for take number;
    juce::String fileName("take"+juce::String(takeNum)+".flac");
    juce::String legalFileName = juce::File::createLegalFileName(fileName);
    juce::File flacFile = trackDir.getChildFile(legalFileName);

    return flacFile;
}

void stoppedRecordingCallback()
{
    // for data needed after recording
    // recorded length in samples
    long reclen = engine->trackArray.getReference(engine->currentTrackNumber)->getCurrentTakeBufferPointer()->getNumSamples();
    // samplerate of recording made
    int sampleRate = engine->sampleRate;
    // filepath
    std::string filePath = flacFilePathFromTrackNumber(engine->currentTrackNumber, engine->trackArray.getReference(engine->currentTrackNumber)->getCurrentTakeNumber()).getFullPathName().toStdString();
    // waveform array
    std::vector<float> waveformArray = engine->trackArray.getReference(engine->currentTrackNumber)->getWaveformArray();
    engine->recordingStoppedCallback(reclen, sampleRate, filePath, waveformArray);
}

long microsToSamples(long micros)
{
    return micros * (engine->sampleRate / 1000000.00);
}

void setCountInLengthInSamples()
{
    // convert the number of bars countin to a length in samples
    float bpm = engine->bpm;
    int timeSigNom = engine->timeSignature.getUnchecked(0);
    int bars = engine->countInBars;
    long countInSamples = (60/bpm) * timeSigNom * bars * engine->sampleRate;
    // in countin, let the beat play out, dont start on the bang of the last beat!
    // add a beat to account for that
    countInSamples += engine->samplesPerBeat;
    engine->setCountInSamples(countInSamples);
}

float channelGainFromPan(float pan, int channel)
{
    // turn a pan value from 0.0 to 1.0 into a gain value for a particular channel
    // channel 0 is left, channel 1 is right
    if (channel == 0) {
        float leftChannel = juce::jmap(juce::jlimit(0.5f, 1.0f, pan), 0.5f, 1.0f, 1.0f, 0.0f);
        return leftChannel;
    } else if (channel == 1) {
        float rightChannel = juce::jmap(juce::jlimit(0.0f, 0.5f, pan), 0.0f, 0.5f, 0.0f, 1.0f);
        return rightChannel;
    } else {
        return 0;
    }
}

std::vector<float> waveformArray(juce::AudioBuffer<float>* buffer)
{
    // return a waveform array for a buffer. 100 values
    std::vector<float> waveformArray;
    int iterator = buffer->getNumSamples() / 100; // 100 values in the vector
    
    for (int i = 0; i < buffer->getNumSamples(); i += iterator) {
        float sample = buffer->getSample(0, i);
        if (sample < 0)
            sample = sample * -1;
        waveformArray.push_back(sample);
    }
    
    return waveformArray;
}
