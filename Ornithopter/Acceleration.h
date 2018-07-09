#ifndef Acceleration_h
#define Acceleration_h

class Acceleration
{
  public:
    Acceleration();
    void SETUP();
    int X_Acc;
    int Y_Acc;
    int Z_Acc;
    int X_Gy;
    int Y_Gy;
    int Z_Gy;
    //lol add more
};

extern Acceleration Accel;

#endif
