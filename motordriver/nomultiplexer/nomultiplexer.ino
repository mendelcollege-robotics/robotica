//moveohmi = https://robotics.stackexchange.com/questions/7829/how-to-program-a-three-wheel-omni
//https://www.pololu.com/product/2997
//https://www.pololu.com/product/4861
//
// motor one
int m1penA = 1;
int m1enB = 2;
int m1pwm1 = 3;
int m1pwm2 = 4;
int m1encA = 13;
int m1encB = 14;
// motor two
int m2enA = 5;
int m2enB = 6;
int m2pwm1 = 7;
int m2pwm2 = 8;
// motor three
int m3enA = 9;
int m3enB = 10;
int m3pwm1 = 11;
int m3pwm2 = 12;

int sp = 160;

double dirA = 0.00;
double dirB = 0.00;
double dirC = 0.00;
double spdA = 0.00;
double spdB = 0.00;
double spdC = 0.00;
double dirrad = 0.00;

void setup()
{
 // set all the motor control pins to outputs
 pinMode(m1enA, OUTPUT);
 pinMode(m1enB, OUTPUT);
 pinMode(m2enA, OUTPUT);
 pinMode(m2enB, OUTPUT);
 pinMode(m3enA, OUTPUT);
 pinMode(m3enB, OUTPUT);

 pinMode(m1pwm1, OUTPUT);
 pinMode(m1pwm2, OUTPUT);
 pinMode(m2pwm1, OUTPUT);
 pinMode(m2pwm2, OUTPUT);
 pinMode(m3pwm1, OUTPUT);
 pinMode(m3pwm2, OUTPUT);

 pinMode(m1encA, INPUT);
 pinMode(m1encB, INPUT);
}

void Amove(int sped){
  digitalWrite(m1enA, HIGH);
  digitalWrite(m1enA, LOW);
  sp = abs(sped);
  if (sped < 0) {
    Serial.print("back");
    analogWrite(m1pwm1, sp);
    digitalWrite(m1pwm2, LOW);
  } else {
    Serial.print("forward");
    digitalWrite(m1pwm1, LOW);
    analogWrite(m1pwm2, sp);
  } 
  Serial.println(sp);
}
void Bmove(int sped) {
  Serial.print("moving B ");
  if (sped < 0) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.print("back");
  } else {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.print("forward");
  } 
  Serial.print("with speed: ");
  int sp = abs(sped);
  analogWrite(enB, sp);
  Serial.println(sp);
}
void Cmove(int sped) {
  Serial.print("moving C ");
  if (sped < 0) {
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    Serial.print("back");
  } else {
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    Serial.print("forward");
  } 
  Serial.print("with speed: ");
  int sp = abs(sped);
  analogWrite(enC, sp);
  Serial.println(sp);
}

void turnoff(){
  Serial.println("stop");
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  analogWrite(enC, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW); 
}
void forward(int speed){
  Serial.println("forward");
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  analogWrite(enC, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
}
void turn(int speed){
  Serial.println("turn");
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  analogWrite(enC, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
}

void moveohmi(int speed, int direction){
  turnoff();
  double dirrad = (direction*71) / 4068;
  dirA = 1.047198-dirrad; 
  dirB = 3.141593-dirrad;
  dirC = 5.235988-dirrad;
  spdA = speed*sin(dirA);
  spdB = speed*sin(dirB);
  spdC = speed*sin(dirC);
  Amove(spdA);
  Bmove(spdB);
  Cmove(spdC);
}
void beddermoveohmi(int speed, int direction){
  turnoff();

  double dirrad = (direction*71) / 4068;  
  Serial.println(dirrad);
  //vector ontb in x en y
  double x = sin(dirrad)*speed;
  double y = cos(dirrad)*speed;
  Serial.println((String)"x:"+x+" y:"+y);
  spdA = -0.5*x - sqrt(3)/2*y;
  spdB = x;
  spdC = -0.5*x + sqrt(3)/2*y;
  Amove(spdA);
  Bmove(spdB);
  Cmove(spdC);

  Serial.println(spdA);
  Serial.println(spdB);
  Serial.println(spdC);
  Serial.println();
  Serial.println();
}
void loop()
{
  delay(1000);
  turnoff();
  beddermoveohmi(255, 0);
  delay(1000);
  turnoff();
  Amove(255);
  delay(1000);
  turnoff();
  Bmove(255);
  delay(1000);
  turnoff();
  Cmove(255);
  delay(1000);
  turnoff();
  turn(254);
  delay(1000);
}
