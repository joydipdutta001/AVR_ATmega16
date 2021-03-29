/*
 * P7_LCD_4bit.c
 *
 * Created: 14-03-2021 10:01:19
 * Author : Jervis
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

lcd_init()
{
	lcd_cmd(0x02);
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
}

lcd_cmd(int x)
{
	PORTD = x;
	PORTC = 0x04;
	_delay_ms(2);
	PORTC = 0x00;
}

lcd_data(int y)
{
	PORTD = y;
	PORTC = 0x05;
	_delay_ms(2);
	PORTC = 0x01;
}

string_data(char *str){
	int i = 0;
	for(i=0; i<=strlen(str) ; i++){
		lcd_data(str[i]);
		_delay_ms(8);
		lcd_cmd(0x06);
	}
}



number_data(int number){
	char arr[11] = "0123456789";
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


int main()
{
	DDRC = DDRD = 0xff;
	lcd_init();
	lcd_cmd(0x80);
	string_data("joy");
	_delay_ms(1000);
	
	lcd_cmd(0xC0);
	
	number_data(9999);
_delay_ms(8);
	
	
}
