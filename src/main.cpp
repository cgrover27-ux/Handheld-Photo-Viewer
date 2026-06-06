#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "HID.h"
#include "input.h"

const int8_t buttonPin = 0; // GP1
const int8_t buttonPin2 = 2;
const int8_t buttonPin3 = 5;




HID myHID;
Input myInput(buttonPin, buttonPin2, buttonPin3);

void setup() {
    Serial.begin(9600);
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
    pinMode(buttonPin3, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
    myHID.setup();
    

    
}

void loop() {
    
    myInput.updateButtons();
    if (myInput.buttonNumPressed(Input::ButtonMASK::BUT1_PRESSED)) {
        Serial.println("Button pressed, sending key");
        digitalWrite(LED_BUILTIN, HIGH);
        myHID.sendKey(HID_KEY_0);

        
        
        
        while(myInput.buttonNumPressed(Input::ButtonMASK::BUT1_PRESSED)) {
            delay(100);
            myInput.updateButtons();    
        }
        myHID.release(); 
    
    } else {
        digitalWrite(LED_BUILTIN, LOW);
        
    }
    
    
}
