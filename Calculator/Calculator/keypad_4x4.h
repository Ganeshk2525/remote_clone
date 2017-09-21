/*
 * 4x4 Keypad 
 * header file
 */ 


#ifndef Keypad_H_
#define Keypad_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define KEY_PRT 	PORTD			/*define 4x4 matrix Keypad port, PD0- PD3: rows, PD4- PD7 columns*/
#define KEY_DDR		DDRD			
#define KEY_PIN		PIND

char read_key();					/*function to detect key pressed*/


#endif 