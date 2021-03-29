/*
 * P1_LedBlink.c
 *
 * Created: 12-03-2021 10:37:34
 * Author : Jervis
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0b00000000;
	// Write your code here
	while (1)
	{
		PORTA = 0b11110000;
		_delay_ms(1000);
		PORTA = 0b00001111;
		_delay_ms(1000);
	}
}

