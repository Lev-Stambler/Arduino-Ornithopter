#include "Arduino.h"
#include "receiver.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const uint64_t pipe = 0xE8E1F0F0E1LL;
RF24 radio (9,10);
int data_received [3];
int X_received, Y_received, Z_received;


receiver::receiver(){
  
}

void receiver::SETUP(){
 radio.begin();
 radio.openReadingPipe (1,pipe);
 radio.startListening();
}

int receiver:: getter(){
radio.read(data_received, sizeof(data_received));
X_received = data_received[0];
Y_received = data_received[1];
Z_received = data_received[2];
return (data_received);
}

receiver recevr = receiver();




