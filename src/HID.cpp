
#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "HID.h"

// HID Report Descriptor for a standard Keyboard
uint8_t const desc_hid_report[] = {
    TUD_HID_REPORT_DESC_KEYBOARD()
};
const size_t desc_hid_report_len = sizeof(desc_hid_report);
Adafruit_USBD_HID usb_hid;







void HID::setup(){ // Inititialize HID
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

void HID::typeLetter(uint8_t alpha){
    switch(alpha){
        case 0:
            sendKey(HID_KEY_A);
            break;
        case 1:
            sendKey(HID_KEY_B);
            break;
        case 2:
            sendKey(HID_KEY_C);
            break;
        case 3:
            sendKey(HID_KEY_D);
            break;
        case 4:   
            sendKey(HID_KEY_E);
            break;
        case 5:
            sendKey(HID_KEY_F);
            break;
        case 6:
            sendKey(HID_KEY_G);
            break;
        case 7:
            sendKey(HID_KEY_H);
            break;
        case 8:
            sendKey(HID_KEY_I);
            break;
        case 9:
            sendKey(HID_KEY_J);
            break;
        case 10:
            sendKey(HID_KEY_K);
            break;
        case 11:
            sendKey(HID_KEY_L);
            break;
        case 12:
            sendKey(HID_KEY_M);
            break;
        case 13:       
            sendKey(HID_KEY_N);
            break;
        case 14:
            sendKey(HID_KEY_O);
            break;
        case 15:
            sendKey(HID_KEY_P);
            break;
        case 16:
            sendKey(HID_KEY_Q);
            break;
        case 17:
            sendKey(HID_KEY_R);
            break;
        case 18:
            sendKey(HID_KEY_S);
            break;
        case 19:
            sendKey(HID_KEY_T);
            break;
        case 20:
            sendKey(HID_KEY_U);
            break;
        case 21:
            sendKey(HID_KEY_V);
            break;
        case 22:
            sendKey(HID_KEY_W);
            break;
        case 23:
            sendKey(HID_KEY_X);
            break;
        case 24:    
            sendKey(HID_KEY_Y);
            break;
        case 25:
            sendKey(HID_KEY_Z);
            break;  
        default:
            break;
    }
}





