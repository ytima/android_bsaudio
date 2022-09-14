#include <jni.h>
#include <string>
#include "BSInterface.h"


std::string convertJStringToStd(JNIEnv *env, jstring value) {
  jboolean isCopy = false;
  std::string newValue = env->GetStringUTFChars(value, &isCopy);
  return newValue;
}

jfloatArray convertVectorFloatToJava(JNIEnv *env, std::vector<float> dataVector) {
  unsigned long size = dataVector.size();
  jfloat outCArray[size];
  std::copy(dataVector.begin(), dataVector.end(), outCArray);
  jfloatArray outJNIArray = env->NewFloatArray(size);
  env->SetFloatArrayRegion(outJNIArray, 0, size, outCArray);
  return outJNIArray;
}

jobject convertVectorStringToJava(JNIEnv *env, std::vector<std::string> dataVector){
  jclass clazz = (*env).FindClass("java/util/ArrayList");
  jobject obj = (*env).NewObject(clazz, (*env).GetMethodID(clazz, "<init>", "()V"));

  for (int n=0;n<dataVector.size();n++)
  {
    std::string e = dataVector[n];
    jstring _str = (*env).NewStringUTF(e.c_str());
    (*env).CallBooleanMethod(obj, (*env).GetMethodID(clazz, "add", "(Ljava/lang/Object;)Z"), _str);
  }

  return obj;
}

// Allow JUCE to initialise. Needs to be called on startup so that JUCE is ready for any subsequent calls
extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_MainActivity_InitialiseJuce(
        JNIEnv *env,
        jobject activity/* this */) {
  juce::Thread::initialiseJUCE(env, activity);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_testtestFunct(
        JNIEnv *env, jobject thiz) {

  std::function<void(int)> t = [&env, &thiz](int value) -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "methodVarCallbackOne", "(I)V");
      (*env).CallVoidMethod(thiz, mid_callback, value);
  };
  testtestFunct(t);
}

// Initialise BSAudioEngine so that it is able to run
extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_MainActivity_BSInitialise(
        JNIEnv *env,
        jobject activity/* this */) {
  BSInitialiseDevice();

}

// Just show some text to prove that C++ working
extern "C" JNIEXPORT jstring JNICALL
Java_com_androidlib_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject activity/* this */) {
  std::string hello = "Hello from C++";
  return env->NewStringUTF(hello.c_str());

}





extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetMetronomeSound(JNIEnv *env, jobject thiz,
                                                                     jstring absoluteFilePathDown,
                                                                     jstring absoluteFilePathUp) {
  BSSetMetronomeSound(convertJStringToStd(env, absoluteFilePathDown),
                      convertJStringToStd(env, absoluteFilePathUp));
}


extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSWriteMixdownFlac(JNIEnv *env, jobject thiz) {

  std::function<void(std::string)> writeMixdownCallback = [&env, &thiz](
          const std::string &value) -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "methodVarCallbackOne",
                                                  "(Ljava/lang/String;)V");

      jstring jValue = (*env).NewStringUTF(value.c_str());

      (*env).CallVoidMethod(thiz, mid_callback, jValue);
  };
  BSWriteMixdownFlac(writeMixdownCallback);
}


extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSReadMixdownFlac(JNIEnv *env, jobject thiz) {
  BSReadMixdownFlac();
}

// a call to prove that we can get the device initilised.
// Will be redundatnt and should be ignored when there are event and callback wrappers working for android
extern "C" JNIEXPORT jboolean JNICALL
Java_com_androidlib_BSEngineModule_BSInitialiseDevice(JNIEnv *env, jobject thiz) {
    std::cout<<"BSAudioEngine"<<std::endl;
    printf("Java_com_androidlib_BSEngineModule_BSInitialiseDevice");
  BSInitialiseDevice();
  jboolean a = true;
  return a;
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSRecordTrack(JNIEnv *env, jobject thiz,
                                                               jlong startAtMicros,
                                                               int currentTrackNumber,
                                                               int currentTakeNumber) {

  std::cout<<"BSAudioEngine"<<std::endl;
  std::function<void(long, int, std::string,
                     std::vector<float>)> recordingStoppedCallback = [&env, &thiz](long valueLong,
                                                                                   int valueInt,
                                                                                   const std::string &valueString,
                                                                                   std::vector<float> valueVector) -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "recordingStoppedCallback",
                                                  "(J;I;Ljava/lang/String;[F;)V");

      jstring jValue = (*env).NewStringUTF(valueString.c_str());
      jfloatArray jfloatArrayValue = convertVectorFloatToJava(env, valueVector);
      (*env).CallVoidMethod(thiz, mid_callback, valueLong, valueInt, jValue, jfloatArrayValue);
  };


