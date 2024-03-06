#include <IRremote.h>
#include <IRremoteInt.h>
#define IR_RECEIVE_PIN 2

const int a=3, b=4, c=5, d=6, e=7, f=8, g=9;
int IRcommand = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
for(int i=0;i<13;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i, HIGH);
    IrReceiver.begin(2);
}
}

void num_0(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, LOW);digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void num_1(){
  digitalWrite(a, HIGH);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void num_2(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, HIGH);digitalWrite(d, LOW);
  digitalWrite(e, LOW);digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void num_3(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, HIGH);digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void num_4(){
  digitalWrite(a, HIGH);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num_5(){
  digitalWrite(a, LOW);digitalWrite(b, HIGH);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, HIGH);digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num_6(){
  digitalWrite(a, LOW);digitalWrite(b, HIGH);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, LOW);digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num_7(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void num_8(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, LOW);digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num_9(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, HIGH);digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void seg_7(int x){
  switch(x){
    case 0:num_0();break;
    case 1:num_1();break;
    case 2:num_2();break;
    case 3:num_3();break;
    case 4:num_4();break;
    case 5:num_5();break;
    case 6:num_6();break;
    case 7:num_7();break;
    case 8:num_8();break;
    case 9:num_9();break;
  }
}

unsigned long last_time = millis();
int t=0;

void loop() {
  // put your main code here, to run repeatedly:
if((millis()-last_time)>1000){
    last_time = millis();
    t--;
    if(t<0){
      t=3;
    }
    seg_7(t);
  }
if (IrReceiver.decode()) {
  uint16_t IRcommand = IrReceiver.decodedIRData.command;
  Serial.println(IRcommand);
  delay(100);
  IrReceiver.resume();
  if(IRcommand==12){
    t=0;
  }
  else if(IRcommand==16){
    t=1;
  }
  else if(IRcommand==17){
    t=2;
  }
  else if(IRcommand==18){
    t=3;
  }
  else if(IRcommand==20){
    t=4;
  }
  else if(IRcommand==21){
    t=5;
  }
  else if(IRcommand==22){
    t=6;
  }
  else if(IRcommand==24){
    t=7;
  }
  else if(IRcommand==25){
    t=8;
  }
  else if(IRcommand==26){
    t=9;
  }
  
}
}