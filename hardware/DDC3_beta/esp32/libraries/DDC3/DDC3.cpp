#include "DDC3.h"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel led(1, LED_BUILTIN, NEO_GRB + NEO_KHZ800);

void ddc3::ledColor(uint8_t r, uint8_t g, uint8_t b){
	led.setPixelColor(0, led.Color(r, g, b));
	led.show();   // Send the updated pixel colors to the hardware.
}

void ddc3::ledBrightness(uint8_t brt){
	led.setBrightness(brt);
	led.show();   // Send the updated pixel colors to the hardware.
}
	
ddc3 DDC3 = ddc3();