/*
 * P9_part2.c
 *
 * Created: 26-03-2021 18:32:33
 * Author : Jervis
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define lcd PORTD

lcd_4bitinit() {
	lcd_4bitcmd(0x02);
	lcd_4bitcmd(0x28);
	lcd_4bitcmd(0x0c);
}

lcd_4bitstr(char *str) {
	int d=0;
	while(str[d]!='\0')
	{
		lcd_4bitdata(str[d]);
		lcd_4bitcmd(0x06);
		d++;
	} }

	lcd_4bitdata(int x) {
		lcd=(x&0xf0)+0x05;
		_delay_ms(2);
		lcd=lcd-0x04;
		lcd=((x<<4)&0xf0)+0x05;
		_delay_ms(2);
		lcd=lcd-0x04;
	}

	lcd_4bitcmd(int x) {
		lcd=(x&0xf0)+0x04;
		_delay_ms(2);
		lcd=lcd-0x04;
		lcd=((x<<4)&0xf0)+0x04;
		_delay_ms(2);
		lcd=lcd-0x04;
	}

	lcd_4bitnum(int n) {
		int d;
		if(n==0){lcd_4bitdata(48);}
		lcd_4bitcmd(0x04);
		while(n!=0)
		{
			d=n%10;
			lcd_4bitdata(d+48);
			n=n/10;
		} }

		int key()
		{
			while (1) {
				PORTB = 0b11011111; _delay_ms(20);
				
				if (PINA == 0xfe) { while (PINA == 0xfe); return  1;}
				
				if (PINA == 0xfd) { while (PINA == 0xfd); return  4;}
				
				if (PINA == 0xfb) { while (PINA == 0xfb); return  7;}
				
				if (PINA == 0xf7) { while (PINA == 0xf7); return 10;}
				
				PORTB = 0b10111111; _delay_ms(20);
				
				if (PINA == 0xfe) { while (PINA == 0xfe); return  2;}
				
				if (PINA == 0xfd) { while (PINA == 0xfd); return  5;}
				
				if (PINA == 0xfb) { while (PINA == 0xfb); return  8;}
				
				if (PINA == 0xf7) { while (PINA == 0xf7); return 11;}
				
				PORTB = 0b01111111; _delay_ms(30);
				
				if (PINA == 0xfe) { while (PINA == 0xfe); return  3;}
				
				if (PINA == 0xfd) { while (PINA == 0xfd); return  6;}
				
				if (PINA == 0xfb) { while (PINA == 0xfb); return  9;}
				
				if (PINA == 0xf7) { while (PINA == 0xf7); return 12;}
			} }

			int main(void)
			{
				DDRC = DDRB = DDRD = 0xff;
				DDRA = 0xf0;
				PORTA = 0xff;
				
				int n[5] = {2,8,4,6,0};
				
				lcd_4bitinit();
				
				while(1)
				{	int a = key();
					
					lcd_4bitcmd(0x01); _delay_ms(10);
					lcd_4bitcmd(0x83); _delay_ms(100);
					lcd_4bitnum(a);
					
					if (a == n[0])
					{	PORTC = 0b00001001;
						lcd_4bitcmd(0xc3);
					lcd_4bitstr(" Forward");	}
					
					
					else if(a == n[1])
					{	PORTC = 0b00000110;
						lcd_4bitcmd(0xc3);
					lcd_4bitstr(" Backward");	}
					
					else if(a == n[2])
					{	PORTC = 0b00000001;
						lcd_4bitcmd(0xc3);
					lcd_4bitstr(" Left");	}
					
					else if(a == n[3])
					{	PORTC = 0b00001000;
						lcd_4bitcmd(0xc3);
					lcd_4bitstr(" Right");	}
					
					else
					{	PORTC = 0b00000000;
						lcd_4bitcmd(0xc3);
					lcd_4bitstr(" Stop");	}
					
				}	}


