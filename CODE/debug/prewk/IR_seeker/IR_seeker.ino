#include <Adafruit_MCP23X17.h>

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

volatile long IRcount1 = 0;
volatile long IRcount2 = 0;
volatile long IRcount3 = 0;
volatile long IRcount4 = 0;
volatile long IRcount5 = 0;
volatile long IRcount6 = 0;
volatile long IRcount7 = 0;
volatile long IRcount8 = 0;
volatile long IRcount9 = 0;
volatile long IRcount10 = 0;
volatile long IRcount11 = 0;
volatile long IRcount12 = 0;
volatile long IRcount13 = 0;
volatile long IRcount14 = 0;
volatile long IRcount15 = 0;
volatile long IRcount16 = 0;

// Instance for the first MCP23017 at address 0x20
Adafruit_MCP23X17 mcp1;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("MCP23xxx Button Test!");

  // Initialize first MCP23017 with I2C address 0x20
  if (!mcp1.begin_I2C(0x20)) {
    Serial.println("Error initializing MCP23017 at 0x20.");
    while (1);
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
  
  attachInterrupt(digitalPinToInterrupt(ir1), IRtrigger1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir2), IRtrigger2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir3), IRtrigger3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir4), IRtrigger4, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir5), IRtrigger5, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir6), IRtrigger6, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir7), IRtrigger7, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir8), IRtrigger8, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir9), IRtrigger9, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir10), IRtrigger10, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir11), IRtrigger11, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir12), IRtrigger12, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir13), IRtrigger13, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir14), IRtrigger14, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir15), IRtrigger15, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir16), IRtrigger16, CHANGE);

  Serial.println("Looping...");
}

void IRtrigger1() {
  IRcount1++;
}
void IRtrigger2() {
  IRcount2++;
}
void IRtrigger3() {
  IRcount3++;
}
void IRtrigger4() {
  IRcount4++;
}
void IRtrigger5() {
  IRcount5++;
}
void IRtrigger6() {
  IRcount6++;
}
void IRtrigger7() {
  IRcount7++;
}
void IRtrigger8() {
  IRcount8++;
}
void IRtrigger9() {
  IRcount9++;
}
void IRtrigger10() {
  IRcount10++;
}
void IRtrigger11() {
  IRcount11++;
}
void IRtrigger12() {
  IRcount12++;
}
void IRtrigger13() {
  IRcount13++;
}
void IRtrigger14() {
  IRcount14++;
}
void IRtrigger15() {
  IRcount15++;
}
void IRtrigger16() {
  IRcount16++;
}


void loop() {
  Serial.print("ir 1 changes: ");
  Serial.print(IRcount1);
  Serial.print(", ir 2 changes: ");
  Serial.print(IRcount2);
  Serial.print(", ir 3 changes: ");
  Serial.print(IRcount3);
  Serial.print(", ir 4 changes: ");
  Serial.print(IRcount4);
  Serial.print(", ir 5 changes: ");
  Serial.print(IRcount5);
  Serial.print(", ir 6 changes: ");
  Serial.print(IRcount6);
  Serial.print(", ir 7 changes: ");
  Serial.print(IRcount7);
  Serial.print(", ir 8 changes: ");
  Serial.print(IRcount8);
  Serial.print(", ir 9 changes: ");
  Serial.print(IRcount9);
  Serial.print(", ir 10 changes: ");
  Serial.print(IRcount10);
  Serial.print(", ir 11 changes: ");
  Serial.print(IRcount11);
  Serial.print(", ir 12 changes: ");
  Serial.print(IRcount12);
  Serial.print(", ir 13 changes: ");
  Serial.print(IRcount13);
  Serial.print(", ir 14 changes: ");
  Serial.print(IRcount14);
  Serial.print(", ir 15 changes: ");
  Serial.print(IRcount15);
  Serial.print(", ir 16 changes: ");
  Serial.println(IRcount16);

  volatile long IRcounts[] = {IRcount1, IRcount2, IRcount3, IRcount4, IRcount5, IRcount6, IRcount7, IRcount8, IRcount9, IRcount10, IRcount11, IRcount12, IRcount13, IRcount14, IRcount15, IRcount16};
  long maxCount = IRcounts[0];
  int highessensor = 1;
  for (int i = 0; i < 15; ++i) {
    if (IRcounts[i] > maxCount) {
      maxCount = IRcounts[i];
      highessensor = i + 1;
    }
  }
  Serial.print("Ball is at sensor: ");
  Serial.print(highessensor);
  Serial.print(", with value of ");
  Serial.println(maxCount);

  delay(250);
}
