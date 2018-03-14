#include "tm1640.h"

void TM1640_sendCmd(unsigned char dat){
	unsigned char ind;
	DIN = 0;  
	SCLK = 0;
  for(ind = 0;ind < 8;ind++){
	  if(((dat >> ind)& 0x01) == 0x01){
		  DIN = 1;
			SCLK = 1;
				Delay10us(TM1640_DEL_TIME);
			SCLK = 0;
		}else{
		  DIN = 0;
			SCLK = 1;
			Delay10us(TM1640_DEL_TIME);
			SCLK = 0;
		}
	}
	SCLK = 1;
	DIN = 1;
}

void TM1640_start(){
  TM1640_sendCmd(0x44);
}

void TM1640_end(){
  TM1640_sendCmd(0x8b);
}

void TM1640_display(unsigned char addr,unsigned char dat){
  TM1640_sendCmd(addr + 0xc0);
  TM1640_sendCmd(dat);
}