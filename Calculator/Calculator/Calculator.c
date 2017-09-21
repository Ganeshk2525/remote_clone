#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LCD_16x2.h"				/*include LCD16x2 library*/
#include "Keypad_4x4.h"				/*include keypad library*/

int main()
{
	char number1[12],number2[12],i,key,answer[12],fun,no1flag;		/*no1, no2, answer arrays index=i*/
	long no1,no2,ans;												/*no1 fun no2 = ans */
	
	lcd_init();
	lcd_string("calculator");
	_delay_ms(500);
	clear_LCD();
	
	i=0;									 /*counter*/
	no1flag=1;								/*no1flag to indicate 1st number no1.*/
	
	while(1)
	{
		key=read_key();						/*detect key pressed*/
		if(key!='c')						/*if key is not 'c'(clear/on) print key on LCD16x2 */
			lcd_data(key);
		
		switch(key)
		{
			case '+':	fun=key;			/*if key pressed is operator, put it in fun*/
						no1flag=i=0;
						break;
			case '-':	fun=key;
						no1flag=i=0;
						break;
			case 'x':	fun=key;
						no1flag=i=0;
						break;
			case '/':	fun=key;
						no1flag=i=0;
						break;
			
			case '=':
						no1=atol(number1);						/*convert no1 & no2 ASCII string to number*/
						no2=atol(number2);
						lcd_command(0xc0);						/*answer on 2nd line*/
						switch(fun)
						{
							case '+':ans=no1+no2;
							sprintf(answer,"%ld",ans);				/*convert ans to ASCII string*/
							lcd_string(answer);
							break;
							case '-':ans=no1-no2;
							sprintf(answer,"%ld",ans);				/*convert ans to ASCII string*/
							lcd_string(answer);
							break;
							case 'x':ans=no1*no2;
							sprintf(answer,"%ld",ans);				/*convert ans to ASCII string*/
							lcd_string(answer);
							break;
							case '/':if (no2==0)
							{	clear_LCD();
								lcd_string("maths error");
								break;
							}
							ans=no1/no2;
							sprintf(answer,"%ld",ans);				/*convert ans to ASCII string*/
							lcd_string(answer);
							break;
						}
						break;
			
			case 'c':												/*clear function, clear all values*/
						memset(number1,0,12);						/*reset array to zero*/
						memset(number2,0,12);
						memset(answer,0,12);
						i=0;
						no1flag=1;
						ans=0;
						clear_LCD();
						break;
				
			default:									/*if key pressed is not operator,'=' or 'C', then definitely it is number*/
					if(no1flag==1)
					number1[i]=key;						/*store 1st no1*/
					else
					number2[i]=key;						/*store 2nd no2.*/
					i++;								/*increment array index*/

		}
	}

	return 0;
}
