int m1enA = 6;
int m1enB = 5;
int m1pwm1 = 4;
int m1pwm2 = 3;
int m1encoA = 32;
int m1encoB = 31;

void setup() {
  Serial.begin(9600);

  pinMode(m1enA, OUTPUT);
  pinMode(m1enB, OUTPUT);
  pinMode(m1pwm1, OUTPUT);
  pinMode(m1pwm2, OUTPUT);

  pinMode(m1pwm1, INPUT);
  pinMode(m1pwm2, INPUT);
  
}

void loop() {
  digitalWrite(m1enA, HIGH);
  digitalWrite(m1enB, LOW);
  digitalWrite(m1pwm1, HIGH);
  digitalWrite(m1pwm2, LOW);
  delay(500);
  digitalWrite(m1enA, HIGH);
  digitalWrite(m1enB, LOW);
  digitalWrite(m1pwm1, LOW);
  digitalWrite(m1pwm2, HIGH);
  delay(500);
}
