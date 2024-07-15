int enA = 1;
int enB = 2;
int pwm1 = 3;
int pwm2 = 4;
int encoA = 5;
int encoB = 6;

int speed = 1; // speed 0-1000

double sp = 0.00;
double rpm = 0.00;
volatile long encount = 0;
unsigned long Ltime = 0;
unsigned long Ctime = 0;
unsigned long Ptime = 0;

int mess;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  pinMode(encoA, INPUT_PULLUP);
  pinMode(encoB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoA), encoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoB), encoderISR, CHANGE);

  Serial.begin(115200);
  Serial.setTimeout(1);
}

void encoderISR() {
  encount++;
}

void readenc() {
  Ctime = micros();
  Ptime = Ctime - Ltime;
  Ltime = Ctime;
  rpm = (encount / 211.2) * (60000000.0 / Ptime);
  /*Serial.print("RPM: ");
  Serial.print(rpm);
  Serial.print("    Sample period:");
  Serial.print(Ptime);
  Serial.print("ms, encoder count:");
  Serial.println(encount);
  */

  encount = 0;
}
void resetenc(){
  Ctime = micros();
  Ltime = Ctime;
  encount = 0;
}

void move(int sped) {
  sp = abs(sped)*2.55;
  analogWrite(enA, sp);
  digitalWrite(enB, LOW);
  if (sped < 0) {
    //Serial.print("back ");
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, HIGH);
  } else {
    //Serial.print("forward ");
    digitalWrite(pwm1, HIGH);
    digitalWrite(pwm2, LOW);
  } 
  //Serial.println(sp);
}

void loop() {
  while (!Serial.available());
  mess = Serial.readString().toInt();
  move(mess);
  readenc();
  Serial.print(rpm);
}
