#ifndef _AT24C16_H_
#define _AT24C16_H_

#include "iic.h"

#define AT24C16_DEVICEADDRESS 0xa0



void AT24C16_write(unsigned int address,unsigned char dat);

void AT24C16_read(unsigned int address);


#endif