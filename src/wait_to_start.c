#include "wait_to_start.h"
#include "em_gpio.h"


/* In this function we are waiting for the user to push PB0 */
void waitToStart(void)
{
	SegmentLCD_Number(0);
	while (GPIO_PinInGet(gpioPortB, 9))
		{
			SegmentLCD_Write("Ready?");
		}
}
