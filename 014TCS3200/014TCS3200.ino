#define s0 8
#define s1 9
#define s2 10
#define s3 11
#define sensorPin 12

int kirmizi, yesil, mavi=0;

void setup() {

pinMode(s0, OUTPUT);
pinMode(s1, OUTPUT);
pinMode(s2, OUTPUT);
pinMode(s3, OUTPUT);
pinMode(sensorPin, INPUT);

digitalWrite(s0, HIGH);
digitalWrite(s1, LOW);
Serial.begin(9600);

}

void loop() {

digitalWrite(s2, LOW);
digitalWrite(s3, LOW);
kirmizi=pulseIn(sensorPin, LOW);
Serial.print("Kirmizi: ");
Serial.print(kirmizi);
Serial.print("\t");
delay(100);

digitalWrite(s2, HIGH);
digitalWrite(s3, HIGH);
yesil=pulseIn(sensorPin, LOW);
Serial.print("Yesil: ");
Serial.print(yesil);
Serial.print("\t");
delay(100);

digitalWrite(s2, LOW);
digitalWrite(s3, HIGH);
mavi=pulseIn(sensorPin, LOW);
Serial.print("Mavi: ");
Serial.print(mavi);
Serial.print("\t");
delay(100);

}
