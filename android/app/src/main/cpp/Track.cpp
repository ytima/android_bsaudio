/*
  ==============================================================================

    Track.cpp
    Created: 15 Jul 2022 11:27:49am
    Author:  BeeSting

  ==============================================================================
*/

#include "Track.h"

Track::Track() : processorGraph (new juce::AudioProcessorGraph())
{
    
    processorGraph->enableAllBuses();
    newTake();
    panChannelGainArray.add(1.0f, 1.0f);
}

void Track::resetTrack() {
    currentTakeNumber = 0;
    waveformArray.clear();
    gain = 1.0f;
    panChannelGainArray.set(0, 1.0f);
    panChannelGainArray.set(1, 1.0f);
    loopMode = false;
    loopBufferPos = 0;
}

void Track::initialiseEffectProcessorGraph(int sampleRate, int blockSize)
{
    processorGraph->clear();
    
    // add processor nodes
    audioInputNode = processorGraph->addNode(std::make_unique<juce::AudioProcessorGraph::AudioGraphIOProcessor> (juce::AudioProcessorGraph::AudioGraphIOProcessor::audioInputNode));
    audioOutputNode = processorGraph->addNode(std::make_unique<juce::AudioProcessorGraph::AudioGraphIOProcessor> (juce::AudioProcessorGraph::AudioGraphIOProcessor::audioOutputNode));

    for (int ch = 0; ch < 2; ch++) {
        processorGraph->addConnection( { {audioInputNode->nodeID, ch},
                                         {audioOutputNode->nodeID, ch} } );
    }
    
        processorGraph->setPlayConfigDetails (2, 2, sampleRate, blockSize);
        processorGraph->prepareToPlay (sampleRate, blockSize);
        processorGraph->enableAllBuses();
    
//    for (auto node : processorGraph->getNodes())
//        node->getProcessor()->enableAllBuses();

}

void Track::resetEffectGraph() {
    processorGraph->reset();
}

void Track::clearEffectProcessorGraph() {
    processorGraph->clear();
}

void Track::addEffectChain(effectPreset effectPreset, int sampleRate, int blockSize)
{
    
    const juce::ScopedLock myScopedLock (objectLock);

    processorGraph->clear();
    effectChain.clear();
    audioInputNode = nullptr;
    audioOutputNode = nullptr;

    for (int i = 0; i < effectPreset.getNumProcessors(); i++) {
        
        effect effect = effectPreset.effects.getUnchecked(i);
        effectParams params = effectPreset.parameters.getUnchecked(i);

        switch (effect)
        {
            case noproc:
            {
                gainParams gainParameters;
                gainParameters.db = 0.0f;
                effectChain.set(i, processorGraph->addNode(std::make_unique<GainProcessor>(gainParameters)));
                break;
            }
            case reverbproc:
            {
                juce::Reverb::Parameters reverbParameters = params.revParams;
                effectChain.set(i, processorGraph->addNode(std::make_unique<ReverbProcessor>(reverbParameters)));
                break;
            }
            case delayproc:
            {
                delayParams delayParameters = params.delayParams;
                effectChain.set(i, processorGraph->addNode(std::make_unique<DelayProcessor>(delayParameters)));
                break;
            }
            case gainproc:
            {
                gainParams gainParameters = params.gainParams;
                effectChain.set(i, processorGraph->addNode(std::make_unique<GainProcessor>(gainParameters)));
                break;
            }
            case compressorproc:
            {
                compParams compParameters = params.compParams;
                effectChain.set(i, processorGraph->addNode(std::make_unique<CompressorProcessor>(compParameters)));
                break;
            }
            case limiterproc:
            {
                limParams limParameters = params.limParams;
                effectChain.set(i, processorGraph->addNode(std::make_unique<LimiterProcessor>(limParameters)));
                break;
            }
            case complimproc:
            {
                compLimParams compLimParameters = params.compLimParams;
                effectChain.set(i, processorGraph->addNode(std::make_unique<MainBusCompLim>(compLimParameters)));
                break;
            }
            default:
                break;
        }
    }
    
    // add processor nodes
    audioInputNode = processorGraph->addNode(std::make_unique<juce::AudioProcessorGraph::AudioGraphIOProcessor> (juce::AudioProcessorGraph::AudioGraphIOProcessor::audioInputNode));
    audioOutputNode = processorGraph->addNode(std::make_unique<juce::AudioProcessorGraph::AudioGraphIOProcessor> (juce::AudioProcessorGraph::AudioGraphIOProcessor::audioOutputNode));
    
    for (int i = 0; i < effectChain.size(); i++)
    {
        effectChain.getReference(i)->getProcessor()->setPlayConfigDetails (
                                                               2,
                                                               2,
                                                               processorGraph->getSampleRate(),
                                                               processorGraph->getBlockSize());
    }
    
    processorGraph->prepareToPlay(sampleRate, blockSize);

    for (int ch = 0; ch < 2; ch++)
    {
        processorGraph->addConnection( { {audioInputNode->nodeID, ch},
                                        {effectChain.getUnchecked(0)->nodeID, ch} } );

        if (effectChain.size() > 1)
        {
            for (int i = 0; i < effectChain.size() - 1; i++)
            {
                processorGraph->addConnection( { {effectChain.getUnchecked(i)->nodeID, ch},
                                                {effectChain.getUnchecked(i+1)->nodeID, ch} } );
            }
    }
    
        processorGraph->addConnection( { {effectChain.getLast()->nodeID, ch},
                                    {audioOutputNode->nodeID, ch} } );
}
    
    for (auto node : processorGraph->getNodes())
        node->getProcessor()->enableAllBuses();
    
}

