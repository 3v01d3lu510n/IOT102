#include <EEPROM.h>
#include "EEPROM.h"

void setup() {
  // put your setup code here, to run once:
  EEPROM.write(100,99);
  int i = EEPROM.read(100);


}

void loop() {
  // put your main code here, to run repeatedly:

}
