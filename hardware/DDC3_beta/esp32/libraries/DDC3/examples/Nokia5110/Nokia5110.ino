#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Declare LCD object for software SPI
// Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(TX, RX, 3, 2, 1);

#define RST 1

int rotatetext = 0;

void setup()   {
  
  display.setRotation(rotatetext);

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
  display.setCursor(13,2);
  display.setTextSize(2);
  display.print("PYGMY");
  display.display();
  //delay(1000);
}

void loop() {
  display.fillRect(0, 19, 84, 29, WHITE);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.display();
  delay(500);
  display.setCursor(11,21);
  display.println("Innovation");
  display.display();
  delay(1000);
  display.setCursor(35,30);
  display.println("of");
  display.display();
  delay(1000);
  display.setCursor(17,39);
  display.println("Creation");
  display.display();
  delay(1000);

  for(uint8_t i = 0; i < 3; i++){
    display.fillRect(0, 19, 84, 29, WHITE);
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.display();
    delay(250);
    display.setCursor(11,21);
    display.println("Innovation");
    display.display();
    display.setCursor(35,30);
    display.println("of");
    display.display();
    display.setCursor(17,39);
    display.println("Creation");
    display.display();
    delay(500);
  }
}
