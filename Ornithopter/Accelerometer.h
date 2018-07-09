#include "Acceleration.h"

#ifndef CI_h
#define CI_h

class Accelerometer
{
  public:
    Accelerometer();
    void SETUP();
    void Accel_State(Acceleration *Accel);
};

extern Accelerometer AccMeter;

#endif
