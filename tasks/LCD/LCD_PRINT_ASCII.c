#include "MemMap.h"
#include "Utiles.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "LCD.h"
#define F_CPU 8000000
#include <util/delay.h>

#define  delay  200


int main(void)
{
	DIO_InIt();
	LCD_Init();

    /***********print-ascii************/
    u8 x='z';
	LCD_WriteString("Char:");
	LCD_SetCurser(1,0);
	LCD_WriteString("ascii:");
    while (1) 
    {
		LCD_SetCurser(0,7);
		LCD_WriteChar(x);
		LCD_SetCurser(1,7);
		LCD_WriteString("   ");
	    LCD_SetCurser(1,7);
	    LCD_WriteNumber(x);	
		x--;
		_delay_ms(400);
    }
}
