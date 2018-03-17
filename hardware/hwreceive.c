#include "hwreceive.h"

const unsigned char code MP3HWTAB[][2]= {
{0xa2,0x25},  //CH-    0
{0x62,0x9d},  //CH     1
{0xe2,0x1d},  //CH+    2
{0x22,0xdd},  //|<<    3
{0x02,0xfd},  //>>|    4
{0xc2,0x3d},  //>||    5
{0xe0,0x1F},  //-      6
{0xa8,0x57},  //+      7
{0x90,0x6f},  //eq     8
{0x68,0x97},  //0      9
{0x98,0x67},  //100+   10
{0xb0,0x4f},  //200+   11
{0x30,0xcf},  //1      12
{0x18,0xe7},  //2      13
{0x7a,0x85},  //3      14
{0x10,0xef},  //4      15
{0x38,0xc7},  //5      16
{0x5a,0xa5},  //6      17
{0x42,0xbd},  //7      18
{0x4a,0xb5},  //8      19
{0x52,0xad}   //9      20
};

unsigned char* getcodedata(){
	//延时函数去除干扰之后进入此函数进行接收解调
	unsigned int num = 0;
	unsigned char i,j;
	unsigned char codedata[4] = {0xff,0xff,0xff,0xff};
  while(!RECE);
	while(RECE){
    Delay1ms(1);
		num++;
		if(num > 6){
			return &codedata;
		}
  }
	for(i=0;i<4;i++){
	  for(j=0;j<8;j++){
			num = 0;
		  while(!RECE);
			while(RECE){
			  Delay10us(1);
				num++;
				if(num >= 300){
			    return &codedata;
			  }
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