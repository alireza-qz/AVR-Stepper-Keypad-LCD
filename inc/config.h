#ifndef CONFIG_H
#define CONFIG_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/* Original Defines */
#define KeyPad_PORT PORTA
#define KeyPad_PIN  PINA
#define Motor_PORT  PORTC
#define LCD_PORT    PORTB

#define E   PB4
#define RW  PB5
#define RS  PB6

#endif
