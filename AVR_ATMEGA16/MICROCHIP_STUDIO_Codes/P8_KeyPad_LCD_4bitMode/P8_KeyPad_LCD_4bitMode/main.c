/*
 * P8_KeyPad_LCD_4bitMode.c
 *
 * Created: 14-03-2021 22:47:25
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

int key()
{
	/* 
		101: ON/C;  104: +; 105: -; 106: *; 107: /
		103: =;
	*/
	
	while (1) {
		PORTB = 0b01111111; _delay_ms(20);
		
		if (PINA == 0xfe) { while (PINA == 0xfe); return  7;}
		
		if (PINA == 0xfd) { while (PINA == 0xfd); return  4;}
		
		if (PINA == 0xfb) { while (PINA == 0xfb); return  1;}
		
		if (PINA == 0xf7) { while (PINA == 0xf7); return 101;}
		
		PORTB = 0b10111111; _delay_ms(20);
		
		if (PINA == 0xfe) { while (PINA == 0xfe); return  8;}
		
		if (PINA== 0xfd) { while (PINA == 0xfd); return  5;}
		
		if (PINA == 0xfb) { while (PINA == 0xfb); return  2;}
		
		if (PINA == 0xf7) { while (PINA == 0xf7); return 0;}
		
		PORTB = 0b11011111; _delay_ms(30);
		
		if (PINA == 0xfe) { while (PINA == 0xfe); return 9;}
		
		if (PINA == 0xfd) { while (PINA == 0xfd); return  6;}
		
		if (PINA == 0xfb) { while (PINA == 0xfb); return  3;}
		
		if (PINA == 0xf7) { while (PINA == 0xf7); return 103;}
			
		PORTB = 0b11101111; _delay_ms(30);
		
		if (PINA == 0xfe) { while (PINA == 0xfe); return  104;}
		
		if (PINA == 0xfd) { while (PINA == 0xfd); return  105;}
		
		if (PINA == 0xfb) { while (PINA == 0xfb); return  106;}
		
		if (PINA == 0xf7) { while (PINA == 0xf7); return 107;}
	} 
}


int main()
{
	DDRC = DDRD = DDRB = 0xff;
	DDRA = 0xf0; PORTA = 0xff;
	
	lcd_init();
	lcd_cmd(0x80);
	string_data("Welcome ......");
	
	_delay_ms(100);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	string_data("Enter:");
	int result;
	int negative_res;
	int operand1,operand2;
	char operators="";
		while (1)
		{
			int num = key();
			if ((num>0 && num <10)|| (num>103 && num <108))
			{
				
				
					_delay_ms(100);
					
					if (num>0 && num<10)
					{	
						if (operators=="")
						{
							operand1= num;
							number_data(operand1);
							lcd_cmd(0x06);
						}
						else if (operators!="")
					{
						operand2= num;
						number_data(operand2);
						lcd_cmd(0x06);
					}
						
				}else if (num==104)
				{
					operators = "/";
					lcd_data('/');
					lcd_cmd(0x06);
				
				}else if (num==105){
					operators = "*"; 
					lcd_data('*'); 
					lcd_cmd(0x06);
					
					}else if (num==106){
						operators = "-";
						lcd_data('-');
						lcd_cmd(0x06);
					
					
					}else if (num == 107)
					{
						operators = "+";
						lcd_data('+');
						lcd_cmd(0x06);
						
					}
			}
			else if (num == 101){ lcd_cmd(0x01);
				_delay_ms(100);
				result=0;
				negative_res=0;
				operand1=0;
				operand2 = 0;
				operators="";
				lcd_cmd(0x80);
				string_data("Enter:");}
			else if(num==103){ 
				lcd_cmd(0xC0);
				if (operators == "+")
				{
					result = operand1 + operand2;
				}else if (operators == "-")
				{
					if (operand2>operand1)
					{
						result = operand2 - operand1;
						negative_res=1;
						}else{
						result = operand1- operand2;
						negative_res = 0;
					}
					
				}else if (operators=="*")
				{
					result = operand1 * operand2;
				}else if (operators=="/")
				{
					result = operand1 / operand2;
				}
				if(negative_res ==1){
					lcd_data('-');
					lcd_cmd(0x06);
					number_data(result);
				}else{
					number_data(result);
				}
			}
		}
		
	
_delay_ms(8);
	
	
}

