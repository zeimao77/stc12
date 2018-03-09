#include "mcuid.h"

void printMCUID(){
	unsigned char idata *iptr = ID_ADDR_RAM;
	unsigned char i;
  for(i=0;i<7;i++){
	  sendChar(*iptr++);
	}
}

void checkMCUID(unsigned char *mcuid){
  unsigned char idata *iptr = ID_ADDR_RAM;
	unsigned char i;
  for(i=0;i<7;i++){
	  sendChar(*iptr++);
		if(*iptr+i != *mcuid+i ){
			while(1){
			  sendChar('n');
			}
		}
	}
}