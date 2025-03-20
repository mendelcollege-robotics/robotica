#include <TimerThree.h>
#include <Adafruit_MCP23X17.h>
#include <SD.h>
#include <SPI.h>

//https://www.pololu.com/product/2997
//https://www.pololu.com/product/4861
//https://ww1.microchip.com/downloads/en/devicedoc/20001952c.pdf

// motor one/A  front
#define  m1enA 3   // GPA3  PWM1
#define  m1enB 2   // GPA2
#define  m1pwm1 0  // GPA0
#define  m1pwm2 1  // GPA1
#define  m1encA 12 // GPB4
#define  m1encB 13 // GPB5
// motor two/B  left
#define  m2enA 7   // GPA7  PWM2
#define  m2enB 6   // GPA6
#define  m2pwm1 4  // GPA4
#define  m2pwm2 5  // GPA5
#define  m2encA 14 // GPB6
#define  m2encB 15 // GPB7
// motor three/C    right
#define  m3enA 11  // GPB3  PWM3
#define  m3enB 10  // GPB2
#define  m3pwm1 8  // GPB0
#define  m3pwm2 9  // GPB1
#define  m3encA 24   // teensy port 24
#define  m3encB 9   // teensy port 9

const int maxspeed = 1000;

double sp = 0.00;
//encoder
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

//kiwidrive
double dirA = 0.00;
double dirB = 0.00;
double dirC = 0.00;
double spdA = 0.00;
double spdB = 0.00;
double spdC = 0.00;
double dirrad = 0.00;
double pi = 3.1415926535897;

//softPWM
volatile int PWMval1 = 0;   // PWM m1enA value 0-100
volatile int PWMval2 = 0;   // PWM m2enA value 0-100
volatile int PWMval3 = 0;   // PWM m3enA value 0-100

volatile int PWMval = 0;   // PWM value 0-100
File ;
File avrage;
Sd2Card card;
SdVolume volume;
SdFile root;
const int chipSelect = BUILTIN_SDCARD;
int x = 1;

int Nloop = 0;
int Atotloopdata[maxspeed] = {};
int Btotloopdata[maxspeed] = {};
int Ctotloopdata[maxspeed] = {};

Adafruit_MCP23X17 mcp2;

void setup() {
  if (!mcp2.begin_I2C(0x22)) {
    Serial.println("Error initializing MCP23017 at 0x22.");
    //while (1);
  }
  // set all the motor control pins
  mcp2.pinMode(m1enA, OUTPUT);
  mcp2.pinMode(m1enB, OUTPUT);
  mcp2.pinMode(m2enA, OUTPUT);
  mcp2.pinMode(m2enB, OUTPUT);
  mcp2.pinMode(m3enA, OUTPUT);
  mcp2.pinMode(m3enB, OUTPUT);
  mcp2.pinMode(m1pwm1, OUTPUT);
  mcp2.pinMode(m1pwm2, OUTPUT);
  mcp2.pinMode(m2pwm1, OUTPUT);
  mcp2.pinMode(m2pwm2, OUTPUT);
  mcp2.pinMode(m3pwm1, OUTPUT);
  mcp2.pinMode(m3pwm2, OUTPUT);

  //set encoder pins
  mcp2.pinMode(m1encA, INPUT);
  mcp2.pinMode(m1encB, INPUT);
  mcp2.pinMode(m2encA, INPUT);
  mcp2.pinMode(m2encB, INPUT);
  pinMode(m3encA, INPUT);
  pinMode(m3encB, INPUT);
  attachInterrupt(digitalPinToInterrupt(m1encA), AencoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m1encB), AencoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m2encA), BencoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m2encB), BencoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m3encA), CencoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m3encB), CencoderISR, CHANGE);

  Timer3.initialize(800); // 800 microseconds or 1.25kHz
  Timer3.attachInterrupt(updatePWM1); 
  Timer3.attachInterrupt(updatePWM2); 
  Timer3.attachInterrupt(updatePWM3); 
}

