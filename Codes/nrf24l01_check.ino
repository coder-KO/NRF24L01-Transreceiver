/*----- Program to check the connection between nRF24L01+ and Arduino/ check nRF24L01+ Module -----*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>

// Be sure that the CE and CSN pins connected by you matches with the ones in the code
#define CE   7
#define CSN 8

const byte thisSlaveAddress[5] = {'C','H','x','0','1'};

RF24 radio(CE, CSN);

char dataReceived[10]; // this must match dataToSend in the TX
bool newData = false;


void setup() {
    Serial.begin(9600);
    printf_begin();

    Serial.println();
    Serial.println("|==========================================================================|");
    Serial.println("\t\t\tnRF24L01 Check Starting");
    Serial.println("|--------------------------------------------------------------------------|");
    Serial.println("| 1 |  With DEFAULT Addresses                                              |");
    Serial.println("|--------------------------------------------------------------------------|");
    Serial.println("IMPORTANT => If the numbers are mostly 0x00 or 0xff\nit indicates some problem in Connection/Module");
    Serial.println();
    radio.begin();
    radio.printDetails();
    Serial.println();
    Serial.println();
    Serial.println("|--------------------------------------------------------------------------|");
    Serial.println("| 2 |  With Addresses AAAxR  0x41 41 41 78 52 on PIPE 1                    |");
    Serial.println("|--------------------------------------------------------------------------|");
    Serial.println("Data Rate  :250kbps");
    Serial.println();
    radio.openReadingPipe(1, thisSlaveAddress);
    radio.setDataRate( RF24_250KBPS );
    radio.printDetails();
    Serial.println("|==========================================================================|");
}


void loop() {

}
