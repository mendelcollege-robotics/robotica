//controller code for the webots exampkle omni wheels
#include <stdio.h>
#include <webots/motor.h>
#include <webots/robot.h>

static WbDeviceTag wheels[3];

int main() {
  int i;

  const double angle = 0.5*3.14;  //the angle [rad]
  const double sped = 0;          //the speed [?]
  const double angulairspeed = 3.14; //angulair speed [?/s]

  // Initialize Webots
  wb_robot_init();

  //start motors
  for (i = 0; i < 3; i++) {
    char name[64];
    sprintf(name, "wheel%d", i + 1);
    wheels[i] = wb_robot_get_device(name);
    wb_motor_set_position(wheels[i], INFINITY); // Set wheels to initial position
  }

  //calculate needed speeds per wheel
  const double sx = sin(angle)*sped;            //convert angle and speed vector lengt to X-speed vector
  const double sy = cos(angle)*sped;            //convert angle and speed vector lengt to Y-speed vector
  const double a = (0.5*sx) - (0.8660254*sy) + angulairspeed;   //convert X and Y speed vecors + angulair speed to the desired speed for wheel A
  const double b = -sx + angulairspeed;                         //convert X and Y speed vecors + angulair speed to the desired speed for wheel B
  const double c = (0.5*sx) + (0.8660254*sy) + angulairspeed;   //convert X and Y speed vecors + angulair speed to the desired speed for wheel C
  //print values for debuging.
  printf("val a %f\n", a);
  printf("val b %f\n", b);
  printf("val c %f\n", c);
  printf("val speed X %f\n", sx);
  printf("val speed Y %f\n", sy);

  //enter calculated speeds into robot
  const double wheel_speeds[] = {b, a, c};
  while (1) {
    for (i = 0; i < 3; i++) {
      double speed = wheel_speeds[i];
      wb_motor_set_velocity(wheels[i], speed);

      // After setting the speed, move to next step
      wb_robot_step(8);
    }
  }

  return 0;
}

