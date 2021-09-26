#include <Arduino.h>
int i;
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
  float angle = sensorValue * (270.0 / 1023.0);
  return angle;


}
/*void feedbackErrorCorrect(){
  float errorValue = requiredangle - readPositionAngle();
  Serial.print("error value is: ");
  Serial.println(errorValue);
  if(errorValue)
  int errorMapped = map(errorValue,0.0, 90.0, 255, 0);
  Serial.print("Value to be mapped : ");
  Serial.println(errorMapped);
  Serial.println();
 analogWrite(motorspeedoutput, errorMapped);

}
*/
void loop() {
  // put your main code here, to run repeatedly:
   readPositionAngle();
   Serial.print("current angle is: ");
   Serial.println(readPositionAngle());
   
   if(readPositionAngle()>2){
     Serial.println("Adjusting motor speed.....");
     Serial.println();
     for ( i= 45; i<=155;i++){

     delay(500);
     Serial.print("VALUE TO MOTOR OUTPUT:");
     Serial.println(i);
     analogWrite(motorspeedoutput,i);
     
     if (readPositionAngle()  >=2 && readPositionAngle()<=6){
       analogWrite(motorspeedoutput, 150);
       Serial.println("Motor speed and angle maintained maintained");
     }
     //feedbackErrorCorrect();
   }
   }
   else
   {
     Serial.println("Peak Overshoot,AUTOCORRECTING");
     Serial.println();
   }
  
//delay(1000);
}