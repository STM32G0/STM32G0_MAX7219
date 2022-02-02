/*****************************************
File  : max7219.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : SEGGER Embedded Studio
******************************************/

#include <stm32g071xx.h>
#include <string.h>
#include "system_config.h"
#include "max7219.h"

uint8_t Max7219SpiBuffer[MAX7219_DEVICES * 2];

// wyslanie 2 bajtów do ukladu MAX7219
// 1 bajt (adress) - adres rejestru do którego bêd¹ wpisane dane
// 2 bajt (data) - dane do zapisania
void max7219_send(uint8_t adress, uint8_t data)
{
    CS_SetLow();	// ustawienie stanu niskiego na linii CS
    SPI1_Transmit_2x8bit(adress, data);
    CS_SetHigh();	// ustawienie stanu wysokiego na linii CS (zatrzaœniêcie danych w ukladzie zboczem narastajacym)
}

// inicjalizacja ukladu MAX7219
void max7219_init(void)
{
	max7219_send(MAX7219_SCAN_LIMIT, (MAX7219_USE_DIGIT-1));  // liczba obslugiwanych wyswietlaczy
	max7219_send(MAX7219_INTENSITY, 15);	// maksymalna jasnosc od zera 0 - 15
	max7219_send(MAX7219_DECODE_MODE, MAX7219_USE_BCD_DECODE); // ustawienie trybu wyswietlania dla poszczególnych wyswietlaczy - BCD
	max7219_send(MAX7219_SHUTDOWN, MAX7219_NORMAL_OPPERATION);	// wlaczenie ukladu (normal operation)
        max7219_send(MAX7219_DISPLAY_TEST, 0) ; //Test OFF
}


// czyszczenie zawartosci wszystkich wyswietlaczy LED
void max7219_clear(void)
{
	uint8_t i=MAX7219_USE_DIGIT ;
	while (i) {
#if MAX7219_USE_BCD_DECODE == 0
		max7219_send(i,0);
#else
		if ((MAX7219_USE_BCD_DECODE & (1<<i))) {
			max7219_send(i,0xF);
		} else {
			max7219_send(i,0);
		}
		i--;
#endif
	}
}


void max7219_SendToDevice(uint8_t DeviceNumber, uint8_t Adress, uint8_t Data)
{
	uint8_t Offset = DeviceNumber * 2;

	memset(Max7219SpiBuffer, 0x00, (MAX7219_DEVICES * 2)); // set NOP
	Max7219SpiBuffer[(MAX7219_DEVICES * 2)-Offset-2] = Adress;
	Max7219SpiBuffer[(MAX7219_DEVICES * 2)-Offset-1] = Data;
        CS_SetLow();	// ustawienie stanu niskiego na linii CS
        SPI1_Transmit_Buffer( Max7219SpiBuffer, (MAX7219_DEVICES * 2));
	CS_SetHigh();	// ustawienie stanu wysokiego na linii CS (zatrzaœniêcie danych w ukladzie zboczem narastajacym)
	
}