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

  attachInterrupt(digitalPinToInterrupt(ir1), IRtrigger1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir2), IRtrigger2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir3), IRtrigger3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir4), IRtrigger4, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir5), IRtrigger5, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir6), IRtrigger6, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir7), IRtrigger7, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir8), IRtrigger8, CHANGE);

  Serial.println("Starting loop");
  Serial1.println("Starting loop");
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

  Serial1.print("ir 1 changes: ");
  Serial1.print(IRcount1);
  Serial1.print(", ir 2 changes: ");
  Serial1.print(IRcount2);
  Serial1.print(", ir 3 changes: ");
  Serial1.print(IRcount3);
  Serial1.print(", ir 4 changes: ");
  Serial1.print(IRcount4);
  Serial1.print(", ir 5 changes: ");
  Serial1.print(IRcount5);
  Serial1.print(", ir 6 changes: ");
  Serial1.print(IRcount6);
  Serial1.print(", ir 7 changes: ");
  Serial1.print(IRcount7);
  Serial1.print(", ir 8 changes: ");
  Serial1.print(IRcount8);

    volatile long IRcounts[] = {IRcount1, IRcount2, IRcount3, IRcount4, IRcount5, IRcount6, IRcount7, IRcount8};
  long maxCount = IRcounts[0];
  int highessensor = 1;
  for (int i = 0; i < 7; ++i) {
    if (IRcounts[i] > maxCount) {
      maxCount = IRcounts[i];
      highessensor = i + 1;
    }
  }
  Serial.print("Ball is at sensor: ");
  Serial.print(highessensor);
  Serial.print(", with value of ");
  Serial.println(maxCount);

  Serial1.print("s");
  Serial1.print(highessensor);
  Serial1.print(", ");
  Serial1.println(maxCount);
  Serial1.print("e");

  IRcount1 = 0;
  IRcount2 = 0;
  IRcount3 = 0;
  IRcount4 = 0;
  IRcount5 = 0;
  IRcount6 = 0;
  IRcount7 = 0;
  IRcount8 = 0;



  delay(250);

}
