
#include <Wire.h>                  //https://www.arduino.cc/reference/en/language/functions/communication/wire/
#include "Adafruit_TCS34725.h"    //https://github.com/adafruit/Adafruit_TCS34725

#define PCAADDR 0x70    //i2c address of the i2c multiplexer


Adafruit_TCS34725 tcs = Adafruit_TCS34725();/* Initialise with default values (int time = 2.4ms, gain = 1x) */

int colsensdata[6] = {99, 99, 99, 99, 99, 99};

void setup() {
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");

}

void pcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(PCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

template <typename T_ty> struct TypeInfo { static const char * name; };
template <typename T_ty> const char * TypeInfo<T_ty>::name = "unknown";
#define TYPE_NAME(var) TypeInfo< typeof(var) >::name
#define MAKE_TYPE_INFO(type)  template <> const char * TypeInfo<type>::name = #type;
MAKE_TYPE_INFO( int )
MAKE_TYPE_INFO( float )
MAKE_TYPE_INFO( short )

void loop() {
  Wire.begin();
  for (uint8_t t=0; t<6; t++) {
    pcaselect(t);
    Serial.print("PCA Port #"); Serial.println(t);
    for (uint8_t addr = 0; addr<=127; addr++) {
      if (addr == PCAADDR) continue;
      Wire.beginTransmission(addr);
      if (!Wire.endTransmission()) {
        Serial.print("Found I2C 0x");  Serial.println(addr,HEX);
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
            colsensdata[t] = 0;
          }
          else if ((g)>=(2*(r)) && (g)>=12){
            colsensdata[t] = 1; 
          }
          else if ((colorTemp)>= 6750){
            colsensdata[t] = 2; 
          }
          else if ((colorTemp) < 6750){
            colsensdata[t] = 3;
          }
          else{
            Serial.println(colorTemp);
            Serial.println(TYPE_NAME((colorTemp, DEC)));
            colsensdata[t] = 98;
          }
        } else {
          Serial.println("No TCS34725 found ... check your connections");
          colsensdata[t] = 97;
        }
      }
    }
  }
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
  delay(2500);
}