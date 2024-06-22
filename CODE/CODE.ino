#include <Wire.h>                 //https://www.arduino.cc/reference/en/language/functions/communication/wire/
#include "Adafruit_TCS34725.h"    //https://github.com/adafruit/Adafruit_TCS34725
#include <Adafruit_MCP23X17.h>    //https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library/tree/master

//25, 26, 27, 28 connect to extra pins for potential expention

//i2c addr
#define PCAADDR 0x70    //i2c address of the i2c multiplexer
#define mcp1ADDR  0x20  //first portmultiplexer for ir sensors
#define mcp2ADDR  0x22  //first portmultiplexer for motors

//miltiplex1
#define ir1  0   // GPA0
#define ir2  1   // GPA1
#define ir3  2   // GPA2
#define ir4  3   // GPA3
#define ir5  4   // GPA4  
#define ir6  5   // GPA5
#define ir7  6   // GPA6
#define ir8  7   // GPA7
#define ir9  8   // GPB0  
#define ir10 9   // GPB1
#define ir11 10  // GPB2
#define ir12 11  // GPB3
#define ir13 12  // GPB4
#define ir14 13  // GPB5
#define ir15 14  // GPB6
#define ir16 15  // GPB7

//miltiplex1
#define pwm5 12  // GPA0  Motor driver 3 pwm1
#define pwm6 13  // GPA1  Motor driver 3 pwm2
#define enB3 14  // GPA2  Motor driver 3 enB
#define enA3 15  // GPA3  Motor driver 3 enA
#define M1A  4   // GPA4  Motor 1 A
#define M1B  5   // GPA5  Morot 1 B
#define M2A  6   // GPA6  Motor 2 A
#define M1B  7   // GPA7  Motpr 2 B
#define pwm1 8   // GPB0  Motor driver 1 pwm1
#define pwm2 9   // GPB1  Motor driver 1 pwm2
#define enB1 10  // GPB2  Motor driver 1 enB
#define enA1 11  // GPB3  Motor driver 1 enA
#define pwm3 12  // GPB4  Motor driver 2 pwm1
#define pwm4 13  // GPB5  Motor driver 2 pwm2
#define enB2 14  // GPB6  Motor driver 2 enB
#define enA2 15  // GPB7  Motor driver 2 enA

//teensy
#define M3A 24  //Motor 3 pin A
#define M3B 9   //Motor 3 pin B
#define dip1 2  //settings dip switch port 1
#define dip2 3  //settings dip switch port 2
#define dip3 4  //settings dip switch port 3
#define dip4 5  //settings dip switch port 4
#define dip5 6  //settings dip switch port 5
#define dip6 27 //settings dip switch port 6
#define buz 8   //buzzer



int dir1 = 1;   // data IR1
int dir2 = 1;   // data IR2
int dir3 = 1;   // etc
int dir4 = 1;   
int dir5 = 1;    
int dir6 = 1;   
int dir7 = 1;   
int dir8 = 1;   
int dir9 = 1;     
int dir10 = 1;  
int dir11 = 1; 
int dir12 = 1; 
int dir13 = 1; 
int dir14 = 1; 
int dir15 = 1; 
int dir16 = 1; 
int colsensdata[6] = {99, 99, 99, 99, 99, 99}; //data colorsensors


Adafruit_MCP23X17 mcp1; // Instance for the first MCP23017 at address 0x20
Adafruit_MCP23X17 mcp2; // Instance for the second MCP23017 at address 0x22

Adafruit_TCS34725 tcs = Adafruit_TCS34725();  // Initialise color sensorwith default values (int time = 2.4ms, gain = 1x) 

String tlocd = ""; //temp data for goal location
String locd = ""; //goal location in deg
bool readloc = false;
unsigned long datatime = 0;

template <typename T_ty> struct TypeInfo { static const char * name; };
template <typename T_ty> const char * TypeInfo<T_ty>::name = "unknown";
#define TYPE_NAME(var) TypeInfo< typeof(var) >::name
#define MAKE_TYPE_INFO(type)  template <> const char * TypeInfo<type>::name = #type;
MAKE_TYPE_INFO( int )
MAKE_TYPE_INFO( float )
MAKE_TYPE_INFO( short )

