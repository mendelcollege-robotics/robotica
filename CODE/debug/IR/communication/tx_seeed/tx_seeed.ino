long randNumber1;
long randNumber2;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(2500);
  randomSeed(analogRead(0));

}

void loop() {
  randNumber1 = random(1000);
  randNumber2 = random(1, 8);
  Serial1.print("s");
  Serial1.print(randNumber2);
  Serial1.print(", ");
  Serial1.print(randNumber1);
  Serial1.print("e");

  Serial.print("s");
  Serial.print(randNumber2);
  Serial.print(", ");
  Serial.print(randNumber1);
  Serial.println("e");
  delay(1000);
  

}
