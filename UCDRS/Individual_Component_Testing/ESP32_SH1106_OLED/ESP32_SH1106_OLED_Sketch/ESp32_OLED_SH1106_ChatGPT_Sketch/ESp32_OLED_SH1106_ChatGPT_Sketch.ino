#include <Wire.h>
#include <U8g2lib.h>

// U8G2_SSD1306_128X64_NONAME_F_HW_I2C - for SSD1306
// U8G2_SH1106_128X64_NONAME_F_HW_I2C - for SH1106 (our case)
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); 

void setup() {
  u8g2.begin();
  u8g2.clearBuffer();          // Clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr); // Choose a suitable font
  u8g2.drawStr(0,10,"Hello from ESP32!");
  u8g2.sendBuffer();           // Transfer internal memory to the display
}

void loop() {
  // You can update text, draw shapes, etc. here
}
