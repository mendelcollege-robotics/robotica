int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600);
  Serial1.begin(75);
  Serial2.begin(75);

}

//  _________________________________________
// / fucking mixes the signal and prints but \
// | dont know recieve format yet so keeping |
// \ it here                                 /
//  -----------------------------------------
//      \   ^__^
//       \  (oo)\_______
//          (__)\       )\/\
//               ||----w |
//               ||     ||

void loop() {
  if (Serial1.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte, DEC);
  }
  if (Serial2.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte, DEC);
  }
}