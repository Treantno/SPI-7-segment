/*
  "spi" 7-segment display SURE electronics

*/

#include <SPI-7-segment.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

SPI_7_segment::SPI_7_segment(int dataPin, int clkPin, int enPin, int numDevices)
{
	DATA_OUT = dataPin;
	CLK      = clkPin;
	ENABLE   = enPin;
   buffer_len = numDevices;
	
	buffer = malloc(numDevices); // Allocate space for databuffer
	memset(buffer,0,numDevices);
}

void SPI_7_segment::clear(void)
{

}

uint8_t SPI_7_segment::map_digit(char in)
{

}

void SPI_7_segment::redraw(void)
{
	size_t cnt1 = buffer_len, cnt2;
	digitalWrite(ENABLE,0); //Turn off display
	while(cnt1--)
	{
		for(cnt2 = 8; cnt2 > 0;cnt2--)
		{
			if( buffer[cnt1] & (1 << cnt2)
				digitalWrite(DATA_OUT,1);
			else
				digitalWrite(DATA_OUT,0);
			
			digitalWrite(CLK,1);
			delayMicroseconds(10);
			digitalWrite(CLK,0);
			delayMicroseconds(10);

	}
	digitalWrite(ENABLE,1); //Turn on display
}
//SPI_7_segment::
//SPI_7_segment::

