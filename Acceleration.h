#ifndef Acceleration_h
#define Acceleration_h

class Acceleration
{
  public:
    Acceleration();
    int16_t X_Acc;
    int16_t Y_Acc;
    int16_t Z_Acc;
    int16_t X_Gy;
    int16_t Y_Gy;
    int16_t Z_Gy;
    //lol add more
};

extern Acceleration Accel;

#endif
