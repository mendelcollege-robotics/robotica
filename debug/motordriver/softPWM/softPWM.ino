#include <TimerThree.h>
#include <Arduino.h>

int pwmPin = 3;

volatile int PWMval = 0;   // PWM value 0-100

void setup() {
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600);

  Timer3.initialize(800); // 800 microseconds or 1.25kHz
  Timer3.attachInterrupt(updatePWM); 
}

void updatePWM() {
  static int counter = 0;

  if (counter < PWMval) {
    digitalWrite(pwmPin, HIGH);
  } else {
    digitalWrite(pwmPin, LOW);
  }

  counter++;
  if (counter >= 100) {
    counter = 0;
  }
}

void mcpsoftpwm(int value) {
  if (value < 0) value = 0;
  if (value > 100) value = 100;

  Serial.print("softPWM pin: 3, value: ");
  Serial.println(value); 
  PWMval = value; 
}

void loop() {
  mcpsoftpwm(100);  // Set PWM to 100%
  delay(1000);
  mcpsoftpwm(50);   // Set PWM to 50%
  delay(1000);
  Serial.println("loop");
}
