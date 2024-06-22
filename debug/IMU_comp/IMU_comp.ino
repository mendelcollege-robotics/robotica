//https://www.pololu.com/product/2862
#include <Wire.h>
#include <LIS3MDL.h>

LIS3MDL mag;

char report[80];

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  if (!mag.init())
  {
    Serial.println("Failed to detect and initialize magnetometer!");
    while (1);
  }

  mag.enableDefault();
}

void loop()
{
  mag.read();

  snprintf(report, sizeof(report), "M: %6d %6d %6d",
    mag.m.x, mag.m.y, mag.m.z);
  Serial.println(report);

  delay(100);
}
