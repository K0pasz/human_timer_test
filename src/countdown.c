#include "countdown.h"
#include "em_lcd.h"

/**********************
 * In this simple function we do a countdown before the start of the measure
 * It is good for the user to prepare for the test
***********************/

void countDown(void)
{
	SegmentLCD_Write("3");
	Delay(1000);
	SegmentLCD_Write("2");
	Delay(1000);
	SegmentLCD_Write("1");
	Delay(1000);
	SegmentLCD_Write("Start");
}
