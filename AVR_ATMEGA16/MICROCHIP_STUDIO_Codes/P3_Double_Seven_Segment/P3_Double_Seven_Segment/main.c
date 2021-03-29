/*
 * P3_Double_Seven_Segment.c
 *
 * Created: 12-03-2021 11:21:05
 * Author : Jervis
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define Direction_led DDRD
#define Direction_led2 DDRC
#define Port_led PORTD
#define Port_led2 PORTC

int main(void)
{
	Direction_led = Direction_led2 = 0xff;
	int n[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	unsigned int i,j,p;
    /* Replace with your application code */
    while (1) 
    {
		for(j=0; j<=5;j++){
			for(i=0; i<=9; i++ ){
				for(p=1; p<=48; p++){
					Port_led = 0x01;
					Port_led2 = n[j];
					_delay_ms(5);
					Port_led = 0x02;
					Port_led2 = n[i];
					_delay_ms(5);
				}
			}
		}
    }
}



