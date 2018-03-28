#ifndef _OLED12864SPI_H_
#define _OLED12864SPI_H_

//#include "spi4.h"
#include "bmp.h"
#include "spi.h"
#include "delay.h"

sbit OLED_RST = P2^3;
sbit OLED_DC = P2^4;

void OLED_Init();

void OLED_writeCmd(unsigned char cmd);

void OLED_writeData(unsigned char dat);

//清屏
void OLED_clear();

void OLED_display_ON();

void OLED_display_OFF();

//定义焦点位置：x [0-128]列  y[0-7]行
void OLED_resetFocus(unsigned char x, unsigned char y);

//绘制图片
void OLED_drawImg(unsigned char bmp[]);

//汉字
//x0参数一般在需要显示的位置*16
void OLED_drawChinese(unsigned char x0,unsigned char page,unsigned int ind);

//显示ascii   [16*8]
//x0参数一般在需要显示的位置*8
void OLED_drawAscii(unsigned char x0,unsigned char page,unsigned char ind);


#endif