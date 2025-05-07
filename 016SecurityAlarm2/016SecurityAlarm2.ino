int sensorPin=9;
int buzzerPin=11;
int ledPin=8;

void setup() {

  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {

  int deger=digitalRead(sensorPin);
  if(deger==HIGH){
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(50);
  }
  
}
