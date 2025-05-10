
# **📌 I2C (Inter-Integrated Circuit) Haberleşme Projesi**  
# **📌 I2C Communication Project**  

---

## **📖 Proje Açıklaması / Project Description**  
Bu proje, bir ana (master) ve bir/çok köle (slave) cihaz arasında **I2C protokolü** kullanarak veri iletişimini gösterir. Sensörler, bellek modülleri ve diğer çevre birimleriyle haberleşme için idealdir.

This project demonstrates **data communication** between one master and one/multiple slave devices using the **I2C protocol**, ideal for communicating with sensors, memory modules and peripherals.

---

### **🎯 Temel Özellikler / Key Features**  

| Türkçe | English |
|--------|---------|
| • **2 kablolu tasarım** (SDA + SCL) | • **2-wire design** (SDA + SCL) |
| • **Çoklu cihaz desteği** (Adresleme mekanizması) | • **Multi-device support** (Addressing mechanism) |
| • **Senkron iletişim** (Clock hatlı) | • **Synchronous communication** (Clock line) |
| • **7-bit/10-bit adresleme** | • **7-bit/10-bit addressing** |
| • **400kHz hıza kadar** (Fast Mode) | • **Up to 400kHz speed** (Fast Mode) |

---

## **🔌 Bağlantı Şeması / Connection Diagram**
```
[MASTER CİHAZ]    [SLAVE CİHAZ 1]    [SLAVE CİHAZ 2]
     SDA <===========> SDA <===========> SDA
     SCL <===========> SCL <===========> SCL
    GND <===========> GND <===========> GND
```

⚠️ **ÖNEMLİ NOTLAR / IMPORTANT NOTES:**  
- **Pull-up dirençleri** (4.7kΩ typical) SDA ve SCL hatlarına eklenmelidir  
- Her slave cihazın **benzersiz bir adresi** olmalıdır  
- Toplam kapasitif yük **400pF'ı geçmemelidir**  

- **Pull-up resistors** (4.7kΩ typical) must be added to SDA and SCL lines  
- Each slave device must have a **unique address**  
- Total capacitive load **should not exceed 400pF**  

---

## **💻 Örnek Kodlar / Example Codes**

### **1️⃣ Master Cihaz Kodu / Master Device Code**
```cpp
#include <Wire.h>

// Türkçe Açıklama:
// I2C master olarak slave cihaza veri gönderir

// English Description:
// Sends data to slave device as I2C master

void setup() {
  Wire.begin(); // Master olarak başlat / Initialize as master
}

void loop() {
  Wire.beginTransmission(0x68); // Slave adresi / Slave address
  Wire.write("Merhaba I2C!");   // Veri gönder / Send data
  Wire.endTransmission();       // İletimi bitir / End transmission
  delay(1000);
}
```

### **2️⃣ Slave Cihaz Kodu / Slave Device Code**
```cpp
#include <Wire.h>

// Türkçe Açıklama:
// I2C slave olarak gelen veriyi işler

// English Description:
// Processes incoming data as I2C slave

void setup() {
  Wire.begin(0x68);            // Slave adresi / Slave address
  Wire.onReceive(receiveEvent); // Callback fonksiyonu / Callback function
  Serial.begin(9600);
}

void loop() {
  delay(100);
}

void receiveEvent(int bytes) {
  while(Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
}
```

---

## **⚡ Teknik Detaylar / Technical Details**

### **I2C Adresleme / I2C Addressing**
```
7-bit format: [ 7 bit adres | R/W bit ]
Örnek/Example: 0x68 (1101000) + 0 (write) = 0xD0
```

### **Veri Çerçevesi / Data Frame**
```
[START] | [SLAVE ADDRESS] | [R/W] | [ACK] | [DATA] | [ACK]... | [STOP]
```

---

## **📊 Protokol Karşılaştırması / Protocol Comparison**

| Özellik/Feature | I2C | SPI | UART |
|----------------|-----|-----|------|
| **Hız/Speed** | 400kHz-3.4MHz | 10MHz+ | 115.2kbps |
| **Hat Sayısı/Lines** | 2 | 4+ | 2 |
| **Çoklu Cihaz/Multi-device** | ✔️ (Adresleme/Addressing) | ✔️ (Slave Select) | ❌ |
| **Mesafe/Distance** | <1m | <1m | 15m+ |

---
