#include "hwsend.h"

//默认高电平 接PNP  低电平发射
void sendhw(unsigned char codedata[]){
	unsigned char i,j,temp;
  SENDHW = SE;
  Delay1ms(9);
	SENDHW = ST;
	Delay1ms(4);
	Delay10us(50);
	for(i=0;i<4;i++){
	  for(j=0;j<8;j++){
		  temp = codedata[i] >> (7-j) & 0x01;
			SENDHW = SE;
			Delay10us(56);
			if(temp == 0x01){
			  SENDHW = ST;
				Delay10us(169);
			}else{
			  SENDHW = ST;
				Delay10us(56);
			}
		}
	}
}