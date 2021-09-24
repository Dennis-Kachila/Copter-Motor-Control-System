#include <Arduino.h>
const int positionValue = A5;
const int motorspeedoutput = 10;
const float requiredangle = 90.0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(motorspeedoutput, OUTPUT);
}

float readPositionAngle(){
  int sensorValue = analogRead(positionValue);
  float angle = sensorValue * (90.0 / 1023.0);
  return angle;


}
void feedbackErrorCorrect(){
  float errorValue = requiredangle - readPositionAngle();
  Serial.print("error value is: ");
  Serial.println(errorValue);
  int errorMapped = map(errorValue,0.0, 90.0, 0, 255);
  Serial.print("Value to be mapped : ");
  Serial.println(errorMapped);
  Serial.println();
 analogWrite(motorspeedoutput, errorMapped);

}
void loop() {
  // put your main code here, to run repeatedly:
   readPositionAngle();
   Serial.print("current angle is: ");
   Serial.println(readPositionAngle());
   if(readPositionAngle()<=90){
     Serial.println("adjusting motor speed");
     Serial.println();
     feedbackErrorCorrect();
   }
   else
   {
     Serial.println("Peak Overshoot,AUTOCORRECTING");
     Serial.println();
   }
delay(1000);
}