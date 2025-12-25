#include "bitops.h"

void set_bit(unsigned char *reg, unsigned char bit){
	*reg |= (1 << bit);
}

void clear_bit(unsigned char *reg, unsigned char bit){
	*reg &= ~(1 << bit);
}
