
#include "Accelerometer.h"
#include "Acceleration.h"
#include "Calculate.h"
#include "Receiver.h"
#include "Movement.h"

bool is_hover;

void setup() 
{
  Serial.begin(9600);
  Serial.println("STARTED");
//  Accel = Acceleration();
   recevr.SETUP();
  recevr.getMovementCommands();
  AccMeter.SETUP();
  // put your setup code here, to run once:
  AccMeter.Accel_State(&Accel);
  Serial.print("Desired:"); Serial.print(Accel.X_Acc); Serial.print(", "); Serial.println(Accel.Y_Acc); 
  calculator.Desire_X = Accel.X_Acc;
  calculator.Desire_Y = Accel.Y_Acc;
  calculator.Desire_Z = Accel.Z_Acc;
}

void loop() 
{
  int * temp = recevr.getMovementCommands();
  if(*(temp + 4) == 1)
  {
    is_hover = True;
  }
  else if(*(temp + 4) == 0)
  {
    is_hover = False;
  }
  if(is_hover)
  {
    AccMeter.Accel_State(&Accel);
    calculator.Power_Fixer(Accel.X_Acc, Accel.Y_Acc, Accel.Z_Acc);
  }
//  Serial.print("Power: "); S/erial.println(calculator.Z_Power);
  else
  {
    mvmnt.Move_X(*temp);
    mvmnt.Move_Y(*(temp+1));
    mvmnt.Move_Z(*(temp+2));
    delay(100);
  }
}



