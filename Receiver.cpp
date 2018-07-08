#include "Arduino.h"
#include "Receiver.h"
//#include <SPI.h>
//#include <nRF24L01.h>
//#include <RF24.h>
const uint64_t pipe = 0xE8E1F0F0E1LL;
RF24 radio (9,10);
int X_received, Y_received, Z_received;


Receiver::Receiver(){
  
}

void Receiver::SETUP()
{
 radio.begin();
 radio.openReadingPipe (1,pipe);
 radio.startListening();
}

struct dataReceived {
int x,y,z;
};

struct dataReceived Receiver:: getMovementCommands()
{
  int data_received [3];
  struct dataReceived coordinates;
  radio.read(data_received, sizeof(data_received));
  coordinates.x = data_received[0];
  coordinates.y = data_received[1];
  coordinates.z = data_received[2];
//  X_received = data_received[0];
//  Y_received = data_received[1];
//  Z_received = data_received[2];
  return (coordinates);
}

Receiver recevr = Receiver();




