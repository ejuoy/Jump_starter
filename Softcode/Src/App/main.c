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

unsigned int xdata temp;

void main (void) 
{
    unsigned int get_vcc_value = 0;
    MODIFY_HIRC(HIRC_24);
    app_uart_init();
    led_gpio_init();
    Version_show();
    led_gpio_contrl(LED_B_FULL,1);
    app_timer0_init();
    jumpstart_gpio_init();
    digital_gpio_init();

    digital_ocr_change(DIGITAL_OCR_V,1);
    digital_ocr_change(DIGITAL_OCR_DP,1);
    digital_vcc_display(456,0);
    while(1)
    {
    	#if  0
        /*Enable channel 4 */ 
        ENABLE_ADC_CH5;
        ADC_ConvertTime(ADC_CH5,2,7);
        clr_ADCCON0_ADCF;
        set_ADCCON0_ADCS;                  // ADC start trig signal
        while(ADCF == 0);
        temp=(ADCRH<<4)+(ADCRL&0x0F);
        get_vcc_value = (unsigned int)(((unsigned long)temp*518)/4095);
        printf("VCC=%d,ADC=%d\r\n",get_vcc_value,temp);
        digital_vcc_display(get_vcc_value,1);
        Timer2_Delay(24000000,128,300,1000);
		#endif
        jumpstart_handle_process();
    }
}

