#include <IRremote.h>
#include <IRremoteInt.h>
#include "SevSeg.h"

SevSeg sevseg;
#define IR_RECEIVE_PIN 2
#define RED_LED_PIN 10
#define YELLOW_LED_PIN 11
#define GREEN_LED_PIN 12

int redDuration = 5;    // Initial red light duration in seconds
int greenDuration = 5;  // Initial green light duration in seconds
int yellowDuration = 2; // Initial yellow light duration in seconds
unsigned long previousMillis = 0;
int currentLight = RED_LED_PIN; // Start with red light
int remainingTime = redDuration;

void setup() {
  Serial.begin(9600);

  byte numDigits = 1;
  byte digitPins[] = {13}; // Define the digit pin for 7-segment display
  byte segmentPins[] = {3, 4, 5, 6, 7, 8, 9};
  bool resistorsOnSegments = true;
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // Initialize the display with the default time (red light)
  sevseg.setNumber(redDuration);
  sevseg.refreshDisplay();
}

void loop() {
  // Check for IR remote input here and update the durations accordingly

  if (IrReceiver.decode()) {
    // Update the durations based on the remote input
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0xA55A38C7: // Remote button for "1"
        redDuration = 5;
        yellowDuration = 2;
        greenDuration = 5;
        break;
      case 0xA55AA857: // Remote button for "2"
        redDuration = 8;
        yellowDuration = 2;
        greenDuration = 8;
        break;
      // Add more cases for other numbers as needed
    }

    remainingTime = redDuration;
    IrReceiver.resume();
  }

  unsigned long currentMillis = millis();

  if (currentLight == RED_LED_PIN) {
    if (currentMillis - previousMillis >= redDuration * 1000) {
      currentLight = YELLOW_LED_PIN;
      previousMillis = currentMillis;
      remainingTime = yellowDuration;
    }
  } else if (currentLight == YELLOW_LED_PIN) {
    if (currentMillis - previousMillis >= yellowDuration * 1000) {
      currentLight = GREEN_LED_PIN;
      previousMillis = currentMillis;
      remainingTime = greenDuration;
    }
  } else if (currentLight == GREEN_LED_PIN) {
    if (currentMillis - previousMillis >= greenDuration * 1000) {
      currentLight = RED_LED_PIN;
      previousMillis = currentMillis;
      remainingTime = redDuration;
    }
  }

  // Update the LED states
  digitalWrite(RED_LED_PIN, currentLight == RED_LED_PIN);
  digitalWrite(YELLOW_LED_PIN, currentLight == YELLOW_LED_PIN);
  digitalWrite(GREEN_LED_PIN, currentLight == GREEN_LED_PIN);

  // Update and display the time on the 7-segment display
  sevseg.setNumber(remainingTime);
  sevseg.refreshDisplay();
}