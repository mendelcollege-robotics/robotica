/*
This sketch combines magnetometer readings from an LIS3MDL and accelerometer
readings from an LSM6 to calculate a tilt-compensated magnetic heading. It
requires Pololu's LSM6 Arduino library to be installed:

https://github.com/pololu/lsm6-arduino

This program can be used with a board that includes both sensors, like the
Pololu MinIMU-9 v5 and AltIMU-10 v5, or with separate carrier boards for the two
sensors, both connected to the same I2C bus. If you are using separate boards,
make sure the axes are oriented the same way on both (i.e. the X, Y, and Z axes
of both boards should point in the same direction, and the surfaces of the
boards should be as close to parallel as possible).
*/

#include <Wire.h>
#include <LIS3MDL.h>
#include <LSM6.h>

LIS3MDL mag;
LSM6 imu;
int front = 0;

/*
Calibration values; the default values of +/-32767 for each axis
lead to an assumed magnetometer bias of 0. Use the Calibrate example
program to determine appropriate values for your particular unit.
*/
LIS3MDL::vector<int16_t> m_min = {+942, +3436, -3323};
LIS3MDL::vector<int16_t> m_max = {+1053, +3559, -3142};

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  if (!mag.init())
  {
    Serial.println("Failed to detect and initialize LIS3MDL magnetometer!");
    while (1);
  }
  mag.enableDefault();

  if (!imu.init())
  {
    Serial.println("Failed to detect and initialize LSM6 IMU!");
    while (1);
  }
  imu.enableDefault();

  //get start heading
  mag.read();
  imu.read();
  float heading = computeHeading();
  front = heading;
  Serial.println(heading);

}

void loop()
{
  mag.read();
  imu.read();


  float heading = computeHeading();
  int offset = front - heading;
  if(offset<0){
    offset=360+offset;
  }
  
  Serial.print("heading: ");
  Serial.print(heading);
  Serial.print(", goal location: ");
  Serial.print(front);
  Serial.print(", offset: ");
  
  Serial.println(offset);

  delay(100);
}

template <typename T> float computeHeading(LIS3MDL::vector<T> from)
{
  LIS3MDL::vector<int32_t> temp_m = {mag.m.x, mag.m.y, mag.m.z};

  // copy acceleration readings from LSM6::vector into an LIS3MDL::vector
  LIS3MDL::vector<int16_t> a = {imu.a.x, imu.a.y, imu.a.z};

  // subtract offset (average of min and max) from magnetometer readings
  temp_m.x -= ((int32_t)m_min.x + m_max.x) / 2;
  temp_m.y -= ((int32_t)m_min.y + m_max.y) / 2;
  temp_m.z -= ((int32_t)m_min.z + m_max.z) / 2;

  // compute E and N
  LIS3MDL::vector<float> E;
  LIS3MDL::vector<float> N;
  LIS3MDL::vector_cross(&temp_m, &a, &E);
  LIS3MDL::vector_normalize(&E);
  LIS3MDL::vector_cross(&a, &E, &N);
  LIS3MDL::vector_normalize(&N);

  // compute heading
  float heading = atan2(LIS3MDL::vector_dot(&E, &from), LIS3MDL::vector_dot(&N, &from)) * 180 / PI;
  if (heading < 0) heading += 360;
  return heading;
}

/*
Returns the angular difference in the horizontal plane between a
default vector (the +X axis) and north, in degrees.
*/
float computeHeading()
{
  return computeHeading((LIS3MDL::vector<int>){1, 0, 0});
}
