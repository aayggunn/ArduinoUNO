const int ledPin = 9;
const int LDRPin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Seri monitör başlatılıyor
}

void loop() {
  int deger = analogRead(LDRPin);

  // Işık değeri seri monitöre yazdırılıyor
  Serial.print("LDR Degeri: ");
  Serial.println(deger);

  // Eşik değeri: 900 (daha düşük = karanlık)
  if (deger < 900) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500); // Aşırı veri akışını azaltmak için küçük bekleme
}
