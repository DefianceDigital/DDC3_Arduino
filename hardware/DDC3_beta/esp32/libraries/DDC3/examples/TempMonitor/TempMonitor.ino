#include "driver/temp_sensor.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Declare LCD object for software SPI
// Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);
#define RST 1
Adafruit_PCD8544 display = Adafruit_PCD8544(TX, RX, 3, 2, RST);

bool hasDisplay = true; // does device have Nokia5110 Display? Set to 'false' if not
bool useFahrenheit = true; // if false, celcius will be used

void initTempSensor(){
    temp_sensor_config_t temp_sensor = TSENS_CONFIG_DEFAULT();
    temp_sensor.dac_offset = TSENS_DAC_L2;  // TSENS_DAC_L2 is default; L4(-40°C ~ 20°C), L2(-10°C ~ 80°C), L1(20°C ~ 100°C), L0(50°C ~ 125°C)
    temp_sensor_set_config(temp_sensor);
    temp_sensor_start();
}

void setup()   {
  Serial.begin();
  
  initTempSensor();

  if(hasDisplay){
    pinMode(RST, OUTPUT);
    digitalWrite(RST, LOW);

    //Initialize Display
    display.begin();

    // you can change the contrast around to adapt the display for the best viewing!
    display.setContrast(59);

    // Clear the buffer.
    display.clearDisplay();

    //display.display();

    display.fillRect(0, 0, 84, 18, BLACK);
    display.setTextColor(WHITE, BLACK); // 'inverted' text
    display.setCursor(7,5);
    display.setTextSize(1);
    if(useFahrenheit){
      display.print("MCU TEMP (F)");
      display.display();
    } else {
      display.print("MCU TEMP (C)");
      display.display();
    }
  }
}

void loop() {
  Serial.print("MCU TEMPERATURE: ");
  float result = 0;
  temp_sensor_read_celsius(&result);
  float fahrenheit = (1.8 * result) +32;
  if(useFahrenheit){
    Serial.print(fahrenheit);
    Serial.println(" °F");
  } else {
    Serial.print(result);
    Serial.println(" °C");
  }

  if(hasDisplay){
    display.fillRect(0, 19, 84, 29, WHITE);
    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.setCursor(2,25);
    if(useFahrenheit){
      display.print(fahrenheit);
      display.display();
    } else {
      display.print(result);
      display.display();
    }
  }

  delay(1000);
}
