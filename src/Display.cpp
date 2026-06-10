#include <TFT_eSPI.h>
#include <Display.h>
#include <SPI.h> 


Display::Display() {
    Display::init();
}

void Display::init(){
    
    tft = TFT_eSPI(); 
    SPI1.setRX(Display::MANUAL_TFT_MISO);
    SPI1.setTX(Display::MANUAL_TFT_MOSI);
    SPI1.setSCK(Display::MANUAL_TFT_SCLK);

    pinMode(Display::MANUAL_TFT_BL, OUTPUT);
    digitalWrite(Display::MANUAL_TFT_BL, HIGH);

    tft.init();
    tft.begin();
    SPI1.beginTransaction(SPISettings(16000000, MSBFIRST, SPI_MODE0));
    tft.setRotation(1); 
    tft.invertDisplay(false);
    tft.setSwapBytes(1);
    tft.setTextFont(4);
    


    

}

void Display::display(const uint16_t* row){
    int32_t w = 320;
    int32_t h = 480;
    int32_t x = 0;
    int32_t y = 0;
    //tft.pushImage(x, y, w, h, row);
    this->drawTestPattern(row);

}
void Display::drawTestPattern(const uint16_t* arr){
   /* tft.startWrite();
    tft.setAddrWindow(0, 0, 320, 480);
    tft.pushPixels(arr, 320*480);
    tft.endWrite();*/

    uint16_t* test = (uint16_t*)arr;

    uint16_t red[48000];

    for (int i{0}; i < 48000; ++i){
        red[i] = TFT_BLUE;
    }
    
    
    tft.pushImage(0,0,480,320, arr);
    
    
    
    
    /*for (int i{0}; i < 320; ++i){
        for (int j{0}; j < 480; ++j){
            tft.drawPixel(i, j, arr[i * 480 + j],0xFF); // Red
        }
    }*/


    
    return;
}
void Display::resetDisplay() {
    tft.init();
    tft.fillScreen(TFT_BLACK);
}

void Display::OneLetterTopLeft(uint8_t x){
    tft.setTextDatum(TL_DATUM);
    tft.setTextColor(TFT_WHITE, TFT_RED);
    switch(x){
        case 0:
            tft.drawChar('A', 10, 10, 4);
            break;
        case 1:  
            tft.drawChar('B', 10, 10, 4);
            break;
        case 2:
            tft.drawChar('C', 10, 10, 4);
            break;
        case 3:
            tft.drawChar('D', 10, 10, 4);
            break;
        case 4:
            tft.drawChar('E', 10, 10, 4);
            break;
        case 5:
            tft.drawChar('F', 10, 10, 4);
            break;
        case 6:
            tft.drawChar('G', 10, 10, 4);
            break;
        case 7:
            tft.drawChar('H', 10, 10, 4);
            break;
        case 8:
            tft.drawChar('I', 10, 10, 4);
            break;
        case 9:
            tft.drawChar('J', 10, 10, 4);
            break;
        case 10:
            tft.drawChar('K', 10, 10, 4);
            break;
        case 11:
            tft.drawChar('L', 10, 10, 4);
            break;
        case 12:
            tft.drawChar('M', 10, 10, 4);
            break;
        case 13:
            tft.drawChar('N', 10, 10, 4);
            break;
        case 14:
            tft.drawChar('O', 10, 10, 4);
            break;
        case 15:
            tft.drawChar('P', 10, 10, 4);
            break;
        case 16:
            tft.drawChar('Q', 10, 10, 4);
            break;
        case 17:
            tft.drawChar('R', 10, 10, 4);
            break;
        case 18:
            tft.drawChar('S', 10, 10, 4);
            break;
        case 19:
            tft.drawChar('T', 10, 10, 4);
            break;
        case 20:
            tft.drawChar('U', 10, 10, 4);
            break;
        case 21:
            tft.drawChar('V', 10, 10, 4);
            break;
        case 22:
            tft.drawChar('W', 10, 10, 4);
            break;
        case 23:
            tft.drawChar('X', 10, 10, 4);
            break;
        case 24:
            tft.drawChar('Y', 10, 10, 4);
            break;
        case 25:
            tft.drawChar('Z', 10, 10, 4);  
        
    }

    /*tft.drawCircle(100,100,50,TFT_WHITE);
    tft.drawTriangle(100,100,150,150,50,150,TFT_WHITE);
    tft.drawRoundRect(100,100,100,100,10,TFT_WHITE);
    tft.setTextPadding(300);
    tft.drawNumber(500,200,200,1);*/
}































/*

void resetDisplay() {
    pinMode(MANUAL_TFT_RST, OUTPUT);
    digitalWrite(MANUAL_TFT_RST, HIGH);
    delay(100);
    digitalWrite(MANUAL_TFT_RST, LOW);
    delay(100);
    digitalWrite(MANUAL_TFT_RST, HIGH);
    delay(200);
}


    // --- DIAGNOSTIC PRINT OUT ---
    setup_t tft_info;
    tft.getSetup(tft_info);

    Serial.println("=========================================");
    Serial.print("Library Version:     "); Serial.println(tft_info.version);
    Serial.print("Display Driver Hex:  0x"); Serial.println(tft_info.tft_driver, HEX);
    Serial.print("Configured MOSI Pin: "); Serial.println(tft_info.pin_tft_mosi);
    Serial.print("Configured MISO Pin: "); Serial.println(tft_info.pin_tft_miso);
    Serial.print("Configured SCLK Pin: "); Serial.println(tft_info.pin_tft_clk);
    Serial.print("Configured CS Pin:   "); Serial.println(tft_info.pin_tft_cs);
    Serial.print("Configured DC Pin:   "); Serial.println(tft_info.pin_tft_dc);
    Serial.print("Configured RST Pin:  "); Serial.println(tft_info.pin_tft_rst);
    Serial.print("SPI Port Active:     SPI"); Serial.println(tft_info.port);
    Serial.print("SPI Frequency (kHz): "); Serial.println(tft_info.tft_spi_freq);
    Serial.println("=========================================");
}


void loop() {
    setup_t tft_info;
    tft.getSetup(tft_info);
    Serial.println("Running...");
    Serial.println("=========================================");
    Serial.print("Library Version:     "); Serial.println(tft_info.version);
    Serial.print("Display Driver Hex:  0x"); Serial.println(tft_info.tft_driver, HEX);
    Serial.print("Configured MOSI Pin: "); Serial.println(tft_info.pin_tft_mosi);
    Serial.print("Configured MISO Pin: "); Serial.println(tft_info.pin_tft_miso);
    Serial.print("Configured SCLK Pin: "); Serial.println(tft_info.pin_tft_clk);
    Serial.print("Configured CS Pin:   "); Serial.println(tft_info.pin_tft_cs);
    Serial.print("Configured DC Pin:   "); Serial.println(tft_info.pin_tft_dc);
    Serial.print("Configured RST Pin:  "); Serial.println(tft_info.pin_tft_rst);
    Serial.print("SPI Port Active:     SPI"); Serial.println(tft_info.port);
    Serial.print("SPI Frequency (kHz): "); Serial.println(tft_info.tft_spi_freq);
    Serial.println("=========================================");
    delay(10000);
}
*/
