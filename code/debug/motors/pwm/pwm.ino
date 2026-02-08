#include <SoftPWM.h>

IntervalTimer enctimer; //encoder timer for speed calc

int m1enA = LED_BUILTIN;  //motor 1 enA
int m1enB = 5;            //motor 1 enB
int m1pwm1 = 4;           //motor 1 PWM1
int m1pwm2 = 3;           //motor 1 PWM2
int m1encoA = 32;         //motor 1 encoderA
int m1encoB = 31;         //motor 1 encoderB
int buzzer = 13;          //pin where the buzzer is

volatile int m1enc = 0; // encoder pulses counted
volatile float m1encSP = 0; // motor speed (updated in interrupt)
int interuptDuration = 50; //how often speed counter is updated

void setup() {
  //serial
  Serial.begin(9600);
  Serial1.begin(75);

  //enable softPWM
  SoftPWMBegin();
  SoftPWMSetPolarity(m1enA, 0);
  SoftPWMSet(m1enA, 0);

  //set pins
  pinMode(m1enB, OUTPUT);
  pinMode(m1pwm1, OUTPUT);
  pinMode(m1pwm2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  noTone(buzzer);

  //create interupts
  attachInterrupt(digitalPinToInterrupt(m1encoA), encaDET, RISING);
  enctimer.begin(updateSpeed, interuptDuration*1000);

}


void loop() {
  SoftPWMSet(m1enA, 50);
  digitalWrite(m1enB, LOW);
  digitalWrite(m1pwm1, HIGH);
  digitalWrite(m1pwm2, LOW);
  delay(500);
  SoftPWMSet(m1enA, 255);
  digitalWrite(m1enA, HIGH);
  digitalWrite(m1enB, LOW);
  digitalWrite(m1pwm1, LOW);
  digitalWrite(m1pwm2, HIGH);
  delay(500);
}

void encaDET() {
  //when encoder detect a change
  m1enc++;
}

void updateSpeed() {
  //6 interupts per rotation and interuptDuration but in seconds
  m1encSP = (m1enc / 6.0) / (interuptDuration/1000.0);
  m1enc = 0;
  if (m1encSP < 1 || isnan(m1encSP)) {
    m1encSP = 0;
    tone(buzzer, 1000);
    Serial.println(" ___________________________");
    Serial.println("< Motor 1 encoder is fucked >");
    Serial.println(" ---------------------------");
    Serial.println("                       \\                    ^    /^");
    Serial.println("                        \\                  / \\  // \\");
    Serial.println("                         \\   |\\___/|      /   \\//  .\\");
    Serial.println("                          \\  /O  O  \\__  /    //  | \\ \\           *----*");
    Serial.println("                            /     /  \\/_/    //   |  \\  \\          \\   |");
    Serial.println("                            @___@`    \\/_   //    |   \\   \\         \\/\\ \\");
    Serial.println("                           0/0/|       \\/_ //     |    \\    \\         \\  \\");
    Serial.println("                       0/0/0/0/|        \///      |     \\     \\       |  |");
    Serial.println("                    0/0/0/0/0/_|_ /   (  //       |      \\     _\\     |  /");
    Serial.println("                 0/0/0/0/0/0/`/,_ _ _/  ) ; -.    |    _ _\\.-~       /   /");
    Serial.println("                             ,-}        _      *-.|.-~-.           .~    ~");
    Serial.println("            \\     \\__/        `/\\      /                 ~-. _ .-~      /");
    Serial.println("             \\____(oo)           *.   }            {                   /");
    Serial.println("             (    (--)          .----~-.\\        \\-`                 .~");
    Serial.println("             //__\\\  \\__ Ack!   ///.----..<        \\             _ -~");
    Serial.println("            //    \\\               ///-._ _ _ _ _ _ _{^ - - - - ~");
    Serial.println("");
  }
}