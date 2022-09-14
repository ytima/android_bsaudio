package com.androidlib;


import android.util.Log;

import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;

import java.util.ArrayList;

public class BSEngineModule extends ReactContextBaseJavaModule {
    BSEngineModule(ReactApplicationContext context) {
        super(context);
    }

    @Override
    public String getName() {
        return "BSAudioEngine";
    }

    static {
        System.loadLibrary("BSAudioEngine");
    }


    public native void BSSetMetronomeSound(String absoluteFilePathDown, String absoluteFilePathUp);

    public native void BSWriteMixdownFlac();

    public native void BSReadMixdownFlac();

    // a call to prove that we can get the device initilised.
// Will be redundatnt and should be ignored when there are event and callback wrappers working for android
    public native boolean BSInitialiseDevice();

    public native void BSRecordTrack(long startAtMicros, int currentTrackNumber, int currentTakeNumber);

    public native void BSPlayTrack(long startAtMicros, int currentTrackNumber, int currentTakeNumber);

    public native void BSSetTake(int trackNumber, int takeNumber);

    public native void BSSetLoopMode(int trackNum, boolean status);

    public native boolean BSGetLoopMode(int trackNum);

    public native void BSClearAllUnusedTrackTakes();

    public native void BSClearAllTrackTakes();

    public native void BSClearTrackTakes(int trackNum);

    public native void BSDeleteTake(int trackNum, int takeNum);

    public native void BSDeleteTrack(int trackNum);

    public native void BSMultitrackPlay(long startAtMicros);

    public native void BSMultitrackRecord(long startAtMicros, int currentTrackNumber, int currentTakeNumber);

    public native void BSPlayMixdown(long startAtMicros);

    public native void BSStop();

    public native boolean BSShutDown();

    public native boolean BSRestartAudioEngine();

    public native void BSSetTrackGain(int track, float gain);

    public native void BSSetTrackPan(int track, float pan);

    public native void BSSetMainGain(float gain);

    public native void BSSetMainPan(float pan);

    public native void BSSetInputMonitoringGain(float gain);

    public native void BSSetInputGain(float gain);

    public native boolean BSMixdown();

    public native void BSAnalyseTrack(String absoluteFilePath);

    public native void BSSetCompressionValues(int sampleRate, int bitDepth, int compressionValue);

    public native void BSCompressFiles();

    public native void BSCompressFile(String absoluteFilePath);

    public native void BSReadFile(String filePath, int trackNum, int takeNum, boolean sampleLoop);

    public native boolean BSMonitor();

    public native void BSSetBPM(float bpm);

    public native void BSSetMetronomeStatus(boolean status);

    public native void BSSetMetronomeLevel(float level);

    public native void BSSetHeadphonesConnected(boolean connected);

    public native void BSSetCountInBars( int bars);

    public native void BSSetMetronomeTimeSignature(int nominator, int denominator);

    public native void BSListener(boolean listener);

    public native void BSAddTrackEffect(int trackNum, String effectName);

    public native void BSRemoveTrackEffects(int trackNum);

    public native void BSSetEffectMixValue(int trackNum, float mixValue);

    public native void BSAddMainBusEffect(String effectName);

    public native void BSResetMainBusEffect();

    public native void BSSetMainBusMixValue(float mixValue);

    public native void BSSetManualLatencyOverride(boolean state);

    public native void BSSetManualLatency(int samples);


    void recordingStoppedCallback(long recordedLength,
                                  int sampleRate,
                                  String filePath,
                                  ArrayList waveformArray) {
        recordingStoppedCallback.invoke(recordedLength, sampleRate, filePath, waveformArray);
    }

    void analyseTrackCallback(long fileLengthSamples,
                              int sampleRate,
                              int bitDepth,
                              long fileLengthMicros) {
        analyseTrackCallback.invoke(fileLengthSamples, sampleRate, bitDepth, fileLengthMicros);
    }

    ;

