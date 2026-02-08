int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600);
  Serial1.begin(75);
  Serial2.begin(75);
  while (!Serial) {
    ;
  }
  while (!Serial1) {
    ;
  }
  while (!Serial2) {
    ;
  }
}

//
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
  if (Serial1 == false) {
    Serial.println(" ________________________________________");
    Serial.println("/ You will be winged by an anti-aircraft \\");
    Serial.println("\\ battery.                               /");
    Serial.println(" ----------------------------------------");
    Serial.println("     \\\\");
    Serial.println("      \\\\");
    Serial.println("             ,;;;;;;;,");
    Serial.println("            ;;;;;;;;;;;,");
    Serial.println("           ;;;;;'_____;'");
    Serial.println("           ;;;(/))))|((\\\\");
    Serial.println("           _;;((((((|))))");
    Serial.println("          / |_\\\\\\\\\\\\\\\\\\\\\\\\");
    Serial.println("     .--~(  \\\\ ~))))))))))))");
    Serial.println("    /     \\\\  `\\\\-(((((((((((\\\\\\\\");
    Serial.println("    |    | `\\\\   ) |\\\\       /|)");
    Serial.println("     |    |  `. _/  \\\\_____/ |");
    Serial.println("      |    , `\\\\~            /");
    Serial.println("       |    \\\\  \\\\           /");
    Serial.println("      | `.   `\\\\|          /");
    Serial.println("      |   ~-   `\\\\        /");
    Serial.println("       \\\\____~._/~ -_,   (\\\\");
    Serial.println("        |-----|\\\\   \\\\    ';;");
    Serial.println("       |      | :;;;'     \\\\");
    Serial.println("      |  /    |            |");
    Serial.println("      |       |            |");
  }
  if (Serial1.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte, DEC);
  }
  if (Serial2.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte, DEC);
  }
}