#include "config.h"
#include "bitops.h"
#include "lcd.h"
#include "keypad.h"
#include "stepper.h"

volatile unsigned char key = 0;
unsigned char number = 0;
unsigned char motor_number = 0;
unsigned char x = 0;
unsigned char weareinMotor = 0;

ISR (INT0_vect){
	if (weareinMotor == 0)
	key = 1;
	else
	weareinMotor = 2;
}

int main(void){
	DDRA = 0b01111000;
	PORTA = 0b10000111;
	DDRB = 0b01111111;
	PORTB = 0b10000000;
	DDRC = 0x0F;
	PORTC = 0xF0;

	LCD_init();

	clear_bit(&DDRD , INT0);
	set_bit(&PORTD , INT0);
	set_bit(&GICR , INT0);
	set_bit(&MCUCR , ISC10);
	clear_bit(&MCUCR , ISC00);

	sei();

	while (1){
		if (key)
		KeyPad();

		while (x != 0)
		steppermotor();
	}
}
