#include "Acceleration.h"

Acceleration::Acceleration()
{
  Acceleration::X_Acc = 0;
  Acceleration::Y_Acc = 0;
  Acceleration::Z_Acc = 0;
  Acceleration::X_Gy = 0;
  Acceleration::Y_Gy = 0;
  Acceleration::Z_Gy = 0;
}

void Acceleration::SETUP()
{
  
}

Acceleration Accel = Acceleration();
