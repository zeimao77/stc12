#include "uart.h"

unsigned char flag,temp1;

void main(){
   UART_Init();
   UART2_Init();
   EA = 1;
   IE2 = 0x01;
   P0M1 = 0x00;
   P0M0 = 0xff;
   while(1){
     if(flag){
	 	flag = 0x00;
		P0 = temp1;
		UART_sendChar(temp1);
		UART2_sendChar(temp1);
	 }
   }
}

void UART2_INTERRUPT(void) interrupt 8{
  if(S2CON&0x01){
    S2CON&=~0x01;
	flag = 0x01;
	temp1 = S2BUF;
  }
}