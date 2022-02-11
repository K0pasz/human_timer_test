#include "measure.h"
#include "em_gpio.h"
#include "bsp.h"
#include "delay.h"

char str[6]; //we need this for the SegmentLCD_Write function

extern endValue;
extern result;
extern resultWhole;
extern resultFraction;
extern msTicks;


/******************************
 * This function represents the test
 * We use the SysTickCounter for counting the elapsed time
 * We turn on the led to give the user a signal to start (and also the "go" on the lcd)
 * We read the starting value from the msTicks (it is in ms)
 * Then we wait for the button to be pushed
 * After it has been pushed, we save the ending value, and calculate the result
 * With the help of sprintf we can take these values into a string
 * In the end we write the result on the lcd, hold it for 3 seconds for the user, then the led turns off
*******************************/
void measure(void)
{
	BSP_LedToggle(0);
	uint32_t startingValue = msTicks;
	while(GPIO_PinInGet(gpioPortB, 9))
	{
		//We are waiting for the button to be pushed
	}
	endValue = msTicks;
	result = endValue - startingValue;
	resultWhole = result / 1000;
	resultFraction = result%1000;

	sprintf(str, "%d.%d", resultWhole, resultFraction);

	SegmentLCD_Write(str);

	BSP_LedToggle(0);
}
