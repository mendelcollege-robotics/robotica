String inp = "01101000";
int decimalValue = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("");

  Serial.println(inp);
  String binary = inp.substring(2);
  Serial.println(binary);
  for (int i = 0; i < binary.length(); i++) {
    // Calculate the value of the current bit
    int bitValue = binary.charAt(i) - '0';
    // Update the decimal value by shifting the bit to its correct position
    decimalValue = (decimalValue << 1) | bitValue;
  }
  Serial.println(decimalValue);
  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);

}
