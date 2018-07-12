#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>
const uint64_t pipe = 0xE8E1F0F0E1LL;
RF24 radio (9,10);
int  acc_data[4];
int Is_Hovering = -1;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW; // the previous reading from the input pin 
int buttonPin = 2;


void setup() {
radio.begin();
radio.openWritingPipe(pipe);
pinMode(buttonPin, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    int temp = 0;
    int X_Pin = analogRead(A1),
        Y_Pin = analogRead(A0),
        Z_Pin = analogRead(A2),
        button = digitalRead(buttonPin);
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
  Serial.println(Is_Hovering);
   while (Serial.available() > 0 && temp < 4)
   {  
      acc_data[0] = map(X_Pin, 0, 1023, 20, 150);
      acc_data[1] = map(Y_Pin, 0, 1023, 20, 150); 
      acc_data[2] = map(Z_Pin, 0, 1023, 0, 255);
      acc_data[3] = Is_Hovering;
      temp++;
  }
}
radio.write(acc_data,sizeof(acc_data));
}
