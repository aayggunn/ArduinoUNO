const int time=20;

void setup() {

  int LedPin;
  for(LedPin=2; LedPin<10; LedPin++){
    pinMode(LedPin, OUTPUT);
  }

}

void loop() {

  int LedPin;
  for(LedPin=2; LedPin<10; LedPin++){
    digitalWrite(LedPin, HIGH);
    delay(time);
    digitalWrite(LedPin, LOW);
  }

   for(LedPin=9; LedPin>1; LedPin--){
    digitalWrite(LedPin, HIGH);
    delay(time);
    digitalWrite(LedPin, LOW);
  }
}
