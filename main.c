/**
 *	Keil project example for HD44780 LCD driver
 *
 *	@author 	Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@ide		Keil uVision 5
 */
#include "defines.h"
#include "stm32f4xx.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_hd44780.h"

int main(void) {
	//Rectangle for custom character
	//xxx means doesn't care, lower 5 bits are important for LCD
	uint8_t customChar[] = {
		0x1F,	// xxx 11111
		0x11,	// xxx 10001
		0x11,	// xxx 10001
		0x11,	// xxx 10001
		0x11,	// xxx 10001
		0x11,	// xxx 10001
		0x11,	// xxx 10001
		0x1F	// xxx 11111
	};
	//Initialize system
	SystemInit();

	//Initialize LCD 20 cols x 4 rows
	TM_HD44780_Init(16, 4);

	//Save custom character on location 0 in LCD
	TM_HD44780_CreateChar(0, &customChar[0]);

	//Put string to LCD
	TM_HD44780_Puts(0, 0, "Ladnie dzialam!");
	TM_HD44780_Puts(0, 1, ":) ;) :D ");


	//Wait a little
	Delayms(3000);

	//Clear LCD
	TM_HD44780_Clear();

	//Show cursor
	TM_HD44780_CursorOn();

	//Write new text
	TM_HD44780_Puts(6, 2, "CLEARED!");

	//Wait a little
	Delayms(1000);

	//Enable cursor blinking
	TM_HD44780_BlinkOn();

	//Show custom character at x = 1, y = 2 from RAM location 0
	TM_HD44780_PutCustom(1, 2, 0);

	while (1) {

	}
}
