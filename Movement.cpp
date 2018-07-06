#include "Arduino.h"
#include "Movement.h"

#include <Servo.h>

Servo servo_x;
Servo servo_y;
int x = //acc value
int y = //acc value
int x_correction = map(x,// , ,0, 180);
int y_correction = map(y,// , , 0, 180);


Movement::Movement(int x_pin, int y_pin, int motor_pin)
{
  servo_x.attach(x_pin); 
  servo_y.attach(y_pin);
  pinMode(motor_pin, OUTPUT);
}

void Movement::Move(int x_angle, int y_angle)
{
   servo_x.write(x_angle);
   servo_y.write(y_angle);
}
                         
                         