void updatePWM1() {
  static int counter1 = 0;

  if (counter1 < PWMval1) {
    mcp2.digitalWrite(m1enA, HIGH);
  } else {
    mcp2.digitalWrite(m1enA, LOW);
  }

  counter1++;
  if (counter1 >= 100) {
    counter1 = 0;
  }
}
void updatePWM2() {
  static int counter2 = 0;

  if (counter2 < PWMval2) {
    mcp2.digitalWrite(m2enA, HIGH);
  } else {
    mcp2.digitalWrite(m2enA, LOW);
  }

  counter2++;
  if (counter2 >= 100) {
    counter2 = 0;
  }
}
void updatePWM3() {
  static int counter3 = 0;

  if (counter3 < PWMval3) {
    mcp2.digitalWrite(m3enA, HIGH);
  } else {
    mcp2.digitalWrite(m3enA, LOW);
  }

  counter3++;
  if (counter3 >= 100) {
    counter3 = 0;
  }
}
void mcpsoftpwm(int pin, int vall){
  //M1enA = 3   = GPA3
  //M2enA = 7   = GPA7
  //M3enA = 11  = GPB3
  Serial.print("softPWM pin: ");
  Serial.print(pin);
  Serial.print(", value: ");
  Serial.println(vall);
  if (pin = 3){
    PWMval1 = vall;
    Serial.print("Motor 1 enA PWM set");
  }
  if (pin = 7){
    PWMval2 = vall;
    Serial.print("Motor 2 enA PWM set");
  }
  if (pin = 11){
    PWMval3 = vall;
    Serial.print("Motor 3 enA PWM set");
  }
  
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
void Aresetenc(){
  ACtime = micros();
  ALtime = ACtime;
  Aencount = 0;
}
void Bresetenc(){
  BCtime = micros();
  BLtime = BCtime;
  Bencount = 0;
}
void Cresetenc(){
  CCtime = micros();
  CLtime = CCtime;
  Cencount = 0;
}

void Amove(double sped) {
  spdA = abs(sped) * 0.1;
  mcpsoftpwm(m1enA, spdA);
  mcp2.digitalWrite(m1enB, LOW);
  if (sped < 0) {
    //Serial.print("Motor A back ");
    mcp2.digitalWrite(m1pwm1, LOW);
    mcp2.digitalWrite(m1pwm2, HIGH);
  } else {
    //Serial.print("Motor A forward ");
    mcp2.digitalWrite(m1pwm1, HIGH);
    mcp2.digitalWrite(m1pwm2, LOW);
  } 
  //Serial.println(spdA);
}
void Bmove(double sped) {
  spdB = abs(sped) * 0.1;
  mcpsoftpwm(m2enA, spdB);
  mcp2.digitalWrite(m2enB, LOW);
  if (sped < 0) {
    //Serial.print("Motor B back ");
    mcp2.digitalWrite(m2pwm1, LOW);
    mcp2.digitalWrite(m2pwm2, HIGH);
  } else {
    //Serial.print("Motor B forward ");
    mcp2.digitalWrite(m2pwm1, HIGH);
    mcp2.digitalWrite(m2pwm2, LOW);
  } 
  //Serial.println(spdB);
}
void Cmove(double sped) {
  spdC = abs(sped) * 0.1;
  mcpsoftpwm(m3enA, spdC);
  mcp2.digitalWrite(m3enB, LOW);
  if (sped < 0) {
    //Serial.print("Motor C back ");
    mcp2.digitalWrite(m3pwm1, LOW);
    mcp2.digitalWrite(m3pwm2, HIGH);
  } else {
    //Serial.print("Motor C forward ");
    mcp2.digitalWrite(m3pwm1, HIGH);
    mcp2.digitalWrite(m3pwm2, LOW);
  } 
  //Serial.println(spdC);
}
void move(double sped) {
  Amove(sped);
  Bmove(sped);
  Cmove(sped);
}
void readenc() {
  Areadenc();
  Breadenc();
  Creadenc();
}
void resetenc() {
  Aresetenc();
  Bresetenc();
  Cresetenc();
}

void loop() {
  move(0);
  delay(2000);
  for (int i = 0; i < maxspeed; i++) {
    Serial.println("0,0");
  }
  int Acurrentloopdata[maxspeed] = {};
  int Bcurrentloopdata[maxspeed] = {};
  int Ccurrentloopdata[maxspeed] = {};
  for (int i = 0; i < maxspeed; i++) {
    move(i);  
    delay(100);
    readenc();
    Serial.print(i);
    Serial.print(",");
    Serial.print(Arpm);
    Acurrentloopdata[i] = Arpm;
    Serial.print(",");
    Serial.print(Brpm);
    Acurrentloopdata[i] = Brpm;
    Serial.print(",");
    Serial.print(Crpm);
    Acurrentloopdata[i] = Crpm;
    Serial.print(",");
    Serial.println(Atotloopdata[i]);
    Serial.print(",");
    Serial.println(Btotloopdata[i]);
    Serial.print(",");
    Serial.println(Ctotloopdata[i]);
  }
  Acurrentloopdata[0] = 0;
  Bcurrentloopdata[0] = 0;
  Ccurrentloopdata[0] = 0;
  if (Nloop == 0){
    for (int i = 0; i < maxspeed; i++) {
      Atotloopdata[i] = Acurrentloopdata[i];
      Btotloopdata[i] = Bcurrentloopdata[i];
      Ctotloopdata[i] = Ccurrentloopdata[i];
    }
  }else{
    for (int i = 0; i < maxspeed; i++) {
      Atotloopdata[i] = ((Atotloopdata[i]*Nloop)+Acurrentloopdata[i])/(Nloop+1);
      Btotloopdata[i] = ((Btotloopdata[i]*Nloop)+Bcurrentloopdata[i])/(Nloop+1);
      Ctotloopdata[i] = ((Ctotloopdata[i]*Nloop)+Ccurrentloopdata[i])/(Nloop+1);
    }
  }
  resetenc();
  SD.remove("Aavrage_motor_values.dat");
  SD.remove("Bavrage_motor_values.dat");
  SD.remove("Cavrage_motor_values.dat");
  File AdataFile = SD.open("Aavrage_motor_values.dat", FILE_WRITE);
  if (AdataFile) {
    for (int i = 0; i < maxspeed; i++) {
      AdataFile.print(Atotloopdata[i]);
      AdataFile.print(", ");
    }
    AdataFile.close();
  }
  File BdataFile = SD.open("Aavrage_motor_values.dat", FILE_WRITE);
  if (BdataFile) {
    for (int i = 0; i < maxspeed; i++) {
      BdataFile.print(Btotloopdata[i]);
      BdataFile.print(", ");
    }
    BdataFile.close();
  }
  File CdataFile = SD.open("Aavrage_motor_values.dat", FILE_WRITE);
  if (CdataFile) {
    for (int i = 0; i < maxspeed; i++) {
      CdataFile.print(Ctotloopdata[i]);
      CdataFile.print(", ");
    }
    CdataFile.close();
  }
  SD.remove("ABC_avrage_motor_values.csv");
  File debugFile = SD.open("ABC_avrage_motor_values.csv", FILE_WRITE);
  if (debugFile) {
    debugFile.println("");
    debugFile.println("Motor A values");
    debugFile.println("");
    for (int i = 0; i < maxspeed; i++) {
      debugFile.print(i);
      debugFile.print(", ");
      debugFile.println(Atotloopdata[i]);
    }
    debugFile.println("");
    debugFile.println("Motor B values");
    debugFile.println("");
    for (int i = 0; i < maxspeed; i++) {
      debugFile.print(i);
      debugFile.print(", ");
      debugFile.println(Btotloopdata[i]);
    }
    debugFile.println("");
    debugFile.println("Motor C values");
    debugFile.println("");
    for (int i = 0; i < maxspeed; i++) {
      debugFile.print(i);
      debugFile.print(", ");
      debugFile.println(Ctotloopdata[i]);
    }
  }

  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("FAILED TO FIND SD CARD");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
  }
  
  
  Nloop++;
  
  
}
