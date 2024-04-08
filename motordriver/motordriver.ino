//moveohmi = https://robotics.stackexchange.com/questions/7829/how-to-program-a-three-wheel-omni
// motor one
int enA = 33;
int in1 = 2;
int in2 = 3;
// motor two
int enB = 36;
int in3 = 4;
int in4 = 5;
// motor three
int enC = 37;
int in5 = 7;
int in6 = 6;

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
 pinMode(enA, OUTPUT);
 pinMode(enB, OUTPUT);
 pinMode(enC, OUTPUT);

 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
 pinMode(in5, OUTPUT);
 pinMode(in6, OUTPUT);
}
void demoOne()
{
// this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, sp);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, sp);
  // turn on motor c
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enC, sp);
  delay(2000);
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  delay(2000);
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void demoTwo()
{
  // this function will run the motors across the range of possible speeds
  // note that maximum speed is determined by the motor itself and theoperating voltage
  // the PWM values sent by analogWrite() are fractions of the maximumspeed possible
  // by your hardware
  // turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  // accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    analogWrite(enC, i); 
    delay(20);
  }
  // decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    analogWrite(enC, i);
    delay(20);
  }
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
}

void Amove(int sped){
  Serial.print("moving A ");
  if (sped < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.print("back");
  }
  else{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    Serial.print("forward");
  } 
  Serial.print("with speed: ");
  sp = abs(sped); 
  analogWrite(enA, sp);
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

void moveohmi(int speed, int direction)
{
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
void beddermoveohmi(int speed, int direction)
{
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
  //demoOne();
  //delay(1000);
  //demoTwo();
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
