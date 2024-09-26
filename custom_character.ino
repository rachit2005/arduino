#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);
uint8_t custom[] = {0x0a, 0x1f, 0x0e, 0x04, 0x00, 0x00, 0x00, 0x00};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.createChar(0,custom);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(byte(0));
}

void loop() {
  // put your main code here, to run repeatedly:

}
// --> https://deepbluembedded.com/lcd-custom-character-generator/
