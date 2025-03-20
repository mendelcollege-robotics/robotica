long randNumber;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(2500);
  randomSeed(analogRead(0));

}

void loop() {
  randNumber = random(300);
  Serial.println("transmission test");
  Serial1.println("transmission test");
  Serial.println(randNumber);
  Serial1.println(randNumber);
  delay(1000);
  

}
