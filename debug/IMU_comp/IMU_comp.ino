#include <Wire.h>
#include <LIS3MDL.h>
#include <math.h>

LIS3MDL mag;

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

  // Calculate heading
  float heading = atan2(mag.m.y, mag.m.x);
  if (heading < 0)
    heading += 2 * PI; // Normalize heading to positive angles

  // Convert from radians to degrees
  float headingDegrees = heading * 180.0 / PI;

  // Adjust for magnetic declination if needed
  // headingDegrees += magneticDeclination;

  // Normalize headingDegrees to [0, 360) range
  if (headingDegrees >= 360.0)
    headingDegrees -= 360.0;

  // Print heading
  Serial.print("Heading: ");
  Serial.println(headingDegrees);

  delay(100);
}
