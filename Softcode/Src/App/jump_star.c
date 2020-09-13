#include "MS51_32K.h"
#include "app_uart.h"
#include "app_type.h"
#include "jump_star.h"
#include "app_adc.h"
#include "digital_lcd.h"
#include "led.h"

static char jumpstar_been_en = 0;
static char jumpstar_relay_en = 0;
static int jumpstar_relay_cyc = 0;

static char jumpstar_work_mode = WORK_JUMP;

char junpstar_adc_chanle = VIN_ADC;
char jumpstar_digital_status = 1;
char junpstar_relay_flag = 0;
unsigned int junpstar_adc_value = 0; 
unsigned int junpstar_out_vcc = 140;
unsigned int jumpstar_battery_vcc = 0;
unsigned int junpstar_vin_vcc = 140;
unsigned int jumpstar_relay_vcc = 0;
unsigned relay_release_status = 0;

unsigned char battery_vcc_table[6]={JUMP_VOUT_BATTER_ERROR,JUMP_VOUT_BATTER_LOW,JUMP_VOUT_BATTER_MIDDLE,JUMP_VOUT_BATTER_FULL,JUMP_VOUT_BATTER_GOOD,JUMP_VOUT_BATTER_FAULT};
unsigned int vout_vcc_arr[JUMP_JUDGE_VOUT_NUM]={0x00};

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

void jumpstart_relay_enable(char enable)
{
	jumpstar_relay_en = enable;
	jumpstar_relay_cyc = 0;
}

void jumpstart_relay_control(void)
{
	if(jumpstar_relay_en==0)return;
	if(jumpstar_relay_cyc==2)
	{
		RELAY_EN = 1;
	}
	else if(jumpstar_relay_cyc==6000)
	{
		RELAY_EN = 0;		
	}
	else if(jumpstar_relay_cyc==6090){
		jumpstar_relay_vcc = app_getadc_value(VOUT_ADC);
		relay_release_status = 1;
	}
	else if(jumpstar_relay_cyc>6100){
		jumpstar_relay_cyc = 0;
	}
	jumpstar_relay_cyc ++;
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
	if(WORK_JUMP==jumpstar_work_mode)
	{
		if(junpstar_adc_chanle==VIN_ADC){
			junpstar_vin_vcc = app_getadc_value(junpstar_adc_chanle);
			junpstar_adc_chanle = VOUT_ADC;
			//printf("Out,%d\r\n",junpstar_vin_vcc);
		}
		else{
			junpstar_out_vcc = app_getadc_value(junpstar_adc_chanle);
			jumpstart_vout_judge(); 	
			//LED_A_GOOD = ~LED_A_GOOD;
			junpstar_adc_chanle = VIN_ADC;
			//printf("Out,%d\r\n",junpstar_out_vcc);
		}
	}
    jumpstart_control_status();
	#endif
}

void jumpstart_batter_ledcontrl(char led_io,char speed)     // 
{
    static unsigned int led_cyc = 0;
    static unsigned int led_pipo = 0;
	unsigned int i = 0;
    if(speed!=5){
		if(led_io!=0)led_gpio_contrl(led_io,1);
        led_cyc ++;
        if(led_cyc==1)
        {
            led_gpio_contrl(led_io+1,led_pipo);
            if(led_pipo==0){
                led_pipo = 1;
            }
            else{
                led_pipo = 0;
            }
        }
        else if(led_cyc>(200/speed)){
            led_cyc = 0;
        }
    }
    else{
        if(led_io!=0)led_gpio_contrl(led_io,0);
        led_gpio_contrl(led_io+1,1);
    }
	for(i = 1;i<6;i++){
		if((i!=led_io)&&(i!=(led_io+1)))
		{
			led_gpio_contrl(i,0);
		}
	}
}

