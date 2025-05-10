#include <SoftwareSerial.h>

SoftwareSerial espSerial(2, 3); // RX, TX

String ssid = "WiFi_ADINIZ";
String password = "WiFi_ŞİFRENİZ";

void setup() {
  Serial.begin(9600);
  espSerial.begin(115200); // Bazı ESP'ler 9600 ile çalışabilir, kontrol edin
  delay(2000);

  Serial.println("ESP8266 Başlatılıyor...");

  sendCommand("AT", 1000);
  sendCommand("AT+CWMODE=1", 1000);
  sendCommand("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"", 5000);
  sendCommand("AT+CIFSR", 1000); // IP adresini göster
  sendCommand("AT+CIPSTART=\"TCP\",\"example.com\",80", 3000);
  sendCommand("AT+CIPSEND=44", 1000);
  sendCommand("GET / HTTP/1.1\r\nHost: example.com\r\n\r\n", 3000);
}

void loop() {
  // Loop içi boş bırakıldı
}

void sendCommand(String command, const int timeout) {
  espSerial.println(command);
  long int time = millis();
  while ((time + timeout) > millis()) {
    while (espSerial.available()) {
      char c = espSerial.read();
      Serial.write(c);
    }
  }
}
