#include "MS51_32K.h"
#include "type.h"
#include "led.h"

//char led_array[] = {LED_B_FULL,LED_J_OK,LED_A_FAULT,LED_A_GOOD,LED_B_LOW};

void led_gpio_init(void)
{
 	P21_PUSHPULL_MODE;
 	P35_PUSHPULL_MODE;
 	P12_PUSHPULL_MODE;
 	P11_PUSHPULL_MODE;
 	P34_PUSHPULL_MODE;
}

void led_gpio_contrl(char led,char status)
{
	if(led>L_NULL)return;
	//led_array[led] = status;
}


