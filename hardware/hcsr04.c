#include "hcsr04.h"

unsigned char outH;
unsigned char outL;
unsigned char count;

void HCSR04_init(){
  P1M0 = 0XFF;
	P1M1 = 0X00;
	TMOD = 0x01;
	IE = 0x80;
	IT0 = 1;
}

unsigned int testdistance(){
	unsigned int distant;
	count = 0;
  TRIG = 1;
  Delay10us(2);
	TRIG = 0;
  TH0 = 0x00;
	TL0 = 0x00;
	while(~ECHO);
  TR0 = 1;
	while(ECHO);
	outH = TH0;
	outL = TL0;
	TR0 = 0;
	distant = outH;
  distant <<= 8;
  distant |= outL;
  UART_sendChar(0xff);
	UART_sendChar(count);
  UART_sendChar(outH);
	UART_sendChar(outL);

	distant = (count * 65536 + distant) * 0.18663;
  return distant;
}

void T_C0() interrupt 1 {
  TH0 = 0x00;
	TL0 = 0x00;
  count++;
}
  