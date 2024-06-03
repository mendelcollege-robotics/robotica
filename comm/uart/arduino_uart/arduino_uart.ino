void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    // Read the most recent byte
    byte byteRead = Serial.read();
    // ECHO the value that was read
    Serial.write(byteRead);
  }
}