#include "iic.h"

//IIC I/O端口初始化
void IIC_Init(){
  IIC_SCL = 1;
  IIC_SDA = 1;
}

//写入开始信号
void IIC_start(){
	IIC_SDA = 1;
	IIC_SCL = 1;
	_nop_();
	_nop_();
  IIC_SDA = 0;
	_nop_();
	_nop_();
	IIC_SCL = 0;
}

//写结束信号
void IIC_end(){
	IIC_SDA = 0;
	_nop_();
	_nop_();
  IIC_SCL = 1;
	_nop_();
	_nop_();
  IIC_SDA = 1;
}

//向IIC总线上发送应答码
void IIC_writeack(bit ack){
  IIC_SDA = ack;
	IIC_SCL = 1;
	Delay10us(IIC_DEL);
  IIC_SCL = 0;
}

//从IIC总线上读取应答码
bit IIC_readack(){
  bit ret;
	IIC_SDA = 1;
  _nop_();
	_nop_();
	IIC_SCL = 1;
	Delay10us(IIC_DEL);
	ret = IIC_SDA;
	IIC_SCL = 0;
	return ret;
}

//往IIC总线上写入一个字节
void IIC_writeByte(unsigned char dat){
  unsigned char ind;
	for(ind = 0;ind < 8;ind++){
	  dat <<= 1;
		IIC_SDA = CY;
		IIC_SCL = 1;
		Delay10us(IIC_DEL);
		IIC_SCL = 0;
		Delay10us(IIC_DEL);
	}
  IIC_readack();
}

//从IIC总线上读取一个字节
unsigned char IIC_readByte(){
  unsigned char dat = 0x00,ind;
	for(ind = 0;ind<8;ind++){
	  IIC_SCL = 1;
		Delay10us(IIC_DEL);
		dat <<= 1;
		dat |= IIC_SDA;
		IIC_SCL = 0;
		Delay10us(IIC_DEL);
	}
	return dat;
}

void IIC_writeCd(unsigned char addr1,unsigned char addr2,unsigned char cd){
	IIC_start();
  IIC_writeByte(addr1);
	IIC_writeByte(addr2);
	IIC_writeByte(cd);
	IIC_end();
}

