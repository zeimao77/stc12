#include "mcuid.h"

//调用之前需要先初始化串口
void printMCUID(){
	unsigned char idata *iptr = ID_ADDR_RAM;
	unsigned char i;
  for(i=0;i<7;i++){
	  UART_sendChar(*iptr++);
	}
}

void checkMCUID(unsigned char *mcuid){
  unsigned char idata *iptr = ID_ADDR_RAM;
	unsigned char i;
  for(i=0;i<7;i++){
	  UART_sendChar(*iptr++);
		if(*iptr+i != *mcuid+i ){
			while(1){
			  UART_sendStr("no\n");
			}
		}
	}
}