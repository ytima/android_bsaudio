package com.androidlib;

import android.util.Log;
import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;

public class BSEngineModule extends ReactContextBaseJavaModule {
    BSEngineModule(ReactApplicationContext context) {

        super(context);
        Log.d("BSEngineModule", "super");
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

    @ReactMethod
    public native Void BSTEST();
}



