#include "getrandom.h"
#include "delay.h"
#include "em_lcd.h"
#include <stdlib.h>

extern random;
extern msTicks;

/*******************************
 * Here we calculate a random number
 * We read the msTicks from the SysTickCounter
 * Then to increase the entropy of the randomness we divide it by a big prime (97)
 * To make the number go from 2 to 10, we do a mod9 and then we add 2 to the result
 * In the end we write it on the LCD
********************************/

void getRandom (void)
{
	uint32_t curTicks;

	curTicks = msTicks;
	//random = (curTicks%9) + 2;

	/* Initializing the random generator */
	srand(curTicks);

	/* getting the random number*/
	random = (rand()%9) + 2;
	SegmentLCD_Number(random);
}
