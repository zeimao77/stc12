#include "spi4.h"

void SPI4_writeByte(unsigned char dat){
	unsigned char ind;
  SPI_CS = SPI_SEND_START;
	for(ind = 0;ind < 8; ind++){
	  SPI_CLK = 0;
		dat <<= 1;
		SPI_MISO = CY;
		SPI_CLK = 1;
		_nop_();
	}
	SPI_CLK = 0;
	SPI_CS = SPI_SEND_STOP;
}

void SPI4_readByte(){
  
}



