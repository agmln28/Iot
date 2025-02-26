#include <Arduino.h>

// Pin GPIO yang terhubung ke LED
#define LED_RED 25     // Pin GPIO 25 untuk LED merah
#define LED_YELLOW 26  // Pin GPIO 26 untuk LED kuning
#define LED_GREEN 27   // Pin GPIO 27 untuk LED hijau

void setup() {
  // Inisialisasi Serial Monitor
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  // Set pin LED sebagai output
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  // Matikan semua LED di awal
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
}

void loop() {
  // Nyalakan LED merah selama 30 detik
  Serial.println("LED Merah Menyala");
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
  delay(30000); // 30 detik

  // Nyalakan LED kuning selama 5 detik
  Serial.println("LED Kuning Menyala");
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_GREEN, LOW);
  delay(5000); // 5 detik

  // Nyalakan LED hijau selama 20 detik
  Serial.println("LED Hijau Menyala");
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, HIGH);
  delay(20000); // 20 detik
}
