#include "input.h"

#include <Arduino.h>
#include <Adafruit_TinyUSB.h>



uint8_t Input::getCurrentState(){
    return Input::currentReading; 
}
uint8_t Input::getLastState(){
    return Input::lastReading;
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

