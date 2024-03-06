int numLEDs = 11; // Số lượng LED
int delayTime = 500; // Thời gian trễ (milliseconds)

void setup() {
  for (int i = 2; i < numLEDs; i += 2) {
    pinMode(i, OUTPUT); // Cài đặt chân LED chẵn là đầu ra
  }
  for (int i = 1; i < numLEDs; i += 2) {
    pinMode(i, OUTPUT); // Cài đặt chân LED lẻ là đầu ra
  }
}

void loop() {
  for (int i = 2; i <= numLEDs; i += 2) {
    digitalWrite(i, HIGH); // Bật LED chẵn
    delay(delayTime);
    digitalWrite(i, LOW); // Tắt LED chẵn
  }
  
  for (int i = 1; i = numLEDs; i += 2) {
    digitalWrite(i, HIGH); // Bật LED lẻ
    delay(delayTime);
    digitalWrite(i, LOW); // Tắt LED lẻ
  }
}
