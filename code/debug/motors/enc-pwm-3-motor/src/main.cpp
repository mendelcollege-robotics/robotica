//motor: https://www.pololu.com/product/4861
//motor driver: https://www.pololu.com/product/2997

//Create the timers
IntervalTimer pwm_timer;
IntervalTimer enc_timer;

//define the pins
//If the motors are spinning incorectly, change pins not the drive function.
int led = 13;

int m1enA = 6;
int m1enB = 5;
int m1pwm1 = 4;
int m1pwm2 = 3;
int m1encoA = 32;
int m1encoB = 31;

int m2enA = 12;
int m2enB = 11;
int m2pwm1 = 9;
int m2pwm2 = 10;
int m2encoA = 30;
int m2encoB = 29;

int m3enA = 27;
int m3enB = 26;
int m3pwm1 = 24;
int m3pwm2 = 25;
int m3encoA = 28;
int m3encoB = 23;

//PWM variables
int pwmacc = 100; //how accurate the PWM is, means you can enter value from 0 to the value of pwmacc
int PWMval1 = 0;  //value of the PWM1, means you can enter value from 0 to the value of pwmacc 
int PWMval2 = 0;  //same but for the second one
int PWMval3 = 0;  //same but for the thirth one

//encoder variables
const int refreshrate = 50; //refresh rate of the encoder
volatile long oneENCcount = 0; //the amount of pulses from motor one encoder 
volatile long twoENCcount = 0; //idem, but motor two
volatile long threeENCcount = 0; //kɛlɔ

double ONErpm = 0.00; //the amount of revolutions motor one makes per minute
double TWOrpm = 0.00; //mismo
double THREErpm = 0.00; //адилхан



void setup() {
  pinMode(m1enA, OUTPUT);
  pinMode(m1enB, OUTPUT);
  pinMode(m1pwm1, OUTPUT);
  pinMode(m1pwm2, OUTPUT);
  
  pinMode(m2enA, OUTPUT);
  pinMode(m2enB, OUTPUT);
  pinMode(m2pwm1, OUTPUT);
  pinMode(m2pwm2, OUTPUT);
  
  pinMode(m3enA, OUTPUT);
  pinMode(m3enB, OUTPUT);
  pinMode(m3pwm1, OUTPUT);
  pinMode(m3pwm2, OUTPUT);

  pwm_timer.begin(updatePWM, refreshrate); //speed at wich PWM is updated PWM 
  enc_timer.begin(enc_refr, 50);  //refresh rate of the encoder

  attachInterrupt(digitalPinToInterrupt(m1encoA), AoneIRS, CHANGE); //calls void AoneIRS if there is a change of the stare of m1encoA
  attachInterrupt(digitalPinToInterrupt(m1encoB), BoneIRS, CHANGE); //ditto
  attachInterrupt(digitalPinToInterrupt(m2encoA), AtwoIRS, CHANGE); //hali
  attachInterrupt(digitalPinToInterrupt(m2encoB), BtwoIRS, CHANGE); //একই
  attachInterrupt(digitalPinToInterrupt(m3encoA), AthreeIRS, CHANGE); //ߊ߬ ߓߍ߮ ߓߋ߫ ߞߟߋ߫
  attachInterrupt(digitalPinToInterrupt(m3encoB), AthreeIRS, CHANGE); //To samo

  Serial.begin(9600);
  Serial.print("start");
  
}

void updatePWM() {
  //PWM one
  //if the entered valvue is less the zero set it to zero, because lower that zero is not posible
  if (PWMval1 < 0) {    
    PWMval1 = 0;
  }
  //if the enterd value is higher than the maximum posible value, set it to max.
  if (PWMval1 > pwmacc) {
    PWMval1 = pwmacc;
  }
  //check if the counter has passed the PWM value, and turn of the motor based on that.
  if (counter1 < PWMval1) {
    digitalWrite(m1enA, HIGH);
  } else {
    digitalWrite(m1enA, LOW);
  }
  counter1++; 

  if (counter1 >= pwmacc) {
    counter1 = 0;
  }

  //PWM two
  static int counter2 = 0;
  if (PWMval2 < 0) {
    PWMval2 = 0;
  }
  if (PWMval2 > pwmacc) {
    PWMval2 = pwmacc;
  }

  if (counter2 < PWMval2) {
    digitalWrite(m2enA, HIGH);
  } else {
    digitalWrite(m2enA, LOW);
  }

  counter2++;
  if (counter2 >= pwmacc) {
    counter2 = 0;
  }

  //PWM three
  int static counter3 = 0;
  if (PWMval3 < 0) {
    PWMval3 = 0;
  }
  if (PWMval3 > pwmacc) {
    PWMval3 = pwmacc;
  }

  if (counter3 < PWMval3) {
    digitalWrite(m3enA, HIGH);
  } else {
    digitalWrite(m3enA, LOW);
  }

  counter3++;
  if (counter3 >= pwmacc) {
    counter3 = 0;
  }
}

