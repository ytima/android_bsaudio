package com.androidlib;

import android.util.Log;

import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import java.util.function.Function;
import com.facebook.react.bridge.Callback;

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


    @ReactMethod
    public void testModule(String name, String location) {
        Log.d("CalendarModule", "Create event called with name: " + name
                + " and location: " + location);
    }

    public native void BSTEST();

    public native void testtestFunct();

    public native void BSSetMetronomeSound(String absoluteFilePathDown, String absoluteFilePathUp);

    //    public native void BSWriteMixdownFlac(  callback: Any/*CallbackWrapper*/)
    public native void BSReadMixdownFlac();

    // a call to prove that we can get the device initilised.
// Will be redundatnt and should be ignored when there are event and callback wrappers working for android
    public native boolean BSInitialiseDevice();

    //    public native BSRecordTrack( startAtMicros: Long,   currentTrackNumber: Int,  currentTakeNumber: Int,callback: Any/*CallbackWrapper*/)
//    public native BSPlayTrack(  startAtMicros: Long,   currentTrackNumber: Int,   currentTakeNumber: Int, callback: Any/*CallbackWrapper*/)
    public native void BSSetTake(int trackNumber, int takeNumber);

    public native void BSSetLoopMode(int trackNum, boolean status);

    public native boolean BSGetLoopMode(int trackNum);

    public native void BSClearAllUnusedTrackTakes();

    public native void BSClearAllTrackTakes();

    public native void BSClearTrackTakes(int trackNum);

    public native void BSDeleteTake(int trackNum, int takeNum);

    public native void BSDeleteTrack(int trackNum);

    //    external fun BSMultitrackPlay( startAtMicros: Long, callback: Any/*CallbackWrapper*/)
//    external fun BSMultitrackRecord( startAtMicros: Long,  currentTrackNumber: Int,  currentTakeNumber: Int, callback: Any/*CallbackWrapper*/)
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

    //    public native void BSAnalyseTrack( absoluteFilePath: String, CallbackWrapper* callback)
    public native void BSSetCompressionValues(int sampleRate, int bitDepth, int compressionValue);

    //    public native void BSCompressFiles(CallbackWrapper* callback)
//    public native void BSCompressFile(  absoluteFilePath: String, CallbackWrapper* callback)
//    public native BSReadFile(  filePath: String,  trackNum: Int,  takeNum: Int,   sampleLoop: Boolean, CallbackWrapper* callback)
    public native boolean BSMonitor();

    public native void BSSetBPM(float bpm);

    public native void BSSetMetronomeStatus(boolean status);

    public native void BSSetMetronomeLevel(float level);

    public native void BSSetHeadphonesConnected(boolean connected);

    //    public native void BSSetCountInBars( bars: Int, CallbackWrapper *callback)
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



//    Function<Integer,Void>   varCallbackOne;
    Callback   varCallbackOne;
    void methodVarCallbackOne(int a) {
//        varCallbackOne.apply(a);
        varCallbackOne.invoke(a);
    }



//    @ReactMethod fun setCallback( callback: (test: String) -> Unit) {
//        varCallback = callback;
//    }

//    @ReactMethod void testCallLib(  Function<Integer,Void> callback)
    @ReactMethod void testCallLib(Callback callBack) {
        Log.d("BSEngineModule", "---140-------");
        varCallbackOne = callBack;
//        varCallbackOne = (Integer a)-> {
//            Log.d("BSEngineModule", "---144---$a----" + a);
////            callBack.invoke(a);
//            return null;
//        };
        Log.d("BSEngineModule", "---147-------");

        testtestFunct();
    }

}



