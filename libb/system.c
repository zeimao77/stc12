#include "system.h"

void sys_en_wdt(bit flag,unsigned char wdt_xdp){
	WDT_CONTR = 0x20;
	if(flag){
		WDT_CONTR |= 0x04;
	}
	WDT_CONTR |= wdt_xdp;
}


void sys_feed_wdt(){
  WDT_CONTR |= 0x10;
}

void sys_pd(){
	PCON |= 0x02;
}

void sys_idle(){
	PCON |= 0x01;
}
