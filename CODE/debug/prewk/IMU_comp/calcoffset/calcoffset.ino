void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);

}

void loop() {
  int front = random(0, 360);
  int heading = random(0, 360);
  Serial.print("Front: ");
  Serial.println(front);
  Serial.print("heading: ");
  Serial.println(heading);

  int offset = heading - front;
  if(offset<0){
    offset=(offset+360);
  }
  Serial.print("offset: ");
  Serial.println(offset);
  
  Serial.println();
  Serial.println();

  delay(5000);

}
