/*
 * Keypad 4x4
 * source file
 *
 */ 
#include "Keypad_4x4.h"


char keypad[4][4] = {{'7','8','9','/'},
					{'4','5','6','x'},
					{'1','2','3','-'},
					{'c','0','=','+'}};
	
char colloc, rowloc;						/*row and column numbers*/

char read_key()
{
	while(1)
	{
		KEY_DDR = 0x0F;						/*making row output, column as input*/
		KEY_PRT = 0xFF;						/*make output high and set internal pull up for input*/

		do
		{
			KEY_PRT &= 0xF0;				/*make rows low and column high*/
			asm("NOP");
			colloc = (KEY_PIN & 0xF0);		/*take column value as input*/
		}while(colloc != 0xF0);				/*wait for all keys to release*/
		
		do
		{
			do
			{
				_delay_ms(40);						/*20ms key debounce time*/
				colloc = (KEY_PIN & 0xF0);
			}while(colloc == 0xF0);
			
			_delay_ms (50);							/*20 ms key debounce time*/
			colloc = (KEY_PIN & 0xF0);
		}while(colloc == 0xF0);						/*wait for key to press*/

		KEY_PRT = 0xFE;								/*row and column detection */
		asm("NOP");
		colloc = (KEY_PIN & 0xF0);
		if(colloc != 0xF0)
		{
			rowloc = 0;
			break;
		}

		KEY_PRT = 0xFD;
		asm("NOP");
		colloc = (KEY_PIN & 0xF0);
		if(colloc != 0xF0)
		{
			rowloc = 1;
			break;
		}
		
		KEY_PRT = 0xFB;
		asm("NOP");
		colloc = (KEY_PIN & 0xF0);
		if(colloc != 0xF0)
		{
			rowloc = 2;
			break;
		}

		KEY_PRT = 0xF7;
		asm("NOP");
		colloc = (KEY_PIN & 0xF0);
		if(colloc != 0xF0)
		{
			rowloc = 3;
			break;
		}
	}

	
	if(colloc == 0xE0)				/*return the key value*/
	return(keypad[rowloc][0]);
	
	else if(colloc == 0xD0)
	return(keypad[rowloc][1]);
	
	else if(colloc == 0xB0)
	return(keypad[rowloc][2]);
	
	else
	return(keypad[rowloc][3]);
}
