#include "Acceleration.h"

/*
*Acceleration is a class which stores values from the accelerometer
*/

Acceleration::Acceleration()
{
  X_Acc = 0;
  Y_Acc = 0;
  Z_Acc = 0;
  X_Gy = 0;
  Y_Gy = 0;
  Z_Gy = 0;
}

void Acceleration::SETUP()
{
  
}

Acceleration Accel = Acceleration();
