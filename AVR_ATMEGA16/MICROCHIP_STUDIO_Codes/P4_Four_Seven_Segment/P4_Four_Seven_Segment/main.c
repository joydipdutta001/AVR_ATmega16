#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = DDRD = 0xff;
	
	int a[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	
	while(1)
	{
		for (int l =0; l<=9;l++)
		{
			for (int k = 0;k<=9;k++)
			{
				for (int j =0; j<=9;j++)
				{
					for (int i =0; i<=9;i++)
					{
						
						for (int p =1; p<=25;p++)
						{
							
							PORTD = 0b00001110;
							PORTC = a[l]; _delay_ms(10);
							
							PORTD = 0b00001101;
							PORTC = a[k]; _delay_ms(10);
							
							PORTD = 0b00001011;
							PORTC = a[j]; _delay_ms(10);
							
							PORTD = 0b00000111;
							PORTC = a[i]; _delay_ms(10);
							
						}
					}
				}
			}
		}
	}
}