void jumpstart_control_status(void)
{
    char led_control_io = 0;
    char led_control_speed = 0;
    char i = 0;
	char batter_star_ok = 0;

	#if 0
	printf("%d= %d-%d\r\n",(unsigned int)jumpstar_work_mode,(unsigned int)junpstar_vin_vcc,\
		(unsigned int)junpstar_out_vcc);
	#endif
	
	#if 0
    if(P_NTC==0)
    {
        jumpstar_digital_status = 0;    // ---
        jumpstart_been_control(1);
		junpstar_relay_flag |=(0x01<<0);
    }
	else{
		junpstar_relay_flag &=~(0x01<<0);
	}
	#endif
	if(junpstar_out_vcc<JUMP_VOUT_SHORT_ERROR)
	{
		jumpstart_been_control(1);
		jumpstart_relay_enable(0);		
        jumpstar_digital_status = 0;    // ---
		digital_ocr_change(DIGITAL_OCR_SC,1);
		junpstar_relay_flag |=(0x01<<1);
	}
	else{
		junpstar_relay_flag &=~(0x01<<1);
	}
	
    if(WORK_JUMP==jumpstar_work_mode)
    {
    	if(junpstar_vin_vcc<JUMP_VIN_LAST_LOW)
		{
            digital_ocr_change(DIGITAL_OCR_UV,1);
			led_gpio_contrl(J_FAULT,1);			
            led_gpio_contrl(J_OK,0);
            jumpstart_been_control(1);
			jumpstar_digital_status = 0;	// ---
			
			junpstar_relay_flag |=(0x01<<2);
		}
        else if(junpstar_vin_vcc<JUMP_VIN_LOW)
        {
            digital_ocr_change(DIGITAL_OCR_UV,1);
            led_gpio_contrl(J_FAULT,1);			
            led_gpio_contrl(J_OK,0);
            jumpstart_been_control(1);
			jumpstar_digital_status = 1;	// ---
			
			junpstar_relay_flag |=(0x01<<2);
        }
        else{			
            digital_ocr_change(DIGITAL_OCR_UV,0);			
            led_gpio_contrl(J_FAULT,0);
            led_gpio_contrl(J_OK,1);	
			junpstar_relay_flag &=~(0x01<<2);
        }
		if((junpstar_relay_flag&0x07)==0x00){
			jumpstar_digital_status = 1;	// ---
			jumpstart_been_control(0);
		}
		
		led_gpio_contrl(B_LOW,0);			
        led_gpio_contrl(B_MIDDLE,0);
		led_gpio_contrl(B_FULL,0);			
        led_gpio_contrl(A_GOOD,0);
        led_gpio_contrl(A_FAULT,0);

		digital_vcc_display(junpstar_vin_vcc,jumpstar_digital_status);
    }
    else
    {
        if(junpstar_out_vcc<JUMP_VOUT_BATTER_ERROR&&junpstar_out_vcc>JUMP_VOUT_SHORT_ERROR)
        {
            jumpstar_digital_status = 0;    // 
            jumpstart_been_control(1);
			jumpstart_relay_enable(0);
			junpstar_relay_flag |=(0x01<<3);
        }
        else if(junpstar_out_vcc>JUMP_VOUT_OVER_ERROR)
        {
            jumpstar_digital_status = 0;    // 
            jumpstart_been_control(1);
			jumpstart_relay_enable(0);
			junpstar_relay_flag |=(0x01<<3);
        }
        else 
        {
            for(i = 0 ;i<5;i++)
            {
                if((junpstar_out_vcc>battery_vcc_table[i])&&(junpstar_out_vcc<=battery_vcc_table[i+1]))
                {
                    led_control_io = i;
                    led_control_speed = (junpstar_out_vcc - battery_vcc_table[i])*5/(battery_vcc_table[i+1]-battery_vcc_table[i]);
                    printf("i=%d ledcontorl = %d,%d\r\n",(unsigned int)i,(unsigned int)led_control_io,(unsigned int)led_control_speed);
                    break;
                }
            }
			junpstar_relay_flag &=~(0x01<<2);
            jumpstart_batter_ledcontrl(led_control_io,led_control_speed);
        }
		if(jumpstar_battery_vcc==0){
			digital_vcc_display(junpstar_out_vcc,jumpstar_digital_status);

		}
		else{
			digital_vcc_display(jumpstar_battery_vcc,jumpstar_digital_status);
		}
		if(jumpstar_relay_en==0&&junpstar_relay_flag==0){			
			jumpstart_relay_enable(1);
		}
		
		if(relay_release_status==1)
		{
			if(jumpstar_battery_vcc>130){
				if(jumpstar_relay_vcc>jumpstar_battery_vcc+5){
					batter_star_ok = 1;
				}
			}
			else{
				if(jumpstar_relay_vcc>130){
					batter_star_ok = 1;
				}
			}
			if(batter_star_ok==1){
				jumpstart_relay_enable(0);
				jumpstar_battery_vcc = 0;
			}
			relay_release_status = 0;
		}
    }
}

