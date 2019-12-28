/*----- Code for nRF24L01 Receiver -----*/

//Including necessary Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//Creating an RF24 object
RF24 radio(7, 8);  // CE, CSN

//Address for communication between the two modules.
const byte address[6] = "00001";

void setup(){
  Serial.begin(9600);
  radio.begin();                      // Initializing the nRF module
  radio.openReadingPipe(0, address);  // Setting the address 
  radio.startListening();             //Set module as receiver

  Serial.println("nRF24L01 Receiver Starting");
}

void loop(){
  delay(2000);    // For configuring with the transmitter
  
  //Read the data if available in buffer
  if (radio.available()){
    char message[32] = {0};
    radio.read(&message, sizeof(message));
    Serial.println(message);
  }else{
    Serial.println("ERROR :Message not received"); 
  }
}
