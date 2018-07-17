#ifndef Receiver_h
#define Receiver_h

//#include "nRF24L01.h"
//#include "RF24.h"


class Receiver
{
  public:
  Receiver();
  void SETUP();
  //struct data_received
  int* getMovementCommands();
  
  //
};

extern Receiver recevr;
#endif
