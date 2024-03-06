#include <Servo.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

Servo my_servo;
const int rs = 5, en = 4, d4 = A0, d5 = A1, d6 = A2, d7 = A3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[rows] = {13, 12, 11, 10};
byte colPins[cols] = {9, 8, 7, 6};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

String Password = String("");

void setup() {
  lcd.begin(16, 2);
  my_servo.attach(3);
  my_servo.write(0);
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), reset, RISING);
}

void readString(int address) {
  char data[5];
  int length = 0;
  char tempChar;
  tempChar = EEPROM.read(address);
  while (tempChar != '\0' && length < 4) {
    tempChar = EEPROM.read(address + length);
    data[length] = tempChar;
    length++;
  }
  data[length] = '\0';
  Password = String(data);
}

void writeString(int address, String data) {
  int _size = data.length();
  for (int i = 0; i < _size; i++) {
    EEPROM.write(address + i, data[i]);
  }
  EEPROM.write(address + _size, '\0'); // Add termination null character for String Data
}

void reset() {
  lcd.setCursor(0, 1);
  writeString(7, "0000");
  Password = "0000";
  lcd.print("Key resetted    ");
  lcd.setCursor(0, 1);
  delay(5000);
  lcd.print("                ");
}

void resetPassword() {
  int n = 0;
  lcd.clear();
  String key = "";
  lcd.setCursor(0, 0);
  lcd.print("Enter new key:");
  for (int i = 0; i < 4;) {
    char customKey = keypad.getKey();
    if (isdigit(customKey) && customKey != NO_KEY) {
      i++;
      lcd.setCursor(n++, 1);
      lcd.print(customKey);
      key += customKey;
    }
  }
  writeString(7, key);
  Password = key;
  delay(100);
}

void enter() {
  while (true) {
    int n = 0;
    lcd.clear();
    String key = "";
    lcd.setCursor(0, 0);
    lcd.print("Enter key:");
    for (int i = 0; i < 4;) {
      char customKey = keypad.getKey();
      if (isdigit(customKey) && customKey != NO_KEY) {
        i++;
        lcd.setCursor(n++, 1);
        lcd.print(customKey);
        key += customKey;
      }
    }

    delay(100);
    if (key != Password) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Key is incorrect");
      delay(1000);
      continue;
    }
    writeString(7, Password);
    if (Password == "0000") {
      resetPassword();
      continue;
    }
    openDoor();
    lockDoor();
    return;
  }
}

void openDoor() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Key is correct");
  lcd.setCursor(0, 1);
  lcd.print("Opening door...");
  for (int pos = 0; pos <= 90; pos += 1) {
    my_servo.write(pos);
    
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Door opened.");
  lcd.setCursor(0, 1);
  lcd.print("Press * to lock.");
}

void lockDoor() {
  while (true) {
    char key = keypad.getKey();
    if (key == '*') {
      break;
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Closing door...");
  for (int pos = 90; pos >= 0; pos -= 1) {
    my_servo.write(pos);
    
  }
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Door is locked.");
  lcd.setCursor(0, 1);
  lcd.print("Press * to open.");

  char key = keypad.getKey();
  if (key != NO_KEY) {
    Serial.println(key);
  }
  if (key == '*') {
    readString(7);
    if (Password.compareTo("") == 0) {
      writeString(7, "0000");
      Password = "0000";
    }
    enter();
  }
}