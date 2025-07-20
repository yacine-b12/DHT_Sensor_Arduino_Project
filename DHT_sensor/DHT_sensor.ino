#include "DHT.h" 
#include <LiquidCrystal.h>

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd_1(12, 11, 6, 5, 4, 3);

void setup() {
  dht.begin();
  lcd_1.begin(16, 2);
}
void loop() {
  lcd_1.print("Temp: " + String(dht.readTemperature())+"'C");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Hum: " + String(dht.readHumidity())+"%");
  delay(1000);
  lcd_1.clear();
}
