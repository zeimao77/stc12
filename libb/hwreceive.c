#include "hwreceive.h"

char* getcodedata(){
	//延时函数去除干扰之后进入此函数进行接收解调
	unsigned char i,j,num = 0;
	unsigned char codedata[4];
  while(!RECE);
	while(RECE);
	for(i=0;i<4;i++){
	  for(j==0;j<8;j++){
		  while(!RECE);
			while(RECE){
			  Delay10us(1);
				num++;
			}
			codedata[i] <<= 1;
			if(num > 60){
			  codedata[i] |= 0x01;
			}else{
			  codedata[i] &= 0xfe;
			}
		}
	}
	return &codedata;
}