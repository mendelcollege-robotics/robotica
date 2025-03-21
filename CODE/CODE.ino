#include <TimerThree.h>
#include <Arduino.h>

int speed = 1000; // speed 0-1

volatile int PWMval1 = 0;   // PWM value 0-100
volatile int PWMval2 = 0;   // PWM value 0-100
volatile int PWMval3 = 0;   // PWM value 0-100

int incomingbyte1 = 0;  //the byte that it is reciefing
bool iswriting1 = false;  //true if writing else fals
String tlocdat1 = "";  //temporary location data
String locdat1 = "";   //location data
int nir1 = "-99"; // which ir sensor it is
int pir1 = "-99"; // amount of pulses it had

int incomingbyte2 = 0;  //same but for seeed xiao N 2
bool iswriting2 = false;
String tlocdat2 = ""; 
String locdat2 = ""; 
int nir2 = "-99";
int pir2 = "-99";

float degwhere = -99.0; // where the ball is in degrees

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

int softpwr = 2;

int pr1 = 13;
int pr2 = 41;
int pr3 = 40;
int pr4 = 39;
int pr5 = 38;
int pr6 = 37;
int pr7 = 36;
int pr8 = 35;

int dpr1 = "LOW";
int dpr2 = "LOW";
int dpr3 = "LOW";
int dpr4 = "LOW";
int dpr5 = "LOW";
int dpr6 = "LOW";
int dpr7 = "LOW";
int dpr8 = "LOW";

double sp1 = 0.00;
double sp2 = 0.00;
double sp3 = 0.00;

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

  pinMode(softpwr, INPUT_PULLUP);

  pinMode(pr1, INPUT);
  pinMode(pr2, INPUT);
  pinMode(pr3, INPUT);
  pinMode(pr4, INPUT);
  pinMode(pr5, INPUT);
  pinMode(pr6, INPUT);
  pinMode(pr7, INPUT);
  pinMode(pr8, INPUT);

  Serial.begin(9600);
  Serial3.begin(9600);
  Serial2.begin(9600);

  Timer3.initialize(800); // 800 microseconds / 1.25kHz
  Timer3.attachInterrupt(updatePWM); 
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
  int sprst = digitalRead(softpwr);  //softpower status
  if(sprst == LOW){
    dpr1 = digitalRead(pr1);
    dpr2 = digitalRead(pr2); 
    dpr3 = digitalRead(pr3); 
    dpr4 = digitalRead(pr4); 
    dpr5 = digitalRead(pr5); 
    dpr6 = digitalRead(pr6); 
    dpr7 = digitalRead(pr7); 
    dpr8 = digitalRead(pr8); 
  
    if(dpr1 == HIGH){
      //go back to ?deg
    }else if (dpr2 == HIGH){
      //go back to ?deg
    }else if (dpr3 == HIGH){
      //go back to ?deg
    }else if (dpr4 == HIGH){
      //go back to ?deg
    }else if (dpr5 == HIGH){
      //go back to ?deg
    }else if (dpr6 == HIGH){
      //go back to ?deg
    }else if (dpr7 == HIGH){
      //go back to ?deg
    }else if (dpr8 == HIGH){
      //go back to ?deg
    }else{
      if (Serial3.available() > 0) {
        incomingbyte1 = Serial3.read();
        //Serial.print(char(incomingbyte1));
        if (incomingbyte1 == 's'){
          iswriting1 = true;
          tlocdat1 = "";
        }else if(incomingbyte1 == 'e'){
          iswriting1 = false;
          locdat1 = tlocdat1;        
        }else if(iswriting1 == true){
          //Serial.print(char(incomingbyte1));
          tlocdat1 += (char)incomingbyte1;  
        }
      }
      if (Serial2.available() > 0) {
        incomingbyte2 = Serial2.read();
        //Serial.print(char(incomingbyte2));
        if (incomingbyte2 == 's'){
          iswriting2 = true;
          tlocdat2 = "";
        }else if(incomingbyte1 == 'e'){
          iswriting2 = false;
          locdat2 = tlocdat1;        
        }else if(iswriting2 == true){
          //Serial.print(char(incomingbyte1));
          tlocdat2 += (char)incomingbyte1;  
        }
      }
      //Serial.println(locdat);
      sscanf(locdat1.c_str(), "%d, %d", &nir1, &pir1);
      sscanf(locdat2.c_str(), "%d, %d", &nir2, &pir2);

      Serial.print("locdat: ");
      Serial.print(String(locdat1));
      Serial.println(String(locdat2));
      
      
      if(pir1 > pir2){
         if(nir1 = 1){    //not good looking code because posbile wrong wireing
          degwhere = 0;      
         }else if(nir1 = 2){
          degwhere = 22.5;
         }else if(nir1 = 3){
          degwhere = 45;
         }else if(nir1 = 4){
          degwhere = 67.5;
         }else if(nir1 = 5){
          degwhere = 90;
         }else if(nir1 = 6){
          degwhere = 112.5;
         }else if(nir1 = 7){
          degwhere = 135;
         }else if(nir1 = 8){
          degwhere = 157.5;
         }
      }else{     
         if(nir2 = 1){
          degwhere = 180;
         }else if(nir2 = 2){
          degwhere = 202.5;
         }else if(nir2 = 3){
          degwhere = 225;
         }else if(nir2 = 4){
          degwhere = 247.5;
         }else if(nir2 = 5){
          degwhere = 270;
         }else if(nir2 = 6){
          degwhere = 292.5;
         }else if(nir2 = 7){
          degwhere = 315; 
         }else if(nir2 = 8){
          degwhere = 337.5; 
         }
      }

      Serial.print("Ball is at ");
      Serial.print(degwhere);
      Serial.println(" degrees.");
      drive(75, degwhere);
      delay(1);
    }
  }else{
    Serial.println("softPWR is off, waiting");
    delay(100);  
  }
}
