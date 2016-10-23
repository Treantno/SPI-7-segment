/*
  "spi" 7-segment display SURE electronics

*/

#include <SPI-7-segment.h>
#include <stdlib.h>
#include <string.h>

SPI_7_segment::SPI_7_segment(int dataPin, int clkPin, int enPin, int numDevices)
{
	DATA_OUT = dataPin;
	CLK      = clkPin;
	ENABLE   = enPin;
	
	buffer = malloc(numDevices); // Allocate space for databuffer
	memset(buffer,0,numDevices);
	bzero(buffer,numDevices);
}
