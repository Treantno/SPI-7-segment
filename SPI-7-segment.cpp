/*
  "spi" 7-segment display SURE electronics

*/

#include <SPI-7-segment.h>
#include <Arduino.h>

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
	memset(buffer, 0, buffer_len);
}

uint8_t SPI_7_segment::map_digit(char in)
{
	if(isdigit(in))
		return(DigitMap[in-'0']);
	if( (toupper(in) >='A') && (toupper(in) <= 'F'))
		return(DigitMap[toupper(in)-'A']);
}

void SPI_7_segment::redraw(void)
{
	size_t cnt1 = buffer_len, cnt2;

	digitalWrite(ENABLE,0); //Turn off display

	while(cnt1--)
	{
		for(cnt2 = 8; cnt2 > 0; cnt2--)
		{
			if( buffer[cnt1] & (1 << cnt2))
				digitalWrite(DATA_OUT,1);
			else
				digitalWrite(DATA_OUT,0);
			
			digitalWrite(CLK,1);
			delayMicroseconds(10);
			digitalWrite(CLK,0);
			delayMicroseconds(10);

		}
	}
	digitalWrite(ENABLE,1); //Turn on display
}

int SPI_7_segment::print(char *data, size_t len)
{
	if(len > buffer_len)
		return 0;
	
	for( size_t cnt=0; cnt < len; cnt++)
	{
		buffer[cnt] = map_digit(data[cnt]);
	}
}

int SPI_7_segment::print(char *data, size_t len, size_t xpos)
{
	
	if( (len + xpos) > buffer_len)
		return 0;
	for( size_t cnt=0; cnt < len; cnt++)
	{
		buffer[cnt+xpos] = map_digit(data[cnt]);
	}
}

//SPI_7_segment::

