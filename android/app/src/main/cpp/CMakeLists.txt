# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

cmake_minimum_required(VERSION 3.4.1)

set(OBOE_DIR "BSAudioEngine/lib/include/juce_audio_devices/native/oboe")

add_subdirectory (${OBOE_DIR} oboe)

add_library("cpufeatures" STATIC "${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c")
set_source_files_properties("${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c" PROPERTIES COMPILE_FLAGS "-Wno-sign-conversion -Wno-gnu-statement-expression")

add_definitions([[-DJUCE_ANDROID=1]] [[-DJUCE_USE_OBOE_STABILIZED_CALLBACK=1]] [[-DJUCE_ANDROID_API_VERSION=16]] [[-DJUCER_ANDROIDSTUDIO_7F0E4A25=1]] [[-DJUCE_APP_VERSION=1.0.0]] [[-DJUCE_APP_VERSION_HEX=0x10000]])

include_directories( AFTER
        "BSAudioEngine/lib/include"
        "${ANDROID_NDK}/sources/android/cpufeatures"
        )

enable_language(ASM)

#debug or release build definitions, comment out accordingly
add_definitions([[-DJUCER_ANDROIDSTUDIO_7F0E4A25=1]] [[-DJUCE_APP_VERSION=1.0.0]] [[-DJUCE_APP_VERSION_HEX=0x10000]] [[-DDEBUG=1]] [[-D_DEBUG=1]])
#add_definitions([[-DJUCER_ANDROIDSTUDIO_7F0E4A25=1]] [[-DJUCE_APP_VERSION=1.0.0]] [[-DJUCE_APP_VERSION_HEX=0x10000]] [[-DNDEBUG=1]])

