#include <SPI.h>

int x;
long randNumber;


volatile boolean received;
volatile byte Slavereceived,Slavesend;

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));
  
  pinMode(MISO,OUTPUT);                  
  SPCR |= _BV(SPE);    
  received = false;
  SPI.attachInterrupt();    
            
}

ISR (SPI_STC_vect){
  Slavereceived = SPDR;   
  received = true; 
}

void loop() {
  // put your main code here, to run repeatedly:
  randNumber = random(0, 1);
  Serial.println(randNumber);
  Slavesend=randNumber;                             
  SPDR = Slavesend;
  delay(1000);

}
