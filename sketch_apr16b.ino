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
const byte SX1509_IR_SENS1 = 0; // ir sens 1 to SX1509's pin 0
const byte SX1509_IR_SENS2 = 1; // ir sens 2 to SX1509's pin 1
const byte SX1509_IR_SENS1 = 2; // ir sens 3 to SX1509's pin 2
const byte SX1509_IR_SENS2 = 3; // ir sens 4 to SX1509's pin 3
const byte SX1509_IR_SENS1 = 4; // ir sens 5 to SX1509's pin 4
const byte SX1509_IR_SENS2 = 5; // ir sens 6 to SX1509's pin 5

int ir1 = 1;
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
  Serial.println("mark 1")
  io.pinMode(SX1509_IR_SENS1, INPUT);
  io.pinMode(SX1509_IR_SENS2, INPUT);
  io.pinMode(SX1509_IR_SENS3, INPUT);
  io.pinMode(SX1509_IR_SENS4, INPUT);
  io.pinMode(SX1509_IR_SENS5, INPUT);
  io.pinMode(SX1509_IR_SENS6, INPUT);
  Serial.println("mark 2")
}

void loop() 
{
  delay(1000);

  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nPCAScanner ready!");

  //port expander
  pcaselect(0);
  Serial.println("PCA Port #0   port multiplier");
  ir1 = io.digitalRead(SX1509_IR_SENS1);
  Serial.println(ir1);
  ir2 = io.digitalRead(SX1509_IR_SENS2);
  Serial.println(ir2);
  ir3 = io.digitalRead(SX1509_IR_SENS3);
  Serial.println(ir3);
  ir4 = io.digitalRead(SX1509_IR_SENS4);
  Serial.println(ir4);
  ir5 = io.digitalRead(SX1509_IR_SENS5);
  Serial.println(ir5);
  ir6 = io.digitalRead(SX1509_IR_SENS6);
  Serial.println(ir6);

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


  
    
  Serial.println("mark end");
  Serial.println("\ndone");
}
