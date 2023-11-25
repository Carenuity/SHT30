#include <Wire.h>
#include <WEMOS_SHT3X.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

 // Declaration for SSD1306 display connected using I2C
#define OLED_RESET  0 // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(OLED_RESET);

SHT3X sht30(0x45);

void setup() {

  Serial.begin(115200);
  Wire.begin();

     // initialize the OLED object
 display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

}

void loop() {
// intialize by Clearing the display.
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(25,7);
  display.startscrollleft(0x00, 0x0F);
  display.print("Hygro-Thermometer");
  delay(4000);

  
  if(sht30.get()==0){
    display.setCursor(35,15);
    display.print("Tem: ");
    display.println(sht30.cTemp);
    display.setCursor(35,25);
    display.print("R.H: ");
    display.println(sht30.humidity);
    display.println();
    display.display();
  }
  else
  {
    display.println("Error!");
  }
  delay(1000);

}
