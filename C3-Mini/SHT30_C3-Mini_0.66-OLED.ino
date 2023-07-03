#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WEMOS_SHT3X.h>

#define OLED_RESET 22  // GPIO22
Adafruit_SSD1306 display(OLED_RESET);

SHT3X sht30(0x45);

void setup() {

  Serial.begin(115200);
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void loop() {
  
  if(sht30.get()==0){
      // Clear the buffer.
    display.clearDisplay();
    display.setTextSize(1.5);
    display.setCursor(35, 10);
    display.setTextColor(WHITE);
    display.println("T: ");
    display.setTextSize(1);
    display.setCursor(48, 10);
    display.println(sht30.cTemp);

    display.setCursor(35, 25);
    display.setTextSize(1.5);
    display.println("H: ");
    display.setTextSize(1);
    display.setCursor(48, 25);
    display.println(sht30.humidity);
  }
  else
  {
    display.println("Error!");
  }
  display.display();
  delay(1000);

}
