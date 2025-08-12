/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/gahym/EE1301/IOT_Labs/Lab2_Sensors_And_Actuators/exercise2/src/exercise2.ino"
/*
 * Project exercise2
 * Description:
 * Author:
 * Date:
 */

// setup() runs once, when the device is first turned on.
void setup();
void loop();
#line 9 "c:/Users/gahym/EE1301/IOT_Labs/Lab2_Sensors_And_Actuators/exercise2/src/exercise2.ino"
int data;
void setup()
{
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