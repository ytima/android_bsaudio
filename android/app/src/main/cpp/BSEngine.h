//
//  BSEngine.h
//  BSAudioEngine - Static Library
//
//  Created by BeeSting on 18/03/2022.
//

#ifndef BSENGINE_H_
#define BSENGINE_H_

#include <vector>
#include <memory>
#include <string>
//#include <JuceHeader.h>
#include "./BSAudioEngine/lib/include/JuceHeader.h"

#include "Track.h"

// Callback Wrapper needed to passs callbacks up to JS frontend, react native only allows these callbacks to be called once.
// The order of these must be identical to the engine definition of the wrapper!
class CallbackWrapper
{
 public:
    virtual void recordingStoppedCallback(long recordedLength,
                                          int sampleRate,
                                          std::string filePath,
                                          std::vector<float> waveformArray);
    virtual void analyseTrackCallback(long fileLengthSamples,
                                      int sampleRate,
                                      int bitDepth,
                                      long fileLengthMicros);
    virtual void compressFilesCallback(std::vector<std::string> absolutePaths);
    virtual void writeMixdownCallback(std::string absolutePath);
    virtual void compressFileCallback(std::string absolutePath);
    virtual void readFileCallback(long recordedLength,
                                  int sampleRate,
                                  std::string filePath,
                                  std::vector<float> waveformArray);
    virtual void playTrackFinishedCallback();
    virtual void multitrackPlayFinishedCallback();
    virtual void countInFinished();
};

// Event Wrapper to wrap up events that are emitted continuously.
// React Native assigns listeners to the events emitted from here.
class EventWrapper
{
 public:
    virtual void sendPlaybackProgress(int position);
    virtual void sendInputLevel(float level);
    virtual void sendMainOutputLevel(float level);
    virtual void sendTrackOutputLevels(std::vector<float> levels);
    virtual void sendOnMetronomeBeat();
    virtual void sendBluetoothConnected(bool bluetoothFlag);
};

