# Smart Temperature & Humidity Monitor

Proyek monitoring suhu dan kelembapan udara berbasis ESP32. Sensor DHT11 membaca kondisi udara secara real-time, lalu hasilnya ditampilkan pada layar OLED 128×64 dan Serial Monitor.

## Deskripsi

ESP32 berperan sebagai pengolah data, DHT11 sebagai sensor, dan OLED I2C sebagai media tampilan. Proyek ini merupakan tahap awal sistem monitoring lingkungan dan dapat dikembangkan lebih lanjut dengan mengirimkan data melalui Wi-Fi ke dashboard IoT.

## Komponen

- ESP32 Dev Module
- Sensor DHT11 3-pin
- OLED I2C 128×64 (SSD1306, alamat 0x3C)
- Kabel jumper dan breadboard
- Kabel USB untuk pemrograman dan daya

## Koneksi Rangkaian

| Komponen | Pin ESP32 |
|---|---|
| DHT11 Plus (+) | 3V3 |
| DHT11 OUT | GPIO 4 |
| DHT11 Minus (−) | GND |
| OLED VCC | 3V3 |
| OLED GND | GND |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |

## Cara Kerja

1. Saat dinyalakan, ESP32 menginisialisasi bus I2C (SDA 21, SCL 22), layar OLED, dan sensor DHT11, lalu menampilkan pesan pembuka selama 2 detik.
2. Setiap 2 detik ESP32 membaca suhu (°C) dan kelembapan (%) dari DHT11.
3. Jika pembacaan gagal, OLED menampilkan pesan "ERROR SENSOR!" dan Serial Monitor mencetak "Gagal membaca DHT11!".
4. Jika pembacaan berhasil, nilai suhu dan kelembapan ditampilkan pada OLED dengan satu angka desimal dan dicetak ke Serial Monitor (baud rate 115200).

Jika OLED tidak terdeteksi saat inisialisasi, program berhenti dan mencetak "OLED tidak terdeteksi!" ke Serial Monitor.

## Perangkat Lunak

- Arduino IDE dengan board package ESP32 (Espressif Systems)
- DHT sensor library (Adafruit)
- Adafruit Unified Sensor
- Adafruit SSD1306
- Adafruit GFX Library

Semua library dapat dipasang melalui Library Manager di Arduino IDE.

## Menjalankan

1. Rangkai komponen sesuai tabel koneksi di atas.
2. Buka `Smart_Temperature_Humidity_Monitor/Smart_Temperature_Humidity_Monitor.ino` di Arduino IDE.
3. Pilih board ESP32 Dev Module dan port yang sesuai.
4. Upload program ke ESP32.
5. Buka Serial Monitor dengan baud rate 115200 untuk melihat hasil pembacaan.

## Struktur Repository

```
.
├── README.md
└── Smart_Temperature_Humidity_Monitor/
    └── Smart_Temperature_Humidity_Monitor.ino
```

## Tujuan Proyek

- Mempelajari penggunaan sensor DHT11.
- Memahami pemrograman ESP32 menggunakan Arduino IDE.
- Menampilkan data sensor pada OLED melalui komunikasi I2C.
- Memahami dasar pengembangan sistem monitoring lingkungan berbasis mikrokontroler.

## Pengembangan Selanjutnya

- Mengirimkan data melalui Wi-Fi ke dashboard IoT.
- Menyimpan riwayat pembacaan untuk analisis tren suhu dan kelembapan.

## Kesimpulan

Sistem berhasil membaca suhu dan kelembapan menggunakan DHT11 dan menampilkannya pada OLED serta Serial Monitor. Proyek ini menjadi dasar untuk pengembangan sistem monitoring lingkungan yang terhubung ke jaringan.
