#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
int buttonState;             // the current reading from the input pin
int buttonPin = 2;
int buttonPrev;

int X_val, Y_val, Z_val;
int X_form = 0, Y_form = 0, Z_form = 0;
const int analog_X = 0;
const int analog_Y = 1;
const int analog_Z = 2;
int is_Hovering = -1,
is_Hover_Prev = 0;

RH_ASK transmitter;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  if(!transmitter.init())
  {
    Serial.println("ERROR");
  }
}

void loop() 
{
  X_val = analogRead(analog_X);
  Y_val = analogRead(analog_Y);
  Z_val = analogRead(analog_Z);

  buttonState = digitalRead(buttonPin);

  if ((millis() - lastDebounceTime) > debounceDelay && buttonPrev != buttonState) 
  {
    
    if (buttonState == LOW) 
    {
      is_Hovering = is_Hovering * -1;
      lastDebounceTime = millis();
    }
    
      buttonPrev = buttonState;
  }

  if(abs(X_val - X_form) > 3 || abs(Y_val - Y_form) > 3 || abs(Z_val - Z_form) > 3 || is_Hover_Prev != is_Hovering)
  {
    String msg_str = String(X_val) + "," + String(Y_val) + "," + String(Z_val) + "," + String(is_Hovering);
    Serial.println(msg_str);
    const char *msg = msg_str.c_str();
    transmitter.send((uint8_t *)msg, strlen(msg));
    transmitter.waitPacketSent();
    X_form = X_val;
    Y_form = Y_val;
    Z_form = Z_val;
    is_Hover_Prev = is_Hovering;
  }
  
  
}
