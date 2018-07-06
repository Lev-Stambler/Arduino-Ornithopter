#ifndef Acceleration_h
#define Acceleration_h

class Acceleration
{
  public:
    Acceleration();
    static int16_t X_Acc;
    static int16_t Y_Acc;
    static int16_t Z_Acc;
    static int16_t X_Gy;
    static int16_t Y_Gy;
    static int16_t Z_Gy;
    //lol add more
};

extern Acceleration Accel;

#endif
