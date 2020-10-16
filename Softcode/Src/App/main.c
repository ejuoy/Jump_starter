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


#define SOFT_VERSION	"v1.01.03"
#define PRJ_NAME		"CP020-621"

void Version_show(void)
{
	printf("\r\n");
	printf("+++++++++++++++++++++++++++++++++\r\n");
	printf("++++++  "PRJ_NAME":"SOFT_VERSION"+++++++\r\n");
	printf("++++++++++ %s++++++++++++++\r\n",__TIME__);
	printf("+++++++++++++++++++++++++++++++++\r\n");
}

void WDT_Init(void)
{
    TA=0xAA;TA=0x55;WDCON|=0x07;                //Setting WDT prescale 
    set_WDCON_WDCLR;                            //Clear WDT timer
    while((WDCON|~SET_BIT6)==0xFF);             //confirm WDT clear is ok before into power down mode
    set_WDCON_WDTR;                             //WDT run
}

void main (void) 
{
    MODIFY_HIRC(HIRC_24);
    Disable_WDT_Reset_Config();
    /*----------------------------------------------------------------------------------------------*/
    /* WDT Init !!! ENABLE CONFIG WDT FIRST !!!                                                     */
    /* Warning:                                                                                     */
    /* Always check CONFIG WDT enable first, CONFIG not enable, SFR can't enable WDT reset          */
    /* Please call Enable_WDT_Reset_Config() function to enable CONFIG WDT reset                    */
    /*----------------------------------------------------------------------------------------------*/

    app_uart_init();
    jumpstart_been_enbale(1);
    led_gpio_init();
    Version_show();
	Timer2_Delay(16000000,128,5,200000);
    app_timer0_init();
    jumpstart_gpio_init();
    digital_gpio_init();
    WDT_Init();
    jumpstart_been_enbale(0);
    while(1)
    {
        jumpstart_handle_process();
        set_WDCON_WDCLR; 
    }
}

