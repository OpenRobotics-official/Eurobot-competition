#include <Servo.h>


int value = 90; // set values you need to zero
int motor = 90;

Servo firstESC, secondESC; //Create as much as Servoobject you want. You can controll 2 or more Servos at the same time

void setup() {

  firstESC.attach(12);    // attached to pin 9 I just do this with 1 Servo
  Serial.begin(9600);    // start serial at 9600 baud

}

void loop() {

//First connect your ESC WITHOUT Arming. Then Open Serial and follo Instructions
 
  firstESC.write(motor);
 
  if(Serial.available())
  {
    Serial.println("Received");
    value = Serial.parseInt();    // Parse an Integer from Serial
    if(value==0)
    {
        motor=85;
        Serial.println("Brake! (85)");
    }
    else
    {
    if ((motor-value)<0)
    {
    for (motor=motor; motor<value; motor++)
    {
      firstESC.write(motor);
      delay(10);
    }
    Serial.println(motor);
    }
    if((motor-value)>0)
        {
        for (motor=motor; motor>value; motor--)
        {
          firstESC.write(motor);
          delay(10);
        }
        Serial.println(motor);
        }
    }
    }
}
