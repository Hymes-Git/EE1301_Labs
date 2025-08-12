/*
 * Project exercise6
 * Description:
 * Author:
 * Date:
 */

#include "neopixel.h"

int ButtonPIN = D2;   // sets the input button to read from pin digital 2
bool ButtonNow = FALSE;  // sets the initial status of the button to be not pressed

int PIXEL_PIN = D4;   // pin the pixel data is sent to
int PIXEL_COUNT = 2;   // number of LEDs
int PIXEL_TYPE = WS2811;  // types of LEDs

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// setup() runs once, when the device is first turned on.
void setup() {
  pinMode(ButtonPIN, INPUT_PULLDOWN);
  strip.begin();
  Serial.begin(9600);
  // Put initialization like pinMode and begin functions here.

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {


ButtonNow=digitalRead(ButtonPIN);   // sets the button now variable to read from the pin the button sends data to

if (ButtonNow == HIGH) {   // if the button is pressed the lights are turned on

 int PixelColorBlue = strip.Color(   0 , 0, 255);   // variable PixelColorBlue is set to output a blue color
    int PixelColorYellow  = strip.Color(  244,   232,   104);  // variable PixelColorYellow is set to output a yellow color
  
    strip.setPixelColor(0, PixelColorBlue);  // sets the first LED to be blue
    strip.setPixelColor(1, PixelColorYellow);   // sets the second LED to be yellow
    strip.show();  // changes the lights
}

else {   // if the button is not pressed turns the lights off

int PixelColorOff = strip.Color(0,0,0);   // sets the variable PixelColorOff to output no light

strip.setPixelColor(0, PixelColorOff);  // sets the lights to be off
    strip.setPixelColor(1, PixelColorOff);
    strip.show();  // changes the lights

}

  // The core of your code will likely live here.

}