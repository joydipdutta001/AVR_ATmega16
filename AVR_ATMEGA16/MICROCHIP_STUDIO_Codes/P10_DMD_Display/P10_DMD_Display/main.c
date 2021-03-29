/*
 * P10_DMD_Display.c
 *
 * Created: 25-03-2021 21:51:10
 * Author : Jervis
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = DDRB = 0xff;
	
	while (1)
	{
		PORTA = 0x7e;
		PORTB= 0xfe;
		_delay_ms(100);
		PORTA = 0x18;
		PORTB = 0x00;
		_delay_ms(100);
	}
}

