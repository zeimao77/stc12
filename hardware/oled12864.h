#ifndef _OLED12864_H_
#define _OLED12864_H_

//IICÇý¶¯
#include "iic.h"
#include "bmp.h"

#define OLED_ADDR 0x78
#define OLED_CMD_ADDR 0x00
#define OLED_DATA_ADDR 0x40

void OLED_SSD1306_Init();

void OLED_SSD1306_drawImg(unsigned char show[]);

void OLED_SSD1306_clear();

void OLED_SSD1306_drawChinese(unsigned char x0,unsigned char page,unsigned int ind);

void OLED_SSD1306_drawAscii(unsigned char x0,unsigned char page,unsigned char ind);

void OLED_SSD1306_setFocus(unsigned char x, unsigned char y);
#endif