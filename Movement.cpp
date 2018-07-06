#include "Arduino.h"
#include "Movement.h"

#include <Servo.h>

Servo servo_x;
Servo servo_y;
int motor_pin;


Movement::Movement(int X_pin, int Y_pin, int Motor_pin)
{
  servo_x.attach(X_pin); 
  servo_y.attach(Y_pin);
  pinMode(motor_pin, OUTPUT);
  motor_pin = Motor_pin;
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
  int power_mapped = map(power,0, 100, 0, 255);
  analogWrite(motor_pin, power_mapped);
}
                         
