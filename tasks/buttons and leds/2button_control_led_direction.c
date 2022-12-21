#define  PORTA  (*(volatile unsigned char *)0X3B)
#define  DDRA   (*(volatile unsigned char *)0X3A)
#define  PINA   (*(volatile unsigned char *)0X39)

#define  PORTB  (*(volatile unsigned char *)0X38)
#define  DDRB   (*(volatile unsigned char *)0X37)
#define  PINB   (*(volatile unsigned char *)0X36)

#define  PORTC  (*(volatile unsigned char *)0X35)
#define  DDRC   (*(volatile unsigned char *)0X34)
#define  PINC   (*(volatile unsigned char *)0X33)

#define  PORTD  (*(volatile unsigned char *)0X32)
#define  DDRD   (*(volatile unsigned char *)0X31)
#define  PIND   (*(volatile unsigned char *)0X30)

#define F_CPU 8000000
#include <util/delay.h>

#define SET_BIT(reg,bit)        (reg|=(1<<bit))
#define CLR_BIT(reg,bit)        (reg&=~(1<<bit))
#define TOG_BIT(reg,bit)        (reg^=~(1<<bit))
#define WRITE_BIT(reg,bit,val)  (reg&=(val<<bit))
#define READ_BIT(reg,bit)       ((reg>>bit)&1)


int main(void)
{
	DDRA = 0XFF;  //pin out
	DDRD = 0X00;  // button input
	PORTD = 0XFF;   // pull up
	unsigned char i=0;
	int flag=0;
	
	
	while (1)
	{
		
		if((READ_BIT(PIND,0)==0 && flag==0))
		{
			    //while(READ_BIT(PIND,0)==0);
				PORTA = 0;
				i++;
				if(i==8)
				{
					i=0;
				}
				flag=1;
			
		}
		else
		{
			flag=0;
		}
		
		if(READ_BIT(PIND,4)==0)
		{
			while(READ_BIT(PIND,4)==0);
			PORTA = 0;
			i--;
			if(i==255)
			{
				i=7;
			}

		}
		SET_BIT(PORTA,i);
	}
}




/*************BY USING SHIFFTED OPERATOR (AT Start Led Status Is Off)************/

/*
int main(void)
{
	DDRA = 0XFF;  //pin out
	DDRD = 0X00;  // button input
	PORTD = 0XFF;   // pull up
	unsigned short i=1;
	
	int flag=0;

	while (1)
	{
		
		if(READ_BIT(PIND,0)==0)
		{
			if(flag==1)
			{
				i=i<<2;
			}
			PORTA = i;
			i=i<<1;
			if(i==256)
			{
				i=1;
			}
			flag=2;
			while(READ_BIT(PIND,0)==0);
	
		}
		
		if(READ_BIT(PIND,4)==0)
		{
			if(flag==2)
			{
				i=i>>2;	
			}
			PORTA = i;
			i=i>>1;
			if(i==0)
			{
				i=128;
			}
			flag=1;
			while(READ_BIT(PIND,4)==0);
	 
		}
		
	}
}
*/

