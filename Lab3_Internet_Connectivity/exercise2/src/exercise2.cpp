/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/gahym/EE1301/IOT_Labs/Lan3_Internet_Connectivity/exercise2/src/exercise2.ino"
/*
 * Project Exercise 2 (Change LED Based on TEMP or HTML)
 * Description:
 * Author: Grant Hymes Hymes019
 * Date: 3-18-22 EE1301
 */

#include "neopixel.h"

void setup();
void loop();
int setModeFromString(String inputString);
#line 10 "c:/Users/gahym/EE1301/IOT_Labs/Lan3_Internet_Connectivity/exercise2/src/exercise2.ino"
enum thermostat_mode_t {
    COOL,
    OFF,
    HEAT,
};
thermostat_mode_t mode = OFF;

int PIXEL_PIN = D4;
int PIXEL_COUNT = 1;
int PIXEL_TYPE = WS2811;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int data;

void setup()
{
  strip.begin();
Particle.variable("TempSensor", data);
Particle.function("setMode", setModeFromString);
Serial.begin(9600);
pinMode(D7, OUTPUT);
pinMode(A0, INPUT);

}

void loop()
{

int PixelColorRed = strip.Color(   255 , 0, 0);
    int PixelColorGreen  = strip.Color(  0,   255,   0);
    int PixelColorBlue = strip.Color(  0,  0,   255);

if (mode == COOL) {strip.setPixelColor(0, PixelColorBlue);}
else if (mode == OFF) {strip.setPixelColor(0, PixelColorGreen);}
else if (mode == HEAT) {strip.setPixelColor(0, PixelColorRed);}

strip.show();

digitalWrite(D7, HIGH);
delay(10);
data = analogRead(A0);
digitalWrite(D7, LOW);
Serial.print(data);
Serial.print(",");
Serial.print((data-620)/12.4);
Serial.print(",");
Serial.print(mode);
Serial.println(";");
delay(1000);



if (data < 900) {mode = HEAT;}
else if (data > 930) {mode = COOL;}
else {mode = OFF;}

if (mode == COOL) {strip.setPixelColor(0, PixelColorBlue);}
else if (mode == OFF) {strip.setPixelColor(0, PixelColorGreen);}
else if (mode == HEAT) {strip.setPixelColor(0, PixelColorRed);}

strip.show();

}



int setModeFromString(String inputString)
{
    if (inputString == "Cool") {
        mode = COOL;
        return 1;
    } else if (inputString == "Off" ) {
        mode = OFF;
        return 1;
    } else if (inputString == "Heat") {
        mode = HEAT;
        return 1;
    } else {
        Serial.print("Invalid Mode: ");
        Serial.println(inputString);
        return -1;
    }
}