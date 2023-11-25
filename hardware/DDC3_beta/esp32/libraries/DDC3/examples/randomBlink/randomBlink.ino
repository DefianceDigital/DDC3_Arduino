#include <DDC3.h>

uint16_t count = 0;
uint32_t timer; // to keep track of time
uint16_t timeout = 1000; // 1 second delay
uint8_t brightness = 25; // value between 0 and 255

void setup() {
  DDC3.ledColor(0,0,0); // led is white by default. Turning the led off should be the first thing done
  DDC3.ledBrightness(brightness);
}

void loop() {
  if(millis() >= timer){
    timer = millis() + timeout; // reset point at which function should trigger
    uint8_t r = random(0, 255); // random value between 0 and 255
    uint8_t g = random(0, 255); // random value between 0 and 255
    uint8_t b = random(0, 255); // random value between 0 and 255
    DDC3.ledColor(r, g, b); // led random color
    delay(250);
    DDC3.ledColor(0,0,0); // turn led off
  }
}