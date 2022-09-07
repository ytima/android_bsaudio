/*
  ==============================================================================

    Track.h
    Created: 15 Jul 2022 11:27:49am
    Author:  BeeSting

  ==============================================================================
*/

#ifndef  TRACK_H_
#define  TRACK_H_

#include <vector>
//#include <JuceHeader.h>
#include "./BSAudioEngine/lib/include/JuceHeader.h"
#include "BSEffectPresets.h"

class Track {
 public:

    Track();

    juce::CriticalSection objectLock;
    
    float gain = 1.0f;
    juce::Array<float> panChannelGainArray;
    std::unique_ptr<juce::AudioProcessorGraph> processorGraph;

    void initialiseEffectProcessorGraph(int sampleRate, int blockSize);
    void resetEffectGraph();
    void clearEffectProcessorGraph();
    void addEffectChain(effectPreset effectPreset, int sampleRate, int blockSize);
    void removeEffects(int sampleRate, int blockSize);
    void resetEffects();
    void setCurrentEffectChain(effectPreset newEffectPreset);
    effectPreset getCurrentEffectChain();
    void bakeEffectToBuffer(juce::AudioBuffer<float> *buffer);
    void bakeEffect();
    juce::AudioBuffer<float> getBakedEffectBuffer();
    juce::AudioBuffer<float>* getBakedEffectBufferPointer();

    void resetTrack();
    void newTake();
    void removeTake (int takeNum);
    void removeAllTakes();
    void setCurrentTakeNumber(int takeNumber);
    int getTakesSize();
    int getCurrentTakeNumber();

    void setWaveformArray(std::vector<float> newArray);
    std::vector<float> getWaveformArray();
    juce::AudioBuffer<float>* getTakeBufferPointer(int takeNumber);
    juce::AudioBuffer<float>* getCurrentTakeBufferPointer();

    void setLoopMode(bool status);
    bool getLoopMode();
    void setLoopBufferPos(int bufferPos);
    int getLoopBufferPos();

    bool isSampleLoop();
    void setSampleLoop(bool newSampleLoop);
    
    void setMixValue(float newValue);
    float getMixValue();
    
private:
    juce::Array<juce::AudioBuffer<float>> takes;
    juce::AudioBuffer<float> bakedEffectBuffer;
    int currentTakeNumber = 0;
    std::vector<float> waveformArray;
    bool loopMode = false;
    int loopBufferPos = 0;
    bool sampleLoop = false;
    float mixValue = 1.0f;
    effectPreset currentEffectPreset = {};

    juce::AudioProcessorGraph::Node::Ptr audioInputNode = nullptr;
    juce::AudioProcessorGraph::Node::Ptr audioOutputNode = nullptr;
    juce::Array<juce::AudioProcessorGraph::Node::Ptr> effectChain;
};

#endif //TRACK_H_
