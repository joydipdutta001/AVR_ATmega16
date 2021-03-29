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

int main(void)
{	
	DC = DD = 0xff;
	
    int a[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	unsigned int i,j,k,l,m,n,o,p,r;	
    while (1) 
    {
		for (i=0;i<10;i++)
		{
			for (j=0;j<10;j++)
			{
				for (k=0;k<10;k++)
				{
					for (l=0;l<10;l++)
					{
						for (m=0;m<10;m++)
						{
							for (n=0;n<10;n++)
							{
								for (o=0;o<10;o++)
								{
									for (p=0;p<10;p++)
									{
										for (r=1;r<=48;r++)
										{
											PORTD = 0b11111110;
											PORTC = a[i]; _delay_ms(2);
											
											PORTD = 0b11111101;
											PORTC = a[j]; _delay_ms(2);
											
											PORTD = 0b11111011;
											PORTC = a[k]; _delay_ms(2);
											
											PORTD = 0b11110111;
											PORTC = a[l]; _delay_ms(2);
											
											PORTD = 0b11101111;
											PORTC = a[m]; _delay_ms(2);
											
											PORTD = 0b11011111;
											PORTC = a[n]; _delay_ms(2);
											
											PORTD = 0b10111111;
											PORTC = a[o]; _delay_ms(2);
											
											PORTD = 0b01111111;
											PORTC = a[p]; _delay_ms(2);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
    }
}

