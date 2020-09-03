#ifndef _DIGITAL_LCD_H_
#define _DIGITAL_LCD_H_

/*  P3  */  
sbit LCD_GPIO_1 = P2^2;
sbit LCD_GPIO_2 = P2^3;
sbit LCD_GPIO_3 = P2^4;
sbit LCD_GPIO_4 = P1^3;
sbit LCD_GPIO_5 = P1^4;
sbit LCD_GPIO_6 = P2^5;
sbit LCD_GPIO_7 = P1^5;

enum DIGITAL_OCR_VALUE
{
    DIGITAL_OCR_DP=27,
    DIGITAL_OCR_V =26,
    DIGITAL_OCR_UV=21,
    DIGITAL_OCR_OV=22,
    DIGITAL_OCR_CB=23,
    DIGITAL_OCR_OT=24,
    DIGITAL_OCR_SC=25,
};

void digital_lcd_test(void);
void digital_ocr_change(char ocr,char status);
void digital_vcc_display(int value,char status);
void digital_lcd_show(void);
void digital_num_change(char pos,char num);
#endif