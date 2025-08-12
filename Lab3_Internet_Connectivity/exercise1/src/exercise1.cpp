/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/gahym/EE1301/IOT_Labs/Lan3_Internet_Connectivity/exercise1/src/exercise1.ino"
/*
 * Project exercise1
 * Description:
 * Author:
 * Date:
 */


void setup();
void loop();
#line 9 "c:/Users/gahym/EE1301/IOT_Labs/Lan3_Internet_Connectivity/exercise1/src/exercise1.ino"
int data;
void setup()
{
Particle.variable("TempSensor", data);
Serial.begin(9600);
pinMode(D7, OUTPUT);
pinMode(A0, INPUT);
}

void loop()
{
digitalWrite(D7, HIGH);
delay(10);
data = analogRead(A0);
digitalWrite(D7, LOW);
Serial.print(data);
Serial.print(",");
Serial.print((data-620)/12.4);
Serial.println(";");
delay(490);
}