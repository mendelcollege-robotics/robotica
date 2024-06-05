//https://tronixstuff.com/2011/08/26/arduino-mcp23017-tutorial/
//https://www.circuitbasics.com/how-to-use-an-mpc23017-port-expander-on-the-arduino/
//https://ww1.microchip.com/downloads/en/devicedoc/20001952c.pdf



#include <Wire.h> 
byte BbyteVal=0;
byte AbyteVal=0;
byte chipAddr = 0x20;
byte GPIOA = 0x12; // PortA reg addr
byte GPIOB = 0x13; // PortB reg addr
byte IODIRA = 0x00; // PortA direction reg addr
byte IODIRB = 0x01; // PortB direction reg addr

void setup(){
  Serial.begin(9600);
  Wire.begin();
  
  Wire.beginTransmission(chipAddr);
  Wire.write(IODIRA); // IODIRA dir register
  Wire.write(0xff); // set entire PORT A  as output
  Wire.endTransmission();

  Wire.beginTransmission(chipAddr);
  Wire.write(IODIRB); // IODIRB dir register
  Wire.write(0xff); // set entire PORT B as input
  Wire.endTransmission();
  }

void loop(){    
  Wire.beginTransmission(chipAddr);
  Wire.write(GPIOB);  // read the inputs off PORT B
  Wire.requestFrom(chipAddr, 1); // ask for 1 byte
  BbyteVal = Wire.read(); // read it
  Wire.endTransmission();
  Serial.println(BbyteVal);

  Wire.beginTransmission(chipAddr);
  Wire.write(GPIOB);  // read the inputs off PORT B
  Wire.requestFrom(chipAddr, 1); // ask for 1 byte
  AbyteVal = Wire.read(); // read it
  Wire.endTransmission();
  Serial.println(AbyteVal);
}
