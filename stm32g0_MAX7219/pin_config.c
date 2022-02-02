/*****************************************
File  : pin_config.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : SEGGER Embedded Studio
******************************************/

#include <stm32g071xx.h>

void PIN_MANAGER_Initialize(void) {
/********** PA1 (SCK) and PA2 (MOSI) set for SPI1*****************/
/*set Alternate fuction mode (0b10)*/
/*Pin PA1*/
GPIOA->MODER &= ~GPIO_MODER_MODE1_0;
/*Pin PA2*/
GPIOA->MODER &= ~GPIO_MODER_MODE2_0;
/*set low speed (0b01)*/
GPIOA->OSPEEDR |= (GPIO_OSPEEDR_OSPEED1_0 | GPIO_OSPEEDR_OSPEED2_0) ;
/*GPIO alternate function low register (GPIOA_AFRL for AFSEL1 and AFSEL2 set default 0b0000)*/

/********** PC15 set Out for LED **********************/
GPIOC->MODER &= ~GPIO_MODER_MODE15_1; //MODE15 -> 0b01

/********** PA8 set Out for LED **********************/
GPIOA->MODER &= ~GPIO_MODER_MODE8_1; //MODE8 -> 0b01

/********** PA3 set Out for CS MAX7219 **********************/
GPIOA->MODER &= ~GPIO_MODER_MODE3_1; //MODE3 -> 0b01
          
}