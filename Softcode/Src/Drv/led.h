#ifndef  _LED_H_
#ifndef _LED_H_
#define _LED_H_

/*  P3  */  
sbit LED_B_FULL = P2^1;
sbit LED_J_OK =	P3^5;
sbit LED_A_FAULT = P1^2;
sbit LED_A_GOOD	= P1^1;
sbit LED_J_FAULT = P1^7;
sbit LED_B_MIDDLE = P3^0;
sbit LED_B_LOW = P3^4;

enum _LED_CONTROL_
{
    J_OK = 0,
    B_LOW,
    B_MIDDLE,
    B_FULL ,
    A_GOOD,
    A_FAULT,
    J_FAULT,
    L_NULL,
};

void led_gpio_init(void);
void led_gpio_contrl(char led,char status);
void led_gpio_all_on(void);
#endif


