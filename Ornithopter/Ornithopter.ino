#include "Accelerometer.h"
#include "Acceleration.h"
#include "Calculate.h"
#include "Receiver.h"
#include "Movement.h"

const int RFPin = 2;
bool is_hover= true;
uint8_t* temp;
/*
* is hover is used to determine whether the arduino is in hover or control mode
*/

void setup() 
{
  Serial.begin(9600);
  Serial.println("STARTED");
  recevr.SETUP();
//  recevr.getMovementCommands(RH_ASK* receiver);
  AccMeter.SETUP();
  AccMeter.Accel_State(&Accel);
  Serial.print("Desired:"); Serial.print(Accel.X_Acc); Serial.print(", "); Serial.println(Accel.Y_Acc); 
  calculator.Desire_X = Accel.X_Acc;
  calculator.Desire_Y = Accel.Y_Acc;
  calculator.Desire_Z = Accel.Z_Acc;

  
}


void loop() 
{
  temp = recevr.getMovementCommands();


  if(*(temp + 3) == 255)
  {
    is_hover = true;
  }
  else if(*(temp + 3) == 1)
  {
    is_hover = false;
  }
  if(is_hover)
  {
    AccMeter.Accel_State(&Accel);
    calculator.Power_Fixer(Accel.X_Acc, Accel.Y_Acc, Accel.Z_Acc);
    delay(10);
  }
  else
  {
    mvmnt.Move_X(*temp);
    mvmnt.Move_Y(*(temp+1));
    mvmnt.Move_Z(*(temp+2));
    delay(10);
  }
}



