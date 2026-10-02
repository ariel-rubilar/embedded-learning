#include <Arduino.h>

namespace {

constexpr uint8_t kLedPin = 32;
constexpr uint32_t kBlinkIntervalMs = 500;

}

void setup() {
  pinMode(kLedPin, OUTPUT);
  digitalWrite(kLedPin, LOW);
}

void loop() {
  digitalWrite(kLedPin, HIGH);
  delay(kBlinkIntervalMs);

  digitalWrite(kLedPin, LOW);
  delay(kBlinkIntervalMs);
}