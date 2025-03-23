#include <Arduino.h>

int incomingbyte = 0; 
bool iswriting = false;
String tlocdat = "";  //temporary location data 
String locdat = "";   //location data
int ir1 = -99;
int ir2 = -99;
int ir3 = -99;
int ir4 = -99;
int ir5 = -99;
int ir6 = -99;
int ir7 = -99;
int ir8 = -99;


void setup() {
  Serial.begin(9600);
  Serial3.begin(9600); //19200
}

void loop() {
  if (Serial3.available() > 0) {
    incomingbyte = Serial3.read();
    //Serial.print(char(incomingbyte));
    if (incomingbyte == 's'){
      iswriting = true;
      tlocdat = "";
    }else if(incomingbyte == 'e'){
      iswriting = false;
      locdat = tlocdat;        
    }else if(iswriting == true){
      //Serial.print(char(incomingbyte));
      tlocdat += (char)incomingbyte;  
    }
  }
  //Serial.println(locdat);
  sscanf(locdat.c_str(), "%d, %d, %d, %d, %d, %d, %d, %d", &ir1, &ir2, &ir3, &ir4, &ir5, &ir6, &ir7, &ir8);
  Serial.print("IR sensor N: ");
  Serial.print(ir1);
  Serial.print(ir2);
  Serial.print(ir3);
  Serial.print(ir4);
  Serial.print(ir5);
  Serial.print(ir6);
  
  delay(10);
}