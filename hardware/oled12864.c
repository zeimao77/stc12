#include "oled12864.h"

//驱动芯片SSD1306

//OLED初始化
void OLED_SSD1306_Init()
{
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xAE);   //显示关[睡眠模式]   ae/af  ：[显示关/开]
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x20);	 //设置内存地址模式
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xb0);	//Set Page Start Address for Page Addressing Mode,0-7
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xc8);	//Set COM Output Scan Direction
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x00);//---set low column address
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);//---set high column address
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x40);//--set start line address
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x81);//--set contrast control register
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xdf);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xa1);//--set segment re-map 0 to 127
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xa6);    // 正常显示   a6/a7   ：[显示正常/反相]
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xa8);//--set multiplex ratio(1 to 64)
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x3F);//
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xa4);//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xd3);//-set display offset
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x00);//-not offset
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xd5);//--set display clock divide ratio/oscillator frequency
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xf0);//--set divide ratio
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xd9);//--set pre-charge period
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x22); //
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xda);//--set com pins hardware configuration
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x12);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xdb);//--set vcomh
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x20);//0x20,0.77xVcc
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x8d);//--set DC-DC enable
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x14);//
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xaf);    //显示开
}

void Picture(unsigned char show[])
{
  unsigned char x,y;
  unsigned int i=0;
  for(y=0;y<8;y++){
    IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xb0+y);
    IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x00);
    IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);
    for(x=0;x<132;x++){
      IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,show[i++]);
    }
  }
}



