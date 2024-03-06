#include <IRremote.h>
#include <IRremoteInt.h>
#define IR_RECEIVE_PIN 2

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

}

void loop() {
  // put your main code here, to run repeatedly:
if (IrReceiver.decode()) {
  uint16_t command = IrReceiver.decodedIRData.command;
  Serial.println(command);
  delay(100);
  IrReceiver.resume();
}
}