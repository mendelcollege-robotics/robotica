int pr1 = 13;
int pr2 = 41;
int pr3 = 40;
int pr4 = 39;
int pr5 = 38;
int pr6 = 37;
int pr7 = 36;
int pr8 = 35;

int dpr1 = "LOW";
int dpr2 = "LOW";
int dpr3 = "LOW";
int dpr4 = "LOW";
int dpr5 = "LOW";
int dpr6 = "LOW";
int dpr7 = "LOW";
int dpr8 = "LOW";


void setup() {
  pinMode(pr1, INPUT);
  pinMode(pr2, INPUT);
  pinMode(pr3, INPUT);
  pinMode(pr4, INPUT);
  pinMode(pr5, INPUT);
  pinMode(pr6, INPUT);
  pinMode(pr7, INPUT);
  pinMode(pr8, INPUT);
}

void loop() {
  dpr1 = digitalRead(pr1);
  dpr2 = digitalRead(pr2); 
  dpr3 = digitalRead(pr3); 
  dpr4 = digitalRead(pr4); 
  dpr5 = digitalRead(pr5); 
  dpr6 = digitalRead(pr6); 
  dpr7 = digitalRead(pr7); 
  dpr8 = digitalRead(pr8); 

  if(dpr1 == HIGH){
    //go back to ?deg
  }else if (dpr2 == HIGH){
    //go back to ?deg
  }else if (dpr3 == HIGH){
    //go back to ?deg
  }else if (dpr4 == HIGH){
    //go back to ?deg
  }else if (dpr5 == HIGH){
    //go back to ?deg
  }else if (dpr6 == HIGH){
    //go back to ?deg
  }else if (dpr7 == HIGH){
    //go back to ?deg
  }else if (dpr8 == HIGH){
    //go back to ?deg
  }
}
