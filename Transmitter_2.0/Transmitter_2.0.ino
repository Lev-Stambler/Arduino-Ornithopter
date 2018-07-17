#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
int buttonState;             // the current reading from the input pin
int buttonPin = 2;
int buttonPrev;

#define NODE_ID          1
//#define OUTPUT_PIN       11

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
 if (!transmitter.init())
         Serial.println("init failed");
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

    uint8_t *umsg = new uint8_t[4];
    char *msg = new char[4];
    umsg[0] = map(X_val, 0, 1023, 0, 180);
    umsg[1] = map(Y_val, 0, 1023, 0, 180);
    umsg[2] = map(Z_val, 0, 1023, 0, 255);
    umsg[3] = is_Hovering;

    for(int i = 0; i < 1; i++)
    {
      Serial.println(umsg[1]);
      
      transmitter.send(umsg, 4);//strlen(umsg));
      
      transmitter.waitPacketSent();
      delay(50);
    }
    X_form = X_val;
    Y_form = Y_val;
    Z_form = Z_val;
    is_Hover_Prev = is_Hovering;
  }
  
  
}