add_library( BSAudioEngine

        SHARED

        "native-lib.cpp"
        "BSInterface.h"
        "BSInterface.cpp"
        "BSInternal.h"
        "BSInternal.cpp"
        "BSEngine.h"
        "BSEngine.cpp"
        "BSEffectPresets.h"
        "BSEffectPresets.cpp"
        "EffectProcessor.h"
        "EffectProcessor.cpp"
        "Track.h"
        "Track.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h"
        "BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioChannelSet.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioChannelSet.h"
        "BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioDataConverters.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioDataConverters.h"
        "BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.h"
        "BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioSampleBuffer.h"
        "BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_FloatVectorOperations.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMP.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPacket.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPackets.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPConversion.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPConverters.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPDispatcher.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPFactory.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPIterator.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPMidi1ToBytestreamTranslator.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPMidi1ToMidi2DefaultTranslator.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPMidi1ToMidi2DefaultTranslator.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPProtocols.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPReceiver.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPSysEx7.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPSysEx7.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPTests.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPUtils.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPUtils.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPView.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPView.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiBuffer.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiBuffer.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiDataConcatenator.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiFile.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiFile.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiKeyboardState.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiKeyboardState.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiMessage.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiMessage.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiMessageSequence.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiMessageSequence.h"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiRPN.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiRPN.h"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEInstrument.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEInstrument.h"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEMessages.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEMessages.h"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPENote.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPENote.h"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiser.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiser.h"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiserBase.h"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEUtils.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEUtils.h"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEValue.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEValue.h"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEZoneLayout.h"
        "BSAudioEngine/lib/include/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_AudioSource.h"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_BufferingAudioSource.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_BufferingAudioSource.h"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_IIRFilterAudioSource.h"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_MemoryAudioSource.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_MemoryAudioSource.h"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_MixerAudioSource.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_MixerAudioSource.h"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_PositionableAudioSource.h"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ResamplingAudioSource.h"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ReverbAudioSource.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ReverbAudioSource.h"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h"
        "BSAudioEngine/lib/include/juce_audio_basics/synthesisers/juce_Synthesiser.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/synthesisers/juce_Synthesiser.h"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_ADSR.h"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_ADSR_test.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_Decibels.h"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_GenericInterpolator.h"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_IIRFilter.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_IIRFilter.h"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_Interpolators.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_Interpolators.h"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_LagrangeInterpolator.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_Reverb.h"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_SmoothedValue.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_SmoothedValue.h"
        "BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_WindowedSincInterpolator.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/juce_audio_basics.cpp"
        "BSAudioEngine/lib/include/juce_audio_basics/juce_audio_basics.mm"
        "BSAudioEngine/lib/include/juce_audio_basics/juce_audio_basics.h"
        "BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioDeviceManager.h"
        "BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioIODevice.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioIODevice.h"
        "BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioIODeviceType.h"
        "BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_SystemAudioVolume.h"
        "BSAudioEngine/lib/include/juce_audio_devices/midi_io/ump/juce_UMPBytestreamInputHandler.h"
        "BSAudioEngine/lib/include/juce_audio_devices/midi_io/ump/juce_UMPTests.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/midi_io/ump/juce_UMPU32InputHandler.h"
        "BSAudioEngine/lib/include/juce_audio_devices/midi_io/juce_MidiDevices.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/midi_io/juce_MidiDevices.h"
        "BSAudioEngine/lib/include/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/midi_io/juce_MidiMessageCollector.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/AudioStream.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/AudioStreamBase.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/AudioStreamBuilder.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/AudioStreamCallback.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/Definitions.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/LatencyTuner.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/Oboe.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/ResultWithValue.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/StabilizedCallback.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/Utilities.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/Version.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/aaudio/AAudioExtensions.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/AudioClock.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/AudioStream.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/AudioStreamBuilder.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FilterAudioStream.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FilterAudioStream.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockReader.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockReader.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/LatencyTuner.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/MonotonicCounter.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/OboeDebug.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/QuirksManager.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/QuirksManager.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI16Caller.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI16Caller.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI24Caller.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI24Caller.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI32Caller.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI32Caller.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/StabilizedCallback.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/Trace.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/Trace.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/Utilities.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/Version.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoController.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoController.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/HyperbolicCosineWindow.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/KaiserWindow.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/FlowgraphUtilities.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI32.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI32.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI32.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI32.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/CMakeLists.txt"
        "BSAudioEngine/lib/include/juce_audio_devices/native/oboe/README.md"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_android_Audio.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_android_HighPerformanceAudioHelpers.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_android_Midi.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_android_Oboe.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_android_OpenSL.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_ios_Audio.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_ios_Audio.h"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_linux_ALSA.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_linux_Bela.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_linux_JackAudio.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_linux_Midi.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_mac_CoreAudio.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_mac_CoreMidi.mm"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_win32_ASIO.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_win32_DirectSound.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_win32_Midi.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/native/juce_win32_WASAPI.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/sources/juce_AudioSourcePlayer.h"
        "BSAudioEngine/lib/include/juce_audio_devices/sources/juce_AudioTransportSource.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/sources/juce_AudioTransportSource.h"
        "BSAudioEngine/lib/include/juce_audio_devices/juce_audio_devices.cpp"
        "BSAudioEngine/lib/include/juce_audio_devices/juce_audio_devices.mm"
        "BSAudioEngine/lib/include/juce_audio_devices/juce_audio_devices.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/bitmath.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/bitreader.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/cpu.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/crc.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/fixed.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/float.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/format.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/md5.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/memory.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/window_flac.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/all.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/alloc.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/assert.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/callback.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/compat.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/endswap.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/export.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/Flac Licence.txt"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/format.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/metadata.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/ordinals.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/stream_decoder.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/stream_encoder.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/win_utf8_io.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_51.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_stereo.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/floor/floor_books.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/uncoupled/res_books_uncoupled.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/floor_all.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_8.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_11.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_16.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_44.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_8.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_16.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44p51.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44u.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_8.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_11.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_16.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_22.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_32.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44p51.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44u.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_X.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/analysis.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/backends.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/block.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codec_internal.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor0.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor1.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/highlevel.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/info.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup_data.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mapping0.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/masking.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/os.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/res0.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/scales.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/sharedbook.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/synthesis.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisenc.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisfile.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/README.md"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/bitwise.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/codec.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/config_types.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/crctable.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/framing.c"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/ogg.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/os_types.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/vorbisenc.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/vorbisfile.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_AiffAudioFormat.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_CoreAudioFormat.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_FlacAudioFormat.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_MP3AudioFormat.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_WavAudioFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_WavAudioFormat.h"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormat.h"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatManager.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatManager.h"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatReader.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatReader.h"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatReaderSource.h"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatWriter.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatWriter.h"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioSubsectionReader.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioSubsectionReader.h"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_BufferingAudioFormatReader.h"
        "BSAudioEngine/lib/include/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h"
        "BSAudioEngine/lib/include/juce_audio_formats/sampler/juce_Sampler.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/sampler/juce_Sampler.h"
        "BSAudioEngine/lib/include/juce_audio_formats/juce_audio_formats.cpp"
        "BSAudioEngine/lib/include/juce_audio_formats/juce_audio_formats.mm"
        "BSAudioEngine/lib/include/juce_audio_formats/juce_audio_formats.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format/juce_AudioPluginFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format/juce_AudioPluginFormat.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format/juce_AudioPluginFormatManager.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/baseiids.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/classfactoryhelpers.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/thread/include/flock.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/thread/source/flock.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/LICENSE.txt"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/README.md"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/coreiids.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpop.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpush.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fstrdefs.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ftypes.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/futils.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fvariant.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ibstream.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/icloneable.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipersistent.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipluginbase.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/istringresult.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/iupdatehandler.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/smartpointer.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/typesizecheck.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugview.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugviewcontentscalesupport.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstattributes.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstaudioprocessor.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstautomationstate.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstchannelcontextinfo.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcomponent.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcontextmenu.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsteditcontroller.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstevents.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsthostapplication.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstinterappaudio.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmessage.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidicontrollers.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidilearn.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstnoteexpression.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstparameterchanges.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstparameterfunctionname.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstphysicalui.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstpluginterfacesupport.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstplugview.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprefetchablesupport.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprocesscontext.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstrepresentation.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsttestplugprovider.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstunits.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstpshpack4.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstspeaker.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vsttypes.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/LICENSE.txt"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/README.md"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstinitiids.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/LICENSE.txt"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/README.md"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/JUCE_README.md"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/LICENSE.txt"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/README.md"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_AU_Shared.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VST3Common.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VST3Headers.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VST3PluginFormat.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VSTCommon.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VSTMidiEventList.h"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VSTPluginFormat.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioPluginInstance.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioPluginInstance.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessor.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessor.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorEditor.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorEditorHostContext.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorGraph.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorListener.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorParameter.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_HostedAudioProcessorParameter.h"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_PluginDescription.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/processors/juce_PluginDescription.h"
        "BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_KnownPluginList.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_KnownPluginList.h"
        "BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h"
        "BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_PluginListComponent.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_PluginListComponent.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterBool.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterBool.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterChoice.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterChoice.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterFloat.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterFloat.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterInt.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterInt.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_ExtensionsVisitor.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_ParameterAttachments.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_ParameterAttachments.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_PluginHostType.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_PluginHostType.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_RangedAudioParameter.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_RangedAudioParameter.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_VST3ClientExtensions.h"
        "BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_VSTCallbackHandler.h"
        "BSAudioEngine/lib/include/juce_audio_processors/juce_audio_processors.cpp"
        "BSAudioEngine/lib/include/juce_audio_processors/juce_audio_processors.mm"
        "BSAudioEngine/lib/include/juce_audio_processors/juce_audio_processors.h"
        "BSAudioEngine/lib/include/juce_audio_utils/audio_cd/juce_AudioCDBurner.h"
        "BSAudioEngine/lib/include/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/audio_cd/juce_AudioCDReader.h"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioAppComponent.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioAppComponent.h"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioThumbnail.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioThumbnail.h"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioThumbnailBase.h"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioThumbnailCache.h"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioVisualiserComponent.h"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_KeyboardComponentBase.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_KeyboardComponentBase.h"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_MidiKeyboardComponent.h"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_MPEKeyboardComponent.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/gui/juce_MPEKeyboardComponent.h"
        "BSAudioEngine/lib/include/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm"
        "BSAudioEngine/lib/include/juce_audio_utils/native/juce_linux_AudioCDReader.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/native/juce_mac_AudioCDBurner.mm"
        "BSAudioEngine/lib/include/juce_audio_utils/native/juce_mac_AudioCDReader.mm"
        "BSAudioEngine/lib/include/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm"
        "BSAudioEngine/lib/include/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/native/juce_win32_AudioCDReader.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/players/juce_AudioProcessorPlayer.h"
        "BSAudioEngine/lib/include/juce_audio_utils/players/juce_SoundPlayer.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/players/juce_SoundPlayer.h"
        "BSAudioEngine/lib/include/juce_audio_utils/juce_audio_utils.cpp"
        "BSAudioEngine/lib/include/juce_audio_utils/juce_audio_utils.mm"
        "BSAudioEngine/lib/include/juce_audio_utils/juce_audio_utils.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_AbstractFifo.cpp"
        "BSAudioEngine/lib/include/juce_core/containers/juce_AbstractFifo.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_Array.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_ArrayAllocationBase.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_ArrayBase.cpp"
        "BSAudioEngine/lib/include/juce_core/containers/juce_ArrayBase.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_DynamicObject.cpp"
        "BSAudioEngine/lib/include/juce_core/containers/juce_DynamicObject.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_ElementComparator.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_HashMap.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_HashMap_test.cpp"
        "BSAudioEngine/lib/include/juce_core/containers/juce_LinkedListPointer.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_ListenerList.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_NamedValueSet.cpp"
        "BSAudioEngine/lib/include/juce_core/containers/juce_NamedValueSet.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_OwnedArray.cpp"
        "BSAudioEngine/lib/include/juce_core/containers/juce_OwnedArray.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_PropertySet.cpp"
        "BSAudioEngine/lib/include/juce_core/containers/juce_PropertySet.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_ReferenceCountedArray.cpp"
        "BSAudioEngine/lib/include/juce_core/containers/juce_ReferenceCountedArray.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_ScopedValueSetter.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_SingleThreadedAbstractFifo.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_SortedSet.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_SparseSet.cpp"
        "BSAudioEngine/lib/include/juce_core/containers/juce_SparseSet.h"
        "BSAudioEngine/lib/include/juce_core/containers/juce_Variant.cpp"
        "BSAudioEngine/lib/include/juce_core/containers/juce_Variant.h"
        "BSAudioEngine/lib/include/juce_core/files/juce_DirectoryIterator.cpp"
        "BSAudioEngine/lib/include/juce_core/files/juce_DirectoryIterator.h"
        "BSAudioEngine/lib/include/juce_core/files/juce_File.cpp"
        "BSAudioEngine/lib/include/juce_core/files/juce_File.h"
        "BSAudioEngine/lib/include/juce_core/files/juce_FileFilter.cpp"
        "BSAudioEngine/lib/include/juce_core/files/juce_FileFilter.h"
        "BSAudioEngine/lib/include/juce_core/files/juce_FileInputStream.cpp"
        "BSAudioEngine/lib/include/juce_core/files/juce_FileInputStream.h"
        "BSAudioEngine/lib/include/juce_core/files/juce_FileOutputStream.cpp"
        "BSAudioEngine/lib/include/juce_core/files/juce_FileOutputStream.h"
        "BSAudioEngine/lib/include/juce_core/files/juce_FileSearchPath.cpp"
        "BSAudioEngine/lib/include/juce_core/files/juce_FileSearchPath.h"
        "BSAudioEngine/lib/include/juce_core/files/juce_MemoryMappedFile.h"
        "BSAudioEngine/lib/include/juce_core/files/juce_RangedDirectoryIterator.cpp"
        "BSAudioEngine/lib/include/juce_core/files/juce_RangedDirectoryIterator.h"
        "BSAudioEngine/lib/include/juce_core/files/juce_TemporaryFile.cpp"
        "BSAudioEngine/lib/include/juce_core/files/juce_TemporaryFile.h"
        "BSAudioEngine/lib/include/juce_core/files/juce_WildcardFileFilter.cpp"
        "BSAudioEngine/lib/include/juce_core/files/juce_WildcardFileFilter.h"
        "BSAudioEngine/lib/include/juce_core/javascript/juce_Javascript.cpp"
        "BSAudioEngine/lib/include/juce_core/javascript/juce_Javascript.h"
        "BSAudioEngine/lib/include/juce_core/javascript/juce_JSON.cpp"
        "BSAudioEngine/lib/include/juce_core/javascript/juce_JSON.h"
        "BSAudioEngine/lib/include/juce_core/logging/juce_FileLogger.cpp"
        "BSAudioEngine/lib/include/juce_core/logging/juce_FileLogger.h"
        "BSAudioEngine/lib/include/juce_core/logging/juce_Logger.cpp"
        "BSAudioEngine/lib/include/juce_core/logging/juce_Logger.h"
        "BSAudioEngine/lib/include/juce_core/maths/juce_BigInteger.cpp"
        "BSAudioEngine/lib/include/juce_core/maths/juce_BigInteger.h"
        "BSAudioEngine/lib/include/juce_core/maths/juce_Expression.cpp"
        "BSAudioEngine/lib/include/juce_core/maths/juce_Expression.h"
        "BSAudioEngine/lib/include/juce_core/maths/juce_MathsFunctions.h"
        "BSAudioEngine/lib/include/juce_core/maths/juce_NormalisableRange.h"
        "BSAudioEngine/lib/include/juce_core/maths/juce_Random.cpp"
        "BSAudioEngine/lib/include/juce_core/maths/juce_Random.h"
        "BSAudioEngine/lib/include/juce_core/maths/juce_Range.h"
        "BSAudioEngine/lib/include/juce_core/maths/juce_StatisticsAccumulator.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_AllocationHooks.cpp"
        "BSAudioEngine/lib/include/juce_core/memory/juce_AllocationHooks.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_Atomic.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_ByteOrder.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_ContainerDeletePolicy.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_HeapBlock.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_HeavyweightLeakedObjectDetector.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_LeakedObjectDetector.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_Memory.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_MemoryBlock.cpp"
        "BSAudioEngine/lib/include/juce_core/memory/juce_MemoryBlock.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_OptionalScopedPointer.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_ReferenceCountedObject.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_Reservoir.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_ScopedPointer.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_SharedResourcePointer.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_Singleton.h"
        "BSAudioEngine/lib/include/juce_core/memory/juce_WeakReference.h"
        "BSAudioEngine/lib/include/juce_core/misc/juce_ConsoleApplication.cpp"
        "BSAudioEngine/lib/include/juce_core/misc/juce_ConsoleApplication.h"
        "BSAudioEngine/lib/include/juce_core/misc/juce_Functional.h"
        "BSAudioEngine/lib/include/juce_core/misc/juce_Result.cpp"
        "BSAudioEngine/lib/include/juce_core/misc/juce_Result.h"
        "BSAudioEngine/lib/include/juce_core/misc/juce_RuntimePermissions.cpp"
        "BSAudioEngine/lib/include/juce_core/misc/juce_RuntimePermissions.h"
        "BSAudioEngine/lib/include/juce_core/misc/juce_Uuid.cpp"
        "BSAudioEngine/lib/include/juce_core/misc/juce_Uuid.h"
        "BSAudioEngine/lib/include/juce_core/misc/juce_WindowsRegistry.h"
        "BSAudioEngine/lib/include/juce_core/native/java/README.txt"
        "BSAudioEngine/lib/include/juce_core/native/juce_android_Files.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_android_JNIHelpers.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_android_JNIHelpers.h"
        "BSAudioEngine/lib/include/juce_core/native/juce_android_Misc.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_android_Network.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_android_RuntimePermissions.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_android_SystemStats.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_android_Threads.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_BasicNativeHeaders.h"
        "BSAudioEngine/lib/include/juce_core/native/juce_curl_Network.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_intel_SharedCode.h"
        "BSAudioEngine/lib/include/juce_core/native/juce_linux_CommonFile.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_linux_Files.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_linux_Network.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_linux_SystemStats.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_linux_Threads.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_mac_CFHelpers.h"
        "BSAudioEngine/lib/include/juce_core/native/juce_mac_Files.mm"
        "BSAudioEngine/lib/include/juce_core/native/juce_mac_Network.mm"
        "BSAudioEngine/lib/include/juce_core/native/juce_mac_ObjCHelpers.h"
        "BSAudioEngine/lib/include/juce_core/native/juce_mac_Strings.mm"
        "BSAudioEngine/lib/include/juce_core/native/juce_mac_SystemStats.mm"
        "BSAudioEngine/lib/include/juce_core/native/juce_mac_Threads.mm"
        "BSAudioEngine/lib/include/juce_core/native/juce_posix_IPAddress.h"
        "BSAudioEngine/lib/include/juce_core/native/juce_posix_NamedPipe.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_posix_SharedCode.h"
        "BSAudioEngine/lib/include/juce_core/native/juce_wasm_SystemStats.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_win32_ComSmartPtr.h"
        "BSAudioEngine/lib/include/juce_core/native/juce_win32_Files.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_win32_Network.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_win32_Registry.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_win32_SystemStats.cpp"
        "BSAudioEngine/lib/include/juce_core/native/juce_win32_Threads.cpp"
        "BSAudioEngine/lib/include/juce_core/network/juce_IPAddress.cpp"
        "BSAudioEngine/lib/include/juce_core/network/juce_IPAddress.h"
        "BSAudioEngine/lib/include/juce_core/network/juce_MACAddress.cpp"
        "BSAudioEngine/lib/include/juce_core/network/juce_MACAddress.h"
        "BSAudioEngine/lib/include/juce_core/network/juce_NamedPipe.cpp"
        "BSAudioEngine/lib/include/juce_core/network/juce_NamedPipe.h"
        "BSAudioEngine/lib/include/juce_core/network/juce_Socket.cpp"
        "BSAudioEngine/lib/include/juce_core/network/juce_Socket.h"
        "BSAudioEngine/lib/include/juce_core/network/juce_URL.cpp"
        "BSAudioEngine/lib/include/juce_core/network/juce_URL.h"
        "BSAudioEngine/lib/include/juce_core/network/juce_WebInputStream.cpp"
        "BSAudioEngine/lib/include/juce_core/network/juce_WebInputStream.h"
        "BSAudioEngine/lib/include/juce_core/streams/juce_BufferedInputStream.cpp"
        "BSAudioEngine/lib/include/juce_core/streams/juce_BufferedInputStream.h"
        "BSAudioEngine/lib/include/juce_core/streams/juce_FileInputSource.cpp"
        "BSAudioEngine/lib/include/juce_core/streams/juce_FileInputSource.h"
        "BSAudioEngine/lib/include/juce_core/streams/juce_InputSource.h"
        "BSAudioEngine/lib/include/juce_core/streams/juce_InputStream.cpp"
        "BSAudioEngine/lib/include/juce_core/streams/juce_InputStream.h"
        "BSAudioEngine/lib/include/juce_core/streams/juce_MemoryInputStream.cpp"
        "BSAudioEngine/lib/include/juce_core/streams/juce_MemoryInputStream.h"
        "BSAudioEngine/lib/include/juce_core/streams/juce_MemoryOutputStream.cpp"
        "BSAudioEngine/lib/include/juce_core/streams/juce_MemoryOutputStream.h"
        "BSAudioEngine/lib/include/juce_core/streams/juce_OutputStream.cpp"
        "BSAudioEngine/lib/include/juce_core/streams/juce_OutputStream.h"
        "BSAudioEngine/lib/include/juce_core/streams/juce_SubregionStream.cpp"
        "BSAudioEngine/lib/include/juce_core/streams/juce_SubregionStream.h"
        "BSAudioEngine/lib/include/juce_core/streams/juce_URLInputSource.cpp"
        "BSAudioEngine/lib/include/juce_core/streams/juce_URLInputSource.h"
        "BSAudioEngine/lib/include/juce_core/system/juce_CompilerSupport.h"
        "BSAudioEngine/lib/include/juce_core/system/juce_CompilerWarnings.h"
        "BSAudioEngine/lib/include/juce_core/system/juce_PlatformDefs.h"
        "BSAudioEngine/lib/include/juce_core/system/juce_StandardHeader.h"
        "BSAudioEngine/lib/include/juce_core/system/juce_SystemStats.cpp"
        "BSAudioEngine/lib/include/juce_core/system/juce_SystemStats.h"
        "BSAudioEngine/lib/include/juce_core/system/juce_TargetPlatform.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_Base64.cpp"
        "BSAudioEngine/lib/include/juce_core/text/juce_Base64.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_CharacterFunctions.cpp"
        "BSAudioEngine/lib/include/juce_core/text/juce_CharacterFunctions.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_CharPointer_ASCII.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_CharPointer_UTF8.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_CharPointer_UTF16.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_CharPointer_UTF32.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_Identifier.cpp"
        "BSAudioEngine/lib/include/juce_core/text/juce_Identifier.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_LocalisedStrings.cpp"
        "BSAudioEngine/lib/include/juce_core/text/juce_LocalisedStrings.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_NewLine.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_String.cpp"
        "BSAudioEngine/lib/include/juce_core/text/juce_String.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_StringArray.cpp"
        "BSAudioEngine/lib/include/juce_core/text/juce_StringArray.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_StringPairArray.cpp"
        "BSAudioEngine/lib/include/juce_core/text/juce_StringPairArray.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_StringPool.cpp"
        "BSAudioEngine/lib/include/juce_core/text/juce_StringPool.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_StringRef.h"
        "BSAudioEngine/lib/include/juce_core/text/juce_TextDiff.cpp"
        "BSAudioEngine/lib/include/juce_core/text/juce_TextDiff.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_ChildProcess.cpp"
        "BSAudioEngine/lib/include/juce_core/threads/juce_ChildProcess.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_CriticalSection.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_DynamicLibrary.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_HighResolutionTimer.cpp"
        "BSAudioEngine/lib/include/juce_core/threads/juce_HighResolutionTimer.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_InterProcessLock.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_Process.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_ReadWriteLock.cpp"
        "BSAudioEngine/lib/include/juce_core/threads/juce_ReadWriteLock.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_ScopedLock.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_ScopedReadLock.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_ScopedWriteLock.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_SpinLock.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_Thread.cpp"
        "BSAudioEngine/lib/include/juce_core/threads/juce_Thread.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_ThreadLocalValue.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_ThreadPool.cpp"
        "BSAudioEngine/lib/include/juce_core/threads/juce_ThreadPool.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_TimeSliceThread.cpp"
        "BSAudioEngine/lib/include/juce_core/threads/juce_TimeSliceThread.h"
        "BSAudioEngine/lib/include/juce_core/threads/juce_WaitableEvent.cpp"
        "BSAudioEngine/lib/include/juce_core/threads/juce_WaitableEvent.h"
        "BSAudioEngine/lib/include/juce_core/time/juce_PerformanceCounter.cpp"
        "BSAudioEngine/lib/include/juce_core/time/juce_PerformanceCounter.h"
        "BSAudioEngine/lib/include/juce_core/time/juce_RelativeTime.cpp"
        "BSAudioEngine/lib/include/juce_core/time/juce_RelativeTime.h"
        "BSAudioEngine/lib/include/juce_core/time/juce_Time.cpp"
        "BSAudioEngine/lib/include/juce_core/time/juce_Time.h"
        "BSAudioEngine/lib/include/juce_core/unit_tests/juce_UnitTest.cpp"
        "BSAudioEngine/lib/include/juce_core/unit_tests/juce_UnitTest.h"
        "BSAudioEngine/lib/include/juce_core/unit_tests/juce_UnitTestCategories.h"
        "BSAudioEngine/lib/include/juce_core/xml/juce_XmlDocument.cpp"
        "BSAudioEngine/lib/include/juce_core/xml/juce_XmlDocument.h"
        "BSAudioEngine/lib/include/juce_core/xml/juce_XmlElement.cpp"
        "BSAudioEngine/lib/include/juce_core/xml/juce_XmlElement.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/adler32.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/compress.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/crc32.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/crc32.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/deflate.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/deflate.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/infback.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/inffast.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/inffast.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/inffixed.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/inflate.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/inflate.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/inftrees.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/inftrees.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/trees.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/trees.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/uncompr.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/zconf.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/zconf.in.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/zlib.h"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/zutil.c"
        "BSAudioEngine/lib/include/juce_core/zip/zlib/zutil.h"
        "BSAudioEngine/lib/include/juce_core/zip/juce_GZIPCompressorOutputStream.cpp"
        "BSAudioEngine/lib/include/juce_core/zip/juce_GZIPCompressorOutputStream.h"
        "BSAudioEngine/lib/include/juce_core/zip/juce_GZIPDecompressorInputStream.cpp"
        "BSAudioEngine/lib/include/juce_core/zip/juce_GZIPDecompressorInputStream.h"
        "BSAudioEngine/lib/include/juce_core/zip/juce_ZipFile.cpp"
        "BSAudioEngine/lib/include/juce_core/zip/juce_ZipFile.h"
        "BSAudioEngine/lib/include/juce_core/juce_core.cpp"
        "BSAudioEngine/lib/include/juce_core/juce_core.mm"
        "BSAudioEngine/lib/include/juce_core/juce_core.h"
        "BSAudioEngine/lib/include/juce_data_structures/app_properties/juce_ApplicationProperties.cpp"
        "BSAudioEngine/lib/include/juce_data_structures/app_properties/juce_ApplicationProperties.h"
        "BSAudioEngine/lib/include/juce_data_structures/app_properties/juce_PropertiesFile.cpp"
        "BSAudioEngine/lib/include/juce_data_structures/app_properties/juce_PropertiesFile.h"
        "BSAudioEngine/lib/include/juce_data_structures/undomanager/juce_UndoableAction.h"
        "BSAudioEngine/lib/include/juce_data_structures/undomanager/juce_UndoManager.cpp"
        "BSAudioEngine/lib/include/juce_data_structures/undomanager/juce_UndoManager.h"
        "BSAudioEngine/lib/include/juce_data_structures/values/juce_CachedValue.cpp"
        "BSAudioEngine/lib/include/juce_data_structures/values/juce_CachedValue.h"
        "BSAudioEngine/lib/include/juce_data_structures/values/juce_Value.cpp"
        "BSAudioEngine/lib/include/juce_data_structures/values/juce_Value.h"
        "BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTree.cpp"
        "BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTree.h"
        "BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTreePropertyWithDefault.h"
        "BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTreePropertyWithDefault_test.cpp"
        "BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp"
        "BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTreeSynchroniser.h"
        "BSAudioEngine/lib/include/juce_data_structures/juce_data_structures.cpp"
        "BSAudioEngine/lib/include/juce_data_structures/juce_data_structures.mm"
        "BSAudioEngine/lib/include/juce_data_structures/juce_data_structures.h"
        "BSAudioEngine/lib/include/juce_dsp/containers/juce_AudioBlock.h"
        "BSAudioEngine/lib/include/juce_dsp/containers/juce_AudioBlock_test.cpp"
        "BSAudioEngine/lib/include/juce_dsp/containers/juce_FixedSizeFunction.h"
        "BSAudioEngine/lib/include/juce_dsp/containers/juce_FixedSizeFunction_test.cpp"
        "BSAudioEngine/lib/include/juce_dsp/containers/juce_SIMDRegister.h"
        "BSAudioEngine/lib/include/juce_dsp/containers/juce_SIMDRegister_Impl.h"
        "BSAudioEngine/lib/include/juce_dsp/containers/juce_SIMDRegister_test.cpp"
        "BSAudioEngine/lib/include/juce_dsp/filter_design/juce_FilterDesign.cpp"
        "BSAudioEngine/lib/include/juce_dsp/filter_design/juce_FilterDesign.h"
        "BSAudioEngine/lib/include/juce_dsp/frequency/juce_Convolution.cpp"
        "BSAudioEngine/lib/include/juce_dsp/frequency/juce_Convolution.h"
        "BSAudioEngine/lib/include/juce_dsp/frequency/juce_Convolution_test.cpp"
        "BSAudioEngine/lib/include/juce_dsp/frequency/juce_FFT.cpp"
        "BSAudioEngine/lib/include/juce_dsp/frequency/juce_FFT.h"
        "BSAudioEngine/lib/include/juce_dsp/frequency/juce_FFT_test.cpp"
        "BSAudioEngine/lib/include/juce_dsp/frequency/juce_Windowing.cpp"
        "BSAudioEngine/lib/include/juce_dsp/frequency/juce_Windowing.h"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_FastMathApproximations.h"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_LogRampedValue.h"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_LogRampedValue_test.cpp"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_LookupTable.cpp"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_LookupTable.h"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_Matrix.cpp"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_Matrix.h"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_Matrix_test.cpp"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_Phase.h"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_Polynomial.h"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_SpecialFunctions.cpp"
        "BSAudioEngine/lib/include/juce_dsp/maths/juce_SpecialFunctions.h"
        "BSAudioEngine/lib/include/juce_dsp/native/juce_avx_SIMDNativeOps.cpp"
        "BSAudioEngine/lib/include/juce_dsp/native/juce_avx_SIMDNativeOps.h"
        "BSAudioEngine/lib/include/juce_dsp/native/juce_fallback_SIMDNativeOps.h"
        "BSAudioEngine/lib/include/juce_dsp/native/juce_neon_SIMDNativeOps.cpp"
        "BSAudioEngine/lib/include/juce_dsp/native/juce_neon_SIMDNativeOps.h"
        "BSAudioEngine/lib/include/juce_dsp/native/juce_sse_SIMDNativeOps.cpp"
        "BSAudioEngine/lib/include/juce_dsp/native/juce_sse_SIMDNativeOps.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_BallisticsFilter.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_BallisticsFilter.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_DelayLine.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_DelayLine.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_DryWetMixer.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_DryWetMixer.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_FIRFilter.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_FIRFilter.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_FIRFilter_test.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_FirstOrderTPTFilter.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_FirstOrderTPTFilter.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_IIRFilter.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_IIRFilter.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_IIRFilter_Impl.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_LinkwitzRileyFilter.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_LinkwitzRileyFilter.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_Oversampling.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_Oversampling.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_Panner.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_Panner.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_ProcessContext.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_ProcessorChain.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_ProcessorChain_test.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_ProcessorDuplicator.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_ProcessorWrapper.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_StateVariableFilter.h"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_StateVariableTPTFilter.cpp"
        "BSAudioEngine/lib/include/juce_dsp/processors/juce_StateVariableTPTFilter.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Bias.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Chorus.cpp"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Chorus.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Compressor.cpp"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Compressor.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Gain.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_LadderFilter.cpp"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_LadderFilter.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Limiter.cpp"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Limiter.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_NoiseGate.cpp"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_NoiseGate.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Oscillator.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Phaser.cpp"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Phaser.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_Reverb.h"
        "BSAudioEngine/lib/include/juce_dsp/widgets/juce_WaveShaper.h"
        "BSAudioEngine/lib/include/juce_dsp/juce_dsp.cpp"
        "BSAudioEngine/lib/include/juce_dsp/juce_dsp.mm"
        "BSAudioEngine/lib/include/juce_dsp/juce_dsp.h"
        "BSAudioEngine/lib/include/juce_events/broadcasters/juce_ActionBroadcaster.cpp"
        "BSAudioEngine/lib/include/juce_events/broadcasters/juce_ActionBroadcaster.h"
        "BSAudioEngine/lib/include/juce_events/broadcasters/juce_ActionListener.h"
        "BSAudioEngine/lib/include/juce_events/broadcasters/juce_AsyncUpdater.cpp"
        "BSAudioEngine/lib/include/juce_events/broadcasters/juce_AsyncUpdater.h"
        "BSAudioEngine/lib/include/juce_events/broadcasters/juce_ChangeBroadcaster.cpp"
        "BSAudioEngine/lib/include/juce_events/broadcasters/juce_ChangeBroadcaster.h"
        "BSAudioEngine/lib/include/juce_events/broadcasters/juce_ChangeListener.h"
        "BSAudioEngine/lib/include/juce_events/interprocess/juce_ConnectedChildProcess.cpp"
        "BSAudioEngine/lib/include/juce_events/interprocess/juce_ConnectedChildProcess.h"
        "BSAudioEngine/lib/include/juce_events/interprocess/juce_InterprocessConnection.cpp"
        "BSAudioEngine/lib/include/juce_events/interprocess/juce_InterprocessConnection.h"
        "BSAudioEngine/lib/include/juce_events/interprocess/juce_InterprocessConnectionServer.cpp"
        "BSAudioEngine/lib/include/juce_events/interprocess/juce_InterprocessConnectionServer.h"
        "BSAudioEngine/lib/include/juce_events/interprocess/juce_NetworkServiceDiscovery.cpp"
        "BSAudioEngine/lib/include/juce_events/interprocess/juce_NetworkServiceDiscovery.h"
        "BSAudioEngine/lib/include/juce_events/messages/juce_ApplicationBase.cpp"
        "BSAudioEngine/lib/include/juce_events/messages/juce_ApplicationBase.h"
        "BSAudioEngine/lib/include/juce_events/messages/juce_CallbackMessage.h"
        "BSAudioEngine/lib/include/juce_events/messages/juce_DeletedAtShutdown.cpp"
        "BSAudioEngine/lib/include/juce_events/messages/juce_DeletedAtShutdown.h"
        "BSAudioEngine/lib/include/juce_events/messages/juce_Initialisation.h"
        "BSAudioEngine/lib/include/juce_events/messages/juce_Message.h"
        "BSAudioEngine/lib/include/juce_events/messages/juce_MessageListener.cpp"
        "BSAudioEngine/lib/include/juce_events/messages/juce_MessageListener.h"
        "BSAudioEngine/lib/include/juce_events/messages/juce_MessageManager.cpp"
        "BSAudioEngine/lib/include/juce_events/messages/juce_MessageManager.h"
        "BSAudioEngine/lib/include/juce_events/messages/juce_MountedVolumeListChangeDetector.h"
        "BSAudioEngine/lib/include/juce_events/messages/juce_NotificationType.h"
        "BSAudioEngine/lib/include/juce_events/native/juce_android_Messaging.cpp"
        "BSAudioEngine/lib/include/juce_events/native/juce_ios_MessageManager.mm"
        "BSAudioEngine/lib/include/juce_events/native/juce_linux_EventLoop.h"
        "BSAudioEngine/lib/include/juce_events/native/juce_linux_Messaging.cpp"
        "BSAudioEngine/lib/include/juce_events/native/juce_mac_MessageManager.mm"
        "BSAudioEngine/lib/include/juce_events/native/juce_osx_MessageQueue.h"
        "BSAudioEngine/lib/include/juce_events/native/juce_ScopedLowPowerModeDisabler.cpp"
        "BSAudioEngine/lib/include/juce_events/native/juce_ScopedLowPowerModeDisabler.h"
        "BSAudioEngine/lib/include/juce_events/native/juce_win32_HiddenMessageWindow.h"
        "BSAudioEngine/lib/include/juce_events/native/juce_win32_Messaging.cpp"
        "BSAudioEngine/lib/include/juce_events/native/juce_win32_WinRTWrapper.cpp"
        "BSAudioEngine/lib/include/juce_events/native/juce_win32_WinRTWrapper.h"
        "BSAudioEngine/lib/include/juce_events/timers/juce_MultiTimer.cpp"
        "BSAudioEngine/lib/include/juce_events/timers/juce_MultiTimer.h"
        "BSAudioEngine/lib/include/juce_events/timers/juce_Timer.cpp"
        "BSAudioEngine/lib/include/juce_events/timers/juce_Timer.h"
        "BSAudioEngine/lib/include/juce_events/juce_events.cpp"
        "BSAudioEngine/lib/include/juce_events/juce_events.mm"
        "BSAudioEngine/lib/include/juce_events/juce_events.h"
        "BSAudioEngine/lib/include/juce_graphics/colour/juce_Colour.cpp"
        "BSAudioEngine/lib/include/juce_graphics/colour/juce_Colour.h"
        "BSAudioEngine/lib/include/juce_graphics/colour/juce_ColourGradient.cpp"
        "BSAudioEngine/lib/include/juce_graphics/colour/juce_ColourGradient.h"
        "BSAudioEngine/lib/include/juce_graphics/colour/juce_Colours.cpp"
        "BSAudioEngine/lib/include/juce_graphics/colour/juce_Colours.h"
        "BSAudioEngine/lib/include/juce_graphics/colour/juce_FillType.cpp"
        "BSAudioEngine/lib/include/juce_graphics/colour/juce_FillType.h"
        "BSAudioEngine/lib/include/juce_graphics/colour/juce_PixelFormats.h"
        "BSAudioEngine/lib/include/juce_graphics/contexts/juce_GraphicsContext.cpp"
        "BSAudioEngine/lib/include/juce_graphics/contexts/juce_GraphicsContext.h"
        "BSAudioEngine/lib/include/juce_graphics/contexts/juce_LowLevelGraphicsContext.h"
        "BSAudioEngine/lib/include/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp"
        "BSAudioEngine/lib/include/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h"
        "BSAudioEngine/lib/include/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp"
        "BSAudioEngine/lib/include/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h"
        "BSAudioEngine/lib/include/juce_graphics/effects/juce_DropShadowEffect.cpp"
        "BSAudioEngine/lib/include/juce_graphics/effects/juce_DropShadowEffect.h"
        "BSAudioEngine/lib/include/juce_graphics/effects/juce_GlowEffect.cpp"
        "BSAudioEngine/lib/include/juce_graphics/effects/juce_GlowEffect.h"
        "BSAudioEngine/lib/include/juce_graphics/effects/juce_ImageEffectFilter.h"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_AttributedString.cpp"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_AttributedString.h"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_CustomTypeface.cpp"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_CustomTypeface.h"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_Font.cpp"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_Font.h"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_GlyphArrangement.cpp"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_GlyphArrangement.h"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_TextLayout.cpp"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_TextLayout.h"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_Typeface.cpp"
        "BSAudioEngine/lib/include/juce_graphics/fonts/juce_Typeface.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_AffineTransform.cpp"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_AffineTransform.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_BorderSize.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_EdgeTable.cpp"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_EdgeTable.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_Line.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_Parallelogram.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_Path.cpp"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_Path.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_PathIterator.cpp"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_PathIterator.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_PathStrokeType.cpp"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_PathStrokeType.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_Point.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_Rectangle.h"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_Rectangle_test.cpp"
        "BSAudioEngine/lib/include/juce_graphics/geometry/juce_RectangleList.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/cderror.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcapimin.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcapistd.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jccoefct.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jccolor.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcdctmgr.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jchuff.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jchuff.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcinit.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcmainct.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcmarker.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcmaster.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcomapi.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jconfig.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcparam.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcphuff.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcprepct.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcsample.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jctrans.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdapimin.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdapistd.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdatasrc.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdcoefct.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdcolor.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdct.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jddctmgr.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdhuff.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdhuff.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdinput.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdmainct.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdmarker.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdmaster.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdmerge.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdphuff.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdpostct.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdsample.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdtrans.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jerror.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jerror.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jfdctflt.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jfdctfst.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jfdctint.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jidctflt.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jidctfst.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jidctint.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jidctred.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jinclude.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jmemmgr.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jmemnobs.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jmemsys.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jmorecfg.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jpegint.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jpeglib.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jquant1.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jquant2.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jutils.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jversion.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/transupp.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/transupp.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/libpng_readme.txt"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/png.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/png.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngconf.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngdebug.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngerror.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngget.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pnginfo.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngmem.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngpread.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngpriv.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngread.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngrio.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngrtran.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngrutil.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngset.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngstruct.h"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngtrans.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngwio.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngwrite.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngwtran.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngwutil.c"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/juce_GIFLoader.cpp"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/juce_JPEGLoader.cpp"
        "BSAudioEngine/lib/include/juce_graphics/image_formats/juce_PNGLoader.cpp"
        "BSAudioEngine/lib/include/juce_graphics/images/juce_Image.cpp"
        "BSAudioEngine/lib/include/juce_graphics/images/juce_Image.h"
        "BSAudioEngine/lib/include/juce_graphics/images/juce_ImageCache.cpp"
        "BSAudioEngine/lib/include/juce_graphics/images/juce_ImageCache.h"
        "BSAudioEngine/lib/include/juce_graphics/images/juce_ImageConvolutionKernel.cpp"
        "BSAudioEngine/lib/include/juce_graphics/images/juce_ImageConvolutionKernel.h"
        "BSAudioEngine/lib/include/juce_graphics/images/juce_ImageFileFormat.cpp"
        "BSAudioEngine/lib/include/juce_graphics/images/juce_ImageFileFormat.h"
        "BSAudioEngine/lib/include/juce_graphics/images/juce_ScaledImage.h"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_android_Fonts.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_android_GraphicsContext.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_android_IconHelpers.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_freetype_Fonts.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_linux_Fonts.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_linux_IconHelpers.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_mac_CoreGraphicsContext.h"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_mac_CoreGraphicsContext.mm"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_mac_Fonts.mm"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_mac_IconHelpers.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_RenderingHelpers.h"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_win32_Fonts.cpp"
        "BSAudioEngine/lib/include/juce_graphics/native/juce_win32_IconHelpers.cpp"
        "BSAudioEngine/lib/include/juce_graphics/placement/juce_Justification.h"
        "BSAudioEngine/lib/include/juce_graphics/placement/juce_RectanglePlacement.cpp"
        "BSAudioEngine/lib/include/juce_graphics/placement/juce_RectanglePlacement.h"
        "BSAudioEngine/lib/include/juce_graphics/juce_graphics.cpp"
        "BSAudioEngine/lib/include/juce_graphics/juce_graphics.mm"
        "BSAudioEngine/lib/include/juce_graphics/juce_graphics.h"
        "BSAudioEngine/lib/include/juce_gui_basics/accessibility/enums/juce_AccessibilityActions.h"
        "BSAudioEngine/lib/include/juce_gui_basics/accessibility/enums/juce_AccessibilityEvent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/accessibility/enums/juce_AccessibilityRole.h"
        "BSAudioEngine/lib/include/juce_gui_basics/accessibility/interfaces/juce_AccessibilityCellInterface.h"
        "BSAudioEngine/lib/include/juce_gui_basics/accessibility/interfaces/juce_AccessibilityTableInterface.h"
        "BSAudioEngine/lib/include/juce_gui_basics/accessibility/interfaces/juce_AccessibilityTextInterface.h"
        "BSAudioEngine/lib/include/juce_gui_basics/accessibility/interfaces/juce_AccessibilityValueInterface.h"
        "BSAudioEngine/lib/include/juce_gui_basics/accessibility/juce_AccessibilityHandler.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/accessibility/juce_AccessibilityHandler.h"
        "BSAudioEngine/lib/include/juce_gui_basics/accessibility/juce_AccessibilityState.h"
        "BSAudioEngine/lib/include/juce_gui_basics/application/juce_Application.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/application/juce_Application.h"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ArrowButton.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ArrowButton.h"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_Button.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_Button.h"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_DrawableButton.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_DrawableButton.h"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_HyperlinkButton.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_HyperlinkButton.h"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ImageButton.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ImageButton.h"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ShapeButton.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ShapeButton.h"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_TextButton.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_TextButton.h"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ToggleButton.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ToggleButton.h"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ToolbarButton.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ToolbarButton.h"
        "BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandID.h"
        "BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandInfo.h"
        "BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandManager.h"
        "BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandTarget.h"
        "BSAudioEngine/lib/include/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/commands/juce_KeyPressMappingSet.h"
        "BSAudioEngine/lib/include/juce_gui_basics/components/juce_CachedComponentImage.h"
        "BSAudioEngine/lib/include/juce_gui_basics/components/juce_Component.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/components/juce_Component.h"
        "BSAudioEngine/lib/include/juce_gui_basics/components/juce_ComponentListener.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/components/juce_ComponentListener.h"
        "BSAudioEngine/lib/include/juce_gui_basics/components/juce_ComponentTraverser.h"
        "BSAudioEngine/lib/include/juce_gui_basics/components/juce_FocusTraverser.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/components/juce_FocusTraverser.h"
        "BSAudioEngine/lib/include/juce_gui_basics/components/juce_ModalComponentManager.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/components/juce_ModalComponentManager.h"
        "BSAudioEngine/lib/include/juce_gui_basics/desktop/juce_Desktop.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/desktop/juce_Desktop.h"
        "BSAudioEngine/lib/include/juce_gui_basics/desktop/juce_Displays.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/desktop/juce_Displays.h"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_Drawable.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_Drawable.h"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableComposite.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableComposite.h"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableImage.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableImage.h"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawablePath.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawablePath.h"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableRectangle.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableRectangle.h"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableShape.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableShape.h"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableText.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableText.h"
        "BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_SVGParser.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_ContentSharer.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_ContentSharer.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileBrowserListener.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileChooser.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileChooser.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileListComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileListComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FilenameComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileTreeComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_CaretComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_CaretComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyListener.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyListener.h"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyPress.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyPress.h"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_ModifierKeys.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_ModifierKeys.h"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_SystemClipboard.h"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h"
        "BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_TextInputTarget.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_AnimatedPosition.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentAnimator.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentAnimator.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentBuilder.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentBuilder.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentMovementWatcher.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ConcertinaPanel.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ConcertinaPanel.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_FlexBox.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_FlexBox.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_FlexItem.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_Grid.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_Grid.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_GridItem.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_GridItem.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_GroupComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_GroupComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_MultiDocumentPanel.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableBorderComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableCornerComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableEdgeComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ScrollBar.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ScrollBar.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_SidePanel.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_SidePanel.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableLayoutManager.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableObjectResizer.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_TabbedButtonBar.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_TabbedButtonBar.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_TabbedComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_TabbedComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_Viewport.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/layout/juce_Viewport.h"
        "BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel.h"
        "BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h"
        "BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h"
        "BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h"
        "BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h"
        "BSAudioEngine/lib/include/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/menus/juce_BurgerMenuComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/menus/juce_MenuBarComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/menus/juce_MenuBarComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/menus/juce_MenuBarModel.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/menus/juce_MenuBarModel.h"
        "BSAudioEngine/lib/include/juce_gui_basics/menus/juce_PopupMenu.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/menus/juce_PopupMenu.h"
        "BSAudioEngine/lib/include/juce_gui_basics/misc/juce_BubbleComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/misc/juce_BubbleComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/misc/juce_DropShadower.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/misc/juce_DropShadower.h"
        "BSAudioEngine/lib/include/juce_gui_basics/misc/juce_FocusOutline.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/misc/juce_FocusOutline.h"
        "BSAudioEngine/lib/include/juce_gui_basics/misc/juce_JUCESplashScreen.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/misc/juce_JUCESplashScreen.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_ComponentDragger.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_ComponentDragger.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_DragAndDropContainer.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_DragAndDropTarget.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_LassoComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseCursor.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseCursor.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseEvent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseEvent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseInactivityDetector.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseInputSource.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseInputSource.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseListener.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseListener.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_PointerState.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_SelectedItemSet.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h"
        "BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_TooltipClient.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_AccessibilityTextHelpers.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_android_Accessibility.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_ios_Accessibility.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_mac_Accessibility.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_mac_AccessibilitySharedCode.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_Accessibility.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_AccessibilityElement.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_AccessibilityElement.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_ComInterfaces.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAExpandCollapseProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAGridItemProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAGridProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAHelpers.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAInvokeProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAProviderBase.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAProviders.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIARangeValueProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIASelectionProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIATextProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAToggleProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIATransformProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAValueProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAWindowProvider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_WindowsUIAWrapper.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/x11/juce_linux_X11_DragAndDrop.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/x11/juce_linux_X11_Symbols.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/x11/juce_linux_X11_Symbols.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/x11/juce_linux_XWindowSystem.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/x11/juce_linux_XWindowSystem.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_android_ContentSharer.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_android_FileChooser.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_android_Windowing.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_common_MimeTypes.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_ios_ContentSharer.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_ios_FileChooser.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_ios_Windowing.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_linux_FileChooser.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_linux_Windowing.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_mac_FileChooser.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_mac_MainMenu.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_mac_MouseCursor.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_mac_Windowing.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_MultiTouchMapper.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_ScopedDPIAwarenessDisabler.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_win32_DragAndDrop.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_win32_FileChooser.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_win32_ScopedThreadDPIAwarenessSetter.h"
        "BSAudioEngine/lib/include/juce_gui_basics/native/juce_win32_Windowing.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_MarkerList.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_MarkerList.h"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeCoordinate.h"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeParallelogram.h"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativePoint.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativePoint.h"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativePointPath.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativePointPath.h"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeRectangle.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeRectangle.h"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_BooleanPropertyComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_ButtonPropertyComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_ChoicePropertyComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_PropertyComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_PropertyComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_PropertyPanel.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_PropertyPanel.h"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_SliderPropertyComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_TextPropertyComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/properties/juce_TextPropertyComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ComboBox.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ComboBox.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ImageComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ImageComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Label.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Label.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ListBox.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ListBox.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ProgressBar.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ProgressBar.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Slider.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Slider.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TableHeaderComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TableListBox.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TableListBox.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TextEditor.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TextEditor.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Toolbar.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Toolbar.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ToolbarItemComponent.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ToolbarItemFactory.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ToolbarItemPalette.h"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TreeView.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TreeView.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_AlertWindow.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_AlertWindow.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_CallOutBox.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_CallOutBox.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ComponentPeer.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ComponentPeer.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_DialogWindow.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_DialogWindow.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_DocumentWindow.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_DocumentWindow.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_MessageBoxOptions.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_NativeMessageBox.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ResizableWindow.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ResizableWindow.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_TooltipWindow.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_TooltipWindow.h"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_TopLevelWindow.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/windows/juce_TopLevelWindow.h"
        "BSAudioEngine/lib/include/juce_gui_basics/juce_gui_basics.cpp"
        "BSAudioEngine/lib/include/juce_gui_basics/juce_gui_basics.mm"
        "BSAudioEngine/lib/include/juce_gui_basics/juce_gui_basics.h"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CodeDocument.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CodeDocument.h"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CodeEditorComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CodeTokeniser.h"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h"
        "BSAudioEngine/lib/include/juce_gui_extra/documents/juce_FileBasedDocument.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/documents/juce_FileBasedDocument.h"
        "BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_ActiveXControlComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_AndroidViewComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_HWNDComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_NSViewComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_UIViewComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_XEmbedComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_AnimatedAppComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_AppleRemote.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_BubbleMessageComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_ColourSelector.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_ColourSelector.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_LiveConstantEditor.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_LiveConstantEditor.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_PreferencesPanel.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_PreferencesPanel.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_PushNotifications.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_PushNotifications.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_SplashScreen.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_SplashScreen.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_SystemTrayIconComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/misc/juce_WebBrowserComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_android_PushNotifications.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_AndroidViewComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_ios_PushNotifications.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_ios_UIViewComponent.mm"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_AppleRemote.mm"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_NSViewComponent.mm"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_NSViewFrameWatcher.h"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_PushNotifications.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_win32_HWNDComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/juce_gui_extra.cpp"
        "BSAudioEngine/lib/include/juce_gui_extra/juce_gui_extra.mm"
        "BSAudioEngine/lib/include/juce_gui_extra/juce_gui_extra.h"
        "BSAudioEngine/lib/include/AppConfig.h"
        "BSAudioEngine/lib/include/include_juce_audio_basics.cpp"
        "BSAudioEngine/lib/include/include_juce_audio_devices.cpp"
        "BSAudioEngine/lib/include/include_juce_audio_formats.cpp"
        "BSAudioEngine/lib/include/include_juce_audio_processors.cpp"
        "BSAudioEngine/lib/include/include_juce_audio_utils.cpp"
        "BSAudioEngine/lib/include/include_juce_core.cpp"
        "BSAudioEngine/lib/include/include_juce_data_structures.cpp"
        "BSAudioEngine/lib/include/include_juce_dsp.cpp"
        "BSAudioEngine/lib/include/include_juce_events.cpp"
        "BSAudioEngine/lib/include/include_juce_graphics.cpp"
        "BSAudioEngine/lib/include/include_juce_gui_basics.cpp"
        "BSAudioEngine/lib/include/include_juce_gui_extra.cpp"
        "BSAudioEngine/lib/include/JuceHeader.h"
        )

