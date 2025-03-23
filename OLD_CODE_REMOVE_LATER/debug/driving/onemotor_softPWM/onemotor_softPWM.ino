#include <TimerThree.h>

int enA = 6;  //PWM pin
int enB = 5;  //GND
int pwm1 = 4; //
int pwm2 = 3;
int encoA = 32;
int encoB = 31;

int speed = 1000; // speed 0-1

double sp = 0.00;
double rpm = 0.00;
volatile long encount = 0;
unsigned long Ltime = 0;
unsigned long Ctime = 0;
unsigned long Ptime = 0;

volatile int PWMval = 0;   // PWM value 0-100


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
}

void updatePWM() {
  static int counter = 0;

  if (counter < PWMval) {
    digitalWrite(enA, HIGH);
  } else {
    digitalWrite(enA, LOW);
  }

  counter++;
  if (counter >= 100) {
    counter = 0;
  }
}
void mcpsoftpwm(int value) {
  if (value < 0) value = 0;
  if (value > 100) value = 100;

  Serial.print("softPWM pin: enA, value: ");
  Serial.println(value); 
  PWMval = value; 
}

void encoderISR() {
  encount++;
}

void readenc() {
  Ctime = micros();
  Ptime = Ctime - Ltime;
  Ltime = Ctime;
  rpm = (encount / 211.2) * (60000000.0 / Ptime);
  Serial.print("RPM: ");
  Serial.print(rpm);
  Serial.print("    Sample period:");
  Serial.print(Ptime);
  Serial.print("ms, encoder count:");
  Serial.println(encount);

  encount = 0;
}
void resetenc(){
  Ctime = micros();
  Ltime = Ctime;
  encount = 0;
}

void move(int sped) {
  sp = abs(sped)*0.1;
  mcpsoftpwm(sp);
  digitalWrite(enB, LOW);
  if (sped < 0) {
    Serial.print("back ");
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, HIGH);
  } else {
    Serial.print("forward ");
    digitalWrite(pwm1, HIGH);
    digitalWrite(pwm2, LOW);
  } 
  Serial.println(sp);
}

void loop() {
  move(speed);
  delay(1000);
  readenc();
  delay(1000);

  Serial.println();

  move(0);
  delay(1000);
  resetenc();
  delay(1000);
  readenc();
  delay(1000);

  Serial.println();

  move(500);
  delay(1000);
  readenc();
  delay(1000);

  Serial.println();
}
