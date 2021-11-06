/*
The project involving controlling the speed of BLDC motor using a PWM signal from arduino board and a potentiometer which 
which is connected to the arduino board and act as a feedback sensor to control the speed of the motor.

*/
#include <Arduino.h>


//Declaring the pins for the arduino board
int pwmPin = 9;
int feedbackPin = A0;
//declare a float value for angle and set it to 0
float angle = 4.5;


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
    
      //use while loop to increase the value of pwmPin by 1 at a time
      while(feedback_value > angle)
      {
            analogWrite(pwmPin, i);
            delay(100);
            Serial.print("feedback value is ");
              Serial.print(feedback_value);
              Serial.print("\n");
              Serial.print("i is ");
              Serial.print(i);
              Serial.print("\n");
            //check if the feedback value is greater than the angle value
                if(feedback_value < angle)
                  {
                     Serial.print("feedback value is ");
                      Serial.print(feedback_value);
                      Serial.print("\n");
                      Serial.print("i is ");
                      Serial.print(i);
                      Serial.print("\n");
                    //if the feedback value is greater than the angle value, make the pwmPin value constant i.e analogWrite(pwmPin, i) using a while loop
                    while(feedback_value < angle)
                    {
                      analogWrite(pwmPin, i);
                      delay(100);
                     
                    }

                   
                  }
                  //increase the value of i by 1 in the loop
                  i++;
    }
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  compare_feedback();

}
