void setup() {
  Serial1.begin(9600)

}

void loop() {
  Serial1.println("/D:00025:/E");
  delay(250);
}
