# **📌 Bluetooth (BT) Modülü ve AT Komutları Projesi**  
# **📌 Bluetooth Module and AT Commands Project**  

---

## **📖 Proje Açıklaması / Project Description**  
Bu proje, **HC-05/HC-06** gibi Bluetooth modülleriyle AT komutları kullanarak haberleşmeyi ve temel ayarları gösterir. Cihaz adı, PIN kodu, baud hızı gibi parametreleri değiştirmek için kullanılabilir.  

This project demonstrates communication with **HC-05/HC-06** Bluetooth modules using AT commands for basic configurations like device name, PIN code, and baud rate.  

---

### **🎯 Temel Özellikler / Key Features**  
| Türkçe | English |
|--------|---------|
| • AT komutları ile modül yapılandırması | • Module configuration via AT commands |
| • Baud hızı değiştirme (9600, 115200 vb.) | • Baud rate adjustment (9600, 115200 etc.) |
| • Cihaz adı ve PIN kodu ayarlama | • Set device name and PIN code |
| • Master/Slave mod değişikliği | • Master/Slave mode switching |

---

## **🔌 Bağlantı Şeması / Connection Diagram**
```
[ARDUINO]    [BLUETOOTH MODÜLÜ]
      RX --------------------> TX
      TX --------------------> RX
      GND -------------------> GND
      5V --------------------> VCC
```
⚠️ **DİKKAT / NOTE:**  
- **RX-TX bağlantıları çapraz olmalıdır!**  
- **HC-05** modülleri genellikle **3.3V** ile çalışır, gerilim bölücü kullanın!  

- **RX-TX connections must be crossed!**  
- **HC-05** modules typically run on **3.3V**, use a voltage divider!  

---

## **💻 AT Komutları / AT Commands**
### **Temel Komutlar / Basic Commands**
| Komut | Açıklama | Command | Description |
|-------|----------|---------|-------------|
| `AT`  | Bağlantı testi | `AT` | Connection test |
| `AT+NAME?` | Cihaz adını göster | `AT+NAME?` | Show device name |
| `AT+NAME=YENI_AD` | Ad değiştir | `AT+NAME=NEW_NAME` | Change name |
| `AT+PSWD?` | PIN kodunu göster | `AT+PSWD?` | Show PIN code |
| `AT+PSWD="1234"` | PIN değiştir | `AT+PSWD="1234"` | Change PIN |
| `AT+UART?` | Baud hızını göster | `AT+UART?` | Show baud rate |

---

## **⚡ Örnek Kod / Example Code**
```cpp
void setup() {
  Serial.begin(9600);   // Bilgisayarla iletişim / PC communication
  Serial1.begin(38400); // Bluetooth modülü ile iletişim / BT module communication
  delay(1000);
  Serial.println("AT komut moduna girin...");
  Serial.println("Enter AT command mode...");
}

void loop() {
  // Bilgisayardan Bluetooth'a veri iletme
  // Forward data from PC to Bluetooth
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }
  
  // Bluetooth'tan bilgisayara veri iletme
  // Forward data from Bluetooth to PC
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
}
```

---

## **📋 Kullanım Talimatları / Usage Instructions**
1. **AT Moduna Geçiş:**  
   - HC-05: Modül üzerindeki butona basılı tutarak enerji verin  
   - HC-06: Direkt AT komutlarına yanıt verir  

   **Enter AT Mode:**  
   - HC-05: Power on while holding the button  
   - HC-06: Responds to AT commands directly  

2. **Baud Hızı Uyumu:**  
   - Varsayılan baud hızı genellikle **38400** (HC-05) veya **9600** (HC-06)  

   **Baud Rate Note:**  
   - Default is typically **38400** (HC-05) or **9600** (HC-06)  

---

- [HC-05 Datasheet](https://www.olimex.com/Products/Components/RF/BLUETOOTH-SERIAL-HC-05/resources/hc05.pdf)  
- [AT Command List](https://www.microchip.ua/wireless/hc_bluetooth.pdf)
