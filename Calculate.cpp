#include "Calculate.h"



Calculate::Calculate()
{
  
}

void Calculate::Get_Power()
{
  XY_Correction();
  Z_Correction();
}

void Calculate::XY_Correction(int16_t X_Acc, int16_t Y_Acc)
{
  int x_pow;
  int y_pow;

  Calculate::X_Power = x_pow;
  Calculate::Y_Power = y_pow;  
}

void Calculate::Z_Correction(int16_t Z_Acc)
{

  if(Z_Acc < -100)
  {
    Calculate::Z_Power += 10;
  }

}

