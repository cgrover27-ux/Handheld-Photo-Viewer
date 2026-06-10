#pragma once
#include <Arduino.h>
#include <Adafruit_TinyUSB.h>




class Input {
    private:
        const int8_t buttonPin1 = 0;
        const int8_t buttonPin2 = 2;
        const int8_t buttonPin3 = 5;
        uint8_t lastReading;
        uint8_t currentReading;// for debouncing figure this out
    
    public:
        Input() : lastReading(0), currentReading(0) {
            pinMode(buttonPin1, INPUT_PULLUP);
            pinMode(buttonPin2, INPUT_PULLUP);
            pinMode(buttonPin3, INPUT_PULLUP);
        };
        enum class ButtonMASK: uint8_t {
            
            BUT1_PRESSED = 1 << 0,
            BUT2_PRESSED = 1 << 1,
            BUT3_PRESSED = 1 << 2,
            NONE = 0
        };

        void updateButtons();
        uint8_t getCurrentState();
        bool buttonNumPressed(ButtonMASK num);
        bool buttonNumPressedBefore(ButtonMASK num);
        uint8_t getLastState();
        bool buttonNumNewlyPressed(ButtonMASK num);
        bool buttonHeld(ButtonMASK num);
        void addOrSub(uint8_t* val);
            
};


