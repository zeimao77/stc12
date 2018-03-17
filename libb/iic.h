#ifndef _IIC_H_
#define _IIC_H_

#include <stc12c5a60s2.h>
#include "delay.h"

#define IIC_DEL 0

sbit IIC_SCL = P1^1;
sbit IIC_SDA = P1^2;

#include "iic.h"

//IIC I/O端口初始化
void IIC_Init();

//写入开始信号
void IIC_start();

//写结束信号
void IIC_end();

//向IIC总线上发送应答码
void IIC_writeack(bit ack);

//从IIC总线上读取应答码
bit IIC_readack();

//往IIC总线上写入一个字节
void IIC_writeByte(unsigned char dat);

//从IIC总线上读取一个字节
unsigned char IIC_readByte();

//发送一条命令或数据到IIC总线
void IIC_writeCd(unsigned char addr1,unsigned char addr2,unsigned char cd);


#endif