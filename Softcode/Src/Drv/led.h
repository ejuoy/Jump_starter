#define _LED_H_
#define _LED_H_

/*  P3  */  
#define LED_B_FULL	P2^1
#define LED_J_OK	P3^5
#define LED_A_FAULT	P1^2
#define LED_A_GOOD	P1^1
#define LED_B_LOW	P3^4

enum _LED_CONTROL_
{
	B_FULL = 0,
	J_OK ,
	A_FAULT,
	A_GOOD,
	B_LOW,
	L_NULL,
};

void led_gpio_init(void);
void led_gpio_contrl(char led,char status);

#endif


