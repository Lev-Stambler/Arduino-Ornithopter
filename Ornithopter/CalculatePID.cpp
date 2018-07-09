#include <PID_v1.h>
#include "Arduino.h"
#include "CalculatePID.h"



CalculatePID::CalculatePID()
{
  
}

void CalculatePID::SETUP(double* Z_Acc, double* Z_Desired, double* Z_Power, int Kp, int Ki, int Kd)
{ 
  Z_PID = new PID(Z_Acc, Z_Power, Z_Desired, Kp, Ki, Kd, DIRECT);
  Z_PID->SetMode(AUTOMATIC);
}

void CalculatePID::Z_Fix()
{
  Z_PID->Compute();
}

CalculatePID CalcPID = CalculatePID();


