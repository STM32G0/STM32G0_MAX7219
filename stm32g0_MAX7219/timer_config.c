/*****************************************
File  : timer_config.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : SEGGER Embedded Studio
******************************************/

#include <stm32g071xx.h>
#include "timer_config.h"

/*TIM6 to Delay functionality*/
void TIMER6_MANAGER_Initialize(void){
TIM6->PSC = 16-1;  // 16MHz/16 = 1 MHz ~~ 1 uS delay (FCY 16MHz)
TIM6->ARR = 0xffff;  // MAX ARR value
TIM6->CR1 |= TIM_CR1_CEN; // Enable the Counter
while (!(TIM6->SR & TIM_SR_UIF));  // UIF: Update interrupt flag..  This bit is set by hardware when the registers are updated
}