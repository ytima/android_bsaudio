/*
  ==============================================================================

    BSOutputDeviceFlag.h
    Created: 25 Aug 2022 1:11:43pm
    Author:  Arthur Wilson

  ==============================================================================
*/

#pragma once

class BSOutputDeviceFlag {
 public:
    
    void resetAllFlags()
    {
        bluetoothDeviceFlag = false;
        headphonesDeviceFlag = false;
        deviceSpeakerFlag = false;
    }
    
    void setBluetoothDevice()
    {
        resetAllFlags();
        bluetoothDeviceFlag = true;
    }
    
    void setHeadphonesDevice()
    {
        resetAllFlags();
        headphonesDeviceFlag = true;
    }
    
    void setDeviceSpeakerFlag()
    {
        resetAllFlags();
        deviceSpeakerFlag = true;
    }
    
    bool isBluetoothDevice() { return bluetoothDeviceFlag; }
    bool isHeadphonesDevice() { return headphonesDeviceFlag; }
    bool isDeviceSpeaker() { return deviceSpeakerFlag; }
    
    
 private:
    bool bluetoothDeviceFlag = false;
    bool headphonesDeviceFlag = false;
    bool deviceSpeakerFlag = false;
    
};

extern BSOutputDeviceFlag outputDeviceFlag;
