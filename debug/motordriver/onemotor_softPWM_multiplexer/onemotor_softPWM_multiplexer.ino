#include <TimerThree.h>
#include <Adafruit_MCP23X17.h>

Adafruit_MCP23X17 mcp;

int enA = 0;    // GPA0 -PWM
int enB = 1;    // GPA1 -GND
int pwm1 = 2;   // GPA2 -HIGH/LOW
int pwm2 = 3;   // GPA3 -HIGH/LOW
int encoA = 4;  // GPA4 -read
int encoB = 5;  // GPA5 -read

int speed = 1; // speed 0-1

double sp = 0.00;
double rpm = 0.00;
volatile long encount = 0;
unsigned long Ltime = 0;
unsigned long Ctime = 0;
unsigned long Ptime = 0;

volatile int PWMval = 0;   // PWM value 0-100


void setup() {
  Serial.begin(9600);
  if (!mcp.begin_I2C(0x20)) {
    Serial.println("Error initializing MCP23017 at 0x20.");
    while (1);
  }

  mcp.pinMode(enA, OUTPUT);
  mcp.pinMode(enB, OUTPUT);
  mcp.pinMode(pwm1, OUTPUT);
  mcp.pinMode(pwm2, OUTPUT);

  mcp.pinMode(encoA, INPUT_PULLUP);
  mcp.pinMode(encoB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoA), encoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoB), encoderISR, CHANGE);

  Timer3.initialize(800); // 800 microseconds or 1.25kHz
  Timer3.attachInterrupt(updatePWM); 
}

void updatePWM() {
  static int counter = 0;

  if (counter < PWMval) {
    mcp.digitalWrite(enA, HIGH);
  } else {
    mcp.digitalWrite(enA, LOW);
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
  sp = abs(sped)*100;
  mcpsoftpwm(sp);
  mcp.digitalWrite(enB, LOW);
  if (sped < 0) {
    Serial.print("back ");
    mcp.digitalWrite(pwm1, LOW);
    mcp.digitalWrite(pwm2, HIGH);
  } else {
    Serial.print("forward ");
    mcp.digitalWrite(pwm1, HIGH);
    mcp.digitalWrite(pwm2, LOW);
  } 
  Serial.println(sp);
}

void loop() {
  move(speed);
  delay(1000);
  readenc();

  
  move(0);
  resetenc();
  delay(1000);
  readenc();

  move(-speed);
  delay(1000);
  readenc();
}
