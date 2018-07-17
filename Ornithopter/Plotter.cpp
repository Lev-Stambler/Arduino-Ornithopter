#include "Acceleration.h"
#include "Calculate.h"
//#include "Movement.h"
#include "Plotter.h"
#include "Arduino.h"

Plotter :: Plotter(){
  //plot out the values from the accelerometer and servos 
  Serial.print(Accel.X_Acc);
  Serial.print(" "); 
  Serial.print(Accel.Y_Acc); 
  Serial.print (" "); 
  Serial.print(calculator.X_Angle); 
  Serial.print(" ");
  Serial.println(calculator.Y_Angle);
}

void Plotter:: SETUP(){
  
}
Plotter Plot = Plotter();
  
  

