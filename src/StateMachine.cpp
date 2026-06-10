#include "StateMachine.h"
#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "HID.h"
#include "input.h"
#include "Display.h"
#include <test_image_565.h>


void StateMachine::updateState() {
            switch (currentState) {
                case State::ImageSwitch:
                    // Code to handle image switch
                    myInput.updateButtons();
                    break;
                case State::LetterSwitch:
                    myInput.addOrSub(&LetterController);
                    if (millis() - previousTime > 500) {
                        previousTime = millis();
                        d.OneLetterTopLeft(LetterController);
                    }
                    if (myInput.buttonNumNewlyPressed(Input::ButtonMASK::BUT3_PRESSED)){
                        myHID.typeLetter(LetterController);
                    }
                    
                    myInput.updateButtons();
                    break;
                case State::Preprocessing:
                    // Code to handle preprocessing
                    myInput.updateButtons();
                    break;
                case State::Loading:
                    // Code to handle loading
                    myInput.updateButtons();
                    break;
            }
}

void StateMachine::begin(){
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    myHID.setup();
    d.resetDisplay();
    delay(100);

    myInput.updateButtons();
    d.display(test_image_565);
}


void StateMachine::checkState(){
    if (myInput.buttonNumPressed(Input::ButtonMASK::BUT1_PRESSED) && myInput.buttonNumPressed(Input::ButtonMASK::BUT2_PRESSED)){
        currentState = State::LetterSwitch;
    }
    else if (myInput.buttonNumPressed(Input::ButtonMASK::BUT2_PRESSED) && myInput.buttonNumPressed(Input::ButtonMASK::BUT3_PRESSED)){
        currentState = State::ImageSwitch;
    }
}
// 1 2 pressed at the same time
// 2 3 pressed at the same time
