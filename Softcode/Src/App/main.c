/************************************************************************************************************/
/*  File Function: MS51 DEMO project                                                                        */
/************************************************************************************************************/

#include "MS51_32K.h"
#include "app_uart.h"
#include "app_type.h"
#include "led.h"
#include "digital_lcd.h"
#include "app_timer.h"
#include "app_adc.h"
#include "jump_star.h"


#define SOFT_VERSION	"v1.01.02"
#define PRJ_NAME		"CP010-121"

void Version_show(void)
{
	printf("\r\n");
	printf("+++++++++++++++++++++++++++++++++\r\n");
	printf("++++++  "PRJ_NAME":"SOFT_VERSION"+++++++\r\n");
	printf("++++++++++ %s++++++++++++++\r\n",__TIME__);
	printf("+++++++++++++++++++++++++++++++++\r\n");
}

void main (void) 
{
    MODIFY_HIRC(HIRC_24);
    app_uart_init();
    led_gpio_init();
    Version_show();
	Timer2_Delay(16000000,128,5,200000);
    app_timer0_init();
    jumpstart_gpio_init();
    digital_gpio_init();
	
    while(1)
    {
        jumpstart_handle_process();
    }
}



