/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/gahym/EE1301/IOT_Labs/Lan3_Internet_Connectivity/exercise3/src/exercise3.ino"
/*
 * Project Exercise 3
 * Description:
 * Author: Lily Hymes Hymes019
 * Date: 3-19-22 EE1301
 */

#include "neopixel.h"


void setup();
void loop();
int setModeFromString(String inputString);
int setTempFromString(String inputString);
#line 11 "c:/Users/gahym/EE1301/IOT_Labs/Lan3_Internet_Connectivity/exercise3/src/exercise3.ino"
enum thermostat_mode_t {
    COOL,
    OFF,
    HEAT,
    REDALERT,
};
thermostat_mode_t mode = OFF;

int PIXEL_PIN = D4;
int PIXEL_COUNT = 1;
int PIXEL_TYPE = WS2811;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int tempData;
int tempDataConverted;
int desiredTemp;
String strTemp;
int sinceLastPub;

void setup()
{
  strip.begin();
Particle.variable("current_temp", tempDataConverted);
Particle.variable("desired_temp", desiredTemp);
Particle.function("setMode", setModeFromString);
Particle.function("set_temp", setTempFromString);
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
else if (mode == REDALERT) {Particle.publish ("RedAlert");}


strip.show();

digitalWrite(D7, HIGH);
delay(10);
tempData = analogRead(A0);
tempDataConverted = ((tempData-620) / 12.4);
digitalWrite(D7, LOW);
Serial.print(tempData);
Serial.print(",");
Serial.print(tempDataConverted);
Serial.print(",");
Serial.print(mode);
Serial.println(";");
delay(1000);

strTemp = String (tempDataConverted);

if (sinceLastPub > 10) {
Particle.publish("GrantTemp", strTemp);
sinceLastPub = 0;
}
else {++sinceLastPub;}


if (tempData < 900) {mode = HEAT;}
else if (tempData > 930  && tempData < 990) {mode = COOL;}
else if (tempData > 989) {mode = REDALERT;}
else {mode = OFF;}

if (mode == COOL) {strip.setPixelColor(0, PixelColorBlue);}
else if (mode == OFF) {strip.setPixelColor(0, PixelColorGreen);}
else if (mode == HEAT) {strip.setPixelColor(0, PixelColorRed);}
else if (mode == REDALERT) {Particle.publish ("RedAlert");}

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
    } else if (inputString == "RedAlert") {
       mode = REDALERT;
      return 1;
    
    } else {
        Serial.print("Invalid Mode: ");
        Serial.println(inputString);
        return -1;
    }
}


int setTempFromString(String inputString) {

desiredTemp = inputString.toInt();
return 1;
}

