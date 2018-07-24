#include "Remote.h"
#include "Arduino.h"

/*
*Acceleration is a class which stores values from the accelerometer
*/

Remote::Remote()
{
  Is_Hovering = -1;
  lastDebounceTime = 0;  // the last time the output pin was toggled
  debounceDelay = 50;    // the debounce time; increase if the output flickers
  buttonPin = 2;
}

void Remote::SETUP()
{
  pinMode(buttonPin, INPUT_PULLUP);
  lastButtonState = LOW; // the previous reading from the input pin 
}

void Remote::Debounce(){
      if (button!= lastButtonState) lastDebounceTime = millis();
      if ((millis() - lastDebounceTime) > debounceDelay) {
        if (button != buttonState) {
             buttonState = button;
          if (buttonState == HIGH) {
            Is_Hovering = Is_Hovering*-1;
      }
    }
  }
  lastButtonState = button;
}

int* Remote:: getMove(){
  X_Pin = analogRead(A1);
  Y_Pin = analogRead(A0);
  Z_Pin = analogRead(A2);
  button = digitalRead(buttonPin);
  Debounce();  
  move_data[0] = map(X_Pin, 0, 1023, 0, 180);
  move_data[1] = map(Y_Pin, 0, 1023, 0, 180);
  move_data[2] = map(Z_Pin, 0, 1023, 0, 255);
  move_data[3] = Is_Hovering;
//  Serial.print(move_data[0]);
//  Serial.print(" ");
//  Serial.print(move_data[1]);
//  Serial.print(" ");
//  Serial.print(move_data[2]);
//  Serial.print(" ");
//  Serial.println(move_data[3]);
//  
  int* mem;
  mem = &move_data[0];
  return(mem); //import the location in memory the data to controll the ornithopter data is stored
}


Remote remote = Remote();
