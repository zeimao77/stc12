#include "uart.h"
 
void UART_Init(void){
	PCON &= 0x7F;
	SCON = 0x50;
	AUXR |= 0x04;
	BRT = 0xDC;
	AUXR |= 0x01;
	AUXR |= 0x10;
}

void UART2_Init(void)		//9600bps@11.0592MHz
{
	AUXR &= 0xF7;		//波特率不倍速
	S2CON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x04;		//独立波特率发生器时钟为Fosc,即1T
	BRT = 0xDC;		//设定独立波特率发生器重装值
	AUXR |= 0x10;		//启动独立波特率发生器
}


void UART_sendChar(unsigned char dat){
  SBUF = dat;
  while(!TI);
  TI = 0;
}

void UART2_sendChar(unsigned char dat){
	S2BUF = dat;
    while(!(S2CON&0x02));
    S2CON&=~0x02;
}

void UART_sendStr(unsigned char *str){
  while(*str){
  	UART_sendChar(*str);
	  str++;
  }
}

void UART2_sendStr(unsigned char *str){
  while(*str){
  	UART2_sendChar(*str);
	  str++;
  }
}

//void UART1_INTERRUPT(void) interrupt 4{
//  if(RI==1){
//    RI=0;
//	flag = 0x01;
//	temp1 = SBUF;
//  }
//}