set_source_files_properties("BSEngine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSInternal.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSEffectPresets.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSEffectProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("Track.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioChannelSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioChannelSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioDataConverters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioDataConverters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_AudioSampleBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/buffers/juce_FloatVectorOperations.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMP.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPacket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPackets.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPConversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPConverters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPDispatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPMidi1ToBytestreamTranslator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPMidi1ToMidi2DefaultTranslator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPMidi1ToMidi2DefaultTranslator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPProtocols.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPReceiver.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPSysEx7.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPSysEx7.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPTests.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPUtils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPUtils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/ump/juce_UMPView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiDataConcatenator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiKeyboardState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiKeyboardState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiMessage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiMessageSequence.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiMessageSequence.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiRPN.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/midi/juce_MidiRPN.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEInstrument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEInstrument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEMessages.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEMessages.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPENote.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPENote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiserBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEUtils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEUtils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/mpe/juce_MPEZoneLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_AudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_BufferingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_BufferingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_IIRFilterAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_MemoryAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_MemoryAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_MixerAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_MixerAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_PositionableAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ResamplingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ReverbAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ReverbAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/synthesisers/juce_Synthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/synthesisers/juce_Synthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_ADSR.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_ADSR_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_Decibels.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_GenericInterpolator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_IIRFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_IIRFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_Interpolators.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_Interpolators.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_LagrangeInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_Reverb.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_SmoothedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_SmoothedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/utilities/juce_WindowedSincInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/juce_audio_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/juce_audio_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_basics/juce_audio_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioDeviceManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioIODevice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioIODevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_AudioIODeviceType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/audio_io/juce_SystemAudioVolume.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/midi_io/ump/juce_UMPBytestreamInputHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/midi_io/ump/juce_UMPTests.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/midi_io/ump/juce_UMPU32InputHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/midi_io/juce_MidiDevices.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/midi_io/juce_MidiDevices.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/midi_io/juce_MidiMessageCollector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/AudioStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/AudioStreamBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/AudioStreamBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/AudioStreamCallback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/Definitions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/LatencyTuner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/Oboe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/ResultWithValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/StabilizedCallback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/Utilities.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/include/oboe/Version.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/aaudio/AAudioExtensions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/AudioClock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/AudioStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/AudioStreamBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FilterAudioStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FilterAudioStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/LatencyTuner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/MonotonicCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/OboeDebug.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/QuirksManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/QuirksManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI16Caller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI16Caller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI24Caller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI24Caller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI32Caller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/SourceI32Caller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/StabilizedCallback.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/Trace.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/Trace.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/Utilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/common/Version.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoController.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/HyperbolicCosineWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/KaiserWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/FlowgraphUtilities.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI32.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SinkI32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI32.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/flowgraph/SourceI32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/CMakeLists.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/oboe/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_android_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_android_HighPerformanceAudioHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_android_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_android_Oboe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_android_OpenSL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_ios_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_ios_Audio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_linux_ALSA.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_linux_Bela.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_linux_JackAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_linux_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_mac_CoreAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_mac_CoreMidi.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_win32_ASIO.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_win32_DirectSound.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_win32_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/native/juce_win32_WASAPI.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/sources/juce_AudioSourcePlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/sources/juce_AudioTransportSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/sources/juce_AudioTransportSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/juce_audio_devices.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/juce_audio_devices.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_devices/juce_audio_devices.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/bitmath.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/bitreader.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/cpu.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/crc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/fixed.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/float.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/format.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/md5.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/memory.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/libFLAC/window_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/alloc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/assert.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/callback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/compat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/endswap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/export.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/Flac Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/ordinals.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/flac/win_utf8_io.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_stereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/floor/floor_books.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/uncoupled/res_books_uncoupled.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/floor_all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_22.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_X.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/analysis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/backends.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/block.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codec_internal.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/highlevel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/info.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup_data.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mapping0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/masking.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/os.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/res0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/scales.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/sharedbook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/synthesis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisenc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisfile.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/bitwise.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/codec.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/config_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/crctable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/ogg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/os_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/vorbisenc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/oggvorbis/vorbisfile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_AiffAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_CoreAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_FlacAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_MP3AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_WavAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_WavAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatReaderSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatWriter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioFormatWriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioSubsectionReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_AudioSubsectionReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_BufferingAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/sampler/juce_Sampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/sampler/juce_Sampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/juce_audio_formats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/juce_audio_formats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_formats/juce_audio_formats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format/juce_AudioPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format/juce_AudioPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format/juce_AudioPluginFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/baseiids.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/classfactoryhelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/thread/include/flock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/thread/source/flock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/base/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/coreiids.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpush.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fstrdefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ftypes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/futils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fvariant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ibstream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/icloneable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipersistent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipluginbase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/istringresult.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/iupdatehandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/smartpointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/typesizecheck.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugview.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugviewcontentscalesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstattributes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstaudioprocessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstautomationstate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstchannelcontextinfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcomponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcontextmenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsteditcontroller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstevents.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsthostapplication.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstinterappaudio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidicontrollers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidilearn.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstnoteexpression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstparameterchanges.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstparameterfunctionname.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstphysicalui.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstpluginterfacesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstplugview.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprefetchablesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprocesscontext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstrepresentation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsttestplugprovider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstunits.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstpshpack4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstspeaker.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vsttypes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstinitiids.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/public.sdk/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/JUCE_README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/VST3_SDK/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_AU_Shared.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VST3Common.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VST3Headers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VST3PluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VSTCommon.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VSTMidiEventList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/format_types/juce_VSTPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioPluginInstance.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioPluginInstance.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorEditorHostContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorGraph.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_HostedAudioProcessorParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_PluginDescription.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/processors/juce_PluginDescription.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_KnownPluginList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_KnownPluginList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_PluginListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/scanning/juce_PluginListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterBool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterBool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterChoice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterChoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterFloat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterInt.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioParameterInt.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_ExtensionsVisitor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_ParameterAttachments.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_ParameterAttachments.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_PluginHostType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_PluginHostType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_RangedAudioParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_RangedAudioParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_VST3ClientExtensions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/utilities/juce_VSTCallbackHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/juce_audio_processors.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/juce_audio_processors.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_processors/juce_audio_processors.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/audio_cd/juce_AudioCDBurner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/audio_cd/juce_AudioCDReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioThumbnail.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioThumbnail.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioThumbnailBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioThumbnailCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_AudioVisualiserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_KeyboardComponentBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_KeyboardComponentBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_MidiKeyboardComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_MPEKeyboardComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/gui/juce_MPEKeyboardComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/native/juce_linux_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/native/juce_mac_AudioCDBurner.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/native/juce_mac_AudioCDReader.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/native/juce_win32_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/players/juce_AudioProcessorPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/players/juce_SoundPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/players/juce_SoundPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/juce_audio_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/juce_audio_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_audio_utils/juce_audio_utils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_AbstractFifo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_AbstractFifo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_Array.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_ArrayAllocationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_ArrayBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_ArrayBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_DynamicObject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_DynamicObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_ElementComparator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_HashMap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_HashMap_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_LinkedListPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_ListenerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_NamedValueSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_NamedValueSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_OwnedArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_OwnedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_PropertySet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_PropertySet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_ReferenceCountedArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_ReferenceCountedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_ScopedValueSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_SingleThreadedAbstractFifo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_SortedSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_SparseSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_SparseSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_Variant.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/containers/juce_Variant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_DirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_DirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_File.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_File.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_FileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_FileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_FileInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_FileInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_FileOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_FileOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_FileSearchPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_FileSearchPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_MemoryMappedFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_RangedDirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_RangedDirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_TemporaryFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_TemporaryFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_WildcardFileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/files/juce_WildcardFileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/javascript/juce_Javascript.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/javascript/juce_Javascript.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/javascript/juce_JSON.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/javascript/juce_JSON.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/logging/juce_FileLogger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/logging/juce_FileLogger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/logging/juce_Logger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/logging/juce_Logger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/maths/juce_BigInteger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/maths/juce_BigInteger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/maths/juce_Expression.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/maths/juce_Expression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/maths/juce_MathsFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/maths/juce_NormalisableRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/maths/juce_Random.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/maths/juce_Random.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/maths/juce_Range.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/maths/juce_StatisticsAccumulator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_AllocationHooks.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_AllocationHooks.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_Atomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_ByteOrder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_ContainerDeletePolicy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_HeapBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_HeavyweightLeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_LeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_Memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_MemoryBlock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_MemoryBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_OptionalScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_ReferenceCountedObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_Reservoir.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_ScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_SharedResourcePointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_Singleton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/memory/juce_WeakReference.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/misc/juce_ConsoleApplication.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/misc/juce_ConsoleApplication.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/misc/juce_Functional.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/misc/juce_Result.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/misc/juce_Result.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/misc/juce_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/misc/juce_RuntimePermissions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/misc/juce_Uuid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/misc/juce_Uuid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/misc/juce_WindowsRegistry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/java/README.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_android_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_android_JNIHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_android_JNIHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_android_Misc.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_android_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_android_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_android_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_android_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_BasicNativeHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_curl_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_intel_SharedCode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_linux_CommonFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_linux_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_linux_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_linux_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_linux_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_mac_CFHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_mac_Files.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_mac_Network.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_mac_ObjCHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_mac_Strings.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_mac_SystemStats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_mac_Threads.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_posix_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_posix_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_posix_SharedCode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_wasm_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_win32_ComSmartPtr.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_win32_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_win32_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_win32_Registry.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_win32_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/native/juce_win32_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_IPAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_MACAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_MACAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_NamedPipe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_Socket.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_Socket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_URL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_URL.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_WebInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/network/juce_WebInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_BufferedInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_BufferedInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_FileInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_FileInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_InputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_InputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_InputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_MemoryInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_MemoryInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_MemoryOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_MemoryOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_OutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_OutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_SubregionStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_SubregionStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_URLInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/streams/juce_URLInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/system/juce_CompilerSupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/system/juce_CompilerWarnings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/system/juce_PlatformDefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/system/juce_StandardHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/system/juce_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/system/juce_SystemStats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/system/juce_TargetPlatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_Base64.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_Base64.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_CharacterFunctions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_CharacterFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_CharPointer_ASCII.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_CharPointer_UTF8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_CharPointer_UTF16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_CharPointer_UTF32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_Identifier.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_Identifier.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_LocalisedStrings.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_LocalisedStrings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_NewLine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_String.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_String.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_StringArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_StringArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_StringPairArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_StringPairArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_StringPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_StringPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_StringRef.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_TextDiff.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/text/juce_TextDiff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_ChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_ChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_CriticalSection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_DynamicLibrary.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_HighResolutionTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_HighResolutionTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_InterProcessLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_Process.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_ReadWriteLock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_ReadWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_ScopedLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_ScopedReadLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_ScopedWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_SpinLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_Thread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_Thread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_ThreadLocalValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_ThreadPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_ThreadPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_TimeSliceThread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_TimeSliceThread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_WaitableEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/threads/juce_WaitableEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/time/juce_PerformanceCounter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/time/juce_PerformanceCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/time/juce_RelativeTime.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/time/juce_RelativeTime.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/time/juce_Time.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/time/juce_Time.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/unit_tests/juce_UnitTest.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/unit_tests/juce_UnitTest.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/unit_tests/juce_UnitTestCategories.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/xml/juce_XmlDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/xml/juce_XmlDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/xml/juce_XmlElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/xml/juce_XmlElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/adler32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/compress.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/crc32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/crc32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/deflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/deflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/infback.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/inffast.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/inffast.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/inffixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/inflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/inflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/inftrees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/inftrees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/trees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/trees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/uncompr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/zconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/zconf.in.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/zlib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/zutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/zlib/zutil.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/juce_GZIPCompressorOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/juce_GZIPCompressorOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/juce_GZIPDecompressorInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/juce_GZIPDecompressorInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/juce_ZipFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/zip/juce_ZipFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/juce_core.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/juce_core.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_core/juce_core.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/app_properties/juce_ApplicationProperties.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/app_properties/juce_ApplicationProperties.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/app_properties/juce_PropertiesFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/app_properties/juce_PropertiesFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/undomanager/juce_UndoableAction.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/undomanager/juce_UndoManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/undomanager/juce_UndoManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/values/juce_CachedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/values/juce_CachedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/values/juce_Value.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/values/juce_Value.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTree.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTree.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTreePropertyWithDefault.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTreePropertyWithDefault_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/values/juce_ValueTreeSynchroniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/juce_data_structures.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/juce_data_structures.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_data_structures/juce_data_structures.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/containers/juce_AudioBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/containers/juce_AudioBlock_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/containers/juce_FixedSizeFunction.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/containers/juce_FixedSizeFunction_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/containers/juce_SIMDRegister.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/containers/juce_SIMDRegister_Impl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/containers/juce_SIMDRegister_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/filter_design/juce_FilterDesign.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/filter_design/juce_FilterDesign.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/frequency/juce_Convolution.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/frequency/juce_Convolution.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/frequency/juce_Convolution_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/frequency/juce_FFT.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/frequency/juce_FFT.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/frequency/juce_FFT_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/frequency/juce_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/frequency/juce_Windowing.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_FastMathApproximations.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_LogRampedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_LogRampedValue_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_LookupTable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_LookupTable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_Matrix.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_Matrix.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_Matrix_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_Phase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_Polynomial.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_SpecialFunctions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/maths/juce_SpecialFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/native/juce_avx_SIMDNativeOps.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/native/juce_avx_SIMDNativeOps.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/native/juce_fallback_SIMDNativeOps.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/native/juce_neon_SIMDNativeOps.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/native/juce_neon_SIMDNativeOps.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/native/juce_sse_SIMDNativeOps.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/native/juce_sse_SIMDNativeOps.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_BallisticsFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_BallisticsFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_DelayLine.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_DelayLine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_DryWetMixer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_DryWetMixer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_FIRFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_FIRFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_FIRFilter_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_FirstOrderTPTFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_FirstOrderTPTFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_IIRFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_IIRFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_IIRFilter_Impl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_LinkwitzRileyFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_LinkwitzRileyFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_Oversampling.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_Oversampling.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_Panner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_Panner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_ProcessContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_ProcessorChain.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_ProcessorChain_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_ProcessorDuplicator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_ProcessorWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_StateVariableFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_StateVariableTPTFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/processors/juce_StateVariableTPTFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Bias.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Chorus.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Chorus.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Compressor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Compressor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Gain.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_LadderFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_LadderFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Limiter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Limiter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_NoiseGate.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_NoiseGate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Oscillator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Phaser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Phaser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_Reverb.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/widgets/juce_WaveShaper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/juce_dsp.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/juce_dsp.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_dsp/juce_dsp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/broadcasters/juce_ActionBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/broadcasters/juce_ActionBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/broadcasters/juce_ActionListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/broadcasters/juce_AsyncUpdater.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/broadcasters/juce_AsyncUpdater.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/broadcasters/juce_ChangeBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/broadcasters/juce_ChangeBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/broadcasters/juce_ChangeListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/interprocess/juce_ConnectedChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/interprocess/juce_ConnectedChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/interprocess/juce_InterprocessConnection.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/interprocess/juce_InterprocessConnection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/interprocess/juce_InterprocessConnectionServer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/interprocess/juce_InterprocessConnectionServer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/interprocess/juce_NetworkServiceDiscovery.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/interprocess/juce_NetworkServiceDiscovery.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_ApplicationBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_ApplicationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_CallbackMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_DeletedAtShutdown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_DeletedAtShutdown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_Initialisation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_Message.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_MessageListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_MessageListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_MessageManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_MessageManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_MountedVolumeListChangeDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/messages/juce_NotificationType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_android_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_ios_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_linux_EventLoop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_linux_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_mac_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_osx_MessageQueue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_ScopedLowPowerModeDisabler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_ScopedLowPowerModeDisabler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_win32_HiddenMessageWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_win32_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_win32_WinRTWrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/native/juce_win32_WinRTWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/timers/juce_MultiTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/timers/juce_MultiTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/timers/juce_Timer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/timers/juce_Timer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/juce_events.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/juce_events.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_events/juce_events.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/colour/juce_Colour.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/colour/juce_Colour.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/colour/juce_ColourGradient.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/colour/juce_ColourGradient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/colour/juce_Colours.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/colour/juce_Colours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/colour/juce_FillType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/colour/juce_FillType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/colour/juce_PixelFormats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/contexts/juce_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/contexts/juce_GraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/contexts/juce_LowLevelGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/effects/juce_DropShadowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/effects/juce_DropShadowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/effects/juce_GlowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/effects/juce_GlowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/effects/juce_ImageEffectFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_AttributedString.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_AttributedString.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_CustomTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_CustomTypeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_Font.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_Font.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_GlyphArrangement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_GlyphArrangement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_TextLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_TextLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_Typeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/fonts/juce_Typeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_AffineTransform.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_AffineTransform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_BorderSize.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_EdgeTable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_EdgeTable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_Line.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_Parallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_Path.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_Path.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_PathIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_PathIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_PathStrokeType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_PathStrokeType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_Point.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_Rectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_Rectangle_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/geometry/juce_RectangleList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/cderror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jccoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jccolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcdctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jchuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jchuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcinit.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcomapi.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jconfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcparam.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcprepct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jcsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jctrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdatasrc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdcoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdcolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jddctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdhuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdhuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdinput.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdmerge.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdpostct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jdtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jerror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jfdctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jfdctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jfdctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jidctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jidctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jidctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jidctred.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jinclude.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jmemmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jmemnobs.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jmemsys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jmorecfg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jpegint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jpeglib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jquant1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jquant2.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jutils.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/jversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/transupp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/jpglib/transupp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/libpng_readme.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/png.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/png.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngdebug.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngget.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pnginfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngmem.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngpread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngpriv.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngrio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngrtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngrutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngset.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngstruct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngwio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngwrite.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngwtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/pnglib/pngwutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/juce_GIFLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/juce_JPEGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/image_formats/juce_PNGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/images/juce_Image.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/images/juce_Image.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/images/juce_ImageCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/images/juce_ImageCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/images/juce_ImageConvolutionKernel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/images/juce_ImageConvolutionKernel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/images/juce_ImageFileFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/images/juce_ImageFileFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/images/juce_ScaledImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_android_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_android_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_android_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_freetype_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_linux_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_linux_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_mac_CoreGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_mac_CoreGraphicsContext.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_mac_Fonts.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_mac_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_RenderingHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_win32_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/native/juce_win32_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/placement/juce_Justification.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/placement/juce_RectanglePlacement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/placement/juce_RectanglePlacement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/juce_graphics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/juce_graphics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_graphics/juce_graphics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/accessibility/enums/juce_AccessibilityActions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/accessibility/enums/juce_AccessibilityEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/accessibility/enums/juce_AccessibilityRole.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/accessibility/interfaces/juce_AccessibilityCellInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/accessibility/interfaces/juce_AccessibilityTableInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/accessibility/interfaces/juce_AccessibilityTextInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/accessibility/interfaces/juce_AccessibilityValueInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/accessibility/juce_AccessibilityHandler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/accessibility/juce_AccessibilityHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/accessibility/juce_AccessibilityState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/application/juce_Application.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/application/juce_Application.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ArrowButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ArrowButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_Button.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_Button.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_DrawableButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_DrawableButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_HyperlinkButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_HyperlinkButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ImageButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ImageButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ShapeButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ShapeButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_TextButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_TextButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ToggleButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ToggleButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ToolbarButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/buttons/juce_ToolbarButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandInfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/commands/juce_ApplicationCommandTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/commands/juce_KeyPressMappingSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/components/juce_CachedComponentImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/components/juce_Component.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/components/juce_Component.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/components/juce_ComponentListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/components/juce_ComponentListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/components/juce_ComponentTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/components/juce_FocusTraverser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/components/juce_FocusTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/components/juce_ModalComponentManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/components/juce_ModalComponentManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/desktop/juce_Desktop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/desktop/juce_Desktop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/desktop/juce_Displays.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/desktop/juce_Displays.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_Drawable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_Drawable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableComposite.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableComposite.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawablePath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawablePath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableShape.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableShape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableText.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_DrawableText.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/drawables/juce_SVGParser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_ContentSharer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileBrowserListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileChooser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FilenameComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_FileTreeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_CaretComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_CaretComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyPress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_KeyPress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_ModifierKeys.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_ModifierKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_SystemClipboard.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/keyboard/juce_TextInputTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_AnimatedPosition.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentAnimator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentAnimator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ComponentMovementWatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ConcertinaPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ConcertinaPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_FlexBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_FlexBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_FlexItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_Grid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_Grid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_GridItem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_GridItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_GroupComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_GroupComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_MultiDocumentPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableBorderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableCornerComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ResizableEdgeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ScrollBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_ScrollBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_SidePanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_SidePanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableLayoutManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_StretchableObjectResizer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_TabbedButtonBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_TabbedButtonBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_TabbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_TabbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_Viewport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/layout/juce_Viewport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/menus/juce_BurgerMenuComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/menus/juce_MenuBarComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/menus/juce_MenuBarComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/menus/juce_MenuBarModel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/menus/juce_MenuBarModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/menus/juce_PopupMenu.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/menus/juce_PopupMenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/misc/juce_BubbleComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/misc/juce_BubbleComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/misc/juce_DropShadower.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/misc/juce_DropShadower.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/misc/juce_FocusOutline.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/misc/juce_FocusOutline.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/misc/juce_JUCESplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/misc/juce_JUCESplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_ComponentDragger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_ComponentDragger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_DragAndDropContainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_DragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_LassoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseCursor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseCursor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseInactivityDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_MouseListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_PointerState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_SelectedItemSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/mouse/juce_TooltipClient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_AccessibilityTextHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_android_Accessibility.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_ios_Accessibility.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_mac_Accessibility.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_mac_AccessibilitySharedCode.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_Accessibility.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_AccessibilityElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_AccessibilityElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_ComInterfaces.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAExpandCollapseProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAGridItemProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAGridProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAInvokeProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAProviderBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAProviders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIARangeValueProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIASelectionProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIATextProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAToggleProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIATransformProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAValueProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_UIAWindowProvider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/accessibility/juce_win32_WindowsUIAWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/x11/juce_linux_X11_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/x11/juce_linux_X11_Symbols.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/x11/juce_linux_X11_Symbols.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/x11/juce_linux_XWindowSystem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/x11/juce_linux_XWindowSystem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_android_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_android_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_android_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_common_MimeTypes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_ios_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_ios_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_ios_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_linux_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_linux_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_mac_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_mac_MainMenu.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_mac_MouseCursor.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_mac_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_MultiTouchMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_ScopedDPIAwarenessDisabler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_win32_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_win32_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_win32_ScopedThreadDPIAwarenessSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/native/juce_win32_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_MarkerList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_MarkerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeCoordinate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeParallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativePoint.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativePoint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativePointPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativePointPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/positioning/juce_RelativeRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_BooleanPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_ButtonPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_ChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_PropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_PropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_PropertyPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_PropertyPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_SliderPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_TextPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/properties/juce_TextPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ComboBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ComboBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ImageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ImageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Label.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Label.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ProgressBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ProgressBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Slider.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Slider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TableHeaderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TableListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TableListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TextEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TextEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Toolbar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_Toolbar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ToolbarItemComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ToolbarItemFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_ToolbarItemPalette.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TreeView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/widgets/juce_TreeView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_AlertWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_AlertWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_CallOutBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_CallOutBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ComponentPeer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ComponentPeer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_DialogWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_DialogWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_DocumentWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_DocumentWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_MessageBoxOptions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_NativeMessageBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ResizableWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ResizableWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_TooltipWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_TooltipWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_TopLevelWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/windows/juce_TopLevelWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/juce_gui_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/juce_gui_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_basics/juce_gui_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CodeDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CodeDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CodeEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/documents/juce_FileBasedDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/documents/juce_FileBasedDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_ActiveXControlComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_AndroidViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_HWNDComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_NSViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_UIViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/embedding/juce_XEmbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_AnimatedAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_AppleRemote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_BubbleMessageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_ColourSelector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_ColourSelector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_LiveConstantEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_LiveConstantEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_PreferencesPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_PreferencesPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_PushNotifications.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_SplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_SplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_SystemTrayIconComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/misc/juce_WebBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_android_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_AndroidViewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_ios_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_ios_UIViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_AppleRemote.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_NSViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_NSViewFrameWatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_win32_HWNDComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/juce_gui_extra.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/juce_gui_extra.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/juce_gui_extra/juce_gui_extra.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/AppConfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("BSAudioEngine/lib/include/JuceHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)

#target_compile_options(BSAudioEngine PRIVATE "-fsigned-char" )
#
##if( JUCE_BUILD_CONFIGURATION MATCHES "DEBUG" )
##    target_compile_options( ${BINARY_NAME} PRIVATE)
##endif()
##
##if( JUCE_BUILD_CONFIGURATION MATCHES "RELEASE" )
##    target_compile_options( ${BINARY_NAME} PRIVATE)
##endif()

find_library(log "log")
find_library(android "android")
find_library(glesv2 "GLESv2")
find_library(egl "EGL")

target_link_libraries( BSAudioEngine

        ${log}
        ${android}
        ${glesv2}
        ${egl}
        "cpufeatures"
        "oboe"
        )
