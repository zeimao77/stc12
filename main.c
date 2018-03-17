#include "oled12864.h"

void main(){
  OLED_SSD1306_Init();
	while(1){
    OLED_SSD1306_clear();
		OLED_SSD1306_drawChinese(0,0,0);
		OLED_SSD1306_drawChinese(16,0,1);
		OLED_SSD1306_drawChinese(32,0,2);
		OLED_SSD1306_drawAscii(0,2,0x7a);
		OLED_SSD1306_drawAscii(8,2,0x65);
		OLED_SSD1306_drawAscii(16,2,0x69);
		OLED_SSD1306_drawAscii(24,2,0x6d);
		OLED_SSD1306_drawAscii(32,2,0x61);
		OLED_SSD1306_drawAscii(40,2,0x6f);
		OLED_SSD1306_drawAscii(48,2,0x37);
		OLED_SSD1306_drawAscii(56,2,0x37);
		Delay1ms(1000);
		OLED_SSD1306_clear();
	  OLED_SSD1306_drawImg(BMP2);
		Delay1ms(1000);
	}
}