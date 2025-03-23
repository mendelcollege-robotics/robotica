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

int dir17 = 1;   // data IR17
int dir18 = 1;   // data IR18
int dir19 = 1;   // etc
int dir20 = 1;   
int dir21 = 1;    
int dir22 = 1;   
int dir23 = 1;   
int dir24 = 1;   
int dir25 = 1;     
int dir26 = 1;  
int dir27 = 1; 
int dir28 = 1; 
int dir29 = 1; 
int dir30 = 1; 
int dir31 = 1; 
int dir32 = 1; 

// Instance for the first MCP23017 at address 0x20
Adafruit_MCP23X17 mcp1;

// Instance for the second MCP23017 at address 0x22
Adafruit_MCP23X17 mcp2;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("MCP23xxx Button Test!");

  // Initialize first MCP23017 with I2C address 0x20
  if (!mcp1.begin_I2C(0x20)) {
    Serial.println("Error initializing MCP23017 at 0x20.");
    while (1);
  }

  // Initialize second MCP23017 with I2C address 0x22
  if (!mcp2.begin_I2C(0x22)) {
    Serial.println("Error initializing MCP23017 at 0x22.");
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

  // Configure pins for the second MCP23017 (0x22)
  mcp2.pinMode(ir1, INPUT);
  mcp2.pinMode(ir2, INPUT);
  mcp2.pinMode(ir3, INPUT);
  mcp2.pinMode(ir4, INPUT);
  mcp2.pinMode(ir5, INPUT);
  mcp2.pinMode(ir6, INPUT);
  mcp2.pinMode(ir7, INPUT);
  mcp2.pinMode(ir8, INPUT);
  mcp2.pinMode(ir9, INPUT);
  mcp2.pinMode(ir10, INPUT);
  mcp2.pinMode(ir11, INPUT);
  mcp2.pinMode(ir12, INPUT);
  mcp2.pinMode(ir13, INPUT);
  mcp2.pinMode(ir14, INPUT);
  mcp2.pinMode(ir15, INPUT);
  mcp2.pinMode(ir16, INPUT);

  Serial.println("Looping...");
}

void loop() {
  // Read pins from the first MCP23017 (0x20)
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
  
  // Read pins from the second MCP23017 (0x22)
  dir17 = mcp2.digitalRead(ir1);
  dir18 = mcp2.digitalRead(ir2);
  dir19 = mcp2.digitalRead(ir3);
  dir20 = mcp2.digitalRead(ir4);
  dir21 = mcp2.digitalRead(ir5);
  dir22 = mcp2.digitalRead(ir6);
  dir23 = mcp2.digitalRead(ir7);
  dir24 = mcp2.digitalRead(ir8);
  dir25 = mcp2.digitalRead(ir9);
  dir26 = mcp2.digitalRead(ir10);
  dir27 = mcp2.digitalRead(ir11);
  dir28 = mcp2.digitalRead(ir12);
  dir29 = mcp2.digitalRead(ir13);
  dir30 = mcp2.digitalRead(ir14);
  dir31 = mcp2.digitalRead(ir15);
  dir32 = mcp2.digitalRead(ir16);
  
  // Print the results from the first MCP23017 (0x20)
  Serial.print("MCP23017 @ 0x20: ");
  Serial.print(dir1); Serial.print(", "); Serial.print(dir2);
  Serial.print(", "); Serial.print(dir3); Serial.print(", "); Serial.print(dir4);
  Serial.print(", "); Serial.print(dir5); Serial.print(", "); Serial.print(dir6);
  Serial.print(", "); Serial.print(dir7); Serial.print(", "); Serial.print(dir8);
  Serial.print(", "); Serial.print(dir9); Serial.print(", "); Serial.print(dir10);
  Serial.print(", "); Serial.print(dir11); Serial.print(", "); Serial.print(dir12);
  Serial.print(", "); Serial.print(dir13); Serial.print(", "); Serial.print(dir14);
  Serial.print(", "); Serial.print(dir15); Serial.print(", "); Serial.print(dir16);

  // Print the results from the second MCP23017 (0x22)
  Serial.print("  MCP23017 @ 0x22: ");
  Serial.print(dir17); Serial.print(", "); Serial.print(dir18);
  Serial.print(", "); Serial.print(dir19); Serial.print(", "); Serial.print(dir20);
  Serial.print(", "); Serial.print(dir21); Serial.print(", "); Serial.print(dir22);
  Serial.print(", "); Serial.print(dir23); Serial.print(", "); Serial.print(dir24);
  Serial.print(", "); Serial.print(dir25); Serial.print(", "); Serial.print(dir26);
  Serial.print(", "); Serial.print(dir27); Serial.print(", "); Serial.print(dir28);
  Serial.print(", "); Serial.print(dir29); Serial.print(", "); Serial.print(dir30);
  Serial.print(", "); Serial.print(dir31); Serial.print(", "); Serial.println(dir32);
  
  Serial.println();
  delay(250);
}