void AoneIRS(){
  oneENCcount++ //adds one to the count
}
void BoneIRS(){
  oneENCcount++ //dieselbe
}
void AtwoIRS(){
  twoENCcount++ //même
}
void BtwoIRS(){
  twoENCcount++ //samme
}
void AthreeIRS(){
  threeENCcount++ //aynı
}
void BthreeIRS(){
  threeENCcount++ //такой же
}

void enc_refr(){
  //calculate RPM. It gets updated 48 times per rotation.
  ONErpm = (oneENCcount/48.00) * (60000000.00 / refreshrate)
  TWOrpm = (twoENCcount/48.00) * (60000000.00 / refreshrate)
  THREErpm = (threeENCcount/48.00) * (60000000.00 / refreshrate)
  //reset the counting to zero for next cycle.
  oneENCcount = 0;
  twoENCcount = 0;
  threeENCcount = 0;

}
void drive(int speed, int direction){
 //
 //!!!
 // If the motors are spinning incorectly, change pins not the drive function.
 //!!!
 //
 // 0 = motor off
 // + = motor spinning forwards
 // - = motor spinning backwards
 //
 // Motor 1 is the left one.
 // Motor 2 is the one in the back.
 // Motor 3 is the right one.
 //
 // Direction............|.Motor 1.|.Motor 2.|.Motor 3.
 // 0deg(forward)........|....-....|....0....|....+....
 // 60deg................|....0....|....-....|....+....    
 // 120deg...............|....+....|....-....|....0....
 // 180 deg (backward)...|....+....|....0....|....-.... 
 // 240 deg..............|....0....|....+....|....-....
 // 300 deg..............|....-....|....+....|....0....
 //

  PWMval1 = speed;
  PWMval2 = speed;
  PWMval3 = speed;
  digitalWrite(m1enB, LOW);
  digitalWrite(m2enB, LOW);
  digitalWrite(m3enB, LOW);
  Serial.println("debug2");
  Serial.println(direction);
  if(direction>330 || direction<=30){
    //0 deg
    Serial.println("0 deg");
    digitalWrite(m1pwm1, LOW);
    digitalWrite(m1pwm2, HIGH);

    digitalWrite(m2pwm1, LOW);
    digitalWrite(m2pwm2, LOW);

    digitalWrite(m3pwm1, HIGH);
    digitalWrite(m3pwm2, LOW); 
  }else if (direction>30 && direction <= 90){
    //60 deg
    Serial.println("60deg");
    digitalWrite(m1pwm1, LOW);
    digitalWrite(m1pwm2, LOW);

    digitalWrite(m2pwm1, LOW);
    digitalWrite(m2pwm2, HIGH);
    
    digitalWrite(m3pwm1, HIGH);
    digitalWrite(m3pwm2, LOW);
  }else if (direction>90 && direction <= 150){
    //120 deg
    Serial.println("120 deg");
    digitalWrite(m1pwm1, HIGH);
    digitalWrite(m1pwm2, LOW);

    digitalWrite(m2pwm1, LOW);
    digitalWrite(m2pwm2, HIGH);

    digitalWrite(m3pwm1, LOW);
    digitalWrite(m3pwm2, LOW);
  }else if (direction > 150 && direction <= 210) {
    //180 degrees
    Serial.println("on 180");
    digitalWrite(m1pwm1, HIGH);
    digitalWrite(m1pwm2, LOW);

    digitalWrite(m2pwm1, LOW);
    digitalWrite(m2pwm2, LOW);
    
    digitalWrite(m3pwm1, LOW);
    digitalWrite(m3pwm2, HIGH);
  }else if (direction > 210 && direction <= 270) {
    //240 degrees
    Serial.println("240deg");
    digitalWrite(m1pwm1, LOW);
    digitalWrite(m1pwm2, LOW);

    digitalWrite(m2pwm1, HIGH);
    digitalWrite(m2pwm2, LOW);

    digitalWrite(m3pwm1, LOW);
    digitalWrite(m3pwm2, HIGH);
  }else if (direction > 270 && direction <= 330) {
    //300 degrees
    Serial.println("300deg");
    digitalWrite(m1pwm1, LOW);
    digitalWrite(m1pwm2, HIGH);

    digitalWrite(m2pwm1, HIGH);
    digitalWrite(m2pwm2, LOW);

    digitalWrite(m3pwm1, LOW);
    digitalWrite(m3pwm2, LOW);
  }else{
    Serial.println("how?");  
  }
}

//the loop routine runs over and over again forever:
void loop() {
  drive(50, 0); //speed value between 0-100
  Serial.println("Motor one is at: "+ ONErpm + " RPM.");
  Serial.println("Motor two is at: "+ TWOrpm + " RPM.");
  Serial.println("Motor three is at: "+ THREErpm + " RPM.");
  delay(1500);
}
