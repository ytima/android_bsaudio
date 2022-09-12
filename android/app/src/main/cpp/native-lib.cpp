#include <jni.h>
#include <string>
#include "BSInterface.h"


std::string convertJStringToStd(JNIEnv *env,jstring value){
  jboolean isCopy = false;
  std::string newValue = env->GetStringUTFChars(value, &isCopy);
  return newValue;
}

// Allow JUCE to initialise. Needs to be called on startup so that JUCE is ready for any subsequent calls
extern "C" JNIEXPORT void JNICALL
Java_com_example_test2native_1cpp_MainActivity_InitialiseJuce(
        JNIEnv* env,
        jobject activity/* this */) {
    juce::Thread::initialiseJUCE(env, activity);
}

extern "C" JNIEXPORT void JNICALL
//        Java_com_androidlib_BSEngineModule_BSTEST
//Java_com_example_test2native_1cpp_BSEngineModule_testtestFunct(
Java_com_androidlib_BSEngineModule_testtestFunct(
        JNIEnv *env, jobject thiz) {

    jclass cls_foo = (*env).GetObjectClass(thiz);
    jmethodID mid_callback = (*env).GetMethodID(cls_foo, "methodVarCallbackOne", "(I)V");
//    (*env).CallVoidMethod(thiz, mid_callback, 1);


    std::function<void (int)> t = [&env, &thiz](int value)->void{
        jclass cls_foo = (*env).GetObjectClass(thiz);
        jmethodID mid_callback = (*env).GetMethodID(cls_foo, "methodVarCallbackOne", "(I)V");
        (*env).CallVoidMethod(thiz, mid_callback, value);
    };
    testtestFunct(t);
//    testtestFunct( [](int a)->void {
//        (*env).CallVoidMethod(thiz, mid_callback,);
//    });
}


extern "C" JNIEXPORT void JNICALL
Java_com_androidlib_MainActivity_InitialiseJuce(
        JNIEnv* env,
        jobject activity/* this */) {
  juce::Thread::initialiseJUCE(env, activity);
}

extern "C" JNIEXPORT void JNICALL
//Java_com_example_test2native_1cpp_BSEngineModule_BSTEST(
Java_com_androidlib_BSEngineModule_BSTEST(
        JNIEnv *env, jobject thiz
) {

  BSInitialiseDevice();

//  jclass cls_foo = (*env).GetObjectClass(thiz);
//  jmethodID mid_callback = (*env).GetObjectField(thiz,"varCallback");
//  jmethodID mid_callback        = (*env).GetMethodID      (cls_foo, "customCallback"       ,
//                                                           "(Ljava/lang/String;)V");
//  (*env).CallVoidMethod      (thiz, mid_callback,);
//  BSAnalyseTrack1("123", void otherFunct(int a)
//  {
//    printf("%i", a);
//  }
//  );
//  f(1, 2.0, env->NewStringUTF(hello.c_str()));

}

// Initialise BSAudioEngine so that it is able to run
extern "C" JNIEXPORT void JNICALL
Java_com_example_test2native_1cpp_MainActivity_BSInitialise(
        JNIEnv* env,
        jobject activity/* this */) {
    BSInitialiseDevice();

}