    void compressFilesCallback(ArrayList absolutePaths){
        compressFilesCallback.invoke(absolutePaths);
    }

    void writeMixdownCallback(String absolutePath) {
        writeMixdownCallback.invoke(absolutePath);
    }

    void compressFileCallback(String absolutePath){
        compressFileCallback.invoke(absolutePath);
    };

    void readFileCallback(long recordedLength,
                          int sampleRate,
                          String filePath,
                          ArrayList<Float> waveformArray){
        readFileCallback.invoke(recordedLength, sampleRate, filePath, waveformArray);
    };

    void playTrackFinishedCallback() {
        playTrackFinishedCallback.invoke();
    }

    ;

    void multitrackPlayFinishedCallback() {
        multitrackPlayFinishedCallback.invoke();
    }

    ;

    void countInFinished(){
        countInFinished.invoke();
    };


    Callback recordingStoppedCallback;
    Callback analyseTrackCallback;
    Callback compressFilesCallback;
    Callback writeMixdownCallback;
    Callback compressFileCallback;
    Callback readFileCallback;
    Callback playTrackFinishedCallback;
    Callback multitrackPlayFinishedCallback;
    Callback countInFinished;

    @ReactMethod
    void BSWriteMixdownFlac(Callback callback) {
        writeMixdownCallback = callback;
        BSWriteMixdownFlac();
    }

    @ReactMethod
    void BSRecordTrack_new(String startAtMicros, int currentTrackNumber, int currentTakeNumber, Callback callback) {
        long l = Long.parseLong(startAtMicros);
        Log.d("BSAudioEngine", "BSRecordTrack " + l);
        recordingStoppedCallback = callback;
        BSRecordTrack(l, currentTrackNumber, currentTakeNumber);
        Log.d("BSAudioEngine", "BSRecordTrack after");
    }

    @ReactMethod
    void BSMultitrackRecord(long startAtMicros, int currentTrackNumber, int currentTakeNumber, Callback callback) {
        recordingStoppedCallback = callback;
        BSMultitrackRecord(startAtMicros, currentTrackNumber, currentTakeNumber);
    }

    @ReactMethod
    void BSPlayTrack(long startAtMicros, int currentTrackNumber, int currentTakeNumber, Callback callback) {
        playTrackFinishedCallback = callback;
        BSPlayTrack(startAtMicros, currentTrackNumber, currentTakeNumber);
    }

    @ReactMethod
    void BSMultitrackPlay(String startAtMicros, Callback callback) {
        long l = Long.parseLong(startAtMicros);
        Log.d("BSAudioEngine", "BSRecordTrack " + l);
        multitrackPlayFinishedCallback = callback;
        BSMultitrackPlay(l);
    }

    @ReactMethod
    void BSAnalyseTrack(String absoluteFilePath, Callback callback) {
        analyseTrackCallback = callback;
        BSAnalyseTrack(absoluteFilePath);
    }

    @ReactMethod
    void BSCompressFiles(Callback callback) {
        compressFilesCallback = callback;
        BSCompressFiles();
    }

    @ReactMethod
    void BSCompressFile(String absoluteFilePath,Callback callback) {
        compressFileCallback = callback;
        BSCompressFile(absoluteFilePath);
    }

    @ReactMethod
    void BSReadFile(String filePath, int trackNum, int takeNum, boolean sampleLoop,Callback callback) {
        readFileCallback = callback;
        BSReadFile(filePath, trackNum, takeNum, sampleLoop );
    }

    @ReactMethod
    void BSSetCountInBars( int bars, Callback callback) {
        countInFinished = callback;
        BSSetCountInBars(bars );
    }
    @ReactMethod
    boolean BSInitDevice( ) {
        boolean r = BSInitialiseDevice();
        Log.d("BSAudioEngine", "result" + r);
        return r;
    }
    @ReactMethod
    void BSStop_new( ) {
        Log.d("BSAudioEngine", "BSStop_new");
        BSStop();
        Log.d("BSAudioEngine", "BSStop_new after");
    }
}


