#define F_CPU 8000000
#include <util/delay.h>
#include "DIO_Interface.h"
#include "LCD.h"
#include "Utiles.h"
/************private*****************/
static void WriteInstuction(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
}
static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
/*************************************/

void LCD_Init(void)
{
	_delay_ms(50);
	WriteInstuction(0x38); //8bit mode  2lines
	_delay_ms(1);
	WriteInstuction(0x0c);
	_delay_ms(1);
	WriteInstuction(0x01);//clear
	_delay_ms(2);
	WriteInstuction(0x06);//increase ddram adderss   shift off
}
void LCD_Clear(void)
{
	WriteInstuction(0x01);//clear
	_delay_ms(2);
}
void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
}
void LCD_ClearLast(void);
void LCD_ClearLocation(void);
void LCD_WriteNumber(s32 num)
{
	u8 i=0;
	s8 j;
	u8 str[16];
	if(num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if(num<0)
	{
		LCD_WriteChar('-');
		num = num*(-1);
	}
	while(num>0)
	{
		str[i]=num%10+'0';
		num=num/10;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
}
void LCD_WriteString(u8*str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}

void LCD_WriteBinary(u8 num)
{
	s8 i;
	u8 flag=0;
	for(i=7;i>=0;i--)
	{
		if(READ_BIT(num,i)==1)
		{
			flag=1;
		}
		if(flag==1)
		{
			if(READ_BIT(num,i)==1)
			{
				LCD_WriteChar('1');
			}
			else
			{
				LCD_WriteChar('0');
			}
		}
		
	}
}
void LCD_WriteBinary_8D(u8 num)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
		LCD_WriteChar(READ_BIT(num,i)+'0');
	}
}
void LCD_WriteHex(u8 num)
{
	u8 Ln=num&0x0f;
	u8 Hn=num>>4;
	if(Hn<=9)
	{
		LCD_WriteChar(Hn+'0');
	}
	else
	{
		LCD_WriteChar(Hn-10+'A');
	}
	if(Ln<=9)
	{
		LCD_WriteChar(Ln+'0');
	}
	else
	{
		LCD_WriteChar(Ln-10+'A');
	}
}
void LCD_WriteNumber_4D(u16 num)//8542
{
	LCD_WriteChar((num%10000)/1000+'0');
	LCD_WriteChar((num%1000)/100+'0');
	LCD_WriteChar((num%100)/10+'0');
	LCD_WriteChar((num%10)/1+'0');
}
void LCD_SetCurser(u8 line,u8 cell)
{
	if(line==0)
	{
		WriteInstuction(0x80+cell);
	}
	else
	{
		WriteInstuction(0x80+0x40+cell);
	}
}
