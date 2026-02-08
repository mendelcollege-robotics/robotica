
//set pins
int ir1 = 0;
int ir2 = 1;
int ir3 = 9;
int ir4 = 2;
int ir5 = 3;
int ir6 = 4;
int ir7 = 5;
int ir8 = 8;

//arrays cus typing a lot is hard even with auto complete
int pins[8] = {ir1, ir2, ir3, ir4, ir5, ir6, ir7, ir8};
volatile unsigned long startTime[8];
volatile unsigned long pulseWidth[8];

void ISR0();
void ISR1();
void ISR2();
void ISR3();
void ISR4();
void ISR5();
void ISR6();
void ISR7();

void setup() {
  Serial.begin(9600);
  Serial1.begin(75);

  //pins setup
  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], INPUT);
  }
  //attach interpts
  attachInterrupt(digitalPinToInterrupt(ir1), ISR0, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir2), ISR1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir3), ISR2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir4), ISR3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir5), ISR4, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir6), ISR5, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir7), ISR6, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir8), ISR7, CHANGE);
}

void loop() {
  noInterrupts();
  //for (int i = 0; i < 8; i++) {
  //  Serial.print("ir"); Serial.print(i + 1);
  //  Serial.print(": "); Serial.print(pulseWidth[i]); Serial.print("  ");
  //}
  //Serial.println();
  Serial1.println(pulseWidth[8]);
  interrupts();
  delay(200);
}

//calc pulsewidth
void handlePWM(int idx) {
  if (digitalRead(pins[idx]) == HIGH) {
    startTime[idx] = micros();
  } else {
    pulseWidth[idx] = micros() - startTime[idx];
  }
}

//interupts
void ISR0() { handlePWM(0); }
void ISR1() { handlePWM(1); }
void ISR2() { handlePWM(2); }
void ISR3() { handlePWM(3); }
void ISR4() { handlePWM(4); }
void ISR5() { handlePWM(5); }
void ISR6() { handlePWM(6); }
void ISR7() { handlePWM(7); }
