/*
 * P5_Eight_Seven_Segment.c
 *
 * Created: 13-03-2021 14:19:37
 * Author : Jervis
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define DC DDRC
#define DD DDRD
#define PC PORTC
#define PD PORTD
int key()
{
	while (1) {
		PORTB = 0b01111111; _delay_ms(20);
		
		if (PINA == 0xfe) { while (PINA == 0xfe); return  1;}
		
		if (PINA == 0xfd) { while (PINA == 0xfd); return  4;}
		
		if (PINA == 0xfb) { while (PINA == 0xfb); return  7;}
		
		if (PINA == 0xf7) { while (PINA == 0xf7); return 10;}
		
		PORTB = 0b10111111; _delay_ms(20);
		
		if (PINA == 0xfe) { while (PINA == 0xfe); return  2;}
		
		if (PINA== 0xfd) { while (PINA == 0xfd); return  5;}
		
		if (PINA == 0xfb) { while (PINA == 0xfb); return  8;}
		
		if (PINA == 0xf7) { while (PINA == 0xf7); return 11;}
		
		PORTB = 0b11011111; _delay_ms(30);
		
		if (PINA == 0xfe) { while (PINA == 0xfe); return  3;}
		
		if (PINA == 0xfd) { while (PINA == 0xfd); return  6;}
		
		if (PINA == 0xfb) { while (PINA == 0xfb); return  9;}
		
		if (PINA == 0xf7) { while (PINA == 0xf7); return 12;}
	} }


int main(void)
{	
	DC = DD =DDRB = 0xff;
	DDRA = 0xf0; PORTA = 0xff;
    int a[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};	
    while (1) 
    {
		int num = key();
		if (num<10)
		{ 
			PD = 0b11111110;
			PC = a[num];_delay_ms(10);
		}	
    }
}

