#include "ds1302.h"
#include "uart.h"
#include "oled12864.h"

void show(unsigned char addr,unsigned char page,unsigned char dat){
  OLED_SSD1306_drawAscii(addr,page,(dat >> 4)|0x30);
	OLED_SSD1306_drawAscii(addr+8,page,(dat & 0x0f)|0x30);
}

void main(){
	unsigned char ind = 0;
//	struct DS1302_TIME time_buffer;
//	time_buffer.year = 0x18;
//	time_buffer.month = 0x03;
//	time_buffer.day = 0x07;
//	time_buffer.date = 0x18;
//	time_buffer.hour = 0x12;
//	time_buffer.min = 0x05;
//	time_buffer.sec = 0x00;
	DS1302_init();
	OLED_SSD1306_Init();
//  DS1302_writeTime(time_buffer);
	while(1){
	  DS1302_readTime();
		OLED_SSD1306_clear();
		show(0x18,1,0x20);
		show(0x28,1,time_buff.year);
		OLED_SSD1306_drawAscii(0x38,1,0x2d);
		show(0x40,1,time_buff.month);
		OLED_SSD1306_drawAscii(0x50,1,0x2d);
		show(0x58,1,time_buff.date);
		show(0x20,5,time_buff.hour);
		OLED_SSD1306_drawAscii(0x30,5,0x3a);
		show(0x38,5,time_buff.min);
		OLED_SSD1306_drawAscii(0x48,5,0x3a);
		show(0x50,5,time_buff.sec);
		show(0x40,3,time_buff.day);
		Delay1ms(1000);
	}
}



