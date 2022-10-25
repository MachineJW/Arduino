#include <DHT.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 14

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHT11);

void setup() {
  lcd.backlight();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("TEST setup");
  lcd.setCursor(0, 1);
  lcd.print("made by hong");
  dht.begin();
  delay(3000);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TEM : ");
  lcd.print(dht.readTemperature());
  lcd.setCursor(0, 1);
  lcd.print("HUM : ");
  lcd.print(dht.readHumidity());
  delay(2000);
}