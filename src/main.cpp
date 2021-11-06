/*
The project involving controlling the speed of BLDC motor using a PWM signal from arduino board and a potentiometer which 
which is connected to the arduino board and act as a feedback sensor to control the speed of the motor.

*/
#include <Arduino.h>


//Declaring the pins for the arduino board
int pwmPin = 9;
int feedbackPin = A0;
//declare a float value for angle and set it to 0
float angle = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pwmPin, OUTPUT);
  pinMode(feedbackPin, INPUT);
}

float read_feedback()
{
  float feedback_value = analogRead(feedbackPin);
  return feedback_value;
}

void compare_feedback()
{
  float feedback_value = read_feedback();
  if(feedback_value > angle)
  {
    //increase the value of pwmPin from 0 to 255 sequentially using for loop
    for(int i = 0; i < 255; i++)
    {
     
      analogWrite(pwmPin, i);
      delay(1);
       Serial.print("feedback value is ");
        Serial.print(feedback_value);
        Serial.print("\n");
        Serial.print("i is ");
        Serial.print(i);
        Serial.print("\n");
      //check if the feedback value is greater than the angle value
      if(feedback_value < angle)
      {
        //if the feedback value is greater than the angle value, break the loop
        //print the value of feedback value and i to serial monitor
        Serial.print("feedback value is ");
        Serial.print(feedback_value);
        Serial.print("\n");
        Serial.print("i is ");
        Serial.print(i);
        Serial.print("\n");

        break;
      }
    }
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  compare_feedback();

}
