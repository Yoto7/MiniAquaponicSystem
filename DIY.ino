#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); 

#define DHTPIN 18  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  // put your setup code here, to run once:
pinMode (15, OUTPUT);
digitalWrite(15, LOW);
adcAttachPin (34);
Serial.begin(9600);
lcd.init();
lcd.backlight();
Serial.println(F("DIY Home Automation-Yoto Yotov!"));
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(500);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.setCursor(0, 0);
    lcd.println (F("Failed sensor!"));
    Serial.println (F("Failed sensor!"));
    delay(10000);
    lcd.clear();
    return;
    }
  lcd.setCursor(0, 0);
  lcd.print(F("Humidity: "));
  Serial.print(F("Humidity: "));
  lcd.print(h);
  Serial.print(h);
  lcd.print(F("%"));
  Serial.print(F(" %"));
  lcd.setCursor(0,1);
  lcd.print (F("Temp.: "));
  Serial.print(F(" Temp.: "));
  lcd.print(t);
  Serial.print(t);
  lcd.print(F(" C "));
  Serial.print(F(" C "));
  delay(10000);
  lcd.clear(); 
  Serial.println();
int moisture = analogRead(34);
Serial.println(moisture);
delay(5000);
if(moisture>500 && moisture <3800)
digitalWrite(15,HIGH);
else
digitalWrite(15,LOW);
Serial.println(digitalRead(15));
}
