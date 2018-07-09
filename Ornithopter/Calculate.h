#ifndef Calculate_h
#define Calculate_h

class Calculate
{
  public:
    Calculate();
    void Power_Fixer(int X_Acc, int Y_Acc, int Z_Acc);
    int X_Angle;
    int Y_Angle;
    double Z_Power;
    int Desire_X;
    int Desire_Y;
    double Desire_Z;
    double Downwards_Force;
    double Z_Acceleration;
    int Wait_Cycle;
    //lol add more
  private:
    void XY_Correction(int X_Acc, int Y_Acc, int Corr_Time);
    void Z_Correction_PID(int Z_Acc);
    void Z_Correction(int Z_Acc);
    int Get_Z_Correction(int Acc, int Power,int Desired, int Fluctuator);
    int Get_Servo_Angle(int Acc, int Angle, int Desired, int Fluctuator);
    bool if_X_Corr;
    bool if_Y_Corr;
    bool if_Z_Corr;
    int X_Corr_Count;
    int Y_Corr_Count;
    int Z_Corr_Count;
    float pi;
    int Kp, Kd, Ki;
};

extern Calculate calculator;

#endif
