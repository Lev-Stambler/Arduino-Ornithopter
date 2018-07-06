#ifndef Calculate_h
#define Calculate_h

class Calculate
{
  public:
    Calculate();
    void Get_Power();
    int X_Power;
    int Y_Power;
    int Z_Power;
    //lol add more
  private:
    void XY_Correction(int16_t X_Acc, int16_t Y_Acc);
    void Z_Correction(int16_t Z_Acc);
};

extern Calculate Calculate;

#endif
