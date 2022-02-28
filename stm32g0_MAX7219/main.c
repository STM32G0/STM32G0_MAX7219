/*****************************************
File  : main.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : SEGGER Embedded Studio
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stm32g071xx.h>
#include "system_config.h"
#include "max7219.h"
#include "max7219_interface.h"



volatile uint8_t intFlag = 0;

int main(void) {

SystemInit();
SYSTEM_MANAGER_Initialize();

SysTick_Config(16000000 * 0.5); //ok 0.5 s

/* u¿ywamy interfejsu do rozmowy z MAX7219 */
max7219.InitAllDevice();
max7219.ClearAllDevice();

max7219.SendToDevice(Device0, MAX7219_DIGIT5, 5|kropka)  ;
max7219.SendToDevice(Device0, MAX7219_DIGIT6, 2)  ;

max7219.SendToDevice(Device1, MAX7219_DIGIT0, 2)  ;
max7219.SendToDevice(Device1, MAX7219_DIGIT1, 1|kropka)  ;
max7219.SendToDevice(Device1, MAX7219_DIGIT2, 5)  ;

max7219.SendToDevice(Device0, MAX7219_DIGIT0, 1)  ;
max7219.SendToDevice(Device0, MAX7219_DIGIT1, 2)  ;
max7219.SendToDevice(Device0, MAX7219_DIGIT2, 3|kropka)  ;
max7219.SendToDevice(Device0, MAX7219_DIGIT3, 1)  ;


while(1){

if(intFlag){ //flaga aktywowana w przerwaniu SysTick
     
      intFlag = 0; //zeruj flage 
           
              LED2_Toggle();
     }
  }
}

/*Interrupt Handler for SysTick*/

void SysTick_Handler(void){
intFlag = 1;
}














/*
void EXTI0_1_IRQHandler(void){
intFlag = 1;
if(EXTI->FPR1 & EXTI_FPR1_FPIF1)
EXTI->FPR1 |= EXTI_FPR1_FPIF1; //clear pending
}
*/