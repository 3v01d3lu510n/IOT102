// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo my_servo;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //di chuyen con tro chuot den cot va hang tuong ung
  lcd.setCursor(5, 0);
  // Print a message to the LCD.
  lcd.print("Group6");
  pinMode(13,OUTPUT);
  my_servo.attach(3);
}

void loop() {
  int adc0_val = analogRead(A1);
  lcd.setCursor(0, 1);
  // Print a message to the LCD.
  lcd.print("ADC:");
  lcd.setCursor(5, 1);
  lcd.print("          ");
  lcd.setCursor(5, 1);
  lcd.print(adc0_val);
  lcd.setCursor(9, 1);
  lcd.print("LED:");
  lcd.setCursor(13, 1);
    lcd.print("     ");
  if(adc0_val>680){
    lcd.setCursor(13, 1);
    lcd.print("ON");
    digitalWrite(13,HIGH);
  }
  else{
    lcd.setCursor(13, 1);
    lcd.print("OFF");
    digitalWrite(13,LOW);
  }
  my_servo.write(10);
  delay(1000);
  my_servo.write(180);
}