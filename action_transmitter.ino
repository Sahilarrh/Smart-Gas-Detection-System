
// Code 1 : Sending Text (Transmitter)
// Library: TMRh20/RF24 (https://github.com/tmrh20/RF24/)

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
};

void loop() {
  
  int action= analogRead(A0);
  Serial.println(action);
  radio.write(&action, sizeof(action));
  
  
};
