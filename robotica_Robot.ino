/**
MIT License

Copyright (c) 2022 Abel Tim

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 *
 */

 // Code for rbc soccer robot
 //librarys
#include "Wire.h"                 //https://www.arduino.cc/reference/en/language/functions/communication/wire/
#include "Adafruit_TCS34725.h"    //https://github.com/adafruit/Adafruit_TCS34725
#include <SparkFunSX1509.h>       //https://learn.sparkfun.com/tutorials/sx1509-io-expander-breakout-hookup-guide#installing-the-sparkfun-sx1509-arduino-library

#define PCAADDR 0x70              //i2c addres for i2c multiplexer https://learn.adafruit.com/adafruit-tca9548a-1-to-8-i2c-multiplexer-breakout/arduino-wiring-and-test

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X); //collor sensor values


//IR sensors and multiplexer
const byte SX1509_ADDRESS = 0x3E; // SX1509 I2C address
SX1509 io;                        // Create an SX1509 object to be used throughout
const byte SX1509_IR_SENS1 = 1; // ir sens 1 to SX1509's pin 1
const byte SX1509_IR_SENS2 = 2; // ir sens 2 to SX1509's pin 2
const byte SX1509_IR_SENS3 = 3; // ir sens 3 to SX1509's pin 3
const byte SX1509_IR_SENS4 = 4; // ir sens 4 to SX1509's pin 4
const byte SX1509_IR_SENS5 = 5; // ir sens 5 to SX1509's pin 5
const byte SX1509_IR_SENS6 = 6; // ir sens 6 to SX1509's pin 6

int ir1 = 1; // IR sensor 1
int ir2 = 2; // IR sensor 2
int ir3 = 3; // IR sensor 3
int ir4 = 4; // IR sensor 4
int ir5 = 5; // IR sensor 5
int ir6 = 6; // IR sensor 6

//color sensors vars
int r1 = 1;
int g1 = 1;
int b1 = 1;
int r2 = 1;
int g2 = 1;
int b2 = 1;
int r3 = 1;
int g3 = 1;
int b3 = 1;
int r4 = 1;
int g4 = 1;
int b4 = 1;
int r5 = 1;
int g5 = 1;
int b5 = 1;
int r6 = 1;
int g6 = 1;
int b6 = 1;

//Motors
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

int sp = 160; //speed
//variables used for motor controll
double dirA = 0.00;
double dirB = 0.00;
double dirC = 0.00;
double spdA = 0.00;
double spdB = 0.00;
double spdC = 0.00;
double dirrad = 0.00;

//code for i2c multiplexer
void pcaselect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(PCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}
//code for the motors
//for motor A
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
//for motor B
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
//for motor C
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
//for omhi drive capabilities
void moveohmi(int speed, int direction)
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
//for turing
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
//for moving forward
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
//for turning all engines off
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
//for finding the ball
void findball(int irs1, int irs2, int irs3, int irs4, int irs5, int irs6, int spedo){
  if (irs1 == 0){
    //0deg
    Bmove(-spedo);
    Cmove(spedo);
  }else if (irs2 == 0){
    //60deg
    Amove(-spedo);
    Cmove(spedo);
  }
  }else if (irs3 == 0){
    //120deg
    Amove(-spedo);
    Bmove(spedo);
  }else if (irs4 == 0){
    //180deg
    Cmove(-spedo);
    Bmove(spedo);
  }else if (irs5 == 0){
    //240deg
    Cmove(-spedo);
    Amove(spedo);
  }
  else if (irs6 == 0){
    //300deg
    Bmove(-spedo);
    Amove(spedo);
  }
  else(){
    forward(speed);
  }
}


  /**
    
  starting setup

**/
void setup() {
  // Motor setup
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);

  //sensor setup
  delay(1000);
  Wire.begin();
    
  Serial.begin(115200);
  Serial.println("\nPCAScanner ready!");
  for (uint8_t t=0; t<8; t++) {
    pcaselect(t);
    Serial.print("PCA Port #"); Serial.println(t);

    for (uint8_t addr = 0; addr<=127; addr++) {
      if (addr == PCAADDR) continue;

      Wire.beginTransmission(addr);
      if (!Wire.endTransmission()) {
        Serial.print("Found I2C 0x");  Serial.println(addr,HEX);
      }
    }
  }
  Serial.println("\ndone");
  Serial.println("mark1");
  if (io.begin(SX1509_ADDRESS) == false){
    Serial.println("Failed to communicate. Check wiring and address of SX1509.");
    while (1)
      ; // If we fail to communicate, loop forever.
  }
  io.pinMode(SX1509_IR_SENS1, INPUT);
  io.pinMode(SX1509_IR_SENS2, INPUT);
  io.pinMode(SX1509_IR_SENS3, INPUT);
  io.pinMode(SX1509_IR_SENS4, INPUT);
  io.pinMode(SX1509_IR_SENS5, INPUT);
  io.pinMode(SX1509_IR_SENS6, INPUT);
  Serial.println("mark2");

}

  /**
    
  starting loop 
  first collecting sensor data

**/

