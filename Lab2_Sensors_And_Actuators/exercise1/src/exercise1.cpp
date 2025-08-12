/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/gahym/EE1301/IOT_Labs/Lab2_Sensors_And_Actuators/exercise1/src/exercise1.ino"
// IOT Lab 2 Exercise 1
// Grant Hymes
// EE1301

void setup();
void loop();
#line 5 "c:/Users/gahym/EE1301/IOT_Labs/Lab2_Sensors_And_Actuators/exercise1/src/exercise1.ino"
int data0;

void setup() {
  // Put initialization like pinMode and begin functions here.

  // Open the serial port for communication with the computer
  Serial.begin(9600);

    // Setup D7 pin to output a heartbeat
 pinMode(D7, OUTPUT);



}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

  // Heartbeat, show we're alive
  digitalWrite(D7, HIGH);
  delay(250);

    // Read data from analog pins (returns a number from 0 to 4095)
  data0 = analogRead(A1);

    // Print the data to the serial port
  Serial.print("My Data is: ");
  Serial.print(data0);
  Serial.println(";");

  // Heartbeat, show we're alive
  digitalWrite(D7, LOW);
  delay(250);

}