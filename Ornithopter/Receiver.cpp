#include "Arduino.h"
#include "Receiver.h"
//#include "Movement.h"

#include <RH_ASK.h>
#include <SPI.h>
//#include "Manual.h"
//#include <SPI.h>
//#include <nRF24L01.h>
//#include <RF24.h>
RH_ASK reciever;


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
 if (!reciever.init())
         Serial.println("init failed");

//receive data transmitted to manually controll the ornithopter  
}

/*
* This function gets the commands from the RF module and returns the int pointer where 
* the array storring the commands can be found
*/

int* Receiver:: getMovementCommands()
{
    uint8_t buf[16]; 
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println((char*)buf);         
    }

  int* mem;
  int data_received [3];
//  radio.read(data_r/eceived, sizeof(data_received));
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