#if 0
void jumpstart_vout_judge(void)
{
    static char vout_pos = 0;
	static int vout_show = 0;
    char i = 0;
    unsigned int arr_avg = 0;
    unsigned int mul_avg = 0;
    if(vout_pos>JUMP_JUDGE_VOUT_NUM)vout_pos = 0;
    vout_vcc_arr[vout_pos] = junpstar_out_vcc;
    // judge 
    vout_show ++;
    for(i = 0;i<10;i++){
        arr_avg += vout_vcc_arr[i];
    }
    arr_avg /= 10;
    for(i = 0;i<10;i++){
        if(vout_vcc_arr[i]>arr_avg){
            mul_avg += (vout_vcc_arr[i] - arr_avg);
        }
        else{
            mul_avg += (arr_avg - vout_vcc_arr[i]);
        }
    }
    mul_avg /= 10;
	
	vout_pos ++;
	if((arr_avg<JUMP_VOUT_AVG_MAX&&arr_avg>JUMP_VOUT_AVG_MIN)\
		&&mul_avg>=JUMP_VOUT_MUL_VALUE)
	{
		jumpstar_work_mode = WORK_JUMP;
	}
	else if(mul_avg<JUMP_VOUT_MUL_VALUE){
		jumpstar_work_mode = WORK_BATTERY;
	}
	
	vout_show ++;
	if(vout_show>100){
		vout_show = 0;
		printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\r\n",(unsigned int)vout_vcc_arr[0],(unsigned int)vout_vcc_arr[1],\
			(unsigned int)vout_vcc_arr[2],(unsigned int)vout_vcc_arr[3],(unsigned int)vout_vcc_arr[4],(unsigned int)vout_vcc_arr[5],\
			(unsigned int)vout_vcc_arr[6],(unsigned int)vout_vcc_arr[7],(unsigned int)vout_vcc_arr[8],(unsigned int)vout_vcc_arr[9]);
		printf("avg=%d,mul=%d\r\n",(unsigned int)arr_avg,(unsigned int)mul_avg);
	}
}
#endif

void jumpstart_vout_judge(void)
{
    static char vout_pos = 0;
	//static int vout_show = 0;
	unsigned int tmp = 0;
    char i = 0;
	char j = 0;
	unsigned int judge_vcc_arr[JUMP_JUDGE_VOUT_NUM]={0x00};
    unsigned int mul_value = 0;
    unsigned int mul_pos = 0;
    if(vout_pos>JUMP_JUDGE_VOUT_NUM)vout_pos = 0;
    vout_vcc_arr[vout_pos] = junpstar_out_vcc;

	for(i = 0;i<10;i++){
		judge_vcc_arr[i] = vout_vcc_arr[j];
	}
	
	for(i = 0 ;i<9;i++)		//sort 
	{
		for(j = 0;j<9-i;j++)
		{
			if(judge_vcc_arr[j]>judge_vcc_arr[j+1])
			{
				tmp = judge_vcc_arr[j];
				judge_vcc_arr[j] = judge_vcc_arr[j+1];
				judge_vcc_arr[j+1] = tmp;
			}
		}
	}
	for(i = 1;i<8;i++){		//drop max and min
		if((judge_vcc_arr[i+1]-judge_vcc_arr[i])<3){
			mul_value ++;
		}
		else{
			mul_pos = i;
		}
	}
	if((mul_value>4)&&((mul_pos>2)&(mul_pos<6))){
		jumpstar_work_mode = WORK_JUMP;
	}
	else{
		if(jumpstar_work_mode==WORK_JUMP){
			jumpstar_battery_vcc = junpstar_out_vcc;
		}
		jumpstar_work_mode = WORK_BATTERY;
	}
}



