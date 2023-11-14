// This example is for using one serial port or the other (if ESP32-C3 Dev Board)
// See example "003_dualUSB" to see how to use both (if ESP32-C3 Dev Board)

#include <DDC3.h>

uint16_t count = 0;
uint32_t timer; // to keep track of time
uint16_t timeout = 1000; // 1 second delay

void setup() {
  DDC3.ledColor(0,0,0); // led is white by default. Turning the led off should be the first thing done
  Serial.begin(115200); // Setting Baud is not necessary for USB CDC, but we'll do it anyway for code friendliness
  if(ARDUINO_USB_CDC_ON_BOOT){
    delay(1000); // delay recommended after initializing USB CDC
    Serial.println("Printing on USB CDC Port");
  } else {
    Serial.println("Printing on Traditional Port (UART)"); // rIOT-LITE doesn't have this option
  }
}

void loop() {
  if(millis() >= timer){
    timer = millis() + timeout; // reset point at which function should trigger
    count++; // incrrement counter
    Serial.print("Count: "); Serial.println(count);
  }
  if(ARDUINO_USB_CDC_ON_BOOT){ // only USB CDC has connected status function
    if(Serial.connected() == true){
      DDC3.ledColor(0, 0, 4); // led Blue
    }
    else {
      DDC3.ledColor(0, 0, 0); // led off
    }
  }
}
