#include "delay.h"

//@11.0592MHz

void Delay10us(unsigned int del){
	unsigned char i;
  for(;del>0;del--){
	  _nop_();
	  _nop_();
	  _nop_();
	  i = 24;
	  while (--i);
	}
}

void Delay1ms(unsigned int del){
	unsigned char i, j;
  for(;del>0;del--){
	  _nop_();
	  i = 11;
	  j = 190;
	  do{
		  while (--j);
	  } while (--i);
	}
}
