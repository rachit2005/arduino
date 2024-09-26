#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

String text = "";
#define trig 12
#define echo 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(text);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig ,LOW);
  delayMicroseconds(200);
  digitalWrite(trig ,HIGH);
  delayMicroseconds(100);
  digitalWrite(trig ,LOW);

  long allTime = pulseIn(echo , HIGH);
  int distance = 0.0343 * (allTime/2) ;

  text = "Distace = " + String(distance) +"cm";

  Serial.print("Distance = ");
  Serial.println(distance);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(text);
  delay(250);

  if (distance > 15){
    lcd.setCursor(0,1);
    lcd.print("more than 15 cm");
    delay(1000); 
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("less than 15");
    delay(1000); 
  }

}

