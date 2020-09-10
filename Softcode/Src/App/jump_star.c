#include "MS51_32K.h"
#include "app_uart.h"
#include "app_type.h"
#include "jump_star.h"
#include "app_adc.h"
#include "digital_lcd.h"

static char jumpstar_been_en = 0;
static char jumpstar_work_mode = 0;

char junpstar_adc_chanle = 0;
unsigned int junpstar_adc_value = 0; 
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

void jumpstart_been_wave(void)
{
    if(jumpstar_been_en==0)return;
    BUZZ_EN=~BUZZ_EN;
}

void jumpstart_been_control(char enable)
{
    jumpstar_been_en = enable;
}

void jumpstart_vout_show(void)
{
    static int time = 0;
    unsigned int get_vcc_value = 0;
    time++;
    if(time==50){
        time = 0;
        get_vcc_value = junpstar_adc_value*250/4095;
        printf("%d,%d\r\n",get_vcc_value,junpstar_adc_value);
        digital_vcc_display(get_vcc_value,1);
    }
}
void jumpstart_handle_process(void)
{
    junpstar_adc_value = app_getadc_value(junpstar_adc_chanle);
    jumpstart_vout_show();
    // change channle
    if(junpstar_adc_chanle==VIN_ADC){
        junpstar_adc_chanle = VOUT_ADC;
    }
    else{
        junpstar_adc_chanle = VIN_ADC;
    }
}