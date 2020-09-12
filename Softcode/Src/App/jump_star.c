#include "MS51_32K.h"
#include "app_uart.h"
#include "app_type.h"
#include "jump_star.h"
#include "app_adc.h"
#include "digital_lcd.h"

static char jumpstar_been_en = 0;
static char jumpstar_work_mode = 0;

char junpstar_adc_chanle = VIN_ADC;
char jumpstar_digital_status = 1;

unsigned int junpstar_adc_value = 0; 
unsigned int junpstar_vout_vcc = 140;
unsigned int jumpstar_vin_vcc = 140;

char code battery_vcc_table[6]={JUMP_VOUT_BATTER_ERROR,JUMP_VOUT_BATTER_LOW,JUMP_VOUT_BATTER_MIDDLE,JUMP_VOUT_BATTER_FULL,JUMP_VOUT_BATTER_GOOD,JUMP_VOUT_BATTER_FAULT};
unsigned int xcode vout_vcc_arr[10]={0x00};

void jump_star_test(void)
{
    static char pingpong = 0;
    if(pingpong==0){
        app_getadc_value(pingpong);
        pingpong = 1;
    }
    else{
        app_getadc_value(pingpong);
        pingpong = 0;
    }
}

void jumpstart_gpio_init(void)
{
    P07_INPUT_MODE;
    P07_PUSHPULL_MODE;
    P03_PUSHPULL_MODE;
    P33_PUSHPULL_MODE;
    P01_PUSHPULL_MODE;
    P00_PUSHPULL_MODE;

    BUZZ_EN = 0;
    TEST_ENA = 0;
    TEST_ENB = 0;
    RELAY_EN = 0;
}

#if 0
void jumpstart_vout_produce(void)
{
    static int cyc = 0;
    if(cyc==1){
        TEST_ENA = 1;
        TEST_ENB = 0;
    }
    else if(cyc==30){
        TEST_ENA = 0;
        TEST_ENB = 1;
    }
    else if(cyc==61){
        TEST_ENA = 0;
        TEST_ENB = 0;
    }
    else if(cyc>240){
        cyc = 0;
    }
    cyc ++;
}
#endif

void jumpstart_vout_produce(void)
{
    static int cyc = 0;
    if(cyc==1){
        TEST_ENA = 1;
        TEST_ENB = 0;
    }
    else if(cyc==120){
        TEST_ENA = 0;
        TEST_ENB = 1;
    }
    else if(cyc>241){
        cyc = 0;
    }
    cyc ++;
}


void jumpstart_been_wave(void)
{
    static int cyc = 0;	
    if(jumpstar_been_en==0)return;
	cyc++;
	if(cyc<1000)
	{
		BUZZ_EN=~BUZZ_EN;
	}
	else if(cyc<2000){
		BUZZ_EN = 0;
	}
	else if(cyc>2000){
		cyc = 0;
	}
}

void jumpstart_been_control(char enable)
{
    jumpstar_been_en = enable;
}

void jumpstart_relay_control(void)
{
	static int cyc = 0;
	if(cyc==2)
	{
		RELAY_EN = 1;
	}
	else if(cyc==6000)
	{
		RELAY_EN = 0;
	}
	else if(cyc>6100){
		cyc = 0;
	}
	cyc ++;
}

void jumpstart_vout_show(void)
{
    unsigned int get_vcc_value = 0;

	get_vcc_value = (unsigned int)(((unsigned long)junpstar_adc_value*518)/4095);
    printf("%d,%d\r\n",get_vcc_value,junpstar_adc_value);
    digital_vcc_display(get_vcc_value,1);
}

void jumpstart_handle_process(void)
{
    junpstar_adc_value = app_getadc_value(junpstar_adc_chanle);
    jumpstart_vout_show();
	#if 0
    if(junpstar_adc_chanle==VIN_ADC){
        junpstar_adc_chanle = VOUT_ADC;
    }
    else{
        junpstar_adc_chanle = VIN_ADC;
    }
	#endif
	
}

void jumpstart_batter_ledcontrl(char led_io,char speed)     // 
{
    static char led_cyc = 0;
    char i = 0;
    for(i = 0;i<5;i++)
    {
        if(i>speed){
            led_gpio_contrl(led_io,led_cyc);
            if(led_cyc==0){
                led_cyc=1;
            }
            else{
                led_cyc=0;
            }
        }
    }
}


void jumpstart_control_status(void)
{
    char led_control_io = 0;
    char led_control_speed = 0;
    char i = 0;
    if(P_NTC==0)
    {
        jumpstar_digital_status = 0;    // ---
        jumpstart_been_control(1);
    }
    if(WORK_JUMP==jumpstar_work_mode)
    {
        if(junpstar_vin_vcc>JUMP_VIN_LOW)
        {
            digital_ocr_change(DIGITAL_OCR_UV);
            led_gpio_contrl(LED_J_FAULT,1);
            jumpstart_been_control(1);
        }
        else{
            led_gpio_contrl(J_OK,1);
        }
    }
    else
    {
        if(junpstar_out_vcc<JUMP_VOUT_SHORT_ERROR)
        {


        }
        else if(junpstar_out_vcc<JUMP_VIN_BATTER_ERROR)
        {
            jumpstar_digital_status = 0;    // 
            digital_ocr_change(DIGITAL_OCR_UV);
            jumpstart_been_control(1);
        }
        else if(junpstar_out_vcc>JUMP_VOUT_OVER_ERROR)
        {

        }
        else 
        {
            for(i = 0 ;i<5;i++)
            {
                if(junpstar_out_vcc>battery_vcc_table[i]&&junpstar_out_vcc<=battery_vcc_table[i+1])
                {
                    led_control_io = i;
                    led_control_speed = (junpstar_out_vcc - battery_vcc_table[i])*5/(battery_vcc_table[i+1]-battery_vcc_table[i]);
                    break;
                }
            }
            jumpstart_batter_ledcontrl(led_control_io,led_control_speed);
        }
    }
}

void jumpstart_vout_judge(void)
{
    static char vout_pos = 0;
    if(vout_pos>JUMP_JUDGE_VOUT_NUM)vout_pos = 0;
    vout_vcc_arr[vout_pos] = junpstar_adc_value;
    // judge 

}
