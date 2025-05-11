#include <Arduino.h>

int ir1 = 0;
int ir2 = 1;
int ir3 = 9;
int ir4 = 2;
int ir5 = 3;
int ir6 = 4;
int ir7 = 5;
int ir8 = 8;

int dir1 = 1;   // data IR1
int dir2 = 1;   // data IR2
int dir3 = 1;   // etc
int dir4 = 1;   
int dir5 = 1;    
int dir6 = 1;   
int dir7 = 1;   
int dir8 = 1;

volatile long IRcount1 = 0;
volatile long IRcount2 = 0;
volatile long IRcount3 = 0;
volatile long IRcount4 = 0;
volatile long IRcount5 = 0;
volatile long IRcount6 = 0;
volatile long IRcount7 = 0;
volatile long IRcount8 = 0;

void setup() {
  pinMode(ir1, INPUT);  
  pinMode(ir2, INPUT);  
  pinMode(ir3, INPUT);  
  pinMode(ir4, INPUT);  
  pinMode(ir5, INPUT);  
  pinMode(ir6, INPUT);  
  pinMode(ir7, INPUT);  
  pinMode(ir8, INPUT);

  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("start");
  Serial1.println("start");

  Serial.println("Starting loop");
  Serial1.println("Starting loop");
}

void loop() {
    unsigned long p1 = pulseIn(ir1, HIGH);     //pulse width in microseconds
    unsigned long p2 = pulseIn(ir2, HIGH);     //pulse width in microseconds
    unsigned long p3 = pulseIn(ir3, HIGH);     //pulse width in microseconds
    unsigned long p4 = pulseIn(ir4, HIGH);     //pulse width in microseconds
    unsigned long p5 = pulseIn(ir5, HIGH);     //pulse width in microseconds
    unsigned long p6 = pulseIn(ir6, HIGH);     //pulse width in microseconds
    unsigned long p7 = pulseIn(ir7, HIGH);     //pulse width in microseconds
    unsigned long p8 = pulseIn(ir8, HIGH);     //pulse width in microseconds

    //one seeed xiao uses S-R the other uses B-E as start and end
    // it returns data like this:
    // S0, 0, 0, 0, 0, 0, 0, 0R
    //or
    // B0, 0, 0, 0, 0, 0, 0, 0E

    //Serial1print("B");        //uncomment this line to use B-E
    Serial1.print("S");         //uncomment this line to use S-R    
    Serial1.print(p1);
    Serial1.print(", ");
    Serial1.print(p2);
    Serial1.print(", ");
    Serial1.print(p3);
    Serial1.print(", ");
    Serial1.print(p4);
    Serial1.print(", ");
    Serial1.print(p5);
    Serial1.print(", ");
    Serial1.print(p6);
    Serial1.print(", ");
    Serial1.print(p7);
    Serial1.print(", ");
    Serial1.println(p8);
    //Serial1.println("E");     //uncomment this line to use B-E
    Serialq.println("R");       //uncomment this line to use S-R

    delay(100); // delay to avoid flooding the serial port
}