#include "config.h"
#include "bitops.h"
#include "keypad.h"

unsigned char KeyPad_list[4][3] = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
	{'*','0','#'}
};

unsigned char checkkeykon(unsigned char *i , unsigned char k){
	unsigned char c = (*i & (1 << k)) ? 1 : 0;
	if (c){
		_delay_ms(20);
		return ((*i & (1 << k)) ? 1 : 0);
	}
	return 0;
}

void KeyPad(){
	unsigned char break_count = 0;
	KeyPad_PORT = 0xFF;

	for (unsigned char i = 3; i < 7; i++){
		clear_bit(&KeyPad_PORT , i);
		for(unsigned char k = 0; k < 3; k++){
			if (!checkkeykon(&KeyPad_PIN , k)){
				number = KeyPad_list[i-3][k];
				break_count = 1;
				break;
			}
		}
		if (break_count) break;
	}

	key = 0;
	PORTA = 0b10000111;
	LCD_data(number);

	if (number == '#'){
		x = motor_number;
		motor_number = 0;
		number = 0;
		LCD_command(0x01);
		}else{
		motor_number = (motor_number * 10) + (number - '0');
	}
}
