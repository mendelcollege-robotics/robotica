//moveohmi = https://robotics.stackexchange.com/questions/7829/how-to-program-a-three-wheel-omni
//https://www.pololu.com/product/2997
//https://www.pololu.com/product/4861
//
// motor one/A  front
int m1enA = 1;
int m1enB = 2;
int m1pwm1 = 3;
int m1pwm2 = 4;
int m1encA = 13;
int m1encB = 14;
// motor two/B  left
int m2enA = 5;
int m2enB = 6;
int m2pwm1 = 7;
int m2pwm2 = 8;
int m2encA = 15;
int m2encB = 16;
// motor three/C    right
int m3enA = 9;
int m3enB = 10;
int m3pwm1 = 11;
int m3pwm2 = 12;
int m3encA = 17;
int m3encB = 18;

double sp = 1.000; //speed in 0-1

double dirA = 0.00;
double dirB = 0.00;
double dirC = 0.00;
double spdA = 0.00;
double spdB = 0.00;
double spdC = 0.00;
double dirrad = 0.00;
double pi = 3.1415926535897;

double Arpm = 0.00;
volatile long Aencount = 0;
unsigned long ALtime = 0;
unsigned long ACtime = 0;
unsigned long APtime = 0;
double Brpm = 0.00;
volatile long Bencount = 0;
unsigned long BLtime = 0;
unsigned long BCtime = 0;
unsigned long BPtime = 0;
double Crpm = 0.00;
volatile long Cencount = 0;
unsigned long CLtime = 0;
unsigned long CCtime = 0;
unsigned long CPtime = 0;

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

 //set encoder pins to input
 pinMode(m1encA, INPUT);
 pinMode(m1encB, INPUT);
 pinMode(m2encA, INPUT);
 pinMode(m2encB, INPUT);
 pinMode(m3encA, INPUT);
 pinMode(m3encB, INPUT);
 attachInterrupt(digitalPinToInterrupt(m1encA), AencoderISR, CHANGE);
 attachInterrupt(digitalPinToInterrupt(m1encB), AencoderISR, CHANGE);
 attachInterrupt(digitalPinToInterrupt(m2encA), BencoderISR, CHANGE);
 attachInterrupt(digitalPinToInterrupt(m2encB), BencoderISR, CHANGE);
 attachInterrupt(digitalPinToInterrupt(m3encA), CencoderISR, CHANGE);
 attachInterrupt(digitalPinToInterrupt(m3encB), CencoderISR, CHANGE);
}

void AencoderISR() {
  Aencount++;
}
void BencoderISR() {
  Bencount++;
}
void CencoderISR() {
  Cencount++;
}
void Areadenc() {
  ACtime = micros();
  APtime = ACtime - ALtime;
  ALtime = ACtime;
  Arpm = (Aencount / 211.2) * (60000000.0 / APtime);
  Serial.print("Motor A RPM: ");
  Serial.print(Arpm);
  Serial.print("    Sample period:");
  Serial.print(APtime);
  Serial.print("ms, encoder count:");
  Serial.println(Aencount);
  Aencount = 0;
}
void Breadenc() {
  BCtime = micros();
  BPtime = BCtime - BLtime;
  BLtime = BCtime;
  Brpm = (Bencount / 211.2) * (60000000.0 / BPtime);
  Serial.print("Motor B RPM: ");
  Serial.print(Brpm);
  Serial.print("    Sample period: ");
  Serial.print(BPtime);
  Serial.print(" ms, encoder count: ");
  Serial.println(Bencount);
  Bencount = 0;
}
void Creadenc() {
  CCtime = micros();
  CPtime = CCtime - CLtime;
  CLtime = CCtime;
  Crpm = (Cencount / 211.2) * (60000000.0 / CPtime);
  Serial.print("Motor C RPM: ");
  Serial.print(Crpm);
  Serial.print("    Sample period: ");
  Serial.print(CPtime);
  Serial.print(" ms, encoder count: ");
  Serial.println(Cencount);
  Cencount = 0;
}

void Amove(double sped) {
  spdA = abs(sped) * 255.000;
  analogWrite(m1enA, spdA);
  digitalWrite(m1enB, LOW);
  if (sped < 0) {
    Serial.print("Motor A back ");
    digitalWrite(m1pwm1, LOW);
    digitalWrite(m1pwm2, HIGH);
  } else {
    Serial.print("Motor A forward ");
    digitalWrite(m1pwm1, HIGH);
    digitalWrite(m1pwm2, LOW);
  } 
  Serial.println(spdA);
}
void Bmove(double sped) {
  spdB = abs(sped) * 255.000;
  analogWrite(m2enA, spdB);
  digitalWrite(m2enB, LOW);
  if (sped < 0) {
    Serial.print("Motor B back ");
    digitalWrite(m2pwm1, LOW);
    digitalWrite(m2pwm2, HIGH);
  } else {
    Serial.print("Motor B forward ");
    digitalWrite(m2pwm1, HIGH);
    digitalWrite(m2pwm2, LOW);
  } 
  Serial.println(spdB);
}
void Cmove(double sped) {
  spdC = abs(sped) * 255.000;
  analogWrite(m3enA, spdC);
  digitalWrite(m3enB, LOW);
  if (sped < 0) {
    Serial.print("Motor C back ");
    digitalWrite(m3pwm1, LOW);
    digitalWrite(m3pwm2, HIGH);
  } else {
    Serial.print("Motor C forward ");
    digitalWrite(m3pwm1, HIGH);
    digitalWrite(m3pwm2, LOW);
  } 
  Serial.println(spdC);
}


void moveohmi(int speed, int direction){
  Amove(0);
  Bmove(0);
  Cmove(0);

  double dirrad = (direction*71.0000) / 4068.0000;  
  Serial.println(dirrad);
  //vector ontb in x en y
  double y = sin(dirrad);
  double x = cos(dirrad);
  Serial.println((String)"x:"+x+" y:"+y);
  double spdeA = y*speed;
  double spdeB = (-0.500*x - 0.8660054*y)*speed;
  double spdeC = (-0.500*x + 0.8660054*y)*speed;
  Amove(spdeA);
  Bmove(spdeB);
  Cmove(spdeC);
  Serial.println();
  Serial.println();
}
void rotate(int rodeg, int speed){
//use compas heading
}
void demo(){
  Amove(sp);
  Bmove(sp);
  Cmove(sp); 
  Serial.println("seperate A B C rotation");
  delay(1000);
  
  Amove(0);
  Bmove(0);
  Cmove(0);
  Serial.println("seperate A B C stop");
  delay(1000);

  Amove(-sp);
  Bmove(-sp);
  Cmove(-sp);
  Serial.println("seperate A B C -rotation");
  delay(1000);

  moveohmi(0, 0);
  Serial.println("ohmi stop");
  delay(1000);

  rotate(90, sp);
  Serial.println("rotation function 90deg");
  rotate(90, sp);
  Serial.println("rotation function -90deg");
  delay(1000);

  moveohmi(sp, 35);
  Serial.println("ohmi move 35deg");
  delay(1000);

  moveohmi(sp, 240);
  Serial.println("ohmi move 215deg");
  delay(1000);

  for(int i = 0; i<360; i++){
    moveohmi(sp, i);
    Serial.println(i);
    delay(50);
  }
  Serial.println("ohmi move circle");
  delay(1000);
}
void loop(){
  demo();
  delay(100);

}
