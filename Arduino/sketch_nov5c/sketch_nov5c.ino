#include <LiquidCrystal.h>
#include <Servo.h>

const int trig = 9;
const int echo = 8;
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
int select = 0;
bool changeToManual = false;
bool flag = true;

int i = 0;
int value = 0;
int servoPos = 0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo radar;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  lcd.begin(16, 2);
  radar.attach(13);
  attachInterrupt(digitalPinToInterrupt(2), blink, RISING);
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  if(flag){
    display("WELCOME TO THE","BOAT CAPTAIN");
    delay(500);
    flag =false;
  }
  if (select == 0) {
    automode();
  }else {
    nonautomode();
  }
}

float ultrasonic() {
  unsigned long duration;
  float distance;

  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);

  duration = pulseIn(echo, HIGH);
  distance = duration / 2 * 0.0344;
  return distance;
}

void display(String x1, String x2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(x1);
  lcd.setCursor(0, 1);
  lcd.print(x2);
}

void blink() {
  select = !select;
  changeToManual = (changeToManual)?false:true;
  if(!changeToManual){
    i = servoPos;
  }
}

void automode() {
  display("Auto","");
  int d;
  for (i; i <= 180; i++) {
    if(changeToManual){
      break;
    }
    radar.write(i);
    delay(30);
    d = (int)ultrasonic();
    tone(d);
    Serial.print(i);
    Serial.print(",");
    Serial.print(d);
    Serial.print(".");
  }
  for (i; i >= 0; i -= 1) {
    if(changeToManual){
      break;
    }
    radar.write(i);
    delay(30);
    d = (int)ultrasonic();
    tone(d);
    Serial.print(i);
    Serial.print(",");
    Serial.print(d);
    Serial.print(".");
  }
}

void nonautomode() {
  value = analogRead(A0);
  servoPos = map(value, 0, 1023, 0, 180);
  radar.write(servoPos);
  int d = (int)ultrasonic();
  tone(d);
  Serial.print(servoPos);
  Serial.print(",");
  Serial.print(d);
  Serial.print(".");
  display("Manual","");
}

void tone(int d) {
  if (d < 40) {
    tone(3, 1000);
    delay(10);
    noTone(3);
  }
}
