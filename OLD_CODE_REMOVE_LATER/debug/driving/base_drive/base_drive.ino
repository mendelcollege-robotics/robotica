//base code for six direction driving
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
  Serial.begin(9600);
  Serial.print("start");
  
}


void drive(int speed, int direction){
 //
 // Direction............|.Motor 1.|.Motor 2.|.Motor 3.
 // 0deg(forward)........|....0....|....-....|....+....
 // 60deg................|....+....|....-....|....0....    
 // 120deg...............|....+....|....0....|....-....
 // 180 deg (backward)...|....0....|....+....|....-.... 
 // 240 deg..............|....-....|....+....|....0....
 // 300 deg..............|....-....|....0....|....+....
 //

  digitalWrite(m1enA, HIGH);
  digitalWrite(m2enA, HIGH);
  digitalWrite(m3enA, HIGH);
  digitalWrite(m1enB, LOW);
  digitalWrite(m2enB, LOW);
  digitalWrite(m3enB, LOW);
  Serial.println("debug2");
  Serial.println(direction);
  if(direction>330 || direction<=30){
    //0 deg
    digitalWrite(m1pwm1, LOW);
    digitalWrite(m1pwm2, HIGH);

    digitalWrite(m2pwm1, LOW);
    digitalWrite(m2pwm2, LOW);

    digitalWrite(m3pwm1, LOW);
    digitalWrite(m3pwm2, HIGH);
    Serial.println("0 deg"); 
  }else if (direction>30 && direction <= 90){
    //60 deg
    Serial.println("60deg");
    digitalWrite(m1pwm1, LOW);
    digitalWrite(m1pwm2, LOW);

    digitalWrite(m2pwm1, HIGH);
    digitalWrite(m2pwm2, LOW);
    
    digitalWrite(m3pwm1, LOW);
    digitalWrite(m3pwm2, HIGH);
  }else if (direction>90 && direction <= 150){
    //120 deg
    Serial.println("120 deg");
    digitalWrite(m1pwm1, HIGH);
    digitalWrite(m1pwm2, LOW);
    digitalWrite(m2pwm1, HIGH);
    digitalWrite(m2pwm2, LOW);
    digitalWrite(m3pwm1, LOW);
    digitalWrite(m3pwm2, LOW);
  }else if (direction > 150 && direction <= 210) {
    //180 degrees
    Serial.println("on 180");
    digitalWrite(m1pwm1, HIGH);
    digitalWrite(m1pwm2, LOW);

    digitalWrite(m2pwm1, LOW);
    digitalWrite(m2pwm2, LOW);
    
    digitalWrite(m3pwm1, HIGH);
    digitalWrite(m3pwm2, LOW);
  }else if (direction > 210 && direction <= 270) {
    //240 degrees
    digitalWrite(m1pwm1, LOW);
    digitalWrite(m1pwm2, LOW);

    digitalWrite(m2pwm1, LOW);
    digitalWrite(m2pwm2, HIGH);

    digitalWrite(m3pwm1, HIGH);
    digitalWrite(m3pwm2, LOW);
  }else if (direction > 270 && direction <= 330) {
    //300 degrees
    digitalWrite(m1pwm1, LOW);
    digitalWrite(m1pwm2, HIGH);
    digitalWrite(m2pwm1, LOW);
    digitalWrite(m2pwm2, HIGH);
    Serial.println("300deg");
    digitalWrite(m3pwm1, LOW);
    digitalWrite(m3pwm2, LOW);
  }else{
    Serial.println("how?");  
  }
}

// the loop routine runs over and over again forever:
void loop() {
  drive(255, 0);
  Serial.println("ffor");
  delay(1500);
  drive(255, 180);
  Serial.println("back");
  delay(1500);

}
