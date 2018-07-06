#include "Calculate.h"
#include "Arduino.h"
#include "Movement.cpp"

Movement *mover;

Calculate::Calculate()
{
  Calculate::X_Angle = 0;
  Calculate::Y_Angle = 0;
  Calculate::Z_Power = 0;
  //motor 8, x 9, y 11
  mover = new Movement(8, 9, 11);
}


//public func start

void Calculate::Power_Fixer(int X_Acc, int Y_Acc, int Z_Acc)
{
  XY_Correction(X_Acc, Y_Acc);
  Z_Correction(Z_Acc);
  mover->Move_Z(Calculate::Z_Power);
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
  Calculate::X_Angle = Get_Servo_Angle(X_Acc);
  Calculate::Y_Angle = Get_Servo_Angle(Y_Acc);
}

int Calculate::Get_Servo_Angle(int Acc)
{
  if(Acc < -100)
  {
    
  }
}

