/*****************************************
File  : max7219_interface.h
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : SEGGER Embedded Studio
******************************************/

#include <stdint.h>
#include "max7219.h"


#ifndef MAX7219_INTERFACE_H_
#define MAX7219_INTERFACE_H_


typedef  struct {
/*deklaracja wskaznikow na funkcje*/
void (*InitAllDevice)(void);
void (*ClearAllDevice)(void);
void (*SendAllDevice)(uint8_t adress, uint8_t data);
void (*SendToDevice)(uint8_t DeviceNumber, uint8_t adress, uint8_t data);

} max7219_interface_t ;

extern const max7219_interface_t max7219 ;

#endif /*MCP79410_INTERFACE_H*/