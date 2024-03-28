// motor one
int enA = 33;
int in1 = 2;
int in2 = 3;
// motor two
int enB = 36;
int in3 = 4;
int in4 = 5;
// motor three
int enC = 37;
int in5 = 8;
int in6 = 9;

void setup()
{
 // set all the motor control pins to outputs
 pinMode(enA, OUTPUT);
 pinMode(enB, OUTPUT);
 pinMode(enC, OUTPUT);

 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
 pinMode(in5, OUTPUT);
 pinMode(in6, OUTPUT);
}
void demoOne()
{
// this function will run the motors in both directions at a fixed speed
 // turn on motor A
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 // set speed to 200 out of possible range 0~255
 analogWrite(enA, 200);
 // turn on motor B
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 // set speed to 200 out of possible range 0~255
 analogWrite(enB, 200);
  // turn on motor c
 digitalWrite(in5, HIGH);
 digitalWrite(in6, LOW);
 // set speed to 200 out of possible range 0~255
 analogWrite(enC, 200);
 delay(2000);
 // now change motor directions
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 digitalWrite(in5, LOW);
 digitalWrite(in6, HIGH);
 delay(2000);
 // now turn off motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
}
void demoTwo()
{
 // this function will run the motors across the range of possible speeds
 // note that maximum speed is determined by the motor itself and theoperating voltage
 // the PWM values sent by analogWrite() are fractions of the maximumspeed possible
 // by your hardware
 // turn on motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 digitalWrite(in5, LOW);
 digitalWrite(in6, HIGH);
 // accelerate from zero to maximum speed
 for (int i = 0; i < 256; i++)
 {
 analogWrite(enA, i);
 analogWrite(enB, i);
 analogWrite(enC, i); 
 delay(20);
 }
 // decelerate from maximum speed to zero
 for (int i = 255; i >= 0; --i)
 {
  analogWrite(enA, i);
  analogWrite(enB, i);
  analogWrite(enC, i);
  delay(20);
 }
 // now turn off motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
 digitalWrite(in5, LOW);
 digitalWrite(in6, LOW);
}
void forward(speed, direction)
{
 // this function will run the motors across the range of possible speeds
 // note that maximum speed is determined by the motor itself and theoperating voltage
 // the PWM values sent by analogWrite() are fractions of the maximumspeed possible
 // by your hardware
 // turn on motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
 digitalWrite(in5, LOW);
 digitalWrite(in6, LOW);
 // accelerate from zero to maximum speed
 for (int i = 0; i < 256; i++)
 {
 analogWrite(enA, i);
 analogWrite(enB, i);
 analogWrite(enC, i); 
 delay(20);
 }
 // decelerate from maximum speed to zero
 for (int i = 255; i >= 0; --i)
 {
  analogWrite(enA, i);
  analogWrite(enB, i);
  analogWrite(enC, i);
  delay(20);
 }
 // now turn off motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
 digitalWrite(in5, LOW);
 digitalWrite(in6, LOW);
}
void loop()
{
 demoOne();
 delay(1000);
 demoTwo();
 delay(1000);
}
