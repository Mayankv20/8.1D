#include <Wire.h>

// LED on pin 13
const int red = 2; 
const int yellow = 5;
const int green = 13;

void setup() {
  // Join I2C bus as slave with address 8
  Wire.begin(0x8);
  
  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);
  
  // Setup pin 13 as output and turn LED off
  pinMode(red, OUTPUT);
  digitalWrite(red, LOW);
  pinMode(yellow, OUTPUT);
  digitalWrite(yellow, LOW);
  pinMode(green, OUTPUT);
  digitalWrite(green, LOW);
}

// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    if(c == 0)
    {
      digitalWrite(red, 0);
      digitalWrite(yellow, 0);
      digitalWrite(green, 0);
    }
    else if(c == 1)
    {
      digitalWrite(red, 1);
      digitalWrite(yellow, 0);
      digitalWrite(green, 0);
    }
    else if(c == 2)
    {
      digitalWrite(red, 0);
      digitalWrite(yellow, 1);
      digitalWrite(green, 0);
    }

    else if(c == 3)
    {
      digitalWrite(red, 0);
      digitalWrite(yellow, 0);
      digitalWrite(green, 1);
    }
  }
}
void loop() {
  delay(100);
}
