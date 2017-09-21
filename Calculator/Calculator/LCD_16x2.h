
#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL			/* Define CPU Frequency e.g. here its 8MHz, UL is unsigned long data type */
#include <avr/io.h>				/* Include AVR std. library file */
#include <util/delay.h>			/* Include inbuilt defined Delay utilize library file */
#include <avr/io.h>						/* Include AVR std. library file */

#define lcd_data_dir DDRB				/* Define LCD data port direction */
#define lcd_command_dir DDRA			/* Define LCD command port direction register */
#define lcd_data_port PORTB				/* Define LCD data port */
#define lcd_command_port PORTA			/* Define LCD data port */
#define en PA2							/* Define Enable signal pin */
#define rw PA1							/* Define Read/Write signal pin */
#define rs PA0							/* Define Register Select (data reg./command reg.) signal pin */

void lcd_command (char);		/* LCD command write function */
void lcd_data (char);			/* LCD data write function */
void lcd_init (void);					/* LCD Initialize function */
void lcd_string (char*);		/* Send string to LCD function */
void clear_LCD();                       /*clear lcd*/


#endif /* LCD_H_ */