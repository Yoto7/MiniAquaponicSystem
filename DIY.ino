#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
int i;
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
pinMode (2, OUTPUT);
digitalWrite(2, LOW);
pinMode (19, OUTPUT);
digitalWrite(19, LOW);
pinMode (32, OUTPUT);
digitalWrite(32, HIGH);
pinMode (33, OUTPUT);
digitalWrite(33, HIGH);
adcAttachPin (34);
Serial.begin(9600);
lcd.init();
lcd.backlight();
Serial.println(("DIY Home Automation-Yoto Yotov!"));
Serial.print(("LED 1= "));
Serial.println(digitalRead(32));
Serial.print(("LED 2= "));
Serial.println(digitalRead(33));
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
Serial.print(("moisture= "));
Serial.println(moisture);
delay(5000);
if(moisture>3800 && moisture <=4095)
digitalWrite(15,HIGH);
else
digitalWrite(15,LOW);
Serial.print(("Relay1= "));
Serial.println(digitalRead(15));
delay(1000);
if(moisture>3800 && moisture <=4095)
digitalWrite(2,HIGH);
else
digitalWrite(2,LOW);
Serial.print(("Relay2= "));
Serial.println(digitalRead(2));


int pinState=i;

i++;
Serial.print(("i= "));
Serial.println(pinState);
Serial.print(("Relay3= "));
Serial.println(digitalRead(19));
if (i>3) {
digitalWrite(19,HIGH);
delay(5000);
Serial.print(("Relay3= "));
Serial.println(digitalRead(19));

i=0;
digitalWrite(19,LOW);
Serial.print(("Relay3= "));
Serial.println(digitalRead(19));
}


}
