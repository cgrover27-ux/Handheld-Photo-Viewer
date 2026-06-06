#pragma once
#include <Arduino.h>
#include <Adafruit_TinyUSB.h>




class Input {
    private:
        int8_t but1;
        int8_t but2;
        int8_t but3;
        uint8_t lastReading;
        uint8_t currentReading;// for debouncing figure this out
    
    public:
        Input(int8_t pin1, int8_t pin2, int8_t pin3) : but1(pin1), but2(pin2), but3(pin3) {
            pinMode(pin1, INPUT_PULLUP);
            pinMode(pin2, INPUT_PULLUP);
            pinMode(pin3, INPUT_PULLUP);
        };
        enum class ButtonMASK: uint8_t {
            
            BUT1_PRESSED = 1 << 0,
            BUT2_PRESSED = 1 << 1,
            BUT3_PRESSED = 1 << 2,
            NONE = 0
        };

        void updateButtons(){
            lastReading = currentReading;
            currentReading = 0;
            if (digitalRead(but1) == LOW) {
                currentReading |= static_cast<uint8_t> (ButtonMASK::BUT1_PRESSED);
            }
            if (digitalRead(but2) == LOW) {
                currentReading |= static_cast<uint8_t> (ButtonMASK::BUT2_PRESSED);
            }
            if (digitalRead(but3) == LOW) {
                currentReading |= static_cast<uint8_t> (ButtonMASK::BUT3_PRESSED);
            }
        }
        uint8_t getCurrentState();
        bool buttonNumPressed(ButtonMASK num);
        bool buttonNumPressedBefore(ButtonMASK num);
        uint8_t getLastState();
        bool buttonNumNewlyPressed(ButtonMASK num);
        bool buttonHeld(ButtonMASK num);
            
};


