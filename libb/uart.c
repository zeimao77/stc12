#include "uart.h"

//9600bps@11.0592MHz  独立波特率发生器

void uartInit(void){
	PCON &= 0x7F;
	SCON = 0x50;
	AUXR |= 0x04;
	BRT = 0xDC;
	AUXR |= 0x01;
	AUXR |= 0x10;
}

void sendChar(unsigned char dat){
  SBUF = dat;
	while(!TI);
	TI = 0;
}

void sendStr(unsigned char *str){
	unsigned char idata *temp = str;
  sendChar(*temp++);
}