#ifndef Movement_h
#define Movement_h

class Movement
{
  public:
    Movement(int X_pin, int Y_pin, int Motor_pin);
    void Move_XY(int x_angle, int y_angle);
    void Move_Z(int power);
    //lol add more
};

extern Movement Movement;

#endif
