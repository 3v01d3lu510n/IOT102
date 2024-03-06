#include <Servo.h>
#include "SRF05.h"
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int servo_pin=3;
Servo my_servo;

const int trigger = 6;
const int echo    = 5;
SRF05 SRF(trigger, echo);


void setup()
{
  lcd.begin(16, 2);
  //di chuyen con tro chuot den cot va hang tuong ung
  lcd.setCursor(0, 0);
  // Print a message to the LCD.
  lcd.print("DIST:");
  lcd.setCursor(0, 1);
  // Print a message to the LCD.
  lcd.print("SERVO:");

  Serial.begin(9600);
  SRF.setCorrectionFactor(1.035);
  SRF.setModeAverage(5);
  my_servo.attach(servo_pin);
}


void loop(){
  //lay khoang cach
  int dist = SRF.getCentimeter();
  //cai dat hien thi led
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.setCursor(7, 0);
  lcd.print(dist);
  lcd.setCursor(11, 0);
  lcd.print("Cm");
  lcd.setCursor(0, 1);
  lcd.print("Servo: "); 
  
  if(dist>30){
    //xoay 0 do
      my_servo.write(0);
    //xoay 10 do
      my_servo.write(10);
  	  lcd.setCursor(8, 1);
      lcd.print("10"); 
  }else{
   my_servo.write(0);
   //xoay 180 do
   my_servo.write(180);
  	lcd.setCursor(8, 1);
      lcd.print("180"); 
  }
  
}



// -- END OF FILE --

