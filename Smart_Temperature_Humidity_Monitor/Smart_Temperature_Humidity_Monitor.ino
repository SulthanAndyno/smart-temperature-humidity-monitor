
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// Konfigurasi OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// Konfigurasi DHT11
#define DHT_PIN 4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);

  // Inisialisasi I2C ESP32
  Wire.begin(21, 22);

  // Inisialisasi OLED
  if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS)) {
    Serial.println("OLED tidak terdeteksi!");
    while (true) {
      delay(100);
    }
  }

  // Inisialisasi sensor
  dht.begin();

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Monitoring IoT");
  display.println("DHT11 + OLED");
  display.println();
  display.println("Memulai sensor...");
  display.display();

  delay(2000);
}

void loop() {
  // Baca suhu dan kelembapan
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Cek apakah pembacaan valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Gagal membaca DHT11!");

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("ERROR SENSOR!");
    display.println("Periksa wiring DHT11");
    display.display();

    delay(2000);
    return;
  }

  // Tampilkan di Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.print(" C | Kelembapan: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Tampilkan di OLED
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("MONITORING SUHU");

  display.drawLine(0, 12, 127, 12, SSD1306_WHITE);

  display.setCursor(0, 19);
  display.print("Suhu: ");
  display.setTextSize(2);
  display.print(temperature, 1);
  display.setTextSize(1);
  display.println(" C");

  display.setCursor(0, 39);
  display.print("Hum : ");
  display.setTextSize(2);
  display.print(humidity, 1);
  display.setTextSize(1);
  display.println(" %");

  display.drawLine(0, 56, 127, 56, SSD1306_WHITE);
  display.setCursor(0, 57);
  display.print("ESP32 | DHT11");

  display.display();

  delay(2000);
}
