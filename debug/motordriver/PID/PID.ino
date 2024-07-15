#include <TimerThree.h>
#include <QuickPID.h>


//https://www.pololu.com/product/2997
//https://www.pololu.com/product/4861


float Setpoint, Input, Output;
float Kp = 2, Ki = 5, Kd = 1;
QuickPID myPID(&Input, &Output, &Setpoint);


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
  Input = rpm;
  Setpoint = 500;
  myPID.SetTunings(Kp, Ki, Kd);
  myPID.SetMode(myPID.Control::automatic);
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
  Input = rpm;
  myPID.Compute();
  move(Output);
  
}
