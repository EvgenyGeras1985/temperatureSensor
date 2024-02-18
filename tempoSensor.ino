#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей

#include <OneWire.h>
#include <DallasTemperature.h>
 
#define ONE_WIRE_BUS 3

OneWire oneWire(ONE_WIRE_BUS);                                       // вход датчиков 18b20, аналоговый А1, он же 15 цифровой 
DallasTemperature sensors(&oneWire);    

void setup() {
  lcd.init();
  lcd.backlight();// Включаем подсветку дисплея
  lcd.setCursor(8, 0);
  lcd.print("TempSensor.");
  Serial.begin(9600);
  sensors.begin();                                             // инициализация
}

void loop() {

  sensors.requestTemperatures();                               // считываем температуру с датчиков, на это требуется 750мс
  
  Serial.print("Sensor : ");
  Serial.print(sensors.getTempCByIndex(0));                    // отправляем температуру
  Serial.println("C");   

  // Устанавливаем курсор на вторую строку и нулевой символ.
  lcd.setCursor(0, 1);
  // Выводим на экран количество секунд с момента запуска ардуины
  // lcd.print(millis()/1000);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print(" C");
}
