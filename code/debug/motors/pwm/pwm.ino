#include <SoftPWM.h>

int m1enA = LED_BUILTIN;
int m1enB = 5;
int m1pwm1 = 4;
int m1pwm2 = 3;
int m1encoA = 32;
int m1encoB = 31;

void setup() {
  Serial.begin(9600);

  SoftPWMBegin();
  SoftPWMSetPolarity(m1enA, 0);
  SoftPWMSet(m1enA, 0);

  pinMode(m1enB, OUTPUT);
  pinMode(m1pwm1, OUTPUT);
  pinMode(m1pwm2, OUTPUT);

  pinMode(m1pwm1, INPUT);
  pinMode(m1pwm2, INPUT);
  
}

void loop() {
  SoftPWMSet(m1enA, 50);
  digitalWrite(m1enB, LOW);
  digitalWrite(m1pwm1, HIGH);
  digitalWrite(m1pwm2, LOW);
  delay(500);
  SoftPWMSet(m1enA, 255);
  digitalWrite(m1enA, HIGH);
  digitalWrite(m1enB, LOW);
  digitalWrite(m1pwm1, LOW);
  digitalWrite(m1pwm2, HIGH);
  delay(500);
}
