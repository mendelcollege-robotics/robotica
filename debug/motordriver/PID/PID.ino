#include <TimerThree.h>
#include "ArduPID.h"

ArduPID myController;

double input;
double output;
double setpoint = 950; // Desired RPM
double p = 40; // PID P-term
double i = 2;  // PID I-term
double d = 0; // PID D-term

int enA = 1;  // PWM pin
int enB = 2;  // GND
int pwm1 = 3; // Motor control pin 1
int pwm2 = 4; // Motor control pin 2
int encoA = 5; // Encoder pin A
int encoB = 6; // Encoder pin B

double sp = 0.00;
double rpm = 0.00;
volatile long encount = 0;
unsigned long Ltime = 0;
unsigned long Ctime = 0;
unsigned long Ptime = 0;

volatile int PWMval = 0;   // PWM value 0-1000

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  pinMode(encoA, INPUT_PULLUP);
  pinMode(encoB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoA), encoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoB), encoderISR, CHANGE);

  Timer3.initialize(800); // 800 microseconds or 1.25kHz
  Timer3.attachInterrupt(updatePWM); 

  Serial.begin(9600);

  // PID settings
  myController.begin(&input, &output, &setpoint, p, i, d);
  myController.setOutputLimits(0, 1000); // Output limits for PWM control
  myController.setBias(500); // Starting bias for PWM
  myController.setWindUpLimits(-50, 50);

  myController.start();
}

void updatePWM() {
  static int counter = 0;

  if (counter < PWMval) {
    digitalWrite(enA, HIGH);
  } else {
    digitalWrite(enA, LOW);
  }

  counter++;
  if (counter >= 1000) {
    counter = 0;
  }
}

void mcpsoftpwm(int value) {
  if (value < 0) value = 0;
  if (value > 1000) value = 1000;

  PWMval = value; 
}

void encoderISR() {
  encount++;
}

void readenc() {
  Ctime = micros();
  Ptime = Ctime - Ltime;
  Ltime = Ctime;
  rpm = (encount / 211.2) * (60000000.0 / Ptime); // Adjust the encoder counts per revolution here if necessary
  encount = 0;
}

void resetenc() {
  Ctime = micros();
  Ltime = Ctime;
  encount = 0;
}

void move(int sped) {
  sp = abs(sped) * 0.1;
  mcpsoftpwm(sp);
  digitalWrite(enB, LOW);
  if (sped < 0) {
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, HIGH);
  } else {
    digitalWrite(pwm1, HIGH);
    digitalWrite(pwm2, LOW);
  }
}

void loop() {
  readenc();
  input = rpm;
  myController.compute();
  myController.debug(&Serial, "myController", PRINT_INPUT);
  
  move(output); // Replace with plant control signal
  delay(100);
}
