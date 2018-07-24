#include "Accelerometer.h"
#include "Acceleration.h"
#include "Calculate.h"
//#include "Receiver.h"
#include "Remote.h"
#include "Movement.h"
#include "Plotter.h"

const int RFPin = 2;
bool is_hover = false;
int* temp;
/*
* is hover is used to determine whether the arduino is in hover or control mode
*/

void setup() 
{
  Serial.begin(57600);
//  Serial.println("STARTED");
  //recevr.SETUP();
  remote.SETUP();
  AccMeter.SETUP();
  AccMeter.Accel_State(&Accel);
  Serial.print("Desired:"); Serial.print(Accel.X_Acc); Serial.print(", "); Serial.println(Accel.Y_Acc); 
  calculator.Desire_X = Accel.X_Acc;
  calculator.Desire_Y = Accel.Y_Acc;
  calculator.Desire_Z = Accel.Z_Acc;  
}

/*
 * This is the main loop function
 */

void loop() 
{
  temp = remote.getMove(); //gets commands from the RF reciever

  if(*(temp + 3) == 1 && !is_hover) //if the value of the fourth byte sent is 255, then hovering mode
  {
    is_hover = true;
    AccMeter.Accel_State(&Accel);
    calculator.Desire_X = Accel.X_Acc;
    calculator.Desire_Y = Accel.Y_Acc;
    calculator.Desire_Z = Accel.Z_Acc;
    calculator.X_Angle = 90;
    calculator.Y_Angle = 90;
   //comment out above for debugging
//    Serial.println("Changed to hover");  
  }
  else if(*(temp + 3) == -1 && is_hover) //if the value of the fourth byte is 1, then control mode
  {
    is_hover = false;
  }
  if(is_hover) //for hover mode
  {
    AccMeter.Accel_State(&Accel); //gets accelerometer state
    calculator.Power_Fixer(Accel.X_Acc, Accel.Y_Acc, Accel.Z_Acc); //Finds the change to the servos and motors need and changes them accordingly
    Plot.Printer(); //Graphing purposes
    delay(10);
  }
  else
  {
    mvmnt.Move_X(*temp); //moves X to the sent value
    mvmnt.Move_Y(*(temp+1)); //moves X to the sent value
    mvmnt.Move_Z(*(temp+2)); //sets PWM of Z Value
    delay(10);
  }
}


