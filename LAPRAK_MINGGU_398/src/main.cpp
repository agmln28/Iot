#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 14        
#define DHTTYPE DHT22
#define LDR_PIN 34      

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 20, 4); 

int cahaya_adc = analogRead(LDR_PIN);
int cahaya_lux = map(cahaya_adc, 0, 1023, 0, 1000); // Konversi ADC ke lux

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("   Sistem Monitoring");
  delay(2000);
  lcd.clear();
}

void loop() {
  float suhu = dht.readTemperature();   
  float kelembapan = dht.readHumidity();
  int cahaya_adc = analogRead(LDR_PIN);
  int cahaya_lux = map(cahaya_adc, 0, 1023, 0, 1000); // Sesuaikan sesuai slider simulator

  // Tampilkan di Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" C | Kelembapan: ");
  Serial.print(kelembapan);
  Serial.print(" % | Cahaya: ");
  Serial.println(cahaya_lux);
  

  // Tampilkan di LCD
  lcd.setCursor(0, 0);
  lcd.print("Suhu     : ");
  lcd.print(suhu, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Kelembapan: ");
  lcd.print(kelembapan, 1);
  lcd.print(" %");

  lcd.setCursor(0, 2);
  lcd.print("Cahaya   : ");
  lcd.print(cahaya_lux);
  lcd.print(" lux");

  lcd.setCursor(0, 3);
  lcd.print("Monitoring Aktif...");

  delay(2000);
}
