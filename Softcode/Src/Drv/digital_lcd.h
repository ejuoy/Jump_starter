#ifndef _DIGITAL_LCD_H_
#define _DIGITAL_LCD_H_

#define LCD_GPIO_1	P22
#define LCD_GPIO_2	P23
#define LCD_GPIO_3	P24
#define LCD_GPIO_4	P13
#define LCD_GPIO_5	P14
#define LCD_GPIO_6	P25
#define LCD_GPIO_7	P15

void digital_ocr_change(char ocr);
void digital_vcc_display(int value,char status);
void digital_lcd_show(void);

#endif