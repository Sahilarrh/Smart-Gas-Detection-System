
// Code 1 : Sending Text (Receiver)
// Library: TMRh20/RF24 (https://github.com/tmrh20/RF24/)

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#define buzzer 4

RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
};

void loop() {
  
  while (radio.available())
  { int action;
    radio.read(&action, sizeof(action));
    if (action>150)
    {digitalWrite(buzzer, HIGH);}
    else {digitalWrite(buzzer, LOW); }
  }
};

