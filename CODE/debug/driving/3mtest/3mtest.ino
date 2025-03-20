
int led = 13;

int m1enA = 6;
int m1enB = 5;
int m1pwm1 = 4;
int m1pwm2 = 3;
int m1encoA = 32;
int m1encoB = 31;

int m2enA = 12;
int m2enB = 11;
int m2pwm1 = 9;
int m2pwm2 = 10;
int m2encoA = 30;
int m2encoB = 29;

int m3enA = 27;
int m3enB = 26;
int m3pwm1 = 24;
int m3pwm2 = 25;
int m3encoA = 28;
int m3encoB = 23;


void setup() {
  pinMode(m1enA, OUTPUT);
  pinMode(m1enB, OUTPUT);
  pinMode(m1pwm1, OUTPUT);
  pinMode(m1pwm2, OUTPUT);
  
  pinMode(m2enA, OUTPUT);
  pinMode(m2enB, OUTPUT);
  pinMode(m2pwm1, OUTPUT);
  pinMode(m2pwm2, OUTPUT);
  
  pinMode(m3enA, OUTPUT);
  pinMode(m3enB, OUTPUT);
  pinMode(m3pwm1, OUTPUT);
  pinMode(m3pwm2, OUTPUT);
  Serial.begin(9600);
  Serial.print("debug 001");
  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);
  
  digitalWrite(m1enA, HIGH);
  digitalWrite(m1enB, LOW);
  digitalWrite(m1pwm1, HIGH);
  digitalWrite(m1pwm2, LOW);
  

  digitalWrite(m2enA, HIGH);
  digitalWrite(m2enB, LOW);
  digitalWrite(m2pwm1, HIGH);
  digitalWrite(m2pwm2, LOW);

  digitalWrite(m3enA, HIGH);
  digitalWrite(m3enB, LOW);
  digitalWrite(m3pwm1, HIGH);
  digitalWrite(m3pwm2, LOW);  
  
  delay(5000);             


  digitalWrite(led, LOW);
  
  digitalWrite(m1enA, HIGH);
  digitalWrite(m1enB, LOW);
  digitalWrite(m1pwm1, LOW);
  digitalWrite(m1pwm2, LOW);

  digitalWrite(m2enA, HIGH);
  digitalWrite(m2enB, LOW);
  digitalWrite(m2pwm1, LOW);
  digitalWrite(m2pwm2, LOW);

  digitalWrite(m3enA, HIGH);
  digitalWrite(m3enB, LOW);
  digitalWrite(m3pwm1, LOW);
  digitalWrite(m3pwm2, LOW);
  
  
  delay(5000);

  
}
