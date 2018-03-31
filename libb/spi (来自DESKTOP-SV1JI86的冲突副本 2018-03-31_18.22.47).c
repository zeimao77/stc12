#include "spi.h"

void SPI_init(unsigned char DORD,unsigned char CPOL){
//	SPCTL = 0x67 | DORD | CPOL;
	SPCTL = 0xd7;
	SPSTAT = 0xc0;
}

void SPI_writeByte(unsigned char DAT){
  SPDAT = DAT;
	while(!(SPSTAT & 0x80));
	SPSTAT = 0xc0;
}

unsigned char readByte(){
  unsigned char DAT;
	DAT = SPDAT;
	return DAT;
}