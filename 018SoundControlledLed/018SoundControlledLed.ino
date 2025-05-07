int ledPin=9;
int sensorPin=8;
boolean ledDurum=false;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);

}

void loop() {

  int sensorDurum=digitalRead(sensorPin);
  if(sensorDurum==0){
    if(!ledDurum){
      digitalWrite(ledPin, HIGH);
      ledDurum=true;
    }
    else if(ledDurum){
      digitalWrite(ledPin, LOW);
      ledDurum=false;
    }
    delay(50);
  }
}
