#include <LiquidCrystal.h>

#define LED_PIN 9
#define LDR_PIN A0
#define POT_PIN A1

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // (RS, E, DB4, DB5, DB6, DB7)

void setup() {
  lcd.begin(3, 1);
  lcd.setCursor(0, 0);
  
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int lightness = analogRead(LDR_PIN);

  lightness = map(lightness, 0, 1023, 100, 900);
  lightness = map(lightness, 100, 900, 255, 0);

  lcd.clear();
  lcd.print(lightness);

  analogWrite(LED_PIN, lightness);
  delay(300);
}