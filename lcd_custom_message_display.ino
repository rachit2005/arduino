#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

String text = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(text);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    char inchar = (char)Serial.read();
    text += inchar;

    if (inchar == '\n'){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(text);
      Serial.println(text);
      text = "";
    }
  }
}