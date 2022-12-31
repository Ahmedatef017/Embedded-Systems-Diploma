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

   /***********move word*****************/

	u8 str[100]="Welco To Rannen";
	 while (1)
	 {
		 u8 len=0,i=0;

		 for(len=0;str[len];len++);
		 
		 for(i=len;i>1;i--)
		 {
			 LCD_WriteString(str+i-1);
			 _delay_ms(delay);
			 LCD_Clear();
		 }
		 for(i=0;i<=15;i++)
		 {
			 LCD_SetCurser(0,i);
			LCD_WriteString(str);
			_delay_ms(delay);
			LCD_Clear();
		 }
		 
		 for(i=len;i>1;i--)
		 {
			 LCD_SetCurser(1,0);
			 LCD_WriteString(str+i-1);
			 _delay_ms(delay);
			 LCD_Clear();
		 }
		 
		for(i=0;i<=15;i++)
		{
			LCD_SetCurser(1,i);
			LCD_WriteString(str);
			_delay_ms(delay);
			LCD_Clear();
		}
		 
	 }
}
