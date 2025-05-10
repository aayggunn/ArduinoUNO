Here's a professional bilingual README.md with parallel Turkish/English content and enhanced technical details:

# **📌 UART Haberleşme Projesi / UART Communication Project**  
**🔗 İletişim Protokolü / Communication Protocol:**  
Seri (Asenkron) Haberleşme / Serial (Asynchronous) Communication

---

## **📖 Proje Açıklaması / Project Description**  
Bu proje, iki mikrodenetleyici (veya bilgisayar-Arduino) arasında **UART protokolü** kullanarak seri veri iletişimini gösterir. Temel seri haberleşme prensiplerini anlamak için idealdir.

This project demonstrates **serial data transfer** between two microcontrollers (or computer-Arduino) using the **UART protocol**, ideal for understanding fundamental serial communication principles.

---

### **🎯 Temel Özellikler / Key Features**  
| Türkçe | English |
|--------|---------|
| • **Full-Duplex** iletişim (Eş zamanlı veri gönderme/alma) | • **Full-Duplex** communication (Simultaneous transmit/receive) |
| • **Ayarlanabilir Baud Hızı** (Varsayılan: 9600 bps) | • **Adjustable Baud Rate** (Default: 9600 bps) |
| • **Donanım UART** kullanımı (Yazılımsal çözümlerden daha kararlı) | • **Hardware UART** implementation (More reliable than software solutions) |
| • **Hata tespiti** için parity bit desteği | • Parity bit support for **error detection** |

---

## **🔌 Bağlantı Şeması / Connection Diagram**
```
[GÖNDEREN CİHAZ/TRANSMITTER]    [ALICI CİHAZ/RECEIVER]
           TX  -------------------->  RX
           RX  <--------------------  TX
          GND  -------------------->  GND
```

⚠️ **ÖNEMLİ NOTLAR / IMPORTANT NOTES:**  
- TX ve RX hatları **her zaman çapraz bağlanmalıdır**  
- **Toprak bağlantısı (GND)** her iki cihaz arasında ortak olmalıdır  
- Uzun mesafelerde **RS-232/RS-485 dönüştürücü** kullanılması önerilir  

- TX and RX lines **must always be cross-connected**  
- **Ground connection (GND)** must be shared between both devices  
- For long distances, **RS-232/RS-485 converters** are recommended  

---

## **💻 Örnek Kodlar / Example Codes**
### **1️⃣ Gönderen Kodu / Transmitter Code**
```cpp
// Türkçe Açıklama:
// Seri port üzerinden 1 saniyede bir mesaj gönderir

// English Description:
// Sends a message every second via serial port

void setup() {
  Serial.begin(9600); // Baud hızı ayarı / Set baud rate
}

void loop() {
  Serial.println("Veri gönderiliyor.../Sending data...");
  delay(1000); // 1 saniye bekle / Wait 1 second
}
```

### **2️⃣ Alıcı Kodu / Receiver Code**
```cpp
// Türkçe Açıklama:
// Gelen seri veriyi okuyup ekrana yazdırır

// English Description:
// Reads incoming serial data and prints to screen

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readString();
    Serial.print("Alınan veri/Received data: ");
    Serial.println(data);
  }
}
```

---

## **⚡ Teknik Detaylar / Technical Details**
### **Baud Rate Hesaplaması / Baud Rate Calculation**
```
Örnek/Example: 9600 bps için/for 16MHz kristal/16MHz crystal:
UBRR = (F_CPU/(16*BAUD))-1 = (16000000/(16*9600))-1 = 103
```

### **Veri Formatı / Data Format**
```
[Start Bit] | [8 Data Bits] | [Parity Bit (optional)] | [Stop Bit(s)]
```

---

## **📊 Protokol Karşılaştırması / Protocol Comparison**
| Özellik/Feature | UART | SPI | I²C |
|----------------|------|-----|-----|
| **Senkronizasyon/Sync** | Asenkron/Async | Senkron/Sync | Senkron/Sync |
| **Maks. Hız/Max Speed** | 115.2kbps | 10Mbps+ | 3.4Mbps |
| **Hat Sayısı/Lines** | 2 (TX+RX) | 4 | 2 |
| **Mesafe/Distance** | 15m (RS-232) | <1m | <1m |

---
