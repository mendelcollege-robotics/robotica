#include <SPI.h>
#define SS_PIN 10
#define BAUD_RATE 19200
#define CHAR_BUF 128

void setup() {
  pinMode(SS_PIN, OUTPUT);
  Serial.begin(BAUD_RATE);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.setDataMode(SPI_MODE0);
  delay(1000); // Give the OpenMV Cam time to bootup.
}

void loop() {
  int32_t len = 0;
  char buff[CHAR_BUF] = {0};
  digitalWrite(SS_PIN, LOW);
  delay(1); // Give the OpenMV Cam some time to setup to send data.

  if(SPI.transfer(1) == 85) { // saw sync char?
    SPI.transfer(&len, 4); // get length
    if (len) {
      SPI.transfer(&buff, min(len, CHAR_BUF));
      len -= min(len, CHAR_BUF);
    }
    while (len--) SPI.transfer(0); // eat any remaining bytes
  }

  digitalWrite(SS_PIN, HIGH);
  Serial.print(buff);
  delay(1); // Don't loop to quickly.
}