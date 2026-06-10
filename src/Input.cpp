#include "input.h"

#include <Arduino.h>
#include <Adafruit_TinyUSB.h>



uint8_t Input::getCurrentState(){
    return Input::currentReading; 
}
uint8_t Input::getLastState(){
    return Input::lastReading;
}

void Input::updateButtons(){
    lastReading = currentReading;
    currentReading = 0;
    if (digitalRead(buttonPin1) == LOW) {
        currentReading |= static_cast<uint8_t> (ButtonMASK::BUT1_PRESSED);
    }
    if (digitalRead(buttonPin2) == LOW) {
        currentReading |= static_cast<uint8_t> (ButtonMASK::BUT2_PRESSED);
    }
    if (digitalRead(buttonPin3) == LOW) {
        currentReading |= static_cast<uint8_t> (ButtonMASK::BUT3_PRESSED);
    }
}
bool Input::buttonNumPressed(Input::ButtonMASK num){
    return Input::getCurrentState() & static_cast<uint8_t>(num);
}
bool Input::buttonNumPressedBefore(Input::ButtonMASK num){
    return Input::getLastState() & static_cast<uint8_t>(num);
}

bool Input::buttonNumNewlyPressed(Input::ButtonMASK num){
    return ((static_cast<uint8_t> (num) & Input::getCurrentState()) && (!(static_cast<uint8_t> (num) & Input::getLastState())));
}
bool Input::buttonHeld(Input::ButtonMASK num){
    uint8_t mask = static_cast<uint8_t>(num);
    return ((mask & Input::getCurrentState()) && (mask & Input::getLastState()));


}
void Input::addOrSub(uint8_t* val){
    if (Input::buttonNumNewlyPressed(Input::ButtonMASK::BUT1_PRESSED)){
        ++*val;
    }
    else if(Input::buttonNumNewlyPressed(Input::ButtonMASK::BUT2_PRESSED)){
        --*val;
    }
    *val = *val % 26;
}//used newly pressed for debouncing 
