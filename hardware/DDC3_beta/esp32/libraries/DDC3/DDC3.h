#ifndef DDC3_h                     
#define DDC3_h
#endif

#include "Arduino.h"

class ddc3{
  public:
	void ledColor(uint8_t r, uint8_t g, uint8_t b);
	void ledBrightness(uint8_t brt);
  private:  
};

extern ddc3 DDC3;