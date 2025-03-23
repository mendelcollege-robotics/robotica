int enA = 27;
int enB = 26;
int pwm1 = 24;
int pwm2 = 25;
int encoA = 5;
int encoB = 6;
int speed = 1; // speed 0-1

double sp = 0.00;
double rpm = 0.00;
volatile long encount = 0;
unsigned long Ltime = 0;
unsigned long Ctime = 0;
unsigned long Ptime = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(encoA, INPUT_PULLUP);
  pinMode(encoB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoA), encoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoB), encoderISR, CHANGE);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(9600);
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
  sp = abs(sped)*255;
  analogWrite(enA, sp);
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
  digitalWrite(enA, HIGH);
  digitalWrite(enB, LOW);
  digitalWrite(pwm1, LOW);
  digitalWrite(pwm2, HIGH);
  delay(1000);
  readenc();
}
