#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

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

const char *correctPassword = "1234"; // Mật khẩu của bạn
char enteredPassword[5] = "";
int passwordAttempts = 0; // Số lần thử nhập mật khẩu
unsigned long lastPasswordEntryTime = 0;
bool countingDown = false;
unsigned long countDownStartTime;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Input:    ");
  lcd.setCursor(0, 1);
  lcd.print("Status:    ");
  my_servo.attach(3);
  my_servo.write(10); // Góc quay ban đầu của servo
}

void loop() {
  char key = keypad.getKey();

  if (!countingDown) {
    if (key != NO_KEY) {
      if (isdigit(key)) {
        if (strlen(enteredPassword) < 4) {
          enteredPassword[strlen(enteredPassword)] = key;
          lcd.setCursor(7 + strlen(enteredPassword) - 1, 0);
          lcd.print('*');
        }
      }
    }
  }

  if (strlen(enteredPassword) == 4) {
    if (strcmp(enteredPassword, correctPassword) == 0) {
      // Mật khẩu đúng, quay servo 180 độ
      my_servo.write(180);
      lcd.setCursor(8, 1);
      lcd.print("Ok       ");
      lastPasswordEntryTime = millis(); // Lưu thời gian nhập mật khẩu đúng
    } else {
      // Mật khẩu sai
      passwordAttempts++;
      lcd.setCursor(8, 1);
      lcd.print("Wrongpass");

      if (passwordAttempts >= 3) {
        // Đã nhập sai 3 lần, bắt đầu đếm ngược 7 giây
        countingDown = true;
        countDownStartTime = millis();
      }
    }

    // Xóa mật khẩu đã nhập
    memset(enteredPassword, 0, sizeof(enteredPassword));
    lcd.setCursor(7, 0);
    lcd.print("    ");
    delay(2000); // Hiển thị trạng thái trong 2 giây trước khi xóa
    lcd.setCursor(8, 1);
    lcd.print("          ");
  }

  if (countingDown) {
    unsigned long elapsedTime = millis() - countDownStartTime;
    if (elapsedTime < 7000) {
      lcd.setCursor(0, 1);
      lcd.print("Countdown: " + String(7 - elapsedTime / 1000) + "  ");
    } else {
      countingDown = false;
      passwordAttempts = 0; // Reset số lần thử
      lcd.setCursor(0, 1);
      lcd.print("Status:    ");
      lcd.setCursor(7, 1);
      lcd.print("      ");
    }
  }

  // Kiểm tra nếu đã đúng mật khẩu và đã qua 3 giây
  if (lastPasswordEntryTime > 0 && millis() - lastPasswordEntryTime >= 3000) {
    my_servo.write(10); // Quay servo về vị trí ban đầu
    lastPasswordEntryTime = 0; // Reset thời gian
  }
}