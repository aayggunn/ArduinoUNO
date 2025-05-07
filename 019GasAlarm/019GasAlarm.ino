int mavi=9;
int yesil=10;
int kirmizi=11;
int sensorPin=A0;

void setup() {

  pinMode(mavi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(kirmizi, INPUT);
  Serial.begin(9600);

}

void loop() {

  int deger = analogRead(sensorPin);
  Serial.println(deger);
  
  if(deger>750){
    digitalWrite(kirmizi, HIGH);
    digitalWrite(yesil, LOW);
    digitalWrite(mavi, LOW);
  }
  else if(400<deger<750){
    digitalWrite(kirmizi, LOW);
    digitalWrite(yesil, LOW);
    digitalWrite(mavi, HIGH);
  }
  else {
    digitalWrite(kirmizi, LOW);
    digitalWrite(yesil, HIGH);
    digitalWrite(mavi, LOW);
  }

}
