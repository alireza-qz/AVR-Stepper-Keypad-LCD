#ifndef LCD_H
#define LCD_H

void LCD_init(void);
void LCD_command(unsigned char com);
void LCD_data(unsigned char data);
void LCD_desplay(unsigned char *str);

#endif
