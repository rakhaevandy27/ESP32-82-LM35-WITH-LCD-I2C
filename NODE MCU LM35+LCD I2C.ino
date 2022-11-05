#include <LiquidCrystal_I2C.h>
// Konstruk object LCD dengan alamat I2C
// Ganti 0x3F sesuai dengan alamat I2C modul kalian
// Jika tidak tahu dapat menggunakan LCD I2C Scanner
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() {
  lcd.init();
  Serial.begin(9600); 
  lcd.begin(16,2);
  lcd.backlight();
}
 
void loop() 
{
  float vref = 3.3;
  float resolution = vref/1023.0;
  float temperature = analogRead(A0);

  temperature = (temperature*resolution);
  temperature = temperature*100;

  Serial.print("suhu :");
  Serial.println(temperature);

  lcd.setCursor(2, 0);
  lcd.print("TEMPERATURE");
  lcd.setCursor(4, 1);
  lcd.print(temperature);
  lcd.print(" C");
  delay(3000);

  if (temperature >= 60)
  {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("OVERHEATING");
    delay(3000);
  }
  else if (temperature >= 55)
  {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("PANAS");
    delay(3000);
  }
  else if (temperature >= 38)
  {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("DINGIN");
    delay(3000);
  }

  }