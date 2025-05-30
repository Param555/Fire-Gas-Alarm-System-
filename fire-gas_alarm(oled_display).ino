#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Servo gate1;
Servo gate2;

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

    // Initialize OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println("System Loading...");
    display.display();

    for (int a = 0; a <= 15; a++) {
        display.setCursor(10 + a * 5, 30);
        display.print(".");
        display.display();
        delay(200);
    }

    display.clearDisplay();
    display.display();

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

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Gas Level:");

    display.setTextSize(2);
    display.setCursor(0, 20);
    display.println(gasLevel);

    if (gasLevel > threshold) {
        gate1.write(90);
        gate2.write(90);
        Serial.println("Emergency Gates are Opened");

        display.setCursor(0, 45);
        display.setTextSize(2);
        display.println("FIRE ALERT");

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
    }

    display.display();
    delay(1000); 
}
