// code to send random numbers via the seeed XIAO's Serial1 port
#include <Arduino.h>

long rn1;
long rn2;
long rn3;
long rn4;
long rn5;
long rn6;
long rn7;
long rn8;


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("Starting loop");

  randomSeed(analogRead(0));
}

void loop() {
  rn1 = random(1500);
  rn2 = random(1500);
  rn3 = random(1500);
  rn4 = random(1500);
  rn5 = random(1500); 
  rn6 = random(1500);
  rn7 = random(1500);
  rn8 = random(1500);

  Serial1.print("S");
  //Serial1.print("B");
  Serial1.print(rn1);
  Serial1.print(", ");
  Serial1.print(rn2);
  Serial1.print(", ");
  Serial1.print(rn3);
  Serial1.print(", ");
  Serial1.print(rn4);
  Serial1.print(", ");
  Serial1.print(rn5);
  Serial1.print(", ");
  Serial1.print(rn6);
  Serial1.print(", ");
  Serial1.print(rn7);
  Serial1.print(", ");
  Serial1.println(rn8);
  Serial.println("R"); 
  //Serial1.print("E");


  delay(250);

}