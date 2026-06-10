#pragma once
#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "input.h"

extern Adafruit_USBD_HID usb_hid;
extern uint8_t const desc_hid_report[];
extern const size_t desc_hid_report_len;

class HID {
public:
    uint8_t shift = KEYBOARD_MODIFIER_LEFTSHIFT;
    uint8_t ctrl = KEYBOARD_MODIFIER_LEFTCTRL;
    uint8_t alt = KEYBOARD_MODIFIER_LEFTALT;
    uint8_t keyGuide{0};
    
    void setup();
    void send(uint8_t keys[6], uint8_t modifier = 0);
    void release();
    void sendKey(uint8_t key);

    
    void copy();
    void paste();
    void typeLetter(uint8_t alpha);
    void addOrSub(uint8_t* val);
};
