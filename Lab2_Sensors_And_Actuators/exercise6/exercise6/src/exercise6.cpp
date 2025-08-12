/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/gahym/EE1301/IOT_Labs/Lab2_Sensors_And_Actuators/exercise6/exercise6/src/exercise6.ino"
/*
 * Project exercise6
 * Description:
 * Author:
 * Date:
 */

#include "neopixel.h"

void setup();
void loop();
#line 10 "c:/Users/gahym/EE1301/IOT_Labs/Lab2_Sensors_And_Actuators/exercise6/exercise6/src/exercise6.ino"
bool ButtonLast;
int ButtonPIN = D2;
bool ButtonNow = FALSE;

int PIXEL_PIN = D4;
int PIXEL_COUNT = 2;
int PIXEL_TYPE = WS2811;

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


ButtonNow=digitalRead(ButtonPIN);

if (ButtonNow == HIGH) {

 int PixelColorBlue = strip.Color(   0 , 0, 255);
    int PixelColorYellow  = strip.Color(  244,   232,   104);
  
    strip.setPixelColor(0, PixelColorBlue);
    strip.setPixelColor(1, PixelColorYellow);
    strip.show();
}

else {

int PixelColorOff = strip.Color(0,0,0);

strip.setPixelColor(0, PixelColorOff);
    strip.setPixelColor(1, PixelColorOff);
    strip.show();

}

Serial.print(ButtonNow);

  // The core of your code will likely live here.

}