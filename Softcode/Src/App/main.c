/************************************************************************************************************/
/*  File Function: MS51 DEMO project                                                                        */
/************************************************************************************************************/

#include "MS51_32K.h"
#include "app_uart.h"
#include "app_type.h"
#include "led.h"
#include "digital_lcd.h"

#define SOFT_VERSION	"v1.00.01"
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
/* UART0 initial setting
  * include sys.c in Library for modify HIRC value to 24MHz
  * include uart.c in Library for UART initial setting
*/
    MODIFY_HIRC(HIRC_24);
    app_uart_init();
    led_gpio_init();
    Version_show();
    led_gpio_contrl(LED_B_FULL,1);
    digital_gpio_init();
    //digital_ocr_change(DIGITAL_OCR_UV,1);
    //digital_ocr_change(DIGITAL_OCR_DP,1);
    //digital_num_change(0,1);
    //digital_num_change(1,3);
    //digital_num_change(2,3);
    while(1)
    {
      //digital_lcd_test();
      digital_lcd_show();
      //Timer0_Interrupt_Init(16000000,300,1000);
    }
}