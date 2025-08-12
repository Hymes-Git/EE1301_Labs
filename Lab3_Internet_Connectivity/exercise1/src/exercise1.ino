/*
 * Project exercise1
 * Description:
 * Author:
 * Date:
 */


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