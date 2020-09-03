/************************************************************************************************************/
/*  File Function: MS51 DEMO project                                                                        */
/************************************************************************************************************/

#include "MS51_32K.h"
#include "app_uart.h"
#include "type.h"
#include "led.h"
#include "digital_lcd.h"

#define SOFT_VERSION	"v1.00.01"
#define PRJ_NAME		"CP010-121"

void Version_show(void)
{
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
    Version_show();
    while(1);

}