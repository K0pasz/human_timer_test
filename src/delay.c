#include "delay.h"

extern msTicks; /* counts 1ms timeTicks */

/* here we use the Delay function from the blink example project */
void Delay(long dlyTicks) //it delays the program from running for dlyTicks [ms]
{
  long curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks) ;
}
