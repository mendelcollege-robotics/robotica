#include <SPI.h>

int x;

void setup() {
  Serial.begin(115200);    
  SPI.begin(); 
  SPI.setClockDivider(SPI_CLOCK_DIV8);   
  digitalWrite(SS,HIGH);      

}

void loop() {
  byte Mastersend,Mastereceive;
  digitalWrite(SS, LOW);  
  x = 1;
  Mastersend = x;
  Mastereceive=SPI.transfer(Mastersend);        
  if(Mastereceive == 1){
    Serial.println("Master receive 1");
  }
  else{
   Serial.println("Master receive 0");
  }

}
