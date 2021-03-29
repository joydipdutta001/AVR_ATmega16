/*
 * P2_Single_Seven_Segment.c
 *
 * Created: 12-03-2021 11:00:09
 * Author : Jervis
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define Direction_led DDRD
#define Port_led PORTD


int main(void)
{
	Direction_led |= 0xff;
	Port_led |= 0xff;
	int n[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	unsigned int i;
    /* Replace with your application code */
    while (1) 
    {
		for(i=0; i<10; i++ ){
			Port_led = n[i];
			_delay_ms(1000);
		}
    }
}

