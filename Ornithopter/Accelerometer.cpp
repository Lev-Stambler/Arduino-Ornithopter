#include "Arduino.h"
#include "Accelerometer.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include <Wire.h>
#endif
const int MPU_addr=0x68; 
#define Power_Register 0x2D
//#include "MPU6050_6Axis_MotionApps20.h" 

MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

#define OUTPUT_READABLE_ACCELGYRO

Accelerometer::Accelerometer()
{


}

void Accelerometer::SETUP()
{
  mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_8);
   
  /*
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);//Power_Register);  // PWR_MGMT_1 register
  Wire.write(0x00);   //0x6B  // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);*/
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
  mpu.initialize();
}

/*
* This header file interfaces with the accelerometer and stores the information in the acceleration class which is passed in with a pointer
*/

void Accelerometer::Accel_State(Acceleration* acc_state)
{  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  acc_state->X_Acc = ax;
  acc_state->Y_Acc = ay;
  acc_state->Z_Acc = az;
/*  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  acc_state->X_Acc = Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  acc_state->Y_Acc = Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  acc_state->Z_Acc = Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
*/
}

Accelerometer AccMeter = Accelerometer();