//    std::function<void (long ,int, std::string,std::vector<float>  )> recordingStoppedCallback;
  BSRecordTrack(startAtMicros, currentTrackNumber, currentTakeNumber, recordingStoppedCallback);
}
extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSPlayTrack(JNIEnv *env, jobject thiz,
                                                             jlong startAtMicros,
                                                             int currentTrackNumber,
                                                             int currentTakeNumber) {
  std::function<void( )> callBack = [&env, &thiz]() -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "playTrackFinishedCallback",
                                                  "()V");


      (*env).CallVoidMethod(thiz, mid_callback);
  };
  BSPlayTrack(startAtMicros, currentTrackNumber, currentTakeNumber, callBack);
}
extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetTake(JNIEnv *env, jobject thiz,
                                                           int trackNumber, int takeNumber) {
  BSSetTake(trackNumber, takeNumber);
}
extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetLoopMode(JNIEnv *env, jobject thiz,
                                                               int trackNum, jboolean status) {
  BSSetLoopMode(trackNum, status);
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_androidlib_BSEngineModule_BSGetLoopMode(JNIEnv *env, jobject thiz,
                                                               int trackNum) {
  BSGetLoopMode(trackNum);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSClearAllUnusedTrackTakes(JNIEnv *env,
                                                                            jobject thiz) {
  BSClearAllUnusedTrackTakes();
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSClearAllTrackTakes(JNIEnv *env, jobject thiz) {
  BSClearAllTrackTakes();
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSClearTrackTakes(JNIEnv *env, jobject thiz,
                                                                   int trackNum) {
  BSClearTrackTakes(trackNum);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSDeleteTake(JNIEnv *env, jobject thiz,
                                                              int trackNum, int takeNum) {
  BSDeleteTake(trackNum, takeNum);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSDeleteTrack(JNIEnv *env, jobject thiz,
                                                               int trackNum) {
  BSDeleteTrack(trackNum);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSMultitrackPlay(JNIEnv *env, jobject thiz,
                                                                  jlong startAtMicros) {

  std::function<void( )> multitrackPlayFinishedCallback = [&env, &thiz]() -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "multitrackPlayFinishedCallback",
                                                  "()V");


      (*env).CallVoidMethod(thiz, mid_callback);
  };
  BSMultitrackPlay(startAtMicros,multitrackPlayFinishedCallback );
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSMultitrackRecord(JNIEnv *env, jobject thiz,
                                                                    jlong startAtMicros,
                                                                    int currentTrackNumber,
                                                                    int currentTakeNumber) {


  std::function<void(long, int, std::string,
                     std::vector<float>)> recordingStoppedCallback = [&env, &thiz](long valueLong,
                                                                                   int valueInt,
                                                                                   const std::string &valueString,
                                                                                   std::vector<float> valueVector) -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "recordingStoppedCallback",
                                                  "(J;I;Ljava/lang/String;[F;)V");

      jstring jValue = (*env).NewStringUTF(valueString.c_str());
      jfloatArray jfloatArrayValue = convertVectorFloatToJava(env, valueVector);
      (*env).CallVoidMethod(thiz, mid_callback, valueLong, valueInt, jValue, jfloatArrayValue);
  };


  BSMultitrackRecord(startAtMicros, currentTrackNumber, currentTakeNumber,
                     recordingStoppedCallback);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSPlayMixdown(JNIEnv *env, jobject thiz,
                                                               jlong startAtMicros) {
  BSPlayMixdown(startAtMicros);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSStop(JNIEnv *env, jobject thiz) {
  BSStop();
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_androidlib_BSEngineModule_BSShutDown(JNIEnv *env, jobject thiz) {
  return BSShutDown();
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_androidlib_BSEngineModule_BSRestartAudioEngine(JNIEnv *env, jobject thiz) {
  return BSRestartAudioEngine();
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetTrackGain(JNIEnv *env, jobject thiz,
                                                                int track, float gain) {
  BSSetTrackGain(track, gain);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetTrackPan(JNIEnv *env, jobject thiz, int track,
                                                               float pan) {
  BSSetTrackPan(track, pan);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetMainGain(JNIEnv *env, jobject thiz,
                                                               float gain) {
  BSSetMainGain(gain);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetMainPan(JNIEnv *env, jobject thiz,
                                                              float pan) {
  BSSetMainPan(pan);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetInputMonitoringGain(JNIEnv *env, jobject thiz,
                                                                          float gain) {
  BSSetInputMonitoringGain(gain);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetInputGain(JNIEnv *env, jobject thiz,
                                                                float gain) {
  BSSetInputGain(gain);
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_androidlib_BSEngineModule_BSMixdown(JNIEnv *env, jobject thiz) {
  BSMixdown();
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSAnalyseTrack(JNIEnv *env, jobject thiz,
                                                                jstring absoluteFilePath) {

  std::function<void(long ,int ,int ,long)> analyseTrackCallback = [&env, &thiz](long lengthInSamples,
                                                                                 int sampleRate,
                                                                                 int bitdepth,
                                                                                 long  lengthInMicros) -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "analyseTrackCallback",
                                                  "(J;I;I;J;)V");

      (*env).CallVoidMethod(thiz, mid_callback, lengthInSamples, sampleRate, bitdepth, lengthInMicros);
  };

  BSAnalyseTrack(convertJStringToStd(env, absoluteFilePath), analyseTrackCallback);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetCompressionValues(JNIEnv *env, jobject thiz,
                                                                        int sampleRate,
                                                                        int bitDepth,
                                                                        int compressionValue) {
  BSSetCompressionValues(sampleRate, bitDepth, compressionValue);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSCompressFiles(JNIEnv *env, jobject thiz) {

  std::function<void(std::vector<std::string>)> compressFilesCallback = [&env, &thiz](std::vector<std::string> valueVector) -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "compressFilesCallback",
                                                  "([Ljava/lang/String;)V");

      (*env).CallVoidMethod(thiz, mid_callback, convertVectorStringToJava(env, valueVector));
  };

  BSCompressFiles(compressFilesCallback);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSCompressFile(JNIEnv *env, jobject thiz,
                                                                jstring absoluteFilePath) {
  std::function<void(std::string)> compressFileCallback = [&env, &thiz](std::string filePath) -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "compressFileCallback",
                                                  "(Ljava/lang/String;)V");

      (*env).CallVoidMethod(thiz, mid_callback, filePath.c_str());
  };

  BSCompressFile(convertJStringToStd(env, absoluteFilePath), compressFileCallback);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSReadFile(JNIEnv *env, jobject thiz,
                                                            jstring filePath, int trackNum,
                                                            int takeNum, jboolean sampleLoop) {

  std::function<void(long, int, std::string,
                     std::vector<float>)> readFileCallback = [&env, &thiz](long recordedLength,
                                                                           int sampleRate,
                                                                           const std::string &filePath,
                                                                           std::vector<float> waveformArray) -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "readFileCallback",
                                                  "(J;I;Ljava/lang/String;[F;)V");

      jstring jValue = (*env).NewStringUTF(filePath.c_str());
      jfloatArray jfloatArrayValue = convertVectorFloatToJava(env, waveformArray);
      (*env).CallVoidMethod(thiz, mid_callback, recordedLength, sampleRate, jValue, jfloatArrayValue);
  };


  BSReadFile(convertJStringToStd(env, filePath), trackNum, takeNum, sampleLoop, readFileCallback);
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_androidlib_BSEngineModule_BSMonitor(JNIEnv *env, jobject thiz) {
  BSMonitor();
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetBPM(JNIEnv *env, jobject thiz, float bpm) {
  BSSetBPM(bpm);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetMetronomeStatus(JNIEnv *env, jobject thiz,
                                                                      jboolean status) {
  BSSetMetronomeStatus(status);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetMetronomeLevel(JNIEnv *env, jobject thiz,
                                                                     float level) {
  BSSetMetronomeLevel(level);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetHeadphonesConnected(JNIEnv *env, jobject thiz,
                                                                          jboolean connected) {
  BSSetHeadphonesConnected(connected);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetCountInBars(JNIEnv *env, jobject thiz,
                                                                  int bars) {
  std::function<void( )> countInFinished = [&env, &thiz]() -> void {
      jclass cls_foo = (*env).GetObjectClass(thiz);
      jmethodID mid_callback = (*env).GetMethodID(cls_foo, "countInFinished",
                                                  "()V");

      (*env).CallVoidMethod(thiz, mid_callback);
  };
  BSSetCountInBars(bars, countInFinished);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetMetronomeTimeSignature(JNIEnv *env,
                                                                             jobject thiz,
                                                                             int nominator,
                                                                             int denominator) {
  BSSetMetronomeTimeSignature(nominator, denominator);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSListener(JNIEnv *env, jobject thiz,
                                                            jboolean listener) {
  BSListener(listener);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSAddTrackEffect(JNIEnv *env, jobject thiz,
                                                                  int trackNum,
                                                                  jstring effectName) {
  BSAddTrackEffect(trackNum, convertJStringToStd(env, effectName));
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSRemoveTrackEffects(JNIEnv *env, jobject thiz,
                                                                      int trackNum) {
  BSRemoveTrackEffects(trackNum);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetEffectMixValue(JNIEnv *env, jobject thiz,
                                                                     int trackNum, float mixValue) {
  BSSetEffectMixValue(trackNum, mixValue);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSAddMainBusEffect(JNIEnv *env, jobject thiz,
                                                                    jstring effectName) {
  BSAddMainBusEffect(convertJStringToStd(env, effectName));
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSResetMainBusEffect(JNIEnv *env, jobject thiz) {
  BSResetMainBusEffect();
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetMainBusMixValue(JNIEnv *env, jobject thiz,
                                                                      float mixValue) {
  BSSetMainBusMixValue(mixValue);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetManualLatencyOverride(JNIEnv *env,
                                                                            jobject thiz,
                                                                            jboolean state) {
  BSSetManualLatencyOverride(state);
}

extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_BSEngineModule_BSSetManualLatency(JNIEnv *env, jobject thiz,
                                                                    int samples) {
  BSSetManualLatency(samples);
}