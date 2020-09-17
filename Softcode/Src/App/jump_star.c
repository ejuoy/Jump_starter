#include "MS51_32K.h"
#include "app_uart.h"
#include "app_type.h"
#include "jump_star.h"
#include "app_adc.h"
#include "digital_lcd.h"
#include "led.h"

static unsigned int  key_press = 0; 
static char jumpstar_been_en = 0;
static char jumpstar_relay_en = 0;
static unsigned int jumpstar_relay_cyc = 0;
static char jumpstar_work_mode = WORK_JUMP;

char junpstar_adc_chanle = VIN_ADC;
char jumpstar_digital_status = 1;
char junpstar_relay_flag = 0;
unsigned int junpstar_adc_value = 0; 
unsigned int junpstar_out_vcc = 140;
unsigned int jumpstar_battery_vcc = 0;
unsigned int junpstar_vin_vcc = 140;
unsigned int jumpstar_relay_vcc = 0;
unsigned int relay_release_flag = 0;
unsigned char jumpstar_battery_over = 0;
static int judge_disable_cnt = 0;
char junpstar_waring_flag = 0;

unsigned char battery_vcc_table[6]={JUMP_VOUT_BATTER_ERROR,JUMP_VOUT_BATTER_LOW,JUMP_VOUT_BATTER_MIDDLE,JUMP_VOUT_BATTER_FULL,JUMP_VOUT_BATTER_GOOD,JUMP_VOUT_BATTER_FAULT};
unsigned int vout_vcc_arr[JUMP_JUDGE_VOUT_NUM]={0xff};

