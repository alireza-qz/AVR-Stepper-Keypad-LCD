#ifndef KEYPAD_H
#define KEYPAD_H

extern volatile unsigned char key;
extern unsigned char number;
extern unsigned char motor_number;
extern unsigned char x;

void KeyPad(void);

#endif
