/*----- Code for nRF24L01 Transmitter -----*/

//Including necessary Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//Creating an RF24 object
RF24 radio(7, 8);  // CE, CSN

//Address for communication between the two modules.
const byte address[6] = "00001";
// Frequecny of sending message
const int frequency = 1000;

void setup(){
  Serial.begin(9600);
  radio.begin();                  // Initializing the nRF module
  radio.openWritingPipe(address); // Setting the address
  radio.stopListening();          // Set module as transmitter

  Serial.println("nRF24L01 Transmitter starting");
}

void loop(){
  // Generating the message
  const char message[] = "Hey, This is nRF24L01.!";
  
  // Sending the message while checking its status  
  bool ack = radio.write(&message, sizeof(message));
  
  // To check wether or not the message was sent
  if(ack == true){
    Serial.println("Message Sent");
  }else{
    Serial.println("Message not Sent");
  }
  delay(frequency);
}
