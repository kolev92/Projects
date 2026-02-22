#include <LiquidCrystal.h>
#include <NewPing.h>
#define TRIGGER_PIN  11
#define ECHO_PIN     12
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Distance Sensor");
}

void loop() {
 delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
  lcd.setCursor(0,1);
  lcd.print("Distance:");
  lcd.print(sonar.ping_cm());
  lcd.print("cm  ");
}
