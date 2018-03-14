#include "lcd1602.h"

void LCD1602_write_cmd(unsigned char cmd){
	RS = 0;
  DATA = cmd;
	EN = 1;
	Delay10us(50);
	EN = 0;
	Delay10us(50);
}

void LCD1602_write_data(unsigned char dat){
  RS = 1;
  DATA = dat;
	EN = 1;
	Delay10us(50);
	EN = 0;
	Delay10us(50);
}

void LCD1602_init(){
	RS = 0;
	RW = 0;
	EN = 0;
	//归位
  LCD1602_write_cmd(0x02);
	//设置输入方式，AC自动增一，画面不动
	LCD1602_write_cmd(0x06);
	//显示控制开关
	LCD1602_write_cmd(0x0c);
	//功能设置：8位数据 两行显示，5*7点阵
	LCD1602_write_cmd(0x38);
	//清屏
	LCD1602_write_cmd(0x01);
	//定位光标0X80
	//第二行 0XC0
	LCD1602_write_cmd(0x80);
}