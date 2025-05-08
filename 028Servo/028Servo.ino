#include <Servo.h>

Servo myservo;  
int servoPin = 9;
int pos = 0;    

void setup() {
  myservo.attach(servoPin); 
}

void loop() {
  
  for (pos = 0; pos <= 180; pos += 5) {
    myservo.write(pos);  
    delay(20);           
  }
  
  for (pos = 180; pos >= 0; pos -= 5) {
    myservo.write(pos);
    delay(20);
  }
}