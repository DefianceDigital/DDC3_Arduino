#include <DDC3.h>

#ifdef RIOT_LITE
  #error rIOT-LITE does not have dual Serial Ports! Please select "ESP32-C3 Dev Board" or use example "002_serial" instead   
#else
  #if ARDUINO_USB_CDC_ON_BOOT
  #else
    #error "USB CDC On Boot" must be enabled to use this sketch!
  #endif
#endif

void setup() {
  DDC3.ledColor(0,0,0); // led is white by default. Turning the led off should be the first thing done

  Serial.begin(); // Baud not necessary on USB CDC port
  Serial.println("Running dualSerial");
  Serial0.begin(115200);
}

void loop() {
  if(Serial.connected()){ // Only built-in USB has this function and it's exclusive to this core
    while(Serial.available()){
      Serial0.write(Serial.read()); // echo printed data to the other port
    }
    while(Serial0.available()){
      Serial.write(Serial0.read()); // echo printed data to the other port
    }
  } else {
    Serial0.println("\nPlease open USB CDC port to use this sketch");
    while(Serial.connected() == false); // Don't do anything until it's open
    delay(250); // wait until CDC port should be ready to receive data
    Serial.println("Enter any text to send to UART port");
    Serial0.println("Thanks!"); 
    Serial0.println("Enter any text to send to CDC port");
  }
}
