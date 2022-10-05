// https://github.com/Seeed-Studio/Grove_I2C_Motor_Driver_v1_3/archive/master.zip


#include <Grove_I2C_Motor_Driver.h>

// default I2C address is 0x0f
#define I2C_ADDRESS 0x0f
 
void setup()
{
    Motor.begin(I2C_ADDRESS);
}

// Set the speed of a motor, speed is equal to duty cycle here
void speed(unsigned char motor_id, int _speed);

delay(1000);

// Stop one motor
void stop(unsigned char motor_id);
