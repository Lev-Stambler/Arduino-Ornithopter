#include "Arduino.h"
#include "Receiver.h"
//#include "Movement.h"

//#include "Manual.h"
//#include <SPI.h>
//#include <nRF24L01.h>
//#include <RF24.h>
const uint64_t pipe = 0xE8E1F0F0E1LL;
RF24 radio (9,10);


Receiver::Receiver(){
  
}

void Receiver::SETUP()
{
 radio.begin();
 radio.openReadingPipe (1,pipe);
 radio.startListening();
//receive data transmitted to manually controll the ornithopter  
}


int* Receiver:: getMovementCommands()
{
  int* mem;
  int data_received [3];
  radio.read(data_received, sizeof(data_received));
  mem = &data_received[0];
//  mvmnt.Move_X(data_received[0]);
//  mvmnt.Move_Y(data_received[1]);
//  mvmnt.Move_Z(data_received[2]);  

//  X_received = data_received[0];
//  Y_received = data_received[1];
//  Z_received = data_received[2];
//  remote.SETUP(data_received coordinates);
return(mem);//import the location in memory the data to controll the ornithopter data is stored
}

Receiver recevr = Receiver();




