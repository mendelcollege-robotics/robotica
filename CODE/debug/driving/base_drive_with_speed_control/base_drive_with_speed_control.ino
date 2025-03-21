#include <TimerThree.h>

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

int speed = 1000; // speed 0-1

double sp1 = 0.00;
double sp2 = 0.00;
double sp3 = 0.00;

volatile int PWMval1 = 0;   // PWM value 0-100
volatile int PWMval2 = 0;   // PWM value 0-100
volatile int PWMval3 = 0;   // PWM value 0-100


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
  
  Timer3.initialize(800); // 800 microseconds or 1.25kHz
  Timer3.attachInterrupt(updatePWM); 

  Serial.begin(9600);
}

void updatePWM() {
  static int counter = 0;

  if (counter < PWMval1) {
    digitalWrite(m1enA, HIGH);
  } else {
    digitalWrite(m1enA, LOW);
  }
  
  if (counter < PWMval2) {
    digitalWrite(m2enA, HIGH);
  } else {
    digitalWrite(m2enA, LOW);
  }
  
  if (counter < PWMval3) {
    digitalWrite(m3enA, HIGH);
  } else {
    digitalWrite(m3enA, LOW);
  }

  counter++;
  if (counter >= 100) {
    counter = 0;
  }
}

void mcpsoftpwm1(int value1) {
  if (value1 < 0) value1 = 0;
  if (value1 > 100) value1 = 100;

  Serial.print("softPWM pin: enA, value: ");
  Serial.println(value1); 
  PWMval1 = value1; 
}
void mcpsoftpwm2(int value2) {
  if (value2 < 0) value2 = 0;
  if (value2 > 100) value2 = 100;

  Serial.print("softPWM pin: enA, value: ");
  Serial.println(value2); 
  PWMval2 = value2; 
}void mcpsoftpwm3(int value3) {
  if (value3 < 0) value3 = 0;
  if (value3 > 100) value3 = 100;

  Serial.print("softPWM pin: enA, value: ");
  Serial.println(value3); 
  PWMval3 = value3; 
}

void move1(int sped1) {
  sp1 = abs(sped1)*0.1;
  mcpsoftpwm1(sp1);
  digitalWrite(m1enB, LOW);
  if (sped1 < 0) {
    Serial.print("back ");
    digitalWrite(m1pwm1, LOW);
    digitalWrite(m1pwm2, HIGH);
  } else {
    Serial.print("forward ");
    digitalWrite(m1pwm1, HIGH);
    digitalWrite(m1pwm2, LOW);
  } 
  Serial.println(sp1);
}

void move2(int sped2) {
  sp2 = abs(sped2)*0.1;
  mcpsoftpwm2(sp2);
  digitalWrite(m2enB, LOW);
  if (sped2 < 0) {
    Serial.print("back ");
    digitalWrite(m2pwm1, LOW);
    digitalWrite(m2pwm2, HIGH);
  } else {
    Serial.print("forward ");
    digitalWrite(m2pwm1, HIGH);
    digitalWrite(m2pwm2, LOW);
  } 
  Serial.println(sp2);
}

void move3(int sped3) {
  sp3 = abs(sped3)*0.1;
  mcpsoftpwm3(sp3);
  digitalWrite(m3enB, LOW);
  if (sped3 < 0) {
    Serial.print("back ");
    digitalWrite(m3pwm1, LOW);
    digitalWrite(m3pwm2, HIGH);
  } else {
    Serial.print("forward ");
    digitalWrite(m3pwm1, HIGH);
    digitalWrite(m3pwm2, LOW);
  } 
  Serial.println(sp3);
}

void drive(int speeeed, int direction){
 //
 // Direction............|.Motor 1.|.Motor 2.|.Motor 3.
 // 0deg(forward)........|....0....|....-....|....+....
 // 60deg................|....+....|....-....|....0....    
 // 120deg...............|....+....|....0....|....-....
 // 180 deg (backward)...|....0....|....+....|....-.... 
 // 240 deg..............|....-....|....+....|....0....
 // 300 deg..............|....-....|....0....|....+....
 //
 if(direction>330 || direction<=30){
    //0 deg
    //Serial.println("drive 0 deg"); 
    move1(0);
    move2(-speeeed);
    move3(speeeed);
  }else if (direction>30 && direction <= 90){
    //60 deg
    //Serial.println("drive 60deg");
    move1(speeeed);
    move2(-speeeed);
    move3(0);
  }else if (direction>90 && direction <= 150){
    //120 deg
    //Serial.println("drive 120 deg");
    move1(speeeed);
    move2(0);
    move3(-speeeed);
  }else if (direction > 150 && direction <= 210) {
    //180 degrees
    //Serial.println("drive  180 deg");
    move1(0);
    move2(speeeed);
    move3(-speeeed);
  }else if (direction > 210 && direction <= 270) {
    //240 degrees
    //Serial.println("drive 240 deg");
    move1(-speeeed);
    move2(speeeed);
    move3(0);
  }else if (direction > 270 && direction <= 330) {
    //300 degrees
    //Serial.println("drive 300 deg");
    move1(-speeeed);
    move2(0);
    move3(speeeed);
  }else{
    Serial.println("how?");  
  }
}

void loop() {
  drive(1000, 0);
  Serial.println("ffor");
  delay(1500);
  drive(500, 180);
  Serial.println("back");
  delay(3000);
}
