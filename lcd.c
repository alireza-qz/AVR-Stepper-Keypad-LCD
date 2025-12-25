#include "config.h"
#include "bitops.h"
#include "lcd.h"

void LCD_enable(){
	set_bit(&LCD_PORT , E);
	_delay_us(10);
	clear_bit(&LCD_PORT, E);
	_delay_ms(1);
}

void Send_nibble(unsigned char data){
	LCD_PORT = (LCD_PORT & 0xF0) | (data & 0x0F);
	LCD_enable();
}

void LCD_command(unsigned char com){
	clear_bit(&LCD_PORT , RS);
	Send_nibble(com >> 4);
	Send_nibble(com & 0x0F);
}

void LCD_data(unsigned char data){
	set_bit(&LCD_PORT, RS);
	Send_nibble(data >> 4);
	Send_nibble(data & 0x0F);
}

void LCD_init(){
	_delay_ms(20);
	clear_bit(&LCD_PORT , RW);
	clear_bit(&LCD_PORT , RS);

	Send_nibble(0x03);
	Send_nibble(0x03);
	Send_nibble(0x03);
	Send_nibble(0x02);

	LCD_command(0x28);
	LCD_command(0x0F);
	LCD_command(0x01);
	_delay_ms(10);
	LCD_command(0x80);
}

void LCD_desplay(unsigned char *str){
	while (*str){
		LCD_data(*str++);
	}
}
