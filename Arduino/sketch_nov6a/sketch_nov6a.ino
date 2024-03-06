#include <IRremote.h>
#include <IRremoteInt.h>
#define IR_RECEIVE_PIN 2

const int a = 3;
const int b = 4;
const int c = 5;
const int d = 6;
const int e = 7;
const int f = 8;
const int g = 9;

const int red = 12; // Red
const int yellow = 11; // Yellow
const int green = 10; // Green LED

unsigned long previousMillis = 0;
unsigned long interval = 1000; // 1 second
int countdown = 0;
int IRcommand = 12;

void setup() {
  for (int thisPin = 2; thisPin <= 12; thisPin++) {
    pinMode(thisPin, OUTPUT);
    digitalWrite(thisPin, LOW);
    IrReceiver.begin(2);
  }
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  // red Light
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  countdown;

  while (countdown >= 0) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      digital_display(countdown);
      countdown--;
    }
  }

  // Yellow Light
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  countdown;

  while (countdown >= 0) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      digital_display(countdown);
      countdown--;
    }
  }

  // green Light
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  countdown;

  while (countdown >= 0) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      digital_display(countdown);
      countdown--;
    }
  }

  if (IrReceiver.decode()) {
  uint16_t IRcommand = IrReceiver.decodedIRData.command;
  Serial.println(IRcommand);
  delay(100);
  IrReceiver.resume();

  if(IRcommand==12){
    countdown=0;
  }
  else if(IRcommand==16){
    countdown=1;
  }
  else if(IRcommand==17){
    countdown=2;
  }
  else if(IRcommand==18){
    countdown=3;
  }
  else if(IRcommand==20){
    countdown=4;
  }
  else if(IRcommand==21){
    countdown=5;
  }
  else if(IRcommand==22){
    countdown=6;
  }
  else if(IRcommand==24){
    countdown=7;
  }
  else if(IRcommand==25){
    countdown=8;
  }
  else if(IRcommand==26){
    countdown=9;
  }
  }
}

void digital_display(int number) {
  switch (number) {
    case 0:
      digital_0();
      break;
    case 1:
      digital_1();
      break;
    case 2:
      digital_2();
      break;
    case 3:
      digital_3();
      break;
    case 4:
      digital_4();
      break;
    case 5:
      digital_5();
      break;
    case 6:
      digital_6();
      break;
    case 7:
      digital_7();
      break;
    case 8:
      digital_8();
      break;
  }
}

void digital_0() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void digital_1() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void digital_2() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void digital_3() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void digital_4() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void digital_5() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void digital_6() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void digital_7() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void digital_8() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}