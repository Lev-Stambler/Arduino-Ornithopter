#ifndef Movement_h
#define Movement_h

class Movement
{
  public:
    Movement();
    void SETUP(int X_pin, int Y_pin, int Motor_Pin);
    void Move_X(int x_angle);
    void Move_Y(int y_angle);
    void Move_Z(int power);
    //lol add more
};

extern Movement mvmnt;

#endif
