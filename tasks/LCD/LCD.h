
#ifndef LCD_H_
#define LCD_H_

#include "StdTypes.h"
/*****************LCD_Cfg***************/
#define LCD_PORT  PA
#define RS        PINB0
#define EN        PINB1
/***************************************/
void LCD_Init(void);
void LCD_Clear(void);
void LCD_WriteChar(u8 ch);
void LCD_ClearLast(void);
void LCD_ClearLocation(void);
void LCD_WriteNumber(s32 num);
void LCD_WriteString(u8*str);
void LCD_WriteBinary(u8 num);
void LCD_WriteBinary_8D(u8 num);
void LCD_WriteHex(u8 num);
void LCD_WriteNumber_4D(u16 num);
void LCD_SetCurser(u8 line,u8 cell);
#endif /* LCD_H_ */
