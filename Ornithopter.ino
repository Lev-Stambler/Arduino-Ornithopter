#include "Accelerometer.h"
#include "Acceleration.h"
#include "Calculate.h"

Accelerometer *acc;
Acceleration *acc_state;
Calculate *calculator;


void setup() 
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  calculator = new Calculate();
  acc = new Accelerometer();
  acc_state = new Acceleration();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  acc_state = acc->Accel_State();
  calculator->Power_Fixer(acc_state->X_Acc, acc_state->Y_Acc, acc_state->Z_Acc);
  Serial.print("X_acc: "); Serial.println(acc_state->X_Acc);
  Serial.print("Power: "); Serial.println(calculator->Z_Power);
  delay(100);
}
