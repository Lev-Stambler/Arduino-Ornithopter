#include "Arduino.h"
#include "Receiver.h"
//#include "Movement.h"

//#include <RFReceiver.h>
//#include <PinChangeInterruptHandler.h>
#include <RH_ASK.h>

#include <SPI.h>
//#include "Manual.h"
RH_ASK receiver;


/*
* This class Interfaces with the RF Reciever module
*/

Receiver::Receiver(){
  
}

/*
* This function sets up the RF
*/

void Receiver::SETUP()
{
  if (!receiver.init())
         Serial.println("init failed");
}

/*
* This function gets the commands from the RF module and returns the int pointer where 
* the array storring the commands can be found
*/

int* Receiver:: getMovementCommands()
{
  uint8_t msg[17];
  uint8_t msglen = sizeof(msglen);
  byte senderId = 0;
  byte packageId = 0;
  if(receiver.recv(msg, &msglen))
  {
     Serial.print("Message: ");
      Serial.println((char*)msg);  
  }
  else
  {
//    Serial.println("NONE");
  }
//  byte len = receiver.recvPackage((byte *)msg, &senderId, &packageId);
//  Serial.println("ASAS");

  int* mem;
  int data_received [3];
  char first[3];
  for(int i = 0; i < 3; i++)
  {
    first[i] = msg[i];
  }
  data_received[0] = (int)first;
  mem = &data_received[0];
//  mvmnt.Move_X(data_received[0]);
//  mvmnt.Move_Y(data_received[1]);
//  mvmnt.Move_Z(data_received[2]);  

//  X_received = data_received[0];
//  Y_received = data_received[1];
//  Z_received = data_received[2];
//  remote.SETUP(data_received coordinates);
  return(mem); //import the location in memory the data to controll the ornithopter data is stored
}

Receiver recevr = Receiver();




