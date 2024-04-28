/**
i2c port scanner based on:
  in wire library examples i2c_scanner
  https://learn.adafruit.com/adafruit-pca9548-8-channel-stemma-qt-qwiic-i2c-multiplexer/arduino

color sensor based on±
  adafruit TCS34725 librarys
 *
 */

#include <Wire.h>                  //https://www.arduino.cc/reference/en/language/functions/communication/wire/
#include "Adafruit_TCS34725.h"    //https://github.com/adafruit/Adafruit_TCS34725

#define PCAADDR 0x70    //i2c address of the i2c multiplexer

Adafruit_TCS34725 tcs = Adafruit_TCS34725();

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


void setup() {
  Serial.begin(115200);
  while (!Serial); // Leonardo: wait for Serial Monitor
  Serial.println("\nI2C Scanner");

}

void pcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(PCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}
void scandirectports(){
  Wire.begin();
  int nDevices = 0;
  Serial.println("Scanning for i2c ports on board...");

  for (byte address = 1; address < 127; ++address) {
    // The i2c_scanner uses the return value of
    // the Wire.endTransmission to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");

      ++nDevices;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }
}



void loop() {
  Wire.begin();
  
  for (uint8_t t=0; t<50; t++) {
    Serial.println(); 
  }
  
  scandirectports();
  
  Serial.println();
  Serial.println();
  
  for (uint8_t t=0; t<8; t++) {
    pcaselect(t);
    Serial.print("PCA Port #"); Serial.println(t);
    for (uint8_t addr = 0; addr<=127; addr++) {
      if (addr == PCAADDR) continue;
      Wire.beginTransmission(addr);
      if (!Wire.endTransmission()) {
        Serial.print("Found I2C 0x");  Serial.println(addr,HEX);
        Serial.println("scanning for tcs sensor");
        if (tcs.begin()) {
          Serial.println("Found sensor");
          Serial.println("collecting data");
          uint16_t r, g, b, c, colorTemp, lux;
          tcs.getRawData(&r, &g, &b, &c);
          colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
          lux = tcs.calculateLux(r, g, b);
          Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");
          Serial.println();

          
        } else {
          Serial.println("No TCS34725 found ... check your connections");
        }
      }
    }
  }
  Serial.println();
  Serial.println("DONE");
  delay(5500);
}
