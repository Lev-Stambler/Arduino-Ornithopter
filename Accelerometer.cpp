#include "Arduino.h"
#include "Accelerometer.h"
#include<Wire.h>
const int MPU_addr=0x68; 

Accelerometer::Accelerometer()
{
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}


Acceleration* Accelerometer::Accel_State()
{
  Acceleration* acc_state = new Acceleration();
  
  
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  acc_state->X_Acc = Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  acc_state->Y_Acc = Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  acc_state->Z_Acc = Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
//  acc_state->X_Gy = Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
//  acc_state->Y_Gy = Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
//  acc_state->Z_Gy = Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
//  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  Serial.print("AcX = "); Serial.print(&acc_state->X_Acc + "\n");
  Serial.print(" AcY = "); Serial.print(&acc_state->Y_Acc + "\n");
  Serial.print(" AcZ = "); Serial.print(&acc_state->Z_Acc + "\n");
//  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datashee
  Serial.print(" | GyX = "); Serial.print(&acc_state->X_Gy);
  Serial.print(" | GyY = "); Serial.print(&acc_state->Y_Gy);
  Serial.print(" | GyZ = "); Serial.println(&acc_state->Z_Gy);


  return acc_state;
  
  
  //Get rid of serial print
  //Find how to just get AcX AcY etc rather than all at once
}

