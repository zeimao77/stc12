#include "ds1302.h"

struct DS1302_TIME time_buff;

void DS1302_init(){
 DS1302_RST = 0;
 DS1302_SCK = 0;
 DS1302_DAT = 0;
}

void DS1302_writeByte(unsigned char dat){
  unsigned char i;
  for (i = 0;i < 8;i++) {
    if (dat & 0x01) {
	  DS1302_DAT=1;
    }else{
	  DS1302_DAT=0;
	}
	DS1302_SCK=1;
	DS1302_SCK=0;
	dat >>= 1;
  }
}

void DS1302_write(unsigned char addr,unsigned char dat){
	addr &= 0xfe;
	DS1302_RST = 1;
  DS1302_writeByte(addr);
  DS1302_writeByte(dat);
	DS1302_RST = 0;
}

void DS1302_writeTime(struct DS1302_TIME time_buffer){
  DS1302_write(DS1302_CONTROL_ADDR,0x00);
  DS1302_write(DS1302_SEC_ADDR,0x80);
  DS1302_write(DS1302_YEAR_ADDR,time_buffer.year);
  DS1302_write(DS1302_MONTH_ADDR,time_buffer.month);
  DS1302_write(DS1302_DATE_ADDR,time_buffer.date);
  DS1302_write(DS1302_HOUR_ADDR,time_buffer.hour);
  DS1302_write(DS1302_MIN_ADDR,time_buffer.min);
  DS1302_write(DS1302_SEC_ADDR,time_buffer.sec);
  DS1302_write(DS1302_DAY_ADDR,time_buffer.day);
  DS1302_write(DS1302_CONTROL_ADDR,0x80);
}

void DS1302_readTime(){
  time_buff.year = DS1302_readByte(DS1302_YEAR_ADDR);
  time_buff.month = DS1302_readByte(DS1302_MONTH_ADDR);
  time_buff.date = DS1302_readByte(DS1302_DATE_ADDR);
  time_buff.hour = DS1302_readByte(DS1302_HOUR_ADDR);
  time_buff.min = DS1302_readByte(DS1302_MIN_ADDR);
  time_buff.sec = DS1302_readByte(DS1302_SEC_ADDR)&0x7f;
  time_buff.day = DS1302_readByte(DS1302_DAY_ADDR);
}

unsigned char DS1302_readByte(unsigned char addr){
  unsigned char dat,i;
	DS1302_RST=1;
  addr |= 0x01;
  DS1302_writeByte(addr);
  for (i = 0;i < 8;i++) {
    dat = dat >> 1;
      if (DS1302_DAT) {
	      dat |= 0x80;
	    }else{
		    dat &= 0x7F;
	    }
	  DS1302_SCK=1;
	  DS1302_SCK=0;
  }	
  DS1302_RST=0;
  return dat;
}