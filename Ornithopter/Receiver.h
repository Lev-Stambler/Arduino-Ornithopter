#ifndef Receiver_h
#define Receiver_h
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"


class Receiver
{
  public:
  Receiver();
  void SETUP();
  //struct data_received
  int* getMovementCommands();
  //put setter or whatever we do with the data received here
  
  //
};

extern Receiver recevr;
#endif
