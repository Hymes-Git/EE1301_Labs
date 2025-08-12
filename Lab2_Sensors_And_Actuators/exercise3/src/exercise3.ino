/*
 * Project exercise3
 * Description:
 * Author:
 * Date:
 */

#include "neopixel.h"



// These lines of code should appear AFTER the #include statements, and before
// the setup() function.
// IMPORTANT: Set pixel COUNT, PIN and TYPE
int PIXEL_PIN = D4;
int PIXEL_COUNT = 3;
int PIXEL_TYPE = WS2811;
// int PIXEL_TYPE = WS2812;
// WS2812 NOTE: use WS2812 if you have them

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// setup() runs once, when the device is first turned on.
void setup() {
    strip.begin();
}


// loop() runs over and over again, as quickly as it can execute.
void loop() {
    /* NOTE: Two versions of the color code are specified below for WS2811 and 
             WS2812 neopixels. Use the version according to the type of neopixels in 
             your kit and delete or comment the other version. */
    //Setup some colors, WS2811 version
    int PixelColorCyan = strip.Color(   0 , 255, 255);
    int PixelColorRed  = strip.Color(  80,   0,   0);
    int PixelColorGold = strip.Color(  60,  50,   5);
    //Setup some colors, WS2812 version
    /*
    int PixelColorCyan = strip.Color(   255 , 0, 255);
    int PixelColorRed  = strip.Color(  0,   80,   0);
    int PixelColorGold = strip.Color(  50,  60,   5);
    */

    //Set first pixel to cyan
    strip.setPixelColor(0, PixelColorCyan);
    //set second pixel to red
    strip.setPixelColor(1, PixelColorRed);
    //set third pixel to Gopher Gold!
    strip.setPixelColor(2, PixelColorGold);
    strip.show();
    delay(1000);  //wait 1sec

    //flip the red and gold
    strip.setPixelColor(0, PixelColorCyan);
    strip.setPixelColor(1, PixelColorGold);
    strip.setPixelColor(2, PixelColorRed);
    strip.show();
    delay(1000);  //wait 1sec
}

