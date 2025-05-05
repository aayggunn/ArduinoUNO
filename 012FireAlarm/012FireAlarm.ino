int sensorPin=A2;
int buzzerPin=11;
int ledPin=2;

int sensorDeger=0;
float gerilim=0;
float sicaklik=0;

void setup() {

 pinMode(buzzerPin, OUTPUT);
 pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  sensorDeger=analogRead(sensorPin);
  gerilim=(sensorDeger/1023.0)*5000.0;
  sicaklik=gerilim/10.0;

  Serial.print("Analog Deger: ");
  Serial.print(sensorDeger);
  Serial.print(" | Gerilim: ");
  Serial.print(gerilim, 2); 
  Serial.print(" mV | Sicaklik: ");
  Serial.print(sicaklik, 1);
  Serial.println(" C");
  delay(500);

  if(sicaklik>25){
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
  }

  else{
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
  }
}