void setup() {
  Serial.begin(9600);
  -
  Serial1.begin(19200);
  
  //connect unconected pins to GND
  pinMode(40, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);

  // Initialize first MCP23017 with I2C address 0x20
  if (!mcp1.begin_I2C(mcp1ADDR)) {
    Serial.println("(IR_sensors)Error initializing MCP23017 at 0x20.");
  }

  // Initialize second MCP23017 with I2C address 0x22
  if (!mcp2.begin_I2C(mcp2ADDR)) {
    Serial.println("(Motors)Error initializing MCP23017 at 0x22.");
  }

  // Configure pins for the first MCP23017 (0x20)
  mcp1.pinMode(ir1, INPUT);
  mcp1.pinMode(ir2, INPUT);
  mcp1.pinMode(ir3, INPUT);
  mcp1.pinMode(ir4, INPUT);
  mcp1.pinMode(ir5, INPUT);
  mcp1.pinMode(ir6, INPUT);
  mcp1.pinMode(ir7, INPUT);
  mcp1.pinMode(ir8, INPUT);
  mcp1.pinMode(ir9, INPUT);
  mcp1.pinMode(ir10, INPUT);
  mcp1.pinMode(ir11, INPUT);
  mcp1.pinMode(ir12, INPUT);
  mcp1.pinMode(ir13, INPUT);
  mcp1.pinMode(ir14, INPUT);
  mcp1.pinMode(ir15, INPUT);
  mcp1.pinMode(ir16, INPUT);

  // Configure pins for the second MCP23017 (0x22)
  mcp1.pinMode(ir16, INPUT);
  Serial.println("SETUP COMPLETE GOING TO LOOP");
}


void pcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(PCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}


void loop() {
  Wire.begin();
  // Read IR sensors
  dir1 = mcp1.digitalRead(ir1);
  dir2 = mcp1.digitalRead(ir2);
  dir3 = mcp1.digitalRead(ir3);
  dir4 = mcp1.digitalRead(ir4);
  dir5 = mcp1.digitalRead(ir5);
  dir6 = mcp1.digitalRead(ir6);
  dir7 = mcp1.digitalRead(ir7);
  dir8 = mcp1.digitalRead(ir8);
  dir9 = mcp1.digitalRead(ir9);
  dir10 = mcp1.digitalRead(ir10);
  dir11 = mcp1.digitalRead(ir11);
  dir12 = mcp1.digitalRead(ir12);
  dir13 = mcp1.digitalRead(ir13);
  dir14 = mcp1.digitalRead(ir14);
  dir15 = mcp1.digitalRead(ir15);
  dir16 = mcp1.digitalRead(ir16);
  //Read color sensors
  for (uint8_t t=0; t<6; t++) {
    pcaselect(t);
    for (uint8_t addr = 0; addr<=127; addr++) {
      if (addr == PCAADDR) continue;
      Wire.beginTransmission(addr);
      if (!Wire.endTransmission()) {
        if (tcs.begin()) {
          uint16_t r, g, b, c, colorTemp, lux;
          tcs.getRawData(&r, &g, &b, &c);
          colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
          lux = tcs.calculateLux(r, g, b);
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
  //read camera
  if (Serial1.available()){
    datatime = millis(); 

    byte byteRead = Serial1.read();
    
    if (byteRead == 's'){
      tlocd = ""; 
      readloc = true;
    }
    else if (byteRead == 'e'){
      readloc = false;
      locd = tlocd;
    }
    else if (readloc == true){
      tlocd += (char)byteRead;
    }
  }
  else{
    if (millis() - datatime > 5000){
      locd = "999";
    }
  }
  //read compas


  //printing sensor data
  //IR
  Serial.print("IR data: ");
  Serial.print(dir1); Serial.print(", "); Serial.print(dir2);
  Serial.print(", "); Serial.print(dir3); Serial.print(", "); Serial.print(dir4);
  Serial.print(", "); Serial.print(dir5); Serial.print(", "); Serial.print(dir6);
  Serial.print(", "); Serial.print(dir7); Serial.print(", "); Serial.print(dir8);
  Serial.print(", "); Serial.print(dir9); Serial.print(", "); Serial.print(dir10);
  Serial.print(", "); Serial.print(dir11); Serial.print(", "); Serial.print(dir12);
  Serial.print(", "); Serial.print(dir13); Serial.print(", "); Serial.print(dir14);
  Serial.print(", "); Serial.print(dir15); Serial.print(", "); Serial.print(dir16);
  Serial.println();
  delay(250);
  //color
  Serial.print("sensor data = "); // 0=air, 1=green, 2=black, 3=white, 90=error
  for(int i = 0; i < 6; i++){
    Serial.print(colsensdata[i]);
    Serial.print(", ");
  }
  Serial.println();
  //camera
  Serial.print("location of the goal is: ");
  if(locd == 999){
    Serial.println("unknown, there is no working connection with the camera");
  }
  else{
    Serial.println(locd);
  }
  //compas
  //dip settings



  //do stuf with data
  /**
  first move if line is detected with color sens
  is ball in posesion:
    yes: go to goal using camera location
    no: move to ball using IR data
     * 
   */

  Serial.println();
  Serial.println();
  Serial.println();
  delay(1);
}
