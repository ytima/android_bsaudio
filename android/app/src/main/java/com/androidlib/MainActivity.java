package com.androidlib;

import android.os.Bundle;

import com.facebook.react.ReactActivity;
import com.facebook.react.bridge.ReactMethod;

public class MainActivity extends ReactActivity {

  /**
   * Returns the name of the main component registered from JavaScript. This is used to schedule
   * rendering of the component.
   */
  @Override
  protected String getMainComponentName() {
    return "AndroidLib";
  }

  @Override
  protected void onCreate(Bundle savedInstanceState) {

    InitialiseJuce();
    super.onCreate(savedInstanceState);
  }

  static {
    System.loadLibrary("BSAudioEngine");
  }

  public native Void InitialiseJuce();

}
