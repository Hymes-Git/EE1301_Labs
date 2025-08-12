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

int A =0;

// setup() runs once, when the device is first turned on.
void setup() {
    strip.begin();
}


// loop() runs over and over again, as quickly as it can execute.
void loop() {

if(A>250) {A=0;}

    /* NOTE: Two versions of the color code are specified below for WS2811 and 
             WS2812 neopixels. Use the version according to the type of neopixels in 
             your kit and delete or comment the other version. */
    //Setup some colors, WS2811 version
    int PixelColorGreen = strip.Color(   0 , A, 0);
    int PixelColorRed  = strip.Color(  A,   0,   0);
    int PixelColorBlue = strip.Color(  0,  0,   A);
    //Setup some colors, WS2812 version
    /*
    int PixelColorCyan = strip.Color(   255 , 0, 255);
    int PixelColorRed  = strip.Color(  0,   80,   0);
    int PixelColorGold = strip.Color(  50,  60,   5);
    */

    //Set first pixel to cyan
    strip.setPixelColor(0, PixelColorRed);
    //set second pixel to red
    strip.setPixelColor(1, PixelColorGreen);
    //set third pixel to Gopher Gold!
    strip.setPixelColor(2, PixelColorBlue);
    strip.show();
    delay(1000);  //wait 1sec
   
A = A + 50;
    


}

