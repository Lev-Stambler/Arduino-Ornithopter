#include <PID_v1.h>

#ifndef CalculatePID_h
#define CalculatePID_h

class CalculatePID
{
  public:
    CalculatePID();
    void SETUP(double* Z_Acc,double* Z_Desired, double* Z_Power, int Kp, int Ki, int Kd);
    void Z_Fix();

  private:
    double x_acc;
    double y_acc;
    double z_acc;
    double x_desired;
    double y_desired;
    double z_desired;
    double x_angle;
    PID* Z_PID;
};

extern CalculatePID CalcPID;

#endif
