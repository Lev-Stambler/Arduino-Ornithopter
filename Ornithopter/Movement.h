
//#include <Servo.h>

#include "SoftwareServo.h"


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
  private:
    int motor_pin;
    int wait_time;
    void set_servo(int* last_move, SoftwareServo* servo, int angle, bool overide_wait, int* last_angle);
    int last_x_move,
    last_y_move,
    last_x_angle,
    last_y_angle;     
};

extern Movement mvmnt;

#endif
