// this code is for Teensy 4.1 to read serial data and relay it to serial 1(computer)

#include <Arduino.h>

int incomingbyte = 0; 
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600); //19200
  Serial3.begin(9600); //19200
  Serial.print("Starting ....");
}

void loop() {
  if (Serial3.available() > 0) {
    incomingbyte = Serial3.read();
    Serial.print(char(incomingbyte));
  }
  milis(1);
  
} 