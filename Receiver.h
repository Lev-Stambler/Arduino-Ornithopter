#ifndef Receiver_h
#define Receiver_h
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


class Receiver
{
  public://we could possibly make this private
  Receiver();
  void SETUP();
  struct dataReceived getMovementCommands();
  //put setter or whatever we do with the data received here
  
  //
};

extern Receiver recevr;
#endif
