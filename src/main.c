/************************************
 * BAMBI Homework
 * Made by:
 *  Almasi Zsombor - DZR1RM
 *  Debreczeni Laszlo - IWNUTK
 * Emberi idozito teszt
 * **********************************/
#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "em_lcd.h"
#include "bsp.h"
#include "em_usart.h"

volatile uint32_t msTicks; // counts 1ms timeTicks
volatile uint8_t random; // the random value between 2s and 10s
volatile uint32_t startingValue; //starting value for the measurement
volatile uint32_t endValue; //ending value for the measurement
volatile uint32_t result; //result from the measurement
volatile int resultWhole; //Whole part of the result
volatile int resultFraction; //Fraction part of the result


void SysTick_Handler(void)
{
  msTicks++;       /* increment counter necessary in Delay()*/
}


int main(void)
{
  /* Chip errata */
  CHIP_Init();

  /* Setup SysTick Timer for 1 msec interrupts  */
   if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) {
     while (1) ;
   }

  /* Enable LCD without voltage boost */
  SegmentLCD_Init(false);

  /* Enable clock for GPIO */
  CMU->HFPERCLKEN0 |= CMU_HFPERCLKEN0_GPIO;

  /* Configure PB0 (PushButton0) as input */
  GPIO_PinModeSet(gpioPortB, 9, gpioModeInput, 0);

  /* Clock enable for UART0 */
  CMU_ClockEnable(cmuClock_UART0, true);

  /* USART Pin set */
  GPIO_PinModeSet(gpioPortF, 7, gpioModePushPull, 1);


  /* Configure UART0 (115200 Baud, 8N1), the default init gives us these parameters */
  USART_InitAsync_TypeDef UART0_init = USART_INITASYNC_DEFAULT;
  USART_InitAsync(UART0, &UART0_init);

  /* PE0 (TX) set to push-pull output */
  GPIO_PinModeSet(gpioPortE, 0, gpioModePushPull, 1);
  UART0->ROUTE |= UART_ROUTE_LOCATION_LOC1;
  UART0->ROUTE |= USART_ROUTE_TXPEN;

  /* Initializing the leds with the help from bsp.c */
  BSP_LedsInit();
  BSP_LedClear(0);


  /* Infinite loop */
  while (1) {
	  waitToStart();
	  getRandom();
	  countDown();
	  measure();
	  sendToUsart();
  }
}
