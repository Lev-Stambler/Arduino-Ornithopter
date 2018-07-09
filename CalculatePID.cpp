#include <PID_v1.h>
#include "Arduino.h"
#include "CalculatePID.h"



CalculatePID::CalculatePID()
{
  
}

void CalculatePID::SETUP(double* Z_Acc, double* Z_Desired, double* Z_Power)
{ 
  Z_PID = new PID(Z_Acc, Z_Power, Z_Desired, 2, 5,1, DIRECT);
  Z_PID->SetMode(AUTOMATIC);
}

void CalculatePID::Z_Fix()
{
  Z_PID->Compute();
}

CalculatePID CalcPID = CalculatePID();