// BSEngine does the audio processing and managing input and output (it's the "core" so to sepak)
class BSEngine : public juce::AudioIODeviceCallback,
                 public juce::Timer
{

 public:
    BSEngine();
    ~BSEngine();

    // Audio processing functions
    void audioDeviceIOCallback(const float **inputChannelData, int numInputChannels, float **outputChannelData, int numOutputChannels, int numSamples) override;
    void audioDeviceAboutToStart(juce::AudioIODevice *device) override;
    void audioDeviceStopped() override;
    void timerCallback() override;

    // Recording
    void startRecording(const juce::File& file);  // gets the writer ready to write to disk
    void stop();  // stop writing to disk
    bool isRecording();  // check if write pointer is assigned
    juce::TimeSliceThread backgroundThread { "Audio Recorder Thread" };  // the thread that will write our audio data to disk
    std::unique_ptr<juce::AudioFormatWriter::ThreadedWriter> threadedWriter;  // the FIFO used to buffer the incoming data
    juce::CriticalSection writerLock;
    std::atomic<juce::AudioFormatWriter::ThreadedWriter*> activeWriter { nullptr };
    void stopRecording();  // resets engine member variables and starts the timer thread to read the written file to buffer
    void offsetRecording(int offsetSamples) { offsetStartOfRecording = true; offsetNumSamples = offsetSamples; }  // the recording didn't start from start, so offset it

    // Engine Functions
    void setInputBufferPos(int samples) { m_inputBufferPos = samples; }
    void setOutputBufferPos(int samples) { m_outputBufferPos = samples; }
    void setInputMonitoringGain(float gain) { m_inputMonitoringGain = gain; }
    void setInputGain(float gain) { m_inputGain = gain; }
    void setHeadphonesConnected(bool connected) { m_headphonesConnected = connected; }
    void setMetronomeLevel(float gain) { m_metronomeLevel = gain; }
    void resetEmitThrottleCount() { m_throttleCount = 0; }
    void setCountInSamples(long countInSamples) { m_countInSamples = countInSamples; }

    // Engine Variables
    bool engineActive = false;
    bool recordingMonitor = false;
    bool multitrackFinished = false;
    bool engineStopped = true;
    int sampleRate = 0;
    int bufferSize = 0;
    int currentTrackNumber = 0;
    int maxFileLengthSeconds = 60;
    int maxFileLengthSamples = 2880000;  // default at 48000 samplerate
    float mainGain = 1.0f;  // for gainig main output
    juce::AudioDeviceManager audioDeviceManager;
    juce::File tempDirectory;  // all files written to this directory, cleared on shutdown

    // Takes
    void clearTrackTakes(int trackNum);
    void deleteTrack(int trackNum);
    void deleteTake(int trackNum, int takeNum);

    // Effects
    void removeTrackEffects(int trackNum);
    void addTrackEffect(int trackNum, std::string effectName);
    void addMainBusEffect(std::string effectName);
    void resetMainBusEffect();
    void setMixValueMainBusEffect(float mixValue);

    // Manual latency override
    void setManualLatency(int latencySamples) { m_manualLatency = latencySamples; }
    void setManualLatencyOverride(bool state) { m_manualLatencyOverride = state; }

    // Tracks & Internal Engine Buffers
    juce::Array<Track*> trackArray;
    juce::AudioBuffer<float> mixdownBuffer;
    juce::AudioBuffer<float> metronomeDownBuffer;
    juce::AudioBuffer<float> metronomeUpBuffer;
    juce::Array<float> mainPanChannelGainArray;
    std::vector<float> trackOutputLevels = { 0.0f, 0.0f, 0.0f, 0.0f };
    Track* mainBus;  // main output bus is a track to allow effect functionality on main output

    // Audioiocallback Branches
    bool recordTrack = false;
    bool playTrack = false;
    bool multitrackPlay = false;
    bool mixdownPlay = false;

    // Timing
    bool metronomeStatus = false;
    bool offsetStartOfRecording = false;
    int samplesPerBeat = 48000;
    int countInBars = 0;  // countin length in bars
    int offsetNumSamples = 0;
    float bpm = 120;
    float metronomeModulo = 256;
    juce::Array<int> timeSignature = {4, 4};
    std::string metronomeDownFilePath = "";  // save the paths for ( we need to reread the file if the samplerate changes!)
    std::string metronomeUpFilePath = "";

    // Compression Values (for writing file to be sent to database)
    int writeSampleRate = 48000;
    int writeCompressionValue = 0;
    int writeBitdepth = 16;

    // Callback Pointers
    CallbackWrapper* recordStoppedCallbackPointer = nullptr;
    CallbackWrapper* playTrackFinishedCallbackPointer = nullptr;
    CallbackWrapper* multitrackPlayFinishedCallbackPointer = nullptr;
    CallbackWrapper* countInFinishedCallbackPointer = nullptr;

    // Event Emitting
    bool emitterListeners = false;  // set by front end if there is a listeners to the events
    EventWrapper* eventWrapper = nullptr;

    // Test Tone
    juce::ToneGeneratorAudioSource testTone;

private:

    // Gain and Levels
    float m_inputMonitoringGain = 0.0f;
    float m_inputGain = 1.0f;
    float m_currentInputLevel = 0.0f;
    float m_metronomeLevel = 1.0;

    // Buffer Positions
    int m_inputBufferPos = 0;
    int m_outputBufferPos = 0;
    int m_metronomeBufferPos = 0;

    // Misc
    bool m_headphonesConnected = false;
    bool m_metronomeToggle = false;
    int m_metronomoeCounter = 0;
    int m_numInputChannels = 0;

    // Latency
    bool m_manualLatencyOverride = false;
    int m_inputLatency = 0;
    int m_outputLatency = 0;
    int m_manualLatency = 0;
    int m_bluetoothLatencyMS = 250000;  // arbitrary bluetooth latency value in micros
    int m_bluetoothLatency = 0;
    long m_countInSamples = 0;
    
    // silence from threadedwriter fix
    int m_writeNumSamples = 0;
    

    // Event Emitter Throttle
    int m_throttleCount = 0;  // iterate for every call of audiocallback
    int m_throttleAudioCallbackCycles = 1;  // the amount of cycles per event emit
};

extern BSEngine* engine;

#endif  // BSENGINE_H_
