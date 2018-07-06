#ifndef Movement_h
#define Movement_h

class Movement
{
  public:
    Movement(int x_pin, int y_pin, int motor_pin);
    void Move(int x_angle, int y_angle);
    //lol add more
};

extern Acceleration Accel;

#endif
