#pragma once

enum class State {
    ImageSwitch,
    LetterSwitch,
    Preprocessing,
    Loading
};

class StateMachine {
    private:
        State currentState;
        const int8_t buttonPin1{0}; // GP1
        const int8_t buttonPin2{2};
        const int8_t buttonPin3{5};
        HID myHID;
        Input myInput;
        Display d;
        uint8_t LetterController{0};
        uint16_t previousTime {0};

    public:
        StateMachine() : currentState(State::ImageSwitch) {}
        void updateState();
        void begin();
        void checkState();





};


