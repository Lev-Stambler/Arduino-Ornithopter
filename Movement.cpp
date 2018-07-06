#include "Arduino.h"
#include "Movement.h"

#include <Servo.h>

Servo servo_x;
Servo servo_y;



Movement::Movement(int x_pin, int y_pin, int motor_pin)
{
  servo_x.attach(x_pin); 
  servo_y.attach(y_pin);
  pinMode(motor_pin, OUTPUT);
}

void Movement::Move_XY(int x_angle, int y_angle)
{
   //int x_correction = map(x,// , ,0, 180);
   //int y_correction = map(y,// , , 0, 180);
   servo_x.write(x_angle);
   servo_y.write(y_angle);
}
                         
void Movement::Move_Z(int power)
{
  int power_mapped = map(power, 100, 0, 255);
  analogWrite(motor_pin, power_mapped);
}
                         
