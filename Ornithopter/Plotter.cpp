#include "Acceleration.h"
#include "Calculate.h"
//#include "Movement.h"
#include "Plotter.h"
#include "Arduino.h"

const int accelReadings = 10; 
    int accelX[accelReadings];      
    int accelY[accelReadings];


Plotter :: Plotter(){
  //plot out the values from the accelerometer and servos 
  currentAccel = 0;              
  totalAccelX = 0;                 
  averageAccelX = 0;         
  //int current.accelY = 0;
  totalAccelY = 0;
  averageAccelY = 0;
}

void Plotter:: SETUP(){
    for (int thisReading = 0; thisReading < accelReadings; thisReading++) accelX[thisReading] = 0;
    for (int thisReading = 0; thisReading < accelReadings; thisReading++) accelY[thisReading] = 0;//you could do this in one for loop if you wanted to (maybe)
}

void Plotter::Smooth(){
  // subtract the last reading:
  totalAccelX = totalAccelX - accelX[currentAccel];
  totalAccelY = totalAccelY - accelY[currentAccel];
  accelX[currentAccel] = map(Accel.X_Acc, 0, 4000, 0, 180);
  accelY[currentAccel] = map(Accel.Y_Acc, 0, 4000, 0, 180);
  totalAccelX = totalAccelX + accelX[currentAccel];
  totalAccelY = totalAccelY + accelY[currentAccel];
  // advance to the next position in the array:
  currentAccel = currentAccel + 1;
  // if we're at the end of the array...
  if (currentAccel >= accelReadings && currentAccel >= accelReadings) currentAccel = 0;//you probably don't need && here
  averageAccelX = totalAccelX / accelReadings;
  averageAccelY = totalAccelY / accelReadings; 
  
}

void Plotter::Printer()
{
  Smooth();
  Serial.print(averageAccelX);
  Serial.print(" "); 
  Serial.print(averageAccelY); 
  Serial.print (" "); 
  Serial.print(calculator.X_Angle); 
  Serial.print(" ");
  Serial.println(calculator.Y_Angle);
}

Plotter Plot = Plotter();
