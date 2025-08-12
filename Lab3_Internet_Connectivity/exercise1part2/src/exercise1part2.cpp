/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/gahym/EE1301/IOT_Labs/Lan3_Internet_Connectivity/exercise1part2/src/exercise1part2.ino"
/*
 * Project exercise1part2
 * Description:
 * Author:
 * Date:
 */

void setup();
void loop();
int setModeFromString(String inputString);
#line 8 "c:/Users/gahym/EE1301/IOT_Labs/Lan3_Internet_Connectivity/exercise1part2/src/exercise1part2.ino"
enum thermostat_mode_t {
    COOL,
    OFF,
    HEAT,
};
thermostat_mode_t mode = OFF;

// If you are not familiar with the “enum” construct, the above code acts
// exactly like the following three lines:
//
// #define COOL 0
// #define OFF  1
// #define HEAT 2
//
// and defining an int variable “mode” that is initialized to OFF

void setup()
{
  // register the cloud function
  // first argument is the name called from the web (12 chars or less)
  // second argument is the name of the cloud function in the program
  Particle.function("setMode", setModeFromString);
  Serial.begin(9600);
}

void loop() {

   // the loop function is called repeatedly, as long as microcontroller is turned on

}

// this function automagically gets called upon a matching POST request
// Note that the return type must be int and the argument must be a string
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
