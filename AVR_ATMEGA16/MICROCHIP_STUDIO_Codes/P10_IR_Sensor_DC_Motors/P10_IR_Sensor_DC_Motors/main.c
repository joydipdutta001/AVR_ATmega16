/*
 * P11_IR_Sensor_DC_Motors.c
 *
 * Created: 26-03-2021 19:22:28
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



int main(void)
{
	DDRC = DDRD = 0xff;
	DDRA = 0xff;
	
	lcd_init();
	while(1){
	
	lcd_cmd(0x83);
	string_data("..Object..");
	
	while(PINA == 0x01)
	{
		PORTC = 0x00;
		lcd_cmd(0x01);
		lcd_data(0xc0);
		string_data("Detected Stoping");
		_delay_ms(100);
		
		PORTC = 0x06;
		lcd_cmd(0x01);
		lcd_data(0xc3);
		string_data(" Backward ");
		_delay_ms(1000);
		
		PORTC = 0x08;
		lcd_cmd(0x01);
		lcd_data(0xc3);
		string_data("Right");
		_delay_ms(1000);
		lcd_cmd(0x01);
		_delay_ms(10);
	}	
	
	PORTC = 0x09;
	lcd_cmd(0xc3);
	string_data(" Forward ");
	}
}



