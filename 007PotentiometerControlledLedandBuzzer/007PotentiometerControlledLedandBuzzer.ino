const int buzzerPin=11;
const int ledPin=9;
const int potPin=A0;

void setup() {

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);

}

void loop() {

  int value=analogRead(potPin);
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(value);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
  delay(value);
  
}
