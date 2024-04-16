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
const byte SX1509_IR_SENS1 = 15; // ir sens 1 to SX1509's pin 15

int ir1 = 1;
int port2 = 1;

void pcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(PCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}


// standard Arduino setup()
void setup(){
    delay(1000);
    pinMode(2, INPUT);
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
    io.pinMode(SX1509_IR_SENS1, INPUT);
}

void loop(){
  delay(1000);

  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nPCAScanner ready!");

  //port 2
  port2 = digitalRead(2);
  Serial.println(port2);
  
  //port expander
  pcaselect(0);
  Serial.println("PCA Port #0   port multiplier");
  ir1 = io.digitalRead(SX1509_IR_SENS1);
  Serial.println(ir1);

  //collorsensor 1
  pcaselect(1);
  Serial.println("PCA Port #1   collor sensor 1");
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");
    

  Serial.println("\ndone");
}
