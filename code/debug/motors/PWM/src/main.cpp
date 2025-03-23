#include "SoftPWM.h"
#include <Arduino.h>

int pwmPin = 3;

void setup() {
  SoftPWMBegin();
}

void loop() {
  SoftPWMSetFadeTime(pwmPin, 2500, 2500);
  delay(1000);
}