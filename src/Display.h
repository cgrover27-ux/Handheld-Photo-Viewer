#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h> 



class Display{
    private:
        static constexpr int8_t MANUAL_TFT_BL = 14;
        static constexpr int8_t MANUAL_TFT_RST = 12;
        static constexpr int8_t MANUAL_TFT_MISO = 8;
        static constexpr int8_t MANUAL_TFT_MOSI = 11;
        static constexpr int8_t MANUAL_TFT_SCLK = 10;
        TFT_eSPI tft;

        



    public:
        Display();
        void init();
        void display(const uint16_t* row);
        void drawTestPattern(const uint16_t* arr);
        void resetDisplay();
        void OneLetterTopLeft(uint8_t x);
        




};
