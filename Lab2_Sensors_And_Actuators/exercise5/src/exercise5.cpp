/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/gahym/EE1301/IOT_Labs/Lab2_Sensors_And_Actuators/exercise5/src/exercise5.ino"
void setup();
void loop();
#line 1 "c:/Users/gahym/EE1301/IOT_Labs/Lab2_Sensors_And_Actuators/exercise5/src/exercise5.ino"
int ButtonPIN = D2;
int PotPIN = A2;

bool ButtonLast;
int PotOut = 0;
bool ButtonNow = FALSE;
int ButtonCount = 0;

void setup() {
    pinMode(ButtonPIN, INPUT_PULLDOWN);
    pinMode(PotPIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    
    PotOut = analogRead(PotPIN);

    ButtonNow = digitalRead(ButtonPIN);

    if(ButtonNow == HIGH && ButtonLast == LOW) {
    
        Serial.print("Button Count = ");
        Serial.print(ButtonCount);
        Serial.print(" , Level = ");
        Serial.println(PotOut);

        
        ButtonLast = HIGH;
    } else if (ButtonNow == LOW) {
        ButtonLast = LOW;
    }
}


