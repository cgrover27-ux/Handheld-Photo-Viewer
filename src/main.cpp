#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "HID.h"
#include "input.h"
#include "Display.h"
#include <test_image_565.h>
#include "StateMachine.h"







StateMachine sm;



void setup() {
    sm.begin();
    
    

    
}

void loop() {
    
    
    sm.updateState();
    sm.checkState();
    
    
    
    

    
    
    
}
