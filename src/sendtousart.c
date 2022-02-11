#include "sendtousart.h"
#include "em_usart.h"
#include "em_gpio.h"

char str1 [256]; //this string is for the sendToUsart function
extern random;
extern resultWhole;
extern resultFraction;

/*****************************
 * Here we send the information to the USART
 * We put each line into a string with the values
 * Then we use a for cycle to print the string by characters
******************************/

void sendToUsart(void)
{
	sprintf(str1, "REQ:%d REAL:%d.%d \n\r", random, resultWhole, resultFraction);
	for(int i = 0; i<256; i++)
	{
		USART_Tx(UART0, str1[i]);
	}

	Delay(3000);
}
