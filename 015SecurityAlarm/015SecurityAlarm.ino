int sensorPin = 9;
int buzzerPin = 11;
int ledPin = 8;

void setup() {

  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {

  int deger = digitalRead(sensorPin);
  Serial.println(deger);

  if (deger == HIGH) 
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(100);
  } 
  else 
  {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(100);
  }

}
