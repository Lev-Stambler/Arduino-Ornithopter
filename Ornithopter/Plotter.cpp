#include "Acceleration.h"
#include "Calculate.h"
#include "Plotter.h"
#include "Arduino.h"

const int accelReadings = 10; 
    int accelX[accelReadings];      
    int accelY[accelReadings];
    int accelZ[accelReadings];


Plotter :: Plotter(){
  //plot out the values from the accelerometer and servos 
  currentAccel = 0;              
  totalAccelX = 0;                 
  averageAccelX = 0;         
  totalAccelY = 0;
  averageAccelY = 0;
  totalAccelZ = 0;
  averageAccelZ=0;
}

void Plotter:: SETUP(){
    for (int i = 0; i < accelReadings; i++) accelX[i] = 0;
    for (int i = 0; i < accelReadings; i++) accelY[i] = 0;
    for (int i = 0; i < accelReadings; i++) accelZ[i] = 0;
}

void Plotter::Smooth(){
  // subtract the last reading:
  totalAccelX = totalAccelX - accelX[currentAccel];
  totalAccelY = totalAccelY - accelY[currentAccel];
  totalAccelZ = totalAccelZ - accelZ[currentAccel];
  // acceleration is a scale of 0 to 65536: 16 bits
  accelX[currentAccel] = map(Accel.X_Acc, -32768, 32768, -19.6, 19.6); //on a range of -2g to 2g (9.8m/s2)
  accelY[currentAccel] = map(Accel.Y_Acc, -32768, 32768, -19.6, 19.6); //on a range of -2g to 2g (9.8m/s2)
  accelZ[currentAccel] = map(Accel.Z_Acc, -32768, 32768, -19.6, 19.6);
  totalAccelX = totalAccelX + accelX[currentAccel];
  totalAccelY = totalAccelY + accelY[currentAccel];
  totalAccelZ = totalAccelZ + accelZ[currentAccel];
  // advance to the next position in the array:
  currentAccel = currentAccel + 1;
  if (currentAccel >= accelReadings) currentAccel = 0;//you probably don't need && here
  averageAccelX = totalAccelX / accelReadings;
  averageAccelY = totalAccelY / accelReadings; 
  averageAccelZ = totalAccelZ / accelReadings;
}

void Plotter::Printer()
{
  Smooth();
  Serial.print(averageAccelX);
  Serial.print(" "); 
  Serial.print(averageAccelY); 
  Serial.print(" "); 
  Serial.print(averageAccelZ);
  Serial.print(" ");
  Serial.print(calculator.X_Angle); 
  Serial.print(" ");
  Serial.print(calculator.Y_Angle);
  Serial.print(" ");
  Serial.println(calculator.Z_Power);
}

Plotter Plot = Plotter();