void Track::removeEffects(int sampleRate, int blockSize)
{
    
    const juce::ScopedLock myScopedLock (objectLock);
    
    processorGraph->clear();
    
    for (int i = 0; i < 4; i++)
    {
        effectChain.set(i, nullptr);
    }

    initialiseEffectProcessorGraph(sampleRate, blockSize);
    
}

void Track::resetEffects()
{
    processorGraph->reset();
}

void Track::setCurrentEffectChain(effectPreset newEffectPreset)
{
    currentEffectPreset = newEffectPreset;
}

effectPreset Track::getCurrentEffectChain()
{
    return currentEffectPreset;
}

void Track::bakeEffectToBuffer(juce::AudioBuffer<float> *buffer)
{
    
    int blockSize = processorGraph->getBlockSize();
    juce::AudioBuffer<float> tempBuffer(2, blockSize);
    juce::MidiBuffer emptyMidiBuffer;
    
    emptyMidiBuffer.clear();
    processorGraph->reset();
    
    for (int i = 0; i + blockSize< bakedEffectBuffer.getNumSamples(); i += blockSize)
    {
        const juce::ScopedLock myScopedLock (objectLock);
        tempBuffer.copyFrom(0, 0, *buffer, 0, i, blockSize);
        tempBuffer.copyFrom(1, 0, *buffer, 1, i, blockSize);
        processorGraph->processBlock(tempBuffer, emptyMidiBuffer);
        buffer->applyGain(0, i, blockSize, 1.0f - getMixValue());
        buffer->applyGain(1, i, blockSize, 1.0f - getMixValue());
        buffer->addFrom(0, i, tempBuffer, 0, 0, blockSize, getMixValue());
        buffer->addFrom(1, i, tempBuffer, 1, 0, blockSize, getMixValue());
    }
}

void Track::bakeEffect()
{
    bakedEffectBuffer.clear();
    bakedEffectBuffer.makeCopyOf(*getCurrentTakeBufferPointer());
    bakeEffectToBuffer(&bakedEffectBuffer);
}

juce::AudioBuffer<float> Track::getBakedEffectBuffer()
{
    return bakedEffectBuffer;
}

juce::AudioBuffer<float>* Track::getBakedEffectBufferPointer()
{
    return &bakedEffectBuffer;
}

int Track::getTakesSize()
{
    return takes.size();
}

void Track::newTake()
{
    takes.add(juce::AudioBuffer<float>(2,0));
}

void Track::removeTake (int takeNum)
{
    takes.remove(takeNum);
}

void Track::removeAllTakes()
{
    for (int i = 0; i < takes.size(); i++)
    {
        takes.set(i, juce::AudioBuffer<float>(2,0));
    }
    takes.clear();
    takes.add(juce::AudioBuffer<float>(2,0));
}

void Track::setCurrentTakeNumber(int takeNumber)
{
    currentTakeNumber = takeNumber;
}

int Track::getCurrentTakeNumber()
{
    return currentTakeNumber;
}

void Track::setWaveformArray(std::vector<float> newArray)
{
    waveformArray = newArray;
}

std::vector<float> Track::getWaveformArray()
{
    return waveformArray;
}

juce::AudioBuffer<float>* Track::getTakeBufferPointer(int takeNumber)
{
    return &takes.getReference(takeNumber);
}

juce::AudioBuffer<float>* Track::getCurrentTakeBufferPointer()
{
    return &takes.getReference(currentTakeNumber);
}

void Track::setLoopMode(bool status)
{
    loopMode = status;
}

bool Track::getLoopMode()
{
    return loopMode;
}

void Track::setLoopBufferPos(int bufferPos)
{
    loopBufferPos = bufferPos;
}

int Track::getLoopBufferPos()
{
    return loopBufferPos;
}

bool Track::isSampleLoop()
{
    return sampleLoop;
}

void Track::setSampleLoop(bool newSampleLoop)
{
    sampleLoop = newSampleLoop;
}

void Track::setMixValue(float newValue)
{
    mixValue = newValue;
}

float Track::getMixValue()
{
    return mixValue;
}
