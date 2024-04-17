/**
 * TCA9548 I2CScanner.ino -- I2C bus scanner for Arduino
 *
 * Based on https://playground.arduino.cc/Main/I2cScanner/
 *
 */

#include "Wire.h"
#include "Adafruit_TCS34725.h"
#define PCAADDR 0x70
#include <SparkFunSX1509.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

const byte SX1509_ADDRESS = 0x3E; // SX1509 I2C address
SX1509 io;                        // Create an SX1509 object to be used throughout
const byte SX1509_IR_SENS1 = 1; // ir sens 1 to SX1509's pin 1
const byte SX1509_IR_SENS2 = 2; // ir sens 2 to SX1509's pin 2
const byte SX1509_IR_SENS3 = 3; // ir sens 3 to SX1509's pin 3
const byte SX1509_IR_SENS4 = 4; // ir sens 4 to SX1509's pin 4
const byte SX1509_IR_SENS5 = 5; // ir sens 5 to SX1509's pin 5
const byte SX1509_IR_SENS6 = 6; // ir sens 6 to SX1509's pin 6
const byte SX1509_IR_SENS7 = 7; // ir sens 7 to SX1509's pin 7
const byte SX1509_IR_SENS8 = 8; // ir sens 8 to SX1509's pin 8



int ir1 = 1; // IR sensor 1
int ir2 = 2; // IR sensor 2
int ir3 = 3; // IR sensor 3
int ir4 = 4; // IR sensor 4
int ir5 = 5; // IR sensor 5
int ir6 = 6; // IR sensor 6
int ir7 = 7; // IR sensor 7
int ir8 = 8; // IR sensor 8

void pcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(PCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}


// standard Arduino setup()
void setup()
{
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
  io.pinMode(SX1509_IR_SENS7, INPUT);
  io.pinMode(SX1509_IR_SENS8, INPUT);

}

void loop() 
{
  delay(1);

  Wire.begin();
  Serial.begin(115200);
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
  ir7 = io.digitalRead(SX1509_IR_SENS7);
  ir8 = io.digitalRead(SX1509_IR_SENS8);

  // Define a string to store the collected data
  String irsensdata = "";

  // Read the digital state of each IR sensor pin and concatenate the data to the string
  irsensdata += String(io.digitalRead(SX1509_IR_SENS1));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS2));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS3));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS4));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS5));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS6));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS7));
  irsensdata += String(io.digitalRead(SX1509_IR_SENS8));
  // Print the collected data
  Serial.print("IR sensor data: ")
  Serial.println(irsensdata);



  //collorsensor 1
  pcaselect(1);
  Serial.println("PCA Port #1   collor sensor 1");
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");

  //collorsensor 2
  pcaselect(2);
  Serial.println("PCA Port #2   collor sensor 2");
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");

  //collorsensor 3
  pcaselect(3);
  Serial.println("PCA Port #3   collor sensor 3");
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");

  //collorsensor 4
  pcaselect(4);
  Serial.println("PCA Port #4   collor sensor 4");
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");

  //collorsensor 5
  pcaselect(5);
  Serial.println("PCA Port #5   collor sensor 5");
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");

  //collorsensor 6
  pcaselect(6);
  Serial.println("PCA Port #6   collor sensor 6");
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");
    

  Serial.println("\ndone");
}
