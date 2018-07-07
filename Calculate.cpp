#include "Calculate.h"
#include "Arduino.h"
#include "Movement.h"


Calculate::Calculate()
{
  Calculate::X_Angle = 90;
  Calculate::Y_Angle = 90;
  Calculate::Z_Power = 0;
  //motor 8, x 9, y 11
  mvmnt.SETUP(8, 9, 11);
}


//public func start

void Calculate::Power_Fixer(int X_Acc, int Y_Acc, int Z_Acc)
{
  XY_Correction(X_Acc, Y_Acc);
  Z_Correction(Z_Acc);
  mvmnt.Move_Z(Calculate::Z_Power);
}

//private func start

void Calculate::Z_Correction(int Z_Acc)
{
  if(Z_Acc < 14000)
  {
    Calculate::Z_Power += 10;
  }
  else if(Z_Acc >= 14000 && Z_Acc < 14900)
  {
    Calculate::Z_Power = 0;  
  }
  else
  {
    Calculate::Z_Power -= 10;
  }
  

}

void Calculate::XY_Correction(int X_Acc, int Y_Acc)
{
  int former_X = Calculate::X_Angle;
  int former_Y = Calculate::Y_Angle;

  Calculate::X_Angle = Get_Servo_Angle(X_Acc, former_X, Calculate::Desire_X);
  Calculate::Y_Angle = Get_Servo_Angle(Y_Acc, former_Y, Calculate::Desire_Y);
//  Serial.print(X_Acc); Ser/ial.print(", "); Serial.println(Y_Acc);
  if(former_X != Calculate::X_Angle)
  {
    Serial.println("WOW X Moved");
    mvmnt.Move_X(Calculate::X_Angle);
  }
  if(former_Y != Calculate::Y_Angle)
  {
    Serial.println("WOW Y Moved");
    mvmnt.Move_Y(Calculate::Y_Angle);
  }

  mvmnt.Move_Y(Calculate::Y_Angle);
}

int Calculate::Get_Servo_Angle(int Acc, int Current_Ang, int Desired)
{
  Serial.println(Current_Ang);
  if(Current_Ang > 180 || Current_Ang < 0) return Current_Ang;
  else if(Acc < Desired - 100)
  {
    return (Current_Ang + 10);
  }
  else if(Acc > Desired + 100)
  {
    return (Current_Ang - 10);
  }
}

Calculate calculator = Calculate();

