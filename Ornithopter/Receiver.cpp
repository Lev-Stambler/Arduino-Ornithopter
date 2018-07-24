/*
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

//Receiver::Receiver(){
  
//}

/*
* This function sets up the RF
*/
/*
void Receiver::SETUP()
{
  if (!receiver.init())
         Serial.println("init failed");
}
*/
/*
* This function gets the commands from the RF module and returns the int pointer where 
* the array storring the commands can be found
*/
/*
uint8_t* Receiver:: getMovementCommands()
{
  uint8_t *mem;

  uint8_t msglen = sizeof(msg);

  if(receiver.recv(msg, &msglen))// &msglen))
  {
    int i;

    Serial.print("Message: ");
    Serial.println(msg[0]); 
    Serial.println(msg[1]);
    Serial.println(msg[2]);  
    Serial.println(msg[3]); 
  }
  
  mem = &msg[0];
  

  return(mem); //import the location in memory the data to controll the ornithopter data is stored
}

Receiver recevr = Receiver();


*/

