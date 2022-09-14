/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

import React, { useEffect, useState } from 'react';
import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
  NativeModules,
  TouchableOpacity,
} from 'react-native';

import {
  Colors,
  DebugInstructions,
  Header,
  LearnMoreLinks,
  ReloadInstructions,
} from 'react-native/Libraries/NewAppScreen';
const { BSAudioEngine } = NativeModules;


const Section = ({ children, title }) => {
  const isDarkMode = useColorScheme() === 'dark';
  return (
    <View style={styles.sectionContainer}>
      <Text
        style={[
          styles.sectionTitle,
          {
            color: isDarkMode ? Colors.white : Colors.black,
          },
        ]}>
        {title}
      </Text>
      <Text
        style={[
          styles.sectionDescription,
          {
            color: isDarkMode ? Colors.light : Colors.dark,
          },
        ]}>
        {children}
      </Text>
    </View>
  );
};

const App = () => {
  const [recorded, setRecorded] = useState(false)
  console.log('BSAudioEngine', BSAudioEngine)
  // console.log('NativeModules', NativeModules)
  useEffect(() => {
    const cb = (value) => {
      console.log('testCallLib', value)
    }
    setTimeout(() => {
      // BSAudioEngine.testCallLib(cb)
      // const res = BSAudioEngine.BSInitialiseDevice()
      // console.log('BSAudioEngine.BSInitialiseDevice', res)
      const res = BSAudioEngine.BSInitDevice()
      console.log('BSAudioEngine.BSInitDevice', res)
    }, 1000)

  }, [])
  const isDarkMode = useColorScheme() === 'dark';

  const backgroundStyle = {
    backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
  };
  const handleRecord = () => {
    if (!recorded) {
      // long startAtMicros, int currentTrackNumber, int currentTakeNumber, Callback callback
      // recordedLength, sampleRate, filePath, waveformArray
      BSAudioEngine.BSRecordTrack_new('0', 0, 0, (recordedLength, sampleRate, filePath, waveformArray) => console.log('BSAudioEngine.BSRecordTrack', recordedLength, sampleRate, filePath, waveformArray))
      setRecorded(prev => !prev)
      console.log('BSAudioEngine.BSRecordTrack')
    } else {
      BSAudioEngine.BSStop_new()
    }
  }
  const handlePlay = () => {
    BSAudioEngine.BSMultitrackPlay("0", (res) => console.log('BSMultitrackPlay', res))
  }
  return (
    <SafeAreaView style={backgroundStyle}>
      <StatusBar barStyle={isDarkMode ? 'light-content' : 'dark-content'} />
      <ScrollView
        contentInsetAdjustmentBehavior="automatic"
        style={backgroundStyle}>
        <Header />
        <TouchableOpacity onPress={handleRecord} style={{ width: 200, height: 50, backgroundColor: 'yellow' }}>

        </TouchableOpacity>
        <TouchableOpacity onPress={handlePlay} style={{ width: 200, height: 50, backgroundColor: 'green' }}>

        </TouchableOpacity>
        <View
          style={{
            backgroundColor: isDarkMode ? Colors.black : Colors.white,
          }}>
          <Section title="Step One">
            Edit <Text style={styles.highlight}>App.js</Text> to change this
            screen and then come back to see your edits.
          </Section>
          <Section title="See Your Changes">
            <ReloadInstructions />
          </Section>
          <Section title="Debug">
            <DebugInstructions />
          </Section>
          <Section title="Learn More">
            Read the docs to discover what to do next:
          </Section>
          <LearnMoreLinks />
        </View>
      </ScrollView>
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  sectionContainer: {
    marginTop: 32,
    paddingHorizontal: 24,
  },
  sectionTitle: {
    fontSize: 24,
    fontWeight: '600',
  },
  sectionDescription: {
    marginTop: 8,
    fontSize: 18,
    fontWeight: '400',
  },
  highlight: {
    fontWeight: '700',
  },
});

export default App;
