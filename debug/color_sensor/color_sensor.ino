/**
i2c port scanner based on:
  in wire library examples i2c_scanner
  https://learn.adafruit.com/adafruit-pca9548-8-channel-stemma-qt-qwiic-i2c-multiplexer/arduino

color sensor based on±
  adafruit TCS34725 librarys

 type var:
  https://arduino.stackexchange.com/questions/3079/how-to-retrieve-the-data-type-of-a-variable
  
 *
 */

#include <Wire.h>                  //https://www.arduino.cc/reference/en/language/functions/communication/wire/
#include "Adafruit_TCS34725.h"    //https://github.com/adafruit/Adafruit_TCS34725

#define PCAADDR 0x70    //i2c address of the i2c multiplexer

/* Initialise with default values (int time = 2.4ms, gain = 1x) */
Adafruit_TCS34725 tcs = Adafruit_TCS34725();
//Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

const int buzzer = 6; //buzzer to arduino pin 9


int colsensdata[6] = {99, 99, 99, 99, 99, 99};



void setup() {
  Serial.begin(115200);
  //while (!Serial); // Leonardo: wait for Serial Monitor
  Serial.println("\nI2C Scanner");
  pinMode(buzzer, OUTPUT);

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


// Generic catch-all implementation.
template <typename T_ty> struct TypeInfo { static const char * name; };
template <typename T_ty> const char * TypeInfo<T_ty>::name = "unknown";

// Handy macro to make querying stuff easier.
#define TYPE_NAME(var) TypeInfo< typeof(var) >::name

// Handy macro to make defining stuff easier.
#define MAKE_TYPE_INFO(type)  template <> const char * TypeInfo<type>::name = #type;

// Type-specific implementations.
MAKE_TYPE_INFO( int )
MAKE_TYPE_INFO( float )
MAKE_TYPE_INFO( short )

void loop() {
  Wire.begin();
  
  for (uint8_t t=0; t<50; t++) {
    Serial.println(); 
  }
  
  scandirectports();
  
  Serial.println();
  Serial.println();
  
  for (uint8_t t=0; t<6; t++) {
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
          Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
          Serial.print("RGB: "); Serial.print(r, DEC); Serial.print(", "); Serial.print(g, DEC); Serial.print(", "); Serial.print(b, DEC); Serial.println(" ");
          if ((colorTemp) == 5201){
            Serial.println("sensor in air");
            tone(buzzer, 100);
            colsensdata[t] = 0;
          }
          else if ((g)>=(2*(r)) && (g)>=12){
            Serial.println("green");  
            tone(buzzer, 200);
            colsensdata[t] = 1; 
          }
          else if ((colorTemp)>= 6750){
            Serial.println("black"); 
            tone(buzzer, 300);
            colsensdata[t] = 2; 
          }
          else if ((colorTemp) < 6750){
            Serial.println("white");  
            tone(buzzer, 400);
            colsensdata[t] = 3;
          }
          else{
            Serial.println(colorTemp);
            Serial.println(TYPE_NAME((colorTemp, DEC)));
            colsensdata[t] = 98;
          }
          Serial.println();

          
        } else {
          Serial.println("No TCS34725 found ... check your connections");
          colsensdata[t] = 97;
        }
        delay(500);
      }
    }
  }
  Serial.println();
  Serial.print("sensor data = ");
  for(int i = 0; i < 6; i++){
  Serial.print(colsensdata[i]);
  Serial.print(", ");
  }
  /**
0 = air
1 = green
2 = black
3 = white
90 = error
   
   * 
   */
  Serial.println("");
  Serial.println("DONE");
  tone(buzzer, 1000);
  delay(2500);
}
