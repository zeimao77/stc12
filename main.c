#include "hwreceive.h"
#include "uart.h"
#include "delay.h"
#include "system.h"


void play(unsigned char key1,unsigned char key2){
  if(key1 == MP3HWTAB[12][0] && key2 == MP3HWTAB[12][1]){
	  P0 = 0xf2;
	}
	else if(key1 == MP3HWTAB[13][0] && key2 == MP3HWTAB[13][1]){
	  P0 = 0xf3;
	}
	else if(key1 == MP3HWTAB[14][0] && key2 == MP3HWTAB[14][1]){
	  P0 = 0xf6;
	}
	else if(key1 == MP3HWTAB[15][0] && key2 == MP3HWTAB[15][1]){
	  P0 = 0xf7;
	}
	else if(key1 == MP3HWTAB[16][0] && key2 == MP3HWTAB[16][1]){
	  P0 = 0xfa;
	}
	else if(key1 == MP3HWTAB[17][0] && key2 == MP3HWTAB[17][1]){
	  P0 = 0xfb;
	}
	else if(key1 == MP3HWTAB[18][0] && key2 == MP3HWTAB[18][1]){
	  P0 = 0xfe;
	}
	else if(key1 == MP3HWTAB[9][0] && key2 == MP3HWTAB[9][1]){
	  P0 = 0xf0;
	}
}

void main(){
	unsigned char ind;
	unsigned char *codedata;
	UART_Init();
	RECE = 1;
	P0M1 = 0x00;
	P0M0 = 0xff;
	//开始外部中断
	EA = 1;
	IT1 = 1;
	EX1 = 1;
	while(1){
	  if(RECE == 0){
	    Delay1ms(5);
			if(RECE == 0){
			  codedata = getcodedata();
				for(ind = 0;ind < 4;ind ++){
	        UART_sendChar(codedata[ind]);
	      }
				play(codedata[2],codedata[3]);
			}
	  }
		_nop_();
		_nop_();
		UART_sendStr("进入掉电模式");
		sys_pd();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
	}
}