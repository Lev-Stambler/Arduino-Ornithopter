#include "Acceleration.h"
#include "Calculate.h"
//#include "Movement.h"
#include "Plotter.h"
#include "Arduino.h"

Plotter :: Plotter(){
  //plot out the values from the accelerometer and servos 
  
}

void Plotter:: SETUP(){
  
}

void Plotter::Printer()
{
  Serial.print(map(Accel.X_Acc, 0, 4000, 0, 180));
  Serial.print(" "); 
  Serial.print(map(Accel.Y_Acc, 0, 4000, 0 ,180)); 
  Serial.print (" "); 
  Serial.print(calculator.X_Angle); 
  Serial.print(" ");
  Serial.println(calculator.Y_Angle);
}

Plotter Plot = Plotter();
  
  

