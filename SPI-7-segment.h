/* 

  "SPI" 7-segment display SURE electronics
*/

#ifndef SPI-Seven-segment_h
#define SPI_Seven-segment_h


class SPI_7_segment
{
	private :
		char *buffer;
		/* Pin number for clocking data */
		int CLK;
		/* Pin number for data */
		int DATA_OUT;
		/* Pin for turning display on/off or PWM for dimming */
		int ENABLE;

	public :
   /* :w
     * Create a new controler 
     * Params :
     * int dataPin		The pin on the Arduino where data gets shifted out
     * int clockPin		The pin for the clock
     * int enPin			The pin for turing Display on/off
     * int numDevices	The maximum number of 7-Segments to be controled
     */
    SPI_7_segment(int dataPin, int clkPin, int enPin, int numDevices);

};

#endif
