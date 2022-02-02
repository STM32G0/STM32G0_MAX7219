/*****************************************
File  : max7219_interface.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : SEGGER Embedded Studio
******************************************/

#include "max7219_interface.h"
#include "max7219.h"

/*do wskaznikow przypisujemy funkcje*/
const max7219_interface_t max7219 = {
.InitAllDevice = max7219_init,
.ClearAllDevice = max7219_clear,
.SendAllDevice = max7219_send,
.SendToDevice = max7219_SendToDevice,

};