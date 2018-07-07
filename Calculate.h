#ifndef Calculate_h
#define Calculate_h

class Calculate
{
  public:
    Calculate();
    void Power_Fixer(int X_Acc, int Y_Acc, int Z_Acc);
    int X_Angle;
    int Y_Angle;
    int Z_Power;
    int Desire_X;
    int Desire_Y;
    //lol add more
  private:
    void XY_Correction(int X_Acc, int Y_Acc);
    void Z_Correction(int Z_Acc);
    int Get_Servo_Angle(int Acc, int Angle, int Desired);
};

extern Calculate calculator;

#endif
