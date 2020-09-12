#include "MS51_32K.h"
#include "app_type.h"
#include "led.h"


void led_gpio_init(void)
{
 	P21_PUSHPULL_MODE;
 	P35_PUSHPULL_MODE;
 	P12_PUSHPULL_MODE;
 	P11_PUSHPULL_MODE;
 	P17_PUSHPULL_MODE;
 	P30_PUSHPULL_MODE;
 	P34_PUSHPULL_MODE;

 	LED_B_FULL = 0;
 	LED_J_OK = 0;
 	LED_A_FAULT = 0;
 	LED_A_GOOD = 0;
 	LED_J_FAULT = 0;
 	LED_B_MIDDLE = 0;
 	LED_B_LOW = 0;
}


void led_gpio_contrl(char led,char status)
{
	printf("111 %d,%d\r\n",(unsigned int)led,(unsigned int)status);
	switch(led)
	{
		case B_FULL:
			LED_B_FULL = status;
			break;
		case J_OK:
			LED_J_OK = status;
			break;
		case A_FAULT:
			LED_A_FAULT = status;
			break;
		case A_GOOD:
			LED_A_GOOD = status;
			break;
		case B_LOW:
			LED_B_LOW = status;
			break;
		default:
			break;
	}
}


