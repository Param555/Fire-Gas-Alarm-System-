#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include<Servo.h>
Servo gate1;
Servo gate2;
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int gasSensorPin = A3; 
const int buzzerPin = 13;      
const int led1 = 6;
const int led2 = 5;
const int led3 = 4;
const int led4 = 3;
const int led5 = 2;
const int threshold = 200; 

void setup() {
    Serial.begin(9600);
    gate1.attach(7); //servo 1
    gate2.attach(8); //servo 2
    gate1.write(0);
    gate2.write(0);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(1, 0);
  lcd.print("System Loading");
  for (int a = 0; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(200);
  }
  lcd.clear();
  
    pinMode(buzzerPin, OUTPUT); 
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
  
}

void loop() {
    int gasLevel = analogRead(gasSensorPin); 
    Serial.print("Gas Level: ");
    Serial.println(gasLevel);
    lcd.setCursor(0,0);
    lcd.print("Gas Level:");
    lcd.print(gasLevel);
    lcd.print(" ");

    if (gasLevel > threshold) {
       gate1.write(90);
       gate2.write(90);
       Serial.println("Emergency Gates are Opened");
       lcd.setCursor(0,1);
       lcd.print("Fire Alert");
       digitalWrite(buzzerPin, HIGH); 
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, HIGH);
       digitalWrite(led4, HIGH);
       digitalWrite(led5, HIGH);
     
    } else {
  
      gate1.write(0);
      gate2.write(0);
      digitalWrite(buzzerPin, LOW); 
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW); 
      digitalWrite(led3, LOW); 
      digitalWrite(led4, LOW); 
      digitalWrite(led5, LOW); 
      lcd.setCursor(0,1);
      lcd.print("                ");
    }

    delay(1000); 
}
