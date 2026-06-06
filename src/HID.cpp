
#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "HID.h"

// HID Report Descriptor for a standard Keyboard
uint8_t const desc_hid_report[] = {
    TUD_HID_REPORT_DESC_KEYBOARD()
};
const size_t desc_hid_report_len = sizeof(desc_hid_report);
Adafruit_USBD_HID usb_hid;


//highlight




void HID::setup(){
    usb_hid.setPollInterval(10);
    usb_hid.setReportDescriptor(desc_hid_report, desc_hid_report_len);
    usb_hid.begin();

    while (!TinyUSBDevice.mounted()) {
        delay(1);
    }
    
}

void HID::send(uint8_t keys[6]/* this is the array to send the code */, uint8_t modifier){
    usb_hid.keyboardReport(0, modifier, keys);
}

void HID::release(){
    
    usb_hid.keyboardReport(0, 0, 0);
}

void HID::sendKey(uint8_t key){
        uint8_t keys[6] = {key, 0, 0, 0, 0, 0};
        send(keys);
        
    }
void HID::copy(){
    uint8_t keys[6] = {HID_KEY_KEYPAD_C,0,0,0,0,0};
    HID::send(keys, hid_keyboard_modifier_bm_t(HID_KEY_CONTROL_LEFT));

}
void HID::paste(){
    uint8_t keys[6] = {HID_KEY_V,0,0,0,0,0};
    HID::send(keys, hid_keyboard_modifier_bm_t(HID_KEY_CONTROL_LEFT));
}

    

