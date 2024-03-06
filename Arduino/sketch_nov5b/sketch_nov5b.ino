#include <IRremote.h>
#include <IRremoteInt.h>
#define IR_RECEIVE_PIN 2

const int a=3, b=4, c=5, d=6, e=7, f=8, g=9;
int IRcommand = 0;
int mapCodeToButton(unsigned long code) {
  // For the remote used in the Tinkercad simulator,
  // the buttons are encoded such that the hex code
  // received is of the format: 0xiivvBF00
  // Where the vv is the button value, and ii is
  // the bit-inverse of vv.
  // For example, the power button is 0xFF00BF000

  // Check for codes from this specific remote
  if ((code & 0x0000FFFF) == 0x0000BF00) {
    // No longer need the lower 16 bits. Shift the code by 16
    // to make the rest easier.
    code >>= 16;
    // Check that the value and inverse bytes are complementary.
    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
      return code & 0xFF;
    }
  }
  return -1;
}

int readInfrared() {
  int result = -1;
  // Check if we've received a new code
  if (IrReceiver.decode()) {
    // Get the infrared code
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    // Map it to a specific button on the remote
    result = mapCodeToButton(code);
    // Enable receiving of the next value
    IrReceiver.resume();
  }
  return result;
}

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
  }
}

void loop() {
  // put your main code here, to run repeatedly:
IRcommand = readInfrared();
  if(IRcommand==12){
    seg_7(0);
  }
  else if(IRcommand==16){
    seg_7(1);
  }
  else if(IRcommand==17){
    seg_7(2);
  }
  else if(IRcommand==18){
    seg_7(3);
  }
  else if(IRcommand==20){
    seg_7(4);
  }
  else if(IRcommand==21){
    seg_7(5);
  }
  else if(IRcommand==22){
    seg_7(6);
  }
  else if(IRcommand==24){
    seg_7(7);
  }
  else if(IRcommand==25){
    seg_7(8);
  }
  else if(IRcommand==26){
    seg_7(9);
  }
}