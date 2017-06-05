/* 

  "SPI" 7-segment display SURE electronics
*/

#ifndef SPI-Seven-segment_h
#define SPI_Seven-segment_h

#include <stdint.h>
#include <stdlib.h>

class SPI_7_segment
{
	private :
		char *buffer;
		uint8_t buffer_len;
		/* Pin number for clocking data */
		int CLK;
		/* Pin number for data */
		int DATA_OUT;
		/* Pin for turning display on/off or PWM for dimming */
		int ENABLE;
		//0, 1, 2 .... F
//		const uint8_t DigitMap[16] = { 0xFC, 0x60, 0xDA, 0xf2, 0x66, 0xb6, 0xbe, 0xe0, 0xfe, 0xf6, 0xee, 0x3e, 0x1a, 0x7a, 0x9e, 0x8e };
		const uint8_t DigitMap[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };
			
		
		uint8_t map_digit(char in);
		bool autoupdate=false;

	public :
	/* 
	 * Create a new controler 
	 * Params :
    * int dataPin		The pin on the Arduino where data gets shifted out
	 * int clockPin		The pin for the clock
	 * int enPin			The pin for turing Display on/off
	 * int numDevices	The maximum number of 7-Segments to be controled
	 */
		SPI_7_segment(int dataPin, int clkPin, int enPin, int numDevices);
		void clear(void);
		void redraw(void);
		void redraw(char *dbg);
		int print(char *data, size_t len);
		int print(char *data, size_t len, size_t xpos);
		void setDesimalPoint(int pos);
		void SetAutoUpdate(bool update);

};

#endif
