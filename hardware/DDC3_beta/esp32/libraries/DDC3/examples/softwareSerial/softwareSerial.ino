#include <DDC3.h>
#include <SoftwareSerial.h>

SoftwareSerial softwareSerial(SDA, SCL); // *rIOT-LITE* RX, TX (SCL should never be RX)
//SoftwareSerial softwareSerial(1, 2); // *Dev Board* RX, TX (SDA is LED_BUILTIN on Dev Boards)

// Recommended Max Baud vs Frequency to prevent errors
uint32_t baud = 38400; // 160MHz
//uint32_t baud = 19200; // 80MHz
//uint32_t baud = 9600; // 40MHz

uint16_t count = 0;
uint32_t timer; // to keep track of time
uint16_t timeout = 1000; // 1 second delay

void setup() {
  DDC3.ledColor(0,0,0); // led is white by default. Turning the led off should be the first thing done
  softwareSerial.begin(baud); // 38400 rec max for 160MHz, 19200 rec max for 80MHz
  timer = millis() + timeout; // point at which function should trigger (non-blocking delay)
}

void loop() {
  if(softwareSerial.available()){ // if receives data
    softwareSerial.print("Received: ");
    while(softwareSerial.available()){
      softwareSerial.write(softwareSerial.read());
    }
  }
  else if(millis() >= timer){
    timer = millis() + timeout; // reset point at which function should trigger
    count++; // incrrement counter
    softwareSerial.print("Count: "); softwareSerial.println(count);
  }
}
