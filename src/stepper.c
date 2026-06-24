#include "config.h"
#include "stepper.h"

extern unsigned char weareinMotor;
extern unsigned char x;

unsigned char a[8] = {1,3,2,6,4,12,8,9};

void steppermotor(){
	static unsigned char i = 0;
	weareinMotor = 1;

	Motor_PORT = a[i];
	for(unsigned char k = 0; k < x; k++){
		_delay_ms(10);
	}

	i = (i + 1) % 8;

	if (weareinMotor == 2){
		x = 0;
		weareinMotor = 0;
	}
}
