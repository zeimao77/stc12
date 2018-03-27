#include "hcsr04.h"

unsigned char outH;
unsigned char outL;
unsigned int count;

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
  EX0 = 1;
  TR0 = 1;
	while(ECHO);
	distant = outH;
  distant <<= 8;
  distant |= outL;
  return (count * 65536 + distant) / 32;
}

//处理外部中断  
void INT0() interrupt 0{
  outH = TH0;
	outL = TL0;
	EX0 = 0;
	TR0 = 0;
}

void T_C0() interrupt 1 {
  count++;
}
  