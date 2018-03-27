#include "oled12864.h"

//驱动芯片SSD1306

//OLED初始化
void OLED_SSD1306_Init(){
  IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xAE);  //ae/af   [显示关/显示开]
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x00);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);  //2个4位合成一个字节作为列指针，页模式下指定显示内存的列位置
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x40);  //从RAM中哪一行起读取显示内容(0x00~0x3F)
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x81);  //亮度控制
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xCF); 
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xA1);  //0xa0左右反置 0xa1正常
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xC8);  //行扫描上下反转   0xc0上下反置 0xc8正常
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xA6);  //a6/a7   [正常/反白显示]
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xA8);  //行扫多路
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x3f);  //设置扫描哪些行
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xD3);  //行扫偏移(0x00~0x3F)
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x00);//-not offset
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xd5);   //设置时钟分频
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xD9);  //充放电周期设置
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xF1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xDA);  //行扫配置
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x12);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xDB);  //Vcomh反压
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x40);//Set VCOM Deselect Level
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x20);  //设置页地址模式 (0x00/0x01/0x02)
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x02);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x8D);  //内置升压泵开关
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x14);  //--set(0x10) disable
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xA4);  //a4/a5  [正常/全亮显示]
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xA6);  
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xAF);//--turn on oled panel
	
	OLED_SSD1306_clear();
	OLED_SSD1306_setFocus(0,0);
}

void OLED_SSD1306_drawImg(unsigned char show[]){
  unsigned char x,y;
  unsigned int i=0;
  for(y=0;y<8;y++){
    IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xb0+y);
    IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x00);
    IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);
    for(x=0;x<128;x++){
      IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,show[i++]);
    }
  }
}

void OLED_SSD1306_clear(){
  unsigned char i,j;
	for(i=0;i<8;i++){
		IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xb0+i);
		IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);
		IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);
		for(j=0;j<128;j++){
		  IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,0x00);
		}
	}
}

void OLED_SSD1306_drawChinese(unsigned char x0,unsigned char page,unsigned int ind){
  unsigned char i;
	OLED_SSD1306_setFocus(x0,page);
	for(i=0;i<16;i++){
		IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,GBKZKTAB[ind][i]);
	}
	OLED_SSD1306_setFocus(x0,page+1);
	for(;i<32;i++){
	  IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,GBKZKTAB[ind][i]);
	}
}

void OLED_SSD1306_drawAscii(unsigned char x0,unsigned char page,unsigned char ind){
  unsigned char i;
	OLED_SSD1306_setFocus(x0,page);
	for(i=0;i<8;i++){
		IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,ASCIITAB[ind-0x20][i]);
	}
	OLED_SSD1306_setFocus(x0,page+1);
	for(;i<16;i++){
	  IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,ASCIITAB[ind-0x20][i]);
	}
}

void OLED_SSD1306_setFocus(unsigned char x, unsigned char y){ 
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xb0+y);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,((x&0xf0)>>4)|0x10);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,(x&0x0f)|0x01);
}

