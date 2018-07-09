#include "Arduino.h"
#include "Movement.h"
#include "Servo.h"

#include <Servo.h>

Servo servo_X;
Servo servo_Y;

int motor_pin;


Movement::Movement()
{
  
}

void Movement::SETUP(int X_pin, int Y_pin, int Motor_Pin)
{
  servo_X.attach(X_pin); 
  servo_Y.attach(Y_pin);
  pinMode(Motor_Pin, OUTPUT);

}

void Movement::Move_X(int x_angle)
{
   servo_X.write(x_angle);
}

void Movement::Move_Y(int y_angle)
{
  servo_Y.write(y_angle);
}
                         
void Movement::Move_Z(int power)
{
  int power_mapped = map(power,0, 100, 0, 255);
  analogWrite(motor_pin, power_mapped);
}
                         
