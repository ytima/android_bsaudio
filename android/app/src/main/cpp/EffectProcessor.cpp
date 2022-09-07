/*
  ==============================================================================

    ReverbProcessor.cpp
    Created: 15 Jul 2022 10:53:57am
    Author:  BeeSting

  ==============================================================================
*/

#include "EffectProcessor.h"

// Reverb processor

ReverbProcessor::ReverbProcessor (juce::Reverb::Parameters params)
{
    revParams = params;
};

void ReverbProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    reverb.setParameters(revParams);
    reverb.setSampleRate(sampleRate);
}

void ReverbProcessor::processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&)
{
    
    auto ptrs = buffer.getArrayOfWritePointers();
    reverb.setParameters(revParams);
    
    if (buffer.getNumChannels() == 1)
        reverb.processMono(ptrs[0], buffer.getNumSamples());
    else if (buffer.getNumChannels() == 2)
        reverb.processStereo (ptrs[0], ptrs[1], buffer.getNumSamples());
    else
        jassertfalse;
}

void ReverbProcessor::reset()
{
    reverb.reset();
}

//========================================================================================

DelayProcessor::DelayProcessor(delayParams params)
{
    delayTime = params.delayTime;
    feedback = params.feedback;
    dry = params.dry;
    wet = params.wet;
}

void DelayProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    currentSampleRate = sampleRate;
    delay.setMaximumDelayInSamples(2*sampleRate);
    juce::dsp::ProcessSpec spec { sampleRate, static_cast<juce::uint32> (samplesPerBlock), 2 };
    delay.prepare (spec);
}

void DelayProcessor::processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&)
{
    
    int delaySamples = (delayTime) * currentSampleRate;
    delay.setDelay(delaySamples);

    auto readPointers = buffer.getArrayOfReadPointers();
    auto writePointers = buffer.getArrayOfWritePointers();
    
    for (int sample = 0; sample < buffer.getNumSamples(); sample++)
    {
        
        for(int ch = 0; ch < buffer.getNumChannels(); ch++)
        {
            
            float inputSample = readPointers[ch][sample];
            float delaySample = delay.popSample(ch, -1, true);
            
            float sampleToPush = inputSample + delaySample * (feedback);
            
            delay.pushSample(ch, sampleToPush);
            
            writePointers[ch][sample] = inputSample * (dry) + delaySample * (wet);
            
        }
    }
}

void DelayProcessor::reset()
{
    delay.reset();
}

//========================================================================================

GainProcessor::GainProcessor(gainParams params)
{
    db = params.db;
}

void GainProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    juce::dsp::ProcessSpec spec { sampleRate, static_cast<juce::uint32> (samplesPerBlock), 2 };
    gain.prepare (spec);
    gain.setGainDecibels(db);
}

void GainProcessor::processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&)
{
    
    juce::dsp::AudioBlock<float> block (buffer);
    juce::dsp::ProcessContextReplacing<float> context (block);
    gain.process (context);
}

void GainProcessor::reset()
{
    gain.reset();
}

//========================================================================================

CompressorProcessor::CompressorProcessor(compParams params)
{
    threshold = params.threshold;
    ratio = params.ratio;
    attack = params.attack;
    release = params.release;
}

void CompressorProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    juce::dsp::ProcessSpec spec { sampleRate, static_cast<juce::uint32> (samplesPerBlock), 2 };
    compressor.prepare (spec);
    
    compressor.setThreshold(threshold);
    compressor.setRatio(ratio);
    compressor.setAttack(attack);
    compressor.setRelease(release);
}

void CompressorProcessor::processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&)
{
    
    juce::dsp::AudioBlock<float> block (buffer);
    juce::dsp::ProcessContextReplacing<float> context (block);
    compressor.process (context);
}

void CompressorProcessor::reset() {
    compressor.reset();
}

//========================================================================================

LimiterProcessor::LimiterProcessor(limParams params)
{
    threshold = params.threshold;
    release = params.release;
}

void LimiterProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    juce::dsp::ProcessSpec spec { sampleRate, static_cast<juce::uint32> (samplesPerBlock), 2 };
    limiter.prepare (spec);
    limiter.setThreshold(threshold);
    limiter.setRelease(release);
}

void LimiterProcessor::processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&)
{
    
    juce::dsp::AudioBlock<float> block (buffer);
    juce::dsp::ProcessContextReplacing<float> context (block);

    limiter.process (context);
}

void LimiterProcessor::reset()
{
    limiter.reset();
}

//========================================================================================

MainBusCompLim::MainBusCompLim(compLimParams params)
{
    // Limiter parameters
    limThreshold = params.limThreshold;
    limRelease = params.limRelease;
    
    // Compressor parameters
    compThresholddB = params.compThresholddB;
    compRatio = params.compRatio;
    compAttackTime = params.compAttackTime;
    compReleaseTime = params.compReleaseTime;
}

void MainBusCompLim::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    juce::dsp::ProcessSpec spec { sampleRate, static_cast<juce::uint32> (samplesPerBlock), 2 };
    chain.prepare (spec);
    //compressor
    auto& compressor = chain.template get<0>();
    compressor.setThreshold(compThresholddB);
    compressor.setRatio(compRatio);
    compressor.setAttack(compAttackTime);
    compressor.setRelease(compReleaseTime);

    //limiter
    auto& limiter = chain.template get<1>();
    limiter.setThreshold(limThreshold);
    limiter.setRelease(limRelease);
}

void MainBusCompLim::processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&)
{
    
    juce::dsp::AudioBlock<float> block (buffer);
    juce::dsp::ProcessContextReplacing<float> context (block);
    chain.process (context);

}

void MainBusCompLim::reset()
{
    chain.reset();
}