void jumpstart_gpio_init(void)
{
    P07_INPUT_MODE;
    P06_INPUT_MODE;
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

void jumpstart_been_enbale(char enable)
{
	jumpstar_been_en = enable;
	if(enable==0){
		BUZZ_EN= 0;
	}
}

void jumpstart_relay_enable(char enable)
{
	jumpstar_relay_en = enable;
	jumpstar_relay_cyc = 0;
	relay_release_flag = 0;
	if(enable==0){
		RELAY_EN = 0;
	}
	else{
		printf("jumpstart_relay_enable = %d\r\n",(unsigned int)enable);
	}
}

void jumpstart_relay_control(void)
{
	static char cnt_time = 0;
	if(jumpstar_relay_en==0)return;
	if(cnt_time>10){
		cnt_time = 0;
		if(jumpstar_relay_cyc==2)
		{
			RELAY_EN = 1;
		}
		else if(jumpstar_relay_cyc==600)
		{
			RELAY_EN = 0;		
		}
		else if(jumpstar_relay_cyc==605){
			relay_release_flag = 1;
		}
		else if(jumpstar_relay_cyc>700){
			jumpstar_relay_cyc = 0;
			relay_release_flag = 0;
		}
		jumpstar_relay_cyc ++;
	}
	else{
		cnt_time ++;
	}
}

void jumpstar_key_timecnt(void)
{
    static char key_cnt_time = 0; 
    if(key_press==0)return;
    if(key_cnt_time>10){
        key_cnt_time = 0;
        if(key_press<WOKR_KEY_PRESS_TIME)key_press++;
    }
    else{
        key_cnt_time ++;
    }
}



void jumpstart_vin_ledstatus(void)
{
    if(junpstar_vin_vcc>140){
        led_gpio_contrl(J_OK,1);
        led_gpio_contrl(J_FAULT,0); 
    }
    else{
        led_gpio_contrl(J_OK,0);
        led_gpio_contrl(J_FAULT,1); 
    }
}

void jumpstart_keymode_ledstatus(void)
{
    static unsigned int cnt = 0;
    unsigned int i = 0;
    if(cnt==1)
    {
        for(i = 1;i<6;i++){
            led_gpio_contrl(i,1);   
        }
    }
    else if(cnt==1000){
        for(i = 1;i<6;i++){
            led_gpio_contrl(i,0);   
        }
    }
    if(cnt>2000){
        cnt=0;
    }
    cnt++;
}

void jumpstart_batter_ledcontrl(char led_io,char speed)    
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

void jumpstart_batter_ledstatus(unsigned int vout_vcc)
{
    char led_control_io = 0;
    char led_control_speed = 0;
    char i = 0;
    for(i = 0 ;i<5;i++)
    {
        if((vout_vcc>battery_vcc_table[i])&&(vout_vcc<=battery_vcc_table[i+1]))
        {
            led_control_io = i;
            led_control_speed = (vout_vcc - battery_vcc_table[i])*5/(battery_vcc_table[i+1]-battery_vcc_table[i]);
            break;
        }
    }
    jumpstart_batter_ledcontrl(led_control_io,led_control_speed);
}

void jumpstar_waring_control(void)
{
    junpstar_relay_flag = 0;
    if(P_NTC==1){       //过温    
        junpstar_relay_flag |=(0x01);
    }

    if(junpstar_vin_vcc<JUMP_VIN_LOW){        //vin low beep
        digital_ocr_change(DIGITAL_OCR_UV,1);
    }
    else{
        digital_ocr_change(DIGITAL_OCR_UV,0);
    }

    if(jumpstar_work_mode!=WORK_KEY)
    {
        if(junpstar_out_vcc<JUMP_VOUT_SHORT_ERROR)      //short 
        {
            jumpstart_been_enbale(1);  
            jumpstar_digital_status = 0;    // ---
            digital_ocr_change(DIGITAL_OCR_SC,1);
            junpstar_relay_flag |=(0x01<<1);
        }
        if(junpstar_vin_vcc<JUMP_VIN_LAST_LOW){        //vin low beep
            digital_ocr_change(DIGITAL_OCR_UV,1);
            jumpstar_digital_status = 0;    // ---
            jumpstart_been_enbale(1);
            junpstar_relay_flag |=(0x01<<2);
        }
        if(jumpstar_work_mode!=WORK_JUMP)
        {
            if(junpstar_out_vcc<JUMP_VOUT_BATTER_ERROR&&junpstar_out_vcc>JUMP_VOUT_SHORT_ERROR)     // battery error
            {
                jumpstart_been_enbale(1);
                jumpstar_digital_status = 0;                        // 
                junpstar_relay_flag |=(0x01<<3);
            }
            else if(junpstar_out_vcc>JUMP_VOUT_OVER_ERROR)          //  battery vcc high
            {
                digital_ocr_change(DIGITAL_OCR_OV,1); 
                jumpstart_been_enbale(1);
                jumpstar_digital_status = 0;    // 
                junpstar_relay_flag |=(0x01<<4);          
            }
            if(jumpstar_work_mode==WORK_BOTH){
                if(jumpstar_battery_vcc>junpstar_vin_vcc){
                    digital_ocr_change(DIGITAL_OCR_CB,1);
                    jumpstart_been_enbale(1);
                    jumpstar_digital_status = 0;    // 
                    junpstar_relay_flag |=(0x01<<5);
                }
            }
            if(jumpstar_work_mode==WORK_BATTERY){           
                if(junpstar_out_vcc<75)     // can't work
                {
                    digital_ocr_change(DIGITAL_OCR_UV,1);
                    jumpstart_been_enbale(1);
                    jumpstar_digital_status = 0;    // 
                    junpstar_relay_flag |=(0x01<<5);
                }
            }
        }
    }
    if(junpstar_relay_flag==0){
        digital_ocr_change(DIGITAL_OCR_OV,0);
        digital_ocr_change(DIGITAL_OCR_CB,0);
        digital_ocr_change(DIGITAL_OCR_OT,0);
        digital_ocr_change(DIGITAL_OCR_SC,0);
        jumpstart_been_enbale(0);
        jumpstar_digital_status = 0;
    }
}

void jumpstar_relay_process(void)
{
		char batter_star_ok = 0;
    if(jumpstar_work_mode==WORK_BOTH)
    {
				if(jumpstar_battery_over==1)return ;
        // if not warning 
        if(jumpstar_relay_en==0)        //  OPEN
        {
            if(junpstar_relay_flag==0){
                jumpstart_relay_enable(1); 
            }
        }
        if(jumpstar_relay_en==1)
        {
            if(jumpstar_battery_vcc>130){
                if(junpstar_out_vcc>jumpstar_battery_vcc+5){
                    batter_star_ok = 1;
                }
            }
            else{
                if(junpstar_out_vcc>130){
                    batter_star_ok = 1;
                }
            }
            if(batter_star_ok==1){
                jumpstart_relay_enable(0);
                judge_disable_cnt = 1000;
                batter_star_ok = 0;
                jumpstar_battery_over = 1;
            }
        }
    }
    else if(jumpstar_work_mode==WORK_KEY)
    {
        // if not P P_NTC
        if(jumpstar_relay_en&(0x01))return;     
        if(jumpstar_relay_en==0)        //  OPEN
        {
            jumpstart_relay_enable(1); 
        }
    }
    else 
    {
        if(jumpstar_relay_en==1)
        {
            jumpstart_relay_enable(0);  //close relay
        }
    }
}

void jumpstart_display_control(void)
{
    char i = 0;
    if(jumpstar_work_mode==WORK_JUMP)
    {
        for(i = 1;i<6;i++){
            led_gpio_contrl(i,0);   // clear vout led
        }
        jumpstart_vin_ledstatus();
        digital_vcc_display(junpstar_vin_vcc,jumpstar_digital_status);
    }
    else if(jumpstar_work_mode==WORK_BATTERY)
    {
        led_gpio_contrl(J_OK,0);
        led_gpio_contrl(J_FAULT,0);
        digital_vcc_display(junpstar_vin_vcc,jumpstar_digital_status);
        jumpstart_batter_ledstatus(junpstar_vin_vcc);
    }
    else if(jumpstar_work_mode==WORK_BOTH)
    {
        jumpstart_vin_ledstatus();
        if(jumpstar_battery_over==1){
            jumpstart_batter_ledstatus(junpstar_vin_vcc);
            digital_vcc_display(junpstar_vin_vcc,jumpstar_digital_status);
        }
        else{
            jumpstart_batter_ledstatus(jumpstar_battery_vcc);
            digital_vcc_display(jumpstar_battery_vcc,jumpstar_digital_status);
        }
    }
    else if(jumpstar_work_mode==WORK_KEY)
    {
        jumpstart_keymode_ledstatus();
        jumpstart_vin_ledstatus();
    }
}

unsigned char jumpstart_key_handle(void)
{
    unsigned char key_handle = 0;
    if(GPIO_KEY==0)     //press
    {
        if(key_press==0){
            key_press++;
        }
        if(key_handle==WOKR_KEY_PRESS_TIME)
        {
            key_handle = 2;
        }
    }
    else{
        if(key_press>0&&key_press<WOKR_KEY_PRESS_TIME){
            key_handle = 1;
        }
        key_press = 0;
    }
    return key_handle;
}

unsigned char jumpstart_vout_judge(void)
{
    unsigned char vout_ret = 0;
    static char vout_pos = 0;
    static int vout_show = 0;
    static int judge_batter_cnt = 0;
    static int judge_jump_cnt = 0;

    static unsigned char check_wave_cnt = 0;
    static unsigned char check_battey_cnt = 0;
    unsigned int tmp = 0;
    char i = 0;
    char j = 0;
    unsigned int judge_vcc_arr[JUMP_JUDGE_VOUT_NUM]={0x00};
    unsigned int mul_value = 0;
    unsigned int mul_avg = 0;
    unsigned int mul_pos = 0;
    unsigned int mul_max = 0;

    if(vout_pos>JUMP_JUDGE_VOUT_NUM)vout_pos = 0;
    vout_vcc_arr[vout_pos] = junpstar_out_vcc;
    vout_pos ++;
    
    if(judge_disable_cnt>0)
    {
        judge_disable_cnt --;
        return 0;
    }

    for(i = 0;i<JUMP_JUDGE_VOUT_NUM;i++){
        judge_vcc_arr[i] = vout_vcc_arr[i];
    }

    for(i = 0 ;i<JUMP_JUDGE_VOUT_NUM-1;i++)     //sort 
    {
        for(j = 0;j<JUMP_JUDGE_VOUT_NUM-1-i;j++)
        {
            if(judge_vcc_arr[j]>judge_vcc_arr[j+1])
            {
                tmp = judge_vcc_arr[j];
                judge_vcc_arr[j] = judge_vcc_arr[j+1];
                judge_vcc_arr[j+1] = tmp;
            }
        }
    }
    for(i = 1;i<JUMP_JUDGE_VOUT_NUM-2;i++){     //drop max and min
        if((judge_vcc_arr[i+1]-judge_vcc_arr[i])<2){
            mul_value ++;
            mul_avg +=(judge_vcc_arr[i+1]-judge_vcc_arr[i]);
        }
        else{
            mul_pos = i;
            if(mul_max<(judge_vcc_arr[i+1]-judge_vcc_arr[i])){
                mul_max = judge_vcc_arr[i+1]-judge_vcc_arr[i];
            }
        }
    }
    mul_avg = mul_avg - mul_max;
    if((mul_value>(JUMP_JUDGE_VOUT_NUM/2))&&(mul_value<7)&&(mul_max>6)&&mul_avg<JUMP_JUDGE_VOUT_NUM){
        judge_disable_cnt = JUMP_JUDGE_VOUT_NUM;
        check_wave_cnt++;
        if(jumpstar_relay_en==0){


        }
        if(check_wave_cnt>1){
            check_wave_cnt = 0;
            vout_ret = 1;
        }
    }
    else if(mul_avg<JUMP_JUDGE_VOUT_NUM&&mul_max<6){
        judge_disable_cnt = JUMP_JUDGE_VOUT_NUM;
        check_battey_cnt++;
        if(relay_release_flag==1){
            check_battey_cnt = 0;
            vout_ret = 2;
        }
        else if(check_battey_cnt>1){
            check_battey_cnt = 0;
            vout_ret = 2;
        }
    }
    else{
        check_battey_cnt = 0;
        check_wave_cnt = 0;
        vout_ret = 0;
    }
    return vout_ret;
}

/*

*/
char jumpstart_judge_voutwave(void)     // 0 not judge 1 vout wave  2 vout battey
{
    if(jumpstar_relay_en==0||relay_release_flag==1)
    {
        if(junpstar_adc_chanle==VIN_ADC){
            junpstar_vin_vcc = app_getadc_value(junpstar_adc_chanle);
            junpstar_adc_chanle = VOUT_ADC;
            
        }
        else{
            junpstar_out_vcc = app_getadc_value(junpstar_adc_chanle);
            jumpstart_vout_judge();             
            //LED_A_GOOD = ~LED_A_GOOD;
            junpstar_adc_chanle = VIN_ADC;
            //printf("Out,%d\r\n",junpstar_out_vcc);
        }
    }
}

void jumpstart_judge_mode(void)
{
    char voutstatus = 0;
    char key_value = jumpstart_key_handle();
    voutstatus = jumpstart_judge_voutwave();
    if(junpstar_vin_vcc<40){                // not vin
        if(voutstatus==2){
            jumpstar_work_mode = WORK_BATTERY;
            jumpstar_battery_over = 0;
        }
    }
    else{
        if(jumpstar_work_mode!=WORK_KEY){
            if(key_value==2){
                jumpstar_work_mode = WORK_KEY;
                jumpstar_battery_over = 0;
                key_press = 0;
            }
            else if(voutstatus==2){
                jumpstar_work_mode = WORK_BOTH;
                jumpstar_battery_vcc = junpstar_out_vcc;
            }
            else if(voutstatus==1){
                jumpstar_work_mode = WORK_JUMP;
                jumpstar_battery_over = 0;
            }
        }
        else{
            if(key_value==1)
            {
                jumpstar_work_mode = WORK_NULL;
            }
        }
    }
}

void jumpstart_handle_process(void)
{
    jumpstart_judge_mode();         //
    jumpstart_key_handle();         //   
    jumpstar_waring_control();
    jumpstart_display_control();
    jumpstar_relay_process();
}

