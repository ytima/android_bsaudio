//
//  BSInternal.hpp
//  BSAudioEngine - Static Library
//
//  Created by BeeSting on 18/04/2022.
//

#ifndef  BSINTERNAL_H_
#define  BSINTERNAL_H_

#include "BSEngine.h"
#include "./BSAudioEngine/lib/include/JuceHeader.h"

void readFile(juce::File file, juce::AudioBuffer<float>* buffer);
void writeFlacFile(juce::File file, juce::AudioBuffer<float> *buffer);
void writeCompressedFlacFile(juce::File file, juce::AudioBuffer<float> *buffer);
juce::File flacFilePathFromTrackNumber(int trackNum, int takeNum);
bool readFileToBuffer(int trackNum, int takeNum);
void stoppedRecordingCallback();
long microsToSamples(long micros);
void addTrack();
void setCountInLengthInSamples();
float channelGainFromPan(float pan, int channel);
void clearAllBuffers();
std::vector<float> waveformArray(juce::AudioBuffer<float>* bufferPtr);

#endif  // SOURCE_BSINTERNAL_H_
