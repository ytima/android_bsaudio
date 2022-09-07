/*
  ==============================================================================

    BSEffectPresets.h
    Created: 2 Aug 2022 1:08:21pm
    Author:  BeeSting

  ==============================================================================
*/

//#include <JuceHeader.h>
#include "EffectProcessor.h"
#include "./BSAudioEngine/lib/include/JuceHeader.h"

enum effect { noproc, reverbproc, delayproc, gainproc, compressorproc, limiterproc, complimproc };

struct effectParams {
    juce::Reverb::Parameters revParams;
    delayParams delayParams;
    gainParams gainParams;
    compParams compParams;
    limParams limParams;
    compLimParams compLimParams;
    
};

class effectPreset {
public:
    juce::Array<effect> effects;
    juce::Array<effectParams> parameters;
    
    int getNumProcessors() { return effects.size(); }
};

// track pressets
effectPreset defaultEffect();
effectPreset compressorEffect();
effectPreset reverbShortEffect();
effectPreset reverbLongEffect();
effectPreset delaySlapbackEffect();
effectPreset delayLongEffect();

// main bus effects
effectPreset mainBusEffect();
effectPreset alteredMainBusEffect();

#pragma once
