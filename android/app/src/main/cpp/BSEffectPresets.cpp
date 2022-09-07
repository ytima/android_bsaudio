/*
  ==============================================================================

    BSEffectPresets.cpp
    Created: 2 Aug 2022 1:08:21pm
    Author:  BeeSting

  ==============================================================================
*/
 
#include "BSEffectPresets.h"

effectPreset defaultEffect()
{
    
    juce::Array<effect> effects = { gainproc, gainproc, gainproc, gainproc };
    
    effectParams gainParams;
    gainParams.gainParams.db = 0.0f;

    juce::Array<effectParams> parameters = { gainParams, gainParams, gainParams, gainParams};
    
    effectPreset defaultPreset;
    
    defaultPreset.effects = effects;
    defaultPreset.parameters = parameters;
    
    return defaultPreset;
}

effectPreset compressorEffect()
{

    juce::Array<effect> effects = { compressorproc };
    
    effectParams compParams;
    compParams.compParams.attack = 0.1f;
    compParams.compParams.threshold = -5.0f;
    compParams.compParams.ratio = 2.0f;
    compParams.compParams.release = 10.0f;

    juce::Array<effectParams> parameters = { compParams };
    
    effectPreset compPreset;
    
    compPreset.effects = effects;
    compPreset.parameters = parameters;
    
    return compPreset;
}

effectPreset reverbShortEffect()
{
    juce::Array<effect> effects = { reverbproc };

    effectParams reverbParams;
    reverbParams.revParams.width = 0.5f;
    reverbParams.revParams.damping = 0.1f;
    reverbParams.revParams.dryLevel = 0.0f;
    reverbParams.revParams.roomSize = 0.2f;
    reverbParams.revParams.wetLevel = 1.0f;

    juce::Array<effectParams> parameters = { reverbParams };
    
    effectPreset reverbPreset;
    
    reverbPreset.effects = effects;
    reverbPreset.parameters = parameters;
    
    return reverbPreset;
}

effectPreset reverbLongEffect()
{
    
    juce::Array<effect> effects = { reverbproc };

    effectParams reverbParams;
    reverbParams.revParams.width = 0.5f;
    reverbParams.revParams.damping = 0.1f;
    reverbParams.revParams.dryLevel = 0.0f;
    reverbParams.revParams.roomSize = 0.7f;
    reverbParams.revParams.wetLevel = 1.0f;

    juce::Array<effectParams> parameters = { reverbParams };
    
    effectPreset reverbPreset;
    
    reverbPreset.effects = effects;
    reverbPreset.parameters = parameters;
    
    return reverbPreset;
}

effectPreset delaySlapbackEffect()
{
    
    juce::Array<effect> effects = { delayproc };

    effectParams delayParams;
    delayParams.delayParams.delayTime = 0.075f;
    delayParams.delayParams.feedback = 0.1f;
    delayParams.delayParams.dry = 0.0f;
    delayParams.delayParams.wet = 1.0f;

    juce::Array<effectParams> parameters = { delayParams };
    
    effectPreset delayPreset;
    
    delayPreset.effects = effects;
    delayPreset.parameters = parameters;
    
    return delayPreset;
}

effectPreset delayLongEffect()
{
    
    juce::Array<effect> effects = { delayproc };

    effectParams delayParams;
    delayParams.delayParams.delayTime = 0.2f;
    delayParams.delayParams.feedback = 0.5f;
    delayParams.delayParams.dry = 0.0f;
    delayParams.delayParams.wet = 1.0f;

    juce::Array<effectParams> parameters = { delayParams };
    
    effectPreset delayPreset;
    
    delayPreset.effects = effects;
    delayPreset.parameters = parameters;
    
    return delayPreset;
}

effectPreset mainBusEffect()
{
    
    juce::Array<effect> effects = { gainproc, gainproc, gainproc, complimproc};
    
    effectParams gainParams;
    gainParams.gainParams.db = 0.0f;
    
    effectParams compLimParams;
    compLimParams.compLimParams.compAttackTime  = 0.1f;
    compLimParams.compLimParams.compThresholddB = -3.0f;
    compLimParams.compLimParams.compRatio = 1.2f;
    compLimParams.compLimParams.compReleaseTime = 5.0f;
    compLimParams.compLimParams.limRelease = 1.0f;
    compLimParams.compLimParams.limThreshold = 0.f;
    
    juce::Array<effectParams> parameters = { gainParams, gainParams, gainParams, compLimParams };
    
    effectPreset compLimPreset;
    compLimPreset.effects = effects;
    compLimPreset.parameters = parameters;
    
    return compLimPreset;
}

effectPreset alteredMainBusEffect()
{
    juce::Array<effect> effects = { gainproc, gainproc, gainproc, gainproc};
    
    effectParams gainParams;
    gainParams.gainParams.db = 0.0f;
    
    juce::Array<effectParams> parameters = { gainParams, gainParams, gainParams, gainParams };
    
    effectPreset defaultPreset;
    defaultPreset.effects = effects;
    defaultPreset.parameters = parameters;
    
    return defaultPreset;
}
