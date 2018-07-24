#ifndef Remote_h
#define Remote_h

class Remote
{
  public:
    Remote();
    void SETUP();
    int* getMove();
  private:
    void Debounce();
    int  move_data[4];
    int Is_Hovering;// = -1;
    unsigned long lastDebounceTime;// = 0;  // the last time the output pin was toggled
    unsigned long debounceDelay;// = 50;    // the debounce time; increase if the output flickers
    int buttonState;             // the current reading from the input pin
    int lastButtonState ;//= LOW; // the previous reading from the input pin 
    int buttonPin;// = 2;
    int Y_Pin, X_Pin, Z_Pin, button;
};

extern Remote remote;
#endif

