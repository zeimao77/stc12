#include "hwsend.h"
#include "hwreceive.h"
#include "uart.h"
#include "mcuid.h"

typedef unsigned char u8;
typedef unsigned int u16;

int main(){
  u8 codedata[] = { 0x79,0xf2,0xe2,0x1d };
	u8 i;
	char * codedat;
	printMCUID();
	
	uartInit();
	sendhw(codedata);
	
	while(1){
	  if(!RECE){
		  Delay1ms(6);
		  if(!RECE){
			  codedat = getcodedata();
			}
		}
		for(i=0;i<4;i++){
		  sendChar(codedat[i]);
		}
	}
	
}