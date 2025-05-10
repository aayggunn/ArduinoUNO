#include <Servo.h>
Servo myServo;
int val;

void setup() {

  myServo.attach(9);
  Serial.begin(9600);

}

void loop() {

  if(Serial.available() > 0){

    val = Serial.read();
    myServo.write(val);

  }
  delay(15);
  
}
