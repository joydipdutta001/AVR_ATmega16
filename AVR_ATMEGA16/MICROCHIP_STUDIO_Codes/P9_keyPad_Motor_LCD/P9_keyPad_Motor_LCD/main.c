/*
 * P9_keyPad_Motor_LCD.c
 *
 * Created: 25-03-2021 17:19:38
 * Author : Jervis
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

#define lcd PORTD

lcd_init()
{
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0c);
}
lcd_cmd(int x)
{
	lcd=(x&0xf0)+0x04;
	_delay_ms(2);
	lcd=lcd-0x04;
	lcd=((x<<4)&0xf0)+0x04;
	_delay_ms(2);
	lcd=lcd-0x04;
}
lcd_data(int x)
{
	lcd=(x&0xf0)+0x05;
	_delay_ms(2);
	lcd=lcd-0x04;
	lcd=((x<<4)&0xf0)+0x05;
	_delay_ms(2);
	lcd=lcd-0x04;
}
string_data(char *str){
	int i = 0;
	for(i=0; i<=strlen(str) ; i++){
		lcd_data(str[i]);
		_delay_ms(8);
		lcd_cmd(0x06);
	}
}
char arr[11] = "0123456789";
number_data(int number){
	int i;
	if(number>0)
	{
		i=number%10;
		number=number/10;
		
		number_data(number);
		lcd_data(arr[i]);
		lcd_cmd(0x06);
		_delay_ms(10);
	}
}

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
		
		if (PINA== 0xfd) { while (PINA == 0xfd); return  5;}
		
		if (PINA == 0xfb) { while (PINA == 0xfb); return  8;}
		
		if (PINA == 0xf7) { while (PINA == 0xf7); return 11;}
		
		PORTB = 0b01111111; _delay_ms(30);
		
		if (PINA == 0xfe) { while (PINA == 0xfe); return  3;}
		
		if (PINA == 0xfd) { while (PINA == 0xfd); return  6;}
		
		if (PINA == 0xfb) { while (PINA == 0xfb); return  9;}
		
		if (PINA == 0xf7) { while (PINA == 0xf7); return 12;}
	} 
}


int main(void)
{
    DDRC = DDRB = DDRD = 0xff;
    DDRA = 0xf0;
    PORTA = 0xff;
	int n[5] = {2,8,4,6,0};
	lcd_init();
    while (1) 
    {
		int button = key();
		lcd_cmd(0x01); _delay_ms(10);
		lcd_cmd(0x83); _delay_ms(100);
		number_data(button);
		if (button == n[0])
		{
			PORTC = 0b00001001;
			lcd_cmd(0xc3);
			string_data(" Forward");
		}else if (button== n[1])
		{
			PORTC = 0b00000110;
			lcd_cmd(0xc3);
			string_data(" Backward");
		}else if (button == n[2])
		{
			PORTC = 0b00000001;
			lcd_cmd(0xc3);
			string_data(" Left");
		}else if (button == n[3])
		{
			PORTC = 0b00001000;
			lcd_cmd(0xc3);
			string_data(" Right");
		}else
		{
			PORTC = 0b00000000;
			lcd_cmd(0xc3);
			string_data(" Stop");
		}
		
    }
}

