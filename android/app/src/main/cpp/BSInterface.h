//
// Created by Arthur Wilson on 03/09/2022.
//

#ifndef TEST2NATIVE_CPP_BSINTERFACE_H
#define TEST2NATIVE_CPP_BSINTERFACE_H

#include "BSInternal.h"
#include "./BSAudioEngine/lib/include/JuceHeader.h"

long TestFunction(long a, long b);
void BSSetMetronomeSound(std::string absoluteFilePathDown, std::string absoluteFilePathUp);
void BSWriteMixdownFlac(CallbackWrapper *callback);
void BSReadMixdownFlac();
// a call to prove that we can get the device initilised.
// Will be redundatnt and should be ignored when there are event and callback wrappers working for android
bool BSInitialiseDevice();
void testtestFunct( std::function<void (int)> testFuncccc);
void BSRecordTrack(long startAtMicros, int currentTrackNumber, int currentTakeNumber, CallbackWrapper* callback);
void BSPlayTrack(long startAtMicros, int currentTrackNumber, int currentTakeNumber, CallbackWrapper *callback);
void BSSetTake(int trackNumber, int takeNumber);
void BSSetLoopMode(int trackNum, bool status);
bool BSGetLoopMode(int trackNum);
void BSClearAllUnusedTrackTakes();
void BSClearAllTrackTakes();
void BSClearTrackTakes(int trackNum);
void BSDeleteTake(int trackNum, int takeNum);
void BSDeleteTrack(int trackNum);
void BSMultitrackPlay(long startAtMicros, CallbackWrapper *callback);
void BSMultitrackRecord(long startAtMicros, int currentTrackNumber, int currentTakeNumber, CallbackWrapper *recordCallback);
void BSPlayMixdown(long startAtMicros);
void BSStop();
bool BSShutDown();
bool BSRestartAudioEngine();
void BSSetTrackGain(int track, float gain);
void BSSetTrackPan(int track, float pan);
void BSSetMainGain(float gain);
void BSSetMainPan(float pan);
void BSSetInputMonitoringGain(float gain);
void BSSetInputGain(float gain);
bool BSMixdown();
void BSAnalyseTrack(std::string absoluteFilePath, CallbackWrapper* callback);
void BSAnalyseTrack1(std::string absoluteFilePath, void recordingStoppedCallback(long recordedLength,
                                                                                 int sampleRate,
                                                                                 std::string filePath,
                                                                                 std::vector<float> waveformArray));
void BSSetCompressionValues(int sampleRate, int bitDepth, int compressionValue);
void BSCompressFiles(CallbackWrapper* callback);
void BSCompressFile(std::string absoluteFilePath, CallbackWrapper* callback);
void BSReadFile(std::string filePath, int trackNum, int takeNum, bool sampleLoop, CallbackWrapper* callback);
bool BSMonitor();
void BSSetBPM(float bpm);
void BSSetMetronomeStatus(bool status);
void BSSetMetronomeLevel(float level);
void BSSetHeadphonesConnected(bool connected);
void BSSetCountInBars(int bars, CallbackWrapper *callback);
void BSSetMetronomeTimeSignature(int nominator, int denominator);
void BSListener(bool listener);
void BSAddTrackEffect(int trackNum, std::string effectName);
void BSRemoveTrackEffects(int trackNum);
void BSSetEffectMixValue(int trackNum, float mixValue);
void BSAddMainBusEffect(std::string effectName);
void BSResetMainBusEffect();
void BSSetMainBusMixValue(float mixValue);
void BSSetManualLatencyOverride(bool state);
void BSSetManualLatency(int samples);

#endif //TEST2NATIVE_CPP_BSINTERFACE_H
