//LIBRARY
#include <LiquidCrystal_I2C.h>

// Ganti 0x3F sesuai dengan alamat I2C modul kaliaN
//pin scl -> d2
//pin sda -> d3
//pin vcc -> vcc/5v/3v (recommend 3.3v)
//pin gnd -> gnd
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() {
  //SERIAL AND LCD INIT
  lcd.init();
  Serial.begin(9600); 
  lcd.begin(16,2);
  lcd.backlight();
}
 
void loop() 
{
  float vref = 3.3;
  float resolution = vref/1023.0;
  float temperature = analogRead(A0);//pin A0 sebagai input
  
 //KALKULASI SUHU
  temperature = (temperature*resolution);
  temperature = temperature*100;
  
 //SERIAL OUT
  Serial.print("suhu :");
  Serial.println(temperature);
  
  //LCD OUT
  lcd.setCursor(2, 0);
  lcd.print("TEMPERATURE");
  lcd.setCursor(4, 1);
  lcd.print(temperature);
  lcd.print(" C");
  delay(3000);
 
  //LOGIKA SUHU
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
