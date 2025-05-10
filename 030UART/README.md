# **📌 UART (Universal Asynchronous Receiver-Transmitter) Projesi**  
**🔗 İletişim Protokolü:** Seri (Asenkron) Haberleşme  

---

## **📖 Proje Açıklaması**  
Bu proje, **UART protokolü** kullanılarak iki mikrodenetleyici (veya bilgisayar-arduino) arasında **seri veri iletişimi** sağlar.  

### **🎯 Temel Özellikler**  
- **Full-Duplex** iletişim (Eş zamanlı veri gönderme/alma).  
- **Baud Rate:** 9600 (Ayarlanabilir).  
- **Kullanılan Pinler:**  
  - **TX (Transmit) ➔ RX (Receive)**  
  - **RX (Receive) ➔ TX (Transmit)**  
  - **GND (Toprak Bağlantısı)**  

---

## **🔌 Bağlantı Şeması**  
```
[GÖNDEREN CİHAZ]           [ALICI CİHAZ]  
       TX  -------------------->  RX  
       RX  <--------------------  TX  
      GND  -------------------->  GND  
```
⚠️ **DİKKAT:**  
- TX ve RX hatları **çapraz bağlanmalıdır!**  
- **Toprak (GND) bağlantısı unutulmamalıdır.**  

---

## **💻 Örnek Kodlar**  
### **1️⃣ Gönderen (Transmitter) Kodu**  
```cpp
void setup() {
  Serial.begin(9600); // Seri iletişim başlatıldı
}

void loop() {
  Serial.println("Merhaba UART!"); // Veri gönder
  delay(1000);
}
```

### **2️⃣ Alıcı (Receiver) Kodu**  
```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) { // Veri varsa
    String gelenVeri = Serial.readString(); // Veriyi oku
    Serial.print("Alınan Mesaj: ");
    Serial.println(gelenVeri); // Seri monitöre yazdır
  }
}
```

---

## **⚡ Performans ve Sınırlamalar**  
✔️ **Avantajlar:**  
- Basit ve yaygın kullanım (USB, Bluetooth, GPS, RFID).  
- Clock sinyali gerekmez (Asenkron).  

❌ **Dezavantajlar:**  
- SPI ve I²C'ye göre yavaştır.  
- Sadece iki cihaz arasında çalışır (SPI/I²C gibi çoklu bağlantı yok).  

---

## **📊 UART vs SPI vs I²C Karşılaştırması**  
| Özellik       | UART          | SPI            | I²C            |  
|--------------|--------------|---------------|---------------|  
| **Senkronizasyon** | Asenkron    | Senkron (Clock) | Senkron (Clock) |  
| **Hız**       | Düşük (115.2kbps) | Yüksek (MHz) | Orta (400kHz-3.4MHz) |  
| **Hat Sayısı** | 2 (TX+RX)   | 4 (MOSI, MISO, SCK, SS) | 2 (SDA, SCL) |  
| **Çoklu Cihaz** | ❌ Hayır   | ✔️ Evet (Slave Select) | ✔️ Evet (Adresleme) |  

---
