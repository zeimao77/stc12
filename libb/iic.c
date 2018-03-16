#include "iic.h"

void IIC_Init(){
  IIC_SCL = 1;
  IIC_SDA = 1;
}

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

void IIC_end(){
	IIC_SDA = 0;
	_nop_();
	_nop_();
  IIC_SCL = 1;
	_nop_();
	_nop_();
  IIC_SDA = 1;
}

void IIC_writeack(bit ack){
  IIC_SDA = ack;
	IIC_SCL = 1;
	Delay10us(IIC_DEL);
  IIC_SCL = 0;
}

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