// Just show some text to prove that C++ working
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_test2native_1cpp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject activity/* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());

}





extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetMetronomeSound(JNIEnv *env, jobject thiz,
                                                                       jstring absoluteFilePathDown,
                                                                       jstring absoluteFilePathUp){
  BSSetMetronomeSound(convertJStringToStd(env, absoluteFilePathDown), convertJStringToStd(env, absoluteFilePathUp));
}


//extern "C" JNIEXPORT void JNICALL
//  Java_com_example_test2native_1cpp_BSEngineModule_BSWriteMixdownFlac(JNIEnv *env, jobject thiz, CallbackWrapper *callback){
//  BSWriteMixdownFlac(callback);
//}

//extern "C" JNIEXPORT void JNICALL
//Java_com_example_test2native_1cpp_BSEngineModule_BSWriteMixdownFlac1(JNIEnv *env, jobject thiz, std::function<bool (int)> funccc){
//  funccc.
////  CallbackWrapper wrap = new CallbackWrapper();
////  BSWriteMixdownFlac(callback);
//}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSReadMixdownFlac(JNIEnv *env, jobject thiz ){
  BSReadMixdownFlac();
}

// a call to prove that we can get the device initilised.
// Will be redundatnt and should be ignored when there are event and callback wrappers working for android
extern "C" JNIEXPORT jboolean JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSInitialiseDevice(JNIEnv *env, jobject thiz){
  BSInitialiseDevice();
  jboolean a = true;
  return a;
}

//extern "C" JNIEXPORT void JNICALL
//  Java_com_example_test2native_1cpp_BSEngineModule_BSRecordTrack(JNIEnv *env, jobject thiz, jlong startAtMicros, int currentTrackNumber, int currentTakeNumber, CallbackWrapper* callback){
//  BSRecordTrack(startAtMicros,currentTrackNumber,currentTakeNumber,callback);
//}
//extern "C" JNIEXPORT void JNICALL
//  Java_com_example_test2native_1cpp_BSEngineModule_BSPlayTrack(JNIEnv *env, jobject thiz, jlong startAtMicros, int currentTrackNumber, int currentTakeNumber, CallbackWrapper *callback){
//  BSPlayTrack(startAtMicros, currentTrackNumber, currentTakeNumber, callback);
//}
extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetTake(JNIEnv *env, jobject thiz, int trackNumber, int takeNumber){
  BSSetTake(trackNumber, takeNumber);
}
extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetLoopMode(JNIEnv *env, jobject thiz, int trackNum, jboolean status){
  BSSetLoopMode(trackNum, status);
}

extern "C" JNIEXPORT jboolean JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSGetLoopMode(JNIEnv *env, jobject thiz, int trackNum){
  BSGetLoopMode(trackNum);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSClearAllUnusedTrackTakes(JNIEnv *env, jobject thiz ){
  BSClearAllUnusedTrackTakes();
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSClearAllTrackTakes(JNIEnv *env, jobject thiz ){
  BSClearAllTrackTakes();
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSClearTrackTakes(JNIEnv *env, jobject thiz, int trackNum){
  BSClearTrackTakes(trackNum);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSDeleteTake(JNIEnv *env, jobject thiz, int trackNum, int takeNum){
  BSDeleteTake(trackNum, takeNum);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSDeleteTrack(JNIEnv *env, jobject thiz, int trackNum){
  BSDeleteTrack(trackNum);
}

//extern "C" JNIEXPORT void JNICALL
//  Java_com_example_test2native_1cpp_BSEngineModule_BSMultitrackPlay(JNIEnv *env, jobject thiz, jlong startAtMicros, CallbackWrapper *callback){
//  BSMultitrackPlay(startAtMicros, callback);
//}

//extern "C" JNIEXPORT void JNICALL
//  Java_com_example_test2native_1cpp_BSEngineModule_BSMultitrackRecord(JNIEnv *env, jobject thiz, jlong startAtMicros, int currentTrackNumber, int currentTakeNumber, CallbackWrapper *recordCallback){
//  BSMultitrackRecord(startAtMicros, currentTrackNumber, currentTakeNumber, recordCallback);
//}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSPlayMixdown(JNIEnv *env, jobject thiz, jlong startAtMicros){
  BSPlayMixdown(startAtMicros);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSStop(JNIEnv *env, jobject thiz ){
  BSStop();
}

extern "C" JNIEXPORT jboolean JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSShutDown(JNIEnv *env, jobject thiz ){
  return BSShutDown();
}

extern "C" JNIEXPORT jboolean JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSRestartAudioEngine(JNIEnv *env, jobject thiz ){
  return BSRestartAudioEngine();
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetTrackGain(JNIEnv *env, jobject thiz, int track, float gain){
  BSSetTrackGain(track, gain);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetTrackPan(JNIEnv *env, jobject thiz, int track, float pan){
  BSSetTrackPan(track, pan);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetMainGain(JNIEnv *env, jobject thiz, float gain){
  BSSetMainGain(gain);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetMainPan(JNIEnv *env, jobject thiz, float pan){
  BSSetMainPan(pan);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetInputMonitoringGain(JNIEnv *env, jobject thiz, float gain){
  BSSetInputMonitoringGain(gain);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetInputGain(JNIEnv *env, jobject thiz, float gain){
  BSSetInputGain(gain);
}

extern "C" JNIEXPORT jboolean JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSMixdown(JNIEnv *env, jobject thiz ){
  BSMixdown();
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSAnalyseTrack(JNIEnv *env, jobject thiz, std::string absoluteFilePath, CallbackWrapper* callback){
  BSAnalyseTrack(absoluteFilePath, callback);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetCompressionValues(JNIEnv *env, jobject thiz, int sampleRate, int bitDepth, int compressionValue){
  BSSetCompressionValues(sampleRate,bitDepth, compressionValue);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSCompressFiles(JNIEnv *env, jobject thiz, CallbackWrapper* callback){
  BSCompressFiles(callback);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSCompressFile(JNIEnv *env, jobject thiz, std::string absoluteFilePath, CallbackWrapper* callback){
  BSCompressFile(absoluteFilePath, callback);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSReadFile(JNIEnv *env, jobject thiz, std::string filePath, int trackNum, int takeNum, bool sampleLoop, CallbackWrapper* callback){
  BSReadFile(filePath, trackNum, takeNum, sampleLoop, callback);
}

extern "C" JNIEXPORT jboolean JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSMonitor(JNIEnv *env, jobject thiz ){
  BSMonitor();
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetBPM(JNIEnv *env, jobject thiz, float bpm){
  BSSetBPM(bpm);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetMetronomeStatus(JNIEnv *env, jobject thiz, jboolean status){
  BSSetMetronomeStatus(status);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetMetronomeLevel(JNIEnv *env, jobject thiz, float level){
  BSSetMetronomeLevel(level);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetHeadphonesConnected(JNIEnv *env, jobject thiz, jboolean connected){
  BSSetHeadphonesConnected(connected);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetCountInBars(JNIEnv *env, jobject thiz, int bars, CallbackWrapper *callback){
  BSSetCountInBars(bars, callback);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetMetronomeTimeSignature(JNIEnv *env, jobject thiz, int nominator, int denominator){
  BSSetMetronomeTimeSignature(nominator, denominator);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSListener(JNIEnv *env, jobject thiz, jboolean listener){
  BSListener(listener);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSAddTrackEffect(JNIEnv *env, jobject thiz, int trackNum, jstring effectName){
  BSAddTrackEffect(trackNum, convertJStringToStd(env,effectName));
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSRemoveTrackEffects(JNIEnv *env, jobject thiz, int trackNum){
  BSRemoveTrackEffects(trackNum);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetEffectMixValue(JNIEnv *env, jobject thiz, int trackNum, float mixValue){
  BSSetEffectMixValue(trackNum, mixValue);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSAddMainBusEffect(JNIEnv *env, jobject thiz, jstring effectName){
  BSAddMainBusEffect(convertJStringToStd(env,effectName));
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSResetMainBusEffect(JNIEnv *env, jobject thiz ){
  BSResetMainBusEffect();
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetMainBusMixValue(JNIEnv *env, jobject thiz, float mixValue){
  BSSetMainBusMixValue(mixValue);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetManualLatencyOverride(JNIEnv *env, jobject thiz, jboolean state){
  BSSetManualLatencyOverride(state);
}

extern "C" JNIEXPORT void JNICALL
  Java_com_example_test2native_1cpp_BSEngineModule_BSSetManualLatency(JNIEnv *env, jobject thiz, int samples){
  BSSetManualLatency(samples);
}