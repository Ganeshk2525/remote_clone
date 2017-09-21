
#include "LCD_16x2.h"								/* Include LCD header file */


void lcd_command (char cmd)				/* LCD command write function */

{
	lcd_data_port = cmd;							/* Write command data to LCD data port */	
	lcd_command_port = (0<<rs)|(0<<rw)|(1<<en);		/* Make rs LOW (command reg.), rw LOW (Write), en HIGH (Enable) */
	_delay_ms(1);									/* Wait for 1ms to get data write from port to command reg. */
	lcd_command_port = (0<<rs)|(0<<rw)|(0<<en);		/* Make rs LOW (command reg.), rw LOW (Write), en LOW (Disable) */
	_delay_ms(5);									/* Wait little bit to get internal LCD data operation done */
}

void lcd_data (char data)					/* LCD data write function */

{
	lcd_data_port = data ;							/* Write data to LCD data port */
	lcd_command_port = (1<<rs)|(0<<rw)|(1<<en);		/* Make rs HIGH (data reg.), rw LOW (Write), en HIGH (Enable) */
	_delay_ms(1);									/* Wait for 1ms to get data write from port to data reg. */
	lcd_command_port = (1<<rs)|(0<<rw)|(0<<en);		/* Make rs HIGH (data reg.), rw LOW (Write), en HIGH (Disable) */
	_delay_ms(5);									/* Wait little bit to get internal LCD data operation done */
}

void lcd_init (void)								/* LCD Initialize function */

{
	_delay_ms(50);									/* LCD Initial time */
	lcd_command_dir = 0xFF;							/* Make LCD command port direction as o/p */
	lcd_data_dir = 0xFF;							/* Make LCD data port direction as o/p */
	
	lcd_command (0x38);								/* Initialization of 16X2 LCD in 8bit mode */
	lcd_command (0x01);								/* Clear LCD */
	lcd_command (0x0C);								/* Cursor OFF */
	lcd_command (0x80);								/* 8 is for first line and 0 is for 0th position */
}

void lcd_string (char *str)				/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)							/* Send each char of string till the NULL */
	{
		lcd_data (str[i]);							/* Call LCD data write */
	}
}

void clear_LCD()
{
	lcd_command(0x01);				/*Clear LCD16x2*/
	lcd_command(0x80);
}
