/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/gahym/EE1301/IOT_Labs/Lab4_Simple_Multitasking/lab4exercise1/src/lab4exercise1.ino"
// This program blinks the on board LED (D7) at different rates
// When the button is pressed, the rate of blinking changes.
// Use state variables to store the previous button value and the current blinking rate

// Define the pins we are going to use
void setup();
void loop();
#line 6 "c:/Users/gahym/EE1301/IOT_Labs/Lab4_Simple_Multitasking/lab4exercise1/src/lab4exercise1.ino"
int led = D7;    // The D7 on-board LED
int button = D3; // This is the input button (use an internal pull-down resistor)
int LedFreqState = 0;   // set to 0 for 0.50 Hz, set to 1 for 0.25 Hz
int prevButton = LOW;   // state variable to store if button was HIGH or LOW last time

// creates variables to store the toggle time for each different button frequency
unsigned long int timeToToggle0;
unsigned long int timeToToggle1;
unsigned long int timeToToggle2;
unsigned long int timePrint;

bool ledState = false;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(button, INPUT_PULLDOWN);  // INPUT mode with internal pull-down resistor
    Serial.begin(9600);               // Use Serial port for debugging


    // sets the time to toggle for each different button rate
    timeToToggle0 = millis() + 500;
    timeToToggle1 = millis() + 1000;
    timeToToggle2 = millis() + 2000;
    timePrint = millis() + 1000;

    



}

void loop() {
    unsigned long int currentTime = millis();



// manages the button presses and changing the LED frequency state
    int curButton = digitalRead(button);
    if(curButton == HIGH && prevButton == LOW){
        // a transition happened -- the user has just pressed the button
        Serial.println("Button press detected.");  //Debugging printout
        
        // change the state of the LED blinking rate
        LedFreqState++;
        if(LedFreqState > 2){  // make sure it changes from 0 --> 1 --> 2 --> 0 -->  ...
            LedFreqState = 0;
        }
    }
  
prevButton = curButton; // keep track of the last button pressed

      if(currentTime > timePrint){  
    Serial.print(curButton);  // Debugging printout
    Serial.print(LedFreqState);
    timePrint = timePrint + 1000;

      }






    if(LedFreqState == 0){  // Rate 0: 1.0 Hz (on 0.5 sec, off 0.5 sec)

      if(currentTime > timeToToggle0){  
        // Time to Toggle!
        ledState = !ledState;
        digitalWrite(led, ledState);
        
  timeToToggle0 += 500;

    }

    }else if(LedFreqState == 1){  // Rate 1: 0.5 Hz (on 1 sec, off 1 sec)

      if(currentTime > timeToToggle1){  
        // Time to Toggle!
        ledState = !ledState;
        digitalWrite(led, ledState);

          timeToToggle1 += 1000;


    }
    }else{	              // Rate 2: 0.25Hz (2 secs on, 2 secs off)

      if(currentTime > timeToToggle2){  
        // Time to Toggle!
        ledState = !ledState;
        digitalWrite(led, ledState);
          timeToToggle2 += 2000;


    }
    }



}

