#include "lcd1602.h"

void writecmd(unsigned char cmd){
	RS = 0;
  DATA = cmd;
	EN = 1;
	Delay10us(5);
	EN = 0;
}

void writedata(unsigned char dat){
  RS = 1;
  DATA = dat;
	EN = 1;
	Delay10us(5);
	EN = 0;
}

void initLcd(){
	RW = 0;
	EN = 0;
  writecmd(0x02);
	writecmd(0x06);
	writecmd(0x0c);
	writecmd(0x2c);
	writecmd(0x01);
	writecmd(0x81);
}