void setup() {
  // Initialize Serial1 with a baud rate of 19200
  Serial1.begin(19200);
  Serial.begin(19200); // Initialize Serial for debugging
}

void loop() {
  // Check if there is any data available to read from Serial1
  if (Serial1.available()) {
    // Read the most recent byte
    byte byteRead = Serial1.read();
    // Echo the value that was read
    Serial1.write(byteRead);
    // Print the received byte for debugging
    Serial.print((char)byteRead);
  }
}
