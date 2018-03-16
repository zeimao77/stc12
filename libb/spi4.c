#include "spi4.h"

void SPI4_writeByte(unsigned char dat){
	unsigned char ind;
  SPI_CS = SPI_SEND_START;
	for(ind = 0;ind < 8; ind++){
	  SPI_CLK = 0;
		if(dat & 0x80){
		  SPI_MISO = 1;
		}else{
		  SPI_MISO = 0;
		}
		SPI_CLK = 1;
		dat <<= 1;
	}
	SPI_CLK = 0;
	SPI_CS = SPI_SEND_STOP;
}