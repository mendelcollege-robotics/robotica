#include <Arduino.h>

int pwmPin = 3; //pin for PWM output
int pwmacc = 1000; //how accurate the PWM is, means you can enter value from 0 to the value of pwmacc
int PWMval = 0; //value of the PWM, means you can enter value from 0 to the value of pwmacc


void setup() {
}
void setup() {
  
  Timer3.initialize(800);  // 800 microseconds or 1.25Hz
  Timer3.attachInterrupt(updatePWM);
}

void updatePWM() {
  static int counter = 0;
  if PWMval < 0) {
    PWMval = 0;
  }
  if (PWMval > pwmacc) {
    PWMval = pwmacc;
  }

  if (counter < PWMval) {
    digitalWrite(pwmPin, HIGH);
  } else {
    digitalWrite(pwmPin, LOW);
  }

  counter++;
  if (counter >= pwmacc) {
    counter = 0;
  }
}

void loop() {
  for i (0; i < pwmacc; i++) {
    PWMval = i;
    delay(10);
  }
  for i (pwmacc; i > 0; i--) {
    PWMval = i;
    delay(10);
  }
}