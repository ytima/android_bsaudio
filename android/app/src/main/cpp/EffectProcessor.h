/*
  ==============================================================================

    EffectProcessor.h
    Created: 15 Jul 2022 10:54:10am
    Author:  BeeSting

  ==============================================================================
*/

#ifndef  EFFECTPROCESSOR_H_
#define  EFFECTPROCESSOR_H_

//#include <JuceHeader.h>
#include "./BSAudioEngine/lib/include/JuceHeader.h"

struct delayParams
{
    float delayTime = 0.2f;
    float feedback = 0.5f;
    float dry = 0.5f;
    float wet = 0.5f;
};

struct gainParams
{
    float db = 0.0f;
};

struct compParams
{
    float threshold = -20.0f;
    float ratio = 1.0f;
    float attack = 0.0f;
    float release = 5.0f;
};

struct limParams
{
    float threshold = 0.0f;
    float release = 0.0f;
};

struct compLimParams
{
    // Limiter parameters
    float limThreshold = -10.0f;
    float limRelease = 100.0f;
    
    // Compressor parameters
    float compThresholddB = 0.0f;
    float compRatio = 1.0f;
    float compAttackTime = 1.0f;
    float compReleaseTime = 100.0f;
};

// base class for all effect processors
class ProcessorBase  : public juce::AudioProcessor
{
public:
    ProcessorBase()
        : AudioProcessor (BusesProperties().withInput ("Input", juce::AudioChannelSet::stereo())
                                           .withOutput ("Output", juce::AudioChannelSet::stereo()))
    {}

    void prepareToPlay (double, int) override {}
    void releaseResources() override {}
    void processBlock (juce::AudioSampleBuffer&, juce::MidiBuffer&) override {}

    juce::AudioProcessorEditor* createEditor() override          { return nullptr; }
    bool hasEditor() const override                              { return false; }

    const juce::String getName() const override                  { return {}; }
    bool acceptsMidi() const override                            { return false; }
    bool producesMidi() const override                           { return false; }
    double getTailLengthSeconds() const override                 { return 0; }

    int getNumPrograms() override                                { return 0; }
    int getCurrentProgram() override                             { return 0; }
    void setCurrentProgram (int) override                        {}
    const juce::String getProgramName (int) override             { return {}; }
    void changeProgramName (int, const juce::String&) override   {}

    void getStateInformation (juce::MemoryBlock&) override       {}
    void setStateInformation (const void*, int) override         {}

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ProcessorBase)
};

//========================================================================================

class ReverbProcessor  : public ProcessorBase
{
public:
    
    ReverbProcessor(juce::Reverb::Parameters parmas);
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&) override;
    void reset() override;
    const juce::String getName() const override { return "Reverb"; };

private:
    juce::Reverb reverb;
    juce::Reverb::Parameters revParams;
};

//========================================================================================

class DelayProcessor  : public ProcessorBase
{
public:
    
    DelayProcessor(delayParams params);
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&) override;
    void reset() override;
    const juce::String getName() const override { return "Delay"; }

private:
    int currentSampleRate = 0;
    juce::dsp::DelayLine<float> delay;
    
    float delayTime = 0.2f;
    float feedback = 0.5f;
    float dry = 0.5f;
    float wet = 0.5f;
};

//========================================================================================

class GainProcessor  : public ProcessorBase
{
public:
    GainProcessor(gainParams params);
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&) override;
    void reset() override;
    const juce::String getName() const override { return "Gain"; }

private:
    juce::dsp::Gain<float> gain;
    float db = 0.0f;
};

//========================================================================================

class CompressorProcessor  : public ProcessorBase
{
public:
    CompressorProcessor(compParams params);

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&) override;
    void reset() override;
    const juce::String getName() const override { return "Compressor"; }

private:
    juce::dsp::Compressor<float> compressor;
    float threshold = -20.0f;
    float ratio = 1.0f;
    float attack = 0.0f;
    float release = 5.0f;
};

//========================================================================================

class LimiterProcessor  : public ProcessorBase
{
public:
    LimiterProcessor(limParams params);

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&) override;
    void reset() override;
    const juce::String getName() const override { return "Limiter"; }

private:
    juce::dsp::Limiter<float> limiter;
    float threshold = 0.0f;
    float release = 0.0f;
};

//========================================================================================

class MainBusCompLim : public ProcessorBase
{
public:
    MainBusCompLim(compLimParams params);
    
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&) override;
    void reset() override;
    const juce::String getName() const override { return "MainBusCompLim"; }
    
private:
    juce::dsp::ProcessorChain<juce::dsp::Compressor<float>, juce::dsp::Limiter<float>> chain;
    // Limiter parameters
    float limThreshold = -10.0f;
    float limRelease = 100.0f;
    
    // Compressor parameters
    float compThresholddB = 0.0f;
    float compRatio = 1.0f;
    float compAttackTime = 1.0f;
    float compReleaseTime = 100.0f;
    
};
#endif  // SOURCE_EFFECTPROCESSOR_H_
