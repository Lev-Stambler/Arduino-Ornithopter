#include "Arduino.h"
#include "Movement.h"
#include "SoftwareServo.h"


SoftwareServo servo_X;
SoftwareServo servo_Y;



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
  servo_X.write(90);
  servo_Y.write(90);
  delayMicroseconds(100000);
}

/*
* controll movement in the x-direction via servo motor
*/

void Movement::Move_X(int x_angle)
{
  set_servo(&last_x_move, &servo_X, x_angle, false, &last_x_angle);  
}

/*
* controll movement in the y-direction via servo motor
*/

void Movement::Move_Y(int y_angle)
{
  set_servo(&last_y_move, &servo_Y, y_angle, false, &last_y_angle);
}
 


/*
 * this function sets the servo position. It creates a forcible wait of 20 miliseconds between ever servo move.
 */

void Movement::set_servo(int* last_move, SoftwareServo* servo, int angle, bool overide_wait, int* last_angle)
{
  if(!overide_wait)
  {
    if(millis() - *last_move > 20)
    {
      servo->write(angle);

      *last_move = millis();
      *last_angle = angle;
    }
    else
    {
      //hold servo position
      servo->write(*last_angle);
    }
  }
  else
    servo->write(angle);
  SoftwareServo::refresh();
}

/*
*controll movement in the z direction via pulse with modulation (increase or decrease power being sent to wings)
*/

void Movement::Move_Z(int power)
{
//  int power_mapped = map(power,0, 100, 0, 255);
//  Serial.print("Z POWER: "); Serial.println(power);
  if(power > 255) power = 255;
  analogWrite(motor_pin, power);
}        



Movement mvmnt = Movement();
