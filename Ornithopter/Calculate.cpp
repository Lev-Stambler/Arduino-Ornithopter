#include "Calculate.h"
#include "Arduino.h"
#include "Movement.h"
#include "CalculatePID.h"



//initialize

Calculate::Calculate()
{
  Kp = 2;
  Ki = 5;
  Kd = 5.5;

  X_Corr_Factor = 5;
  Y_Corr_Factor = 5;
  X_Corr_Count = 0;
  Y_Corr_Count = 0;
  X_Angle = 90;
  Y_Angle = 90;
  Z_Power = 220;
  X_fluctuator = 300;
  Y_fluctuator = 300;
  pi = 3.14159265358979323846;
  Wait_Cycle = 10;
  //motor 5, x 6, y 10 z
  mvmnt.SETUP(5, 6, 10);
  CalcPID.SETUP(&Z_Acceleration, &Desire_Z, &Downwards_Force, Kp, Ki, Kd);
}


//public functions start

void Calculate::Power_Fixer(int X_Acc, int Y_Acc, int Z_Acc)
{
  XY_Correction(X_Acc, Y_Acc, 10);
  Z_Correction_PID(Z_Acc);
}



//private functions start

/*
 * The following function uses a PID Controller to calculate the necessary power needed for the PWM of the z-axis motor.
 */

void Calculate::Z_Correction_PID(int Z_Acc)
{
  float x_angle_radians = (abs(90 - X_Angle) * pi)/180;
  float y_angle_radians = (abs(90 - Y_Angle) * pi)/180;
  Z_Acceleration = Z_Acc;
  Downwards_Force = Z_Power * (cos(y_angle_radians)) * cos(x_angle_radians);
  
  CalcPID.Z_Fix();
  Z_Power = Downwards_Force / (cos(y_angle_radians) * cos(x_angle_radians));
  mvmnt.Move_Z(int(Z_Power));
//  Serial.print("Z POWER PID: /"); Serial.print(Z_Power); Serial.print(" Dow/nwards: "); Serial.println(Downwards_Force);
}
/*
  NONE PID CORRECTION FACTOR
void Calculate::Z_Correction(int Z_Acc)
{
  int former_Z = Z_Power;
  
  if(!if_Z_Corr)
    Z_Power = Get_Z_Correction(Z_Acc, former_Z, Desire_Z, 1200);
  else
  {
    if(Z_Corr_Count > Wait_Cycle)
    {
      Z_Corr_Count = 0;
      if_Z_Corr = false;
    }
    Z_Corr_Count++;
  }
  
  if(former_Z != Z_Power)
  {
    mvmnt.Move_Z(Z_Power);
    Serial.print("WOW Z Moved. New Power: "); Serial.println(Z_Power); Serial.println(former_Z); Serial.println(Z_Power);
    if_Z_Corr = true;
  }
  
}

int Calculate::Get_Z_Correction(int Acc, int Power, int Desired, int Fluctuator)
{
  int res = Power;
  if(Acc < Desired - Fluctuator) //when falling
  {
    res = Power + 10;
  }
  else if(Acc < (Desired + Fluctuator)) //all good
  {
    res = 120; //find hovering speed I guess  
  }
  else //when going up
  {
    res = Power - 10;
  }
  return res;
}
*/

/*
 * This function corrects the two servos in order to make flight stable in the X and Y axis
 * The function of Corr_Count is to create a delay after each adjustment to the servo
 */

void Calculate::XY_Correction(int X_Acc, int Y_Acc, int Corr_Time)
{
  int former_X = X_Angle;
  int former_Y = Y_Angle;
//  Serial.print("X: 0");
//  Serial.println(X_Acc);
//  
//  Serial.print("Y: ");
//  Serial.println(Y_Acc);
//  
  if(!if_X_Corr)
    X_Angle = Get_Servo_Angle(X_Acc, former_X, Desire_X, X_fluctuator, X_Corr_Factor);
  
  else
  {
    if(X_Corr_Count > Wait_Cycle)
    {
      X_Corr_Count = 0;
      if_X_Corr = false;
    }
    else
      X_Corr_Count++;
  }

  if(!if_Y_Corr)
    Y_Angle = Get_Servo_Angle(Y_Acc, former_Y, Desire_Y, Y_fluctuator, Y_Corr_Factor);
  else
  {
    if(Y_Corr_Count > Wait_Cycle)
    {
      Y_Corr_Count = 0;
      if_Y_Corr = false;
    }
    else
      Y_Corr_Count++;
  }
  
  if(former_X != X_Angle)
  {
    Serial.print("WOW X Moved: ");
    Serial.println(X_Angle);
    if_X_Corr = true;
  }
    
  if(former_Y != Y_Angle)
  {
    Serial.print("WOW Y Moved: ");
    Serial.println(Y_Angle);
    if_Y_Corr = true;
  }
  
  mvmnt.Move_X(X_Angle);
  mvmnt.Move_Y(Y_Angle);

}

/*
 * This function compares desired acceleration values to current acceleration values and adjusts angle of the servo accordingly
 */

int Calculate::Get_Servo_Angle(int Acc, int Current_Ang, int Desired, int Fluctuator, int Corr_Factor)
{
  int res = Current_Ang;

  if(Acc < (Desired - Fluctuator))
  {
    if(res >= 150)
      res = res;
    else
      res = Current_Ang + Corr_Factor;
  }
  else if(Acc > (Desired + Fluctuator))
  {
    if(res <= 20)
      res = res;
    else
      res = Current_Ang - Corr_Factor; 
  }
  return res;
}

Calculate calculator = Calculate();

