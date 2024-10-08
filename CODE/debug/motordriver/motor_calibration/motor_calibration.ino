#include <TimerThree.h>
#include <SD.h>
#include <SPI.h>

int enA = 1;  //PWM pin
int enB = 2;  //GND
int pwm1 = 3; //
int pwm2 = 4;
int encoA = 5;
int encoB = 6;

const int maxspeed = 1000;

double sp = 0.00;
double rpm = 0.00;
volatile long encount = 0;
unsigned long Ltime = 0;
unsigned long Ctime = 0;
unsigned long Ptime = 0;

volatile int PWMval = 0;   // PWM value 0-100
File ;
File avrage;
Sd2Card card;
SdVolume volume;
SdFile root;
const int chipSelect = BUILTIN_SDCARD;
int x = 1;

int Nloop = 0;
int totloopdata[maxspeed] = {};


void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  pinMode(encoA, INPUT_PULLUP);
  pinMode(encoB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoA), encoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoB), encoderISR, CHANGE);

  Timer3.initialize(800); // 800 microseconds or 1.25kHz
  Timer3.attachInterrupt(updatePWM); 

  Serial.begin(9600);
}

void updatePWM() {
  static int counter = 0;

  if (counter < PWMval) {
    digitalWrite(enA, HIGH);
  } else {
    digitalWrite(enA, LOW);
  }

  counter++;
  if (counter >= 100) {
    counter = 0;
  }
}
void mcpsoftpwm(int value) {
  if (value < 0) value = 0;
  if (value > 100) value = 100;

  //Serial.print("softPWM pin: enA, value: ");
  //Serial.println(value); 
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
  //Serial.print("RPM: ");
  //Serial.print(rpm);
  //Serial.print("    Sample period:");
  //Serial.print(Ptime);
  //Serial.print("ms, encoder count:");
  //Serial.println(encount);

  encount = 0;
}
void resetenc(){
  Ctime = micros();
  Ltime = Ctime;
  encount = 0;
}

void move(int sped) {
  sp = abs(sped)*0.1;
  mcpsoftpwm(sp);
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
  move(0);
  //max
  /*
  Serial.println();
  Serial.println();
  Serial.println();
  move(maxspeed);
  Serial.print("max speed: ");
  delay(1000);
  resetenc();
  delay(1000);
  readenc();
  Serial.print(rpm);
  Serial.print("rpm, with input: ");
  Serial.println(maxspeed);
  delay(250);
  move(0);

  //min
  delay(5000);
  Serial.print("min speed: ");
  for (int i = 0; i < maxspeed; i++) {
    move(i);  
    delay(1000);
    readenc();
    if ((rpm > 10) && (i>5)) {
      Serial.print(rpm);
      Serial.print("rpm, with input: ");
      Serial.println(i);
      break; 
    }
  }
  */
  delay(2000);
  for (int i = 0; i < maxspeed; i++) {
    Serial.println("0,0");
  }
  int currentloopdata[maxspeed] = {};
  for (int i = 0; i < maxspeed; i++) {
    move(i);  
    delay(100);
    readenc();
    Serial.print(i);
    Serial.print(",");
    Serial.print(rpm);
    currentloopdata[i] = rpm;
    Serial.print(",");
    Serial.println(totloopdata[i]);
  }
  /*
  for (int i = 0; i < maxspeed; i++) {
    move(0); 
    delay(200); 
    move(i); 
    delay(1000); 
    resetenc();
    delay(100); 
    readenc();
    Serial.print(i);
    Serial.print(",");
    Serial.print(rpm);
    currentloopdata[i] = rpm;
    Serial.print(",");
    Serial.println(totloopdata[i]);
  }
  */
  currentloopdata[0] = 0;
  if (Nloop == 0){
    for (int i = 0; i < maxspeed; i++) {
      totloopdata[i] = currentloopdata[i];
    }
  }else{
    for (int i = 0; i < maxspeed; i++) {
      //Serial.print(currentloopdata[i]);
      //Serial.print(",  ");
      //Serial.print(totloopdata[i]);
      totloopdata[i] = ((totloopdata[i]*Nloop)+currentloopdata[i])/(Nloop+1);
    }
  }
  for (int i = 0; i < maxspeed; i++) {
    //Serial.print(currentloopdata[i]);
    //Serial.print(",  ");
  }

  resetenc();
  SD.remove("avrage_motor_values.dat");
  File dataFile = SD.open("avrage_motor_values.dat", FILE_WRITE);
  if (dataFile) {
    for (int i = 0; i < maxspeed; i++) {
      dataFile.print(totloopdata[i]);
      dataFile.print(", ");
  }
    dataFile.close();
  }
  SD.remove("avrage_motor_values.csv");
  File debugFile = SD.open("avrage_motor_values.csv", FILE_WRITE);
  if (debugFile) {
    for (int i = 0; i < maxspeed; i++) {
      debugFile.print(i);
      debugFile.print(", ");
      debugFile.println(totloopdata[i]);
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
