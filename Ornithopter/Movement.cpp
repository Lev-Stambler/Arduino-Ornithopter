#include "Arduino.h"
#include "Movement.h"
#include "Servo.h"

#include <Servo.h>

Servo servo_X;
Servo servo_Y;

int motor_pin;

/* 
* This class is used to move the servos and motor
*/

Movement::Movement()
{
  
}

void Movement::SETUP(int X_pin, int Y_pin, int Motor_Pin)
{
  servo_X.attach(X_pin); 
  servo_Y.attach(Y_pin);
  pinMode(Motor_Pin, OUTPUT);
  motor_pin = Motor_Pin;
}

/*
* controll movement in the x-direction via servo motor
*/

void Movement::Move_X(int x_angle)
{
   servo_X.write(x_angle);
//   delayMicroseconds(100000);
  
}

/*
* controll movement in the y-direction via servo motor
*/

void Movement::Move_Y(int y_angle)
{
  servo_Y.write(y_angle);
//  delayMicroseconds(100000);
}

/*
*controll movement in the z direction vai pulse with modulation (increase or decrease power being sent to wings)
*/

void Movement::Move_Z(int power)
{
//  int power_mapped = map(power,0, 100, 0, 255);
//  Serial.print("Z POWER: "); Serial.println(power);
  if(power > 255) power = 255;
  analogWrite(motor_pin, power);
}                       
