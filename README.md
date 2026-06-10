*WORK IN PROGRESS* 

A handheld photo viewer, for my parents, built from scratch: custom PCB, code, LiPo battery powered. Photos are stored on an SD card and browsed using three physical buttons. The device preprocesses BMP images directly from the SD card, downscales depending on the resolution with a Pico PI, and writes the file back in RGB565. This device also features an HID controller. 

The challenge here isn't just displaying an image but it's doing it on hardware where the image file is larger than available RAM(264 KB). Since Iphone images are often 12MP, the files can take up 4000*3000*3 = 36MB which far exceeds the available RAM.


Component Details:

PCBCustom designed in KiCad w/ SMD resistors and capacitors
MicrocontrollerRaspberry Pi Pico (RP2040, 264KB RAM)
Display320×480 TFT ST7796
RGB565 over SPIStorageSD card via SPI (SdFat library)
Protected PowerLiPo cell 
TP4056 charging circuit
tactile buttons

PCB

Single board design integrating the Pico, TFT connector, SD card connector, TP4056 charging circuit, JST LiPo connector, and three navigation buttons.

SPI communication with TFT and SD card reader

Power architecture routes the battery directly to VSYS for battery-powered operation while the TP4056 handles charging from USB. Decoupling capacitors on power rails.

How it works:


Phase 1: Pre-processing  (runs once per image)(This is the part that is incomplete)

When a BMP file is first encountered, the Pico processes it into a 320×480 RGB565 file:

Seek in the BMP file headers to get source width, height, and pixel data offset;

Calculate horizontal and vertical scale ratios: srcWidth / 320, srcHeight / 480

For each output row, read the corresponding N source rows and area-average them into 320 output pixels

Convert each averaged pixel from BMP's BGR byte order to RGB565

Write the line back to the SD card



Phase 2: Display/HID control

State machine that controls what buttons do: 

Displays each Image based on the button input,

Buttons scroll through a character displayed on the top left in order to choose a letter;

Loading screen and Preprocessing


Whats done so Far:

PCB and Wiring tested to confirm its working
Display RGB565 and Full Screen rendering and Tested with test_image_565.cpp
HID control is working, although planning to add more functions Later
Outline for all the other functions to be added state machine




 