void loop() {


  delay(1);
  Wire.begin();
  Serial.println("\nPCAScanner ready!");
  //port expander
  Serial.println("port multiplier");
  ir1 = io.digitalRead(SX1509_IR_SENS1);
  ir1 = io.digitalRead(SX1509_IR_SENS1);
  ir2 = io.digitalRead(SX1509_IR_SENS2);
  ir3 = io.digitalRead(SX1509_IR_SENS3);
  ir4 = io.digitalRead(SX1509_IR_SENS4);
  ir5 = io.digitalRead(SX1509_IR_SENS5);
  ir6 = io.digitalRead(SX1509_IR_SENS6);

  // Define a string to store the collected data
  String irsensdata = "";

  // Read the digital state of each IR sensor pin and concatenate the data to the string
  irsensdata += String(io.digitalRead(SX1509_IR_SENS1));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS2));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS3));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS4));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS5));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS6));
  // Print the collected data
  Serial.print("IR sensor data: ");
  Serial.println(irsensdata);

  //collorsensor 1
  pcaselect(1);
  Serial.println("PCA Port #1   collor sensor 1");
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");
  r1 = (r, DEC);
  g1 = (g, DEC);
  b1 = (b, DEC);
  //collorsensor 2
  pcaselect(2);
  Serial.println("PCA Port #2   collor sensor 2");
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");
  r2 = (r, DEC);
  g2 = (g, DEC);
  b2 = (b, DEC);
  //collorsensor 3
  pcaselect(3);
  Serial.println("PCA Port #3   collor sensor 3");
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");
  r3 = r;
  g3 = g;
  b3 = b;
  //collorsensor 4
  pcaselect(4);
  Serial.println("PCA Port #4   collor sensor 4");
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");
  r4 = r;
  g4 = g;
  b4 = b;
  //collorsensor 5
  pcaselect(5);
  Serial.println("PCA Port #5   collor sensor 5");
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");
  r5 = r;
  g5 = g;
  b5 = b;
  //collorsensor 6
  pcaselect(6);
  Serial.println("PCA Port #6   collor sensor 6");
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");
  r6 = r;
  g6 = g;
  b6 = b;


/**
    Sensor data collected moving on to engines    

    IR sensor variables collected are ir1, ir2, ir3, ir4, ir5, ir6
    if 0 ball is that direction if 1 ball isnt detected
    ir1 = 0deg
    ir2 = 60deg
    ir3 = 120deg
    ir4 = 180deg
    ir5 = 240deg
    ir6 = 300deg

    Collor sensor variables are r1, g1, b1, r2, g2, b2  ... r6, g6, b6
    stil need to check what color it uses
**/




  Serial.println("\ndone");
  Serial.println("mark end loop");
}
