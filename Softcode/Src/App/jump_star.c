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
static int judge_disable_cnt = 50;
char junpstar_waring_flag = 0;
char junpstar_waring_uv = 0;

unsigned int jumpstar_relay_first_vcc = 0;
unsigned int jumpstar_relay_cnt = 0;
unsigned int jumpstar_relay_low_vcc = 0;
unsigned int jumpstar_relay_cur_vcc = 0;


unsigned char battery_vcc_table[6]={JUMP_VOUT_BATTER_ERROR,JUMP_VOUT_BATTER_LOW,JUMP_VOUT_BATTER_MIDDLE,JUMP_VOUT_BATTER_FULL,JUMP_VOUT_BATTER_GOOD,JUMP_VOUT_OVER_ERROR};
unsigned int vout_vcc_arr[JUMP_JUDGE_VOUT_NUM]={0xff};

void jumpstart_gpio_init(void)
{
    P07_INPUT_MODE;
    P06_INPUT_MODE;
    P33_PUSHPULL_MODE;
    P01_PUSHPULL_MODE;
    P00_PUSHPULL_MODE;	
    P03_PUSHPULL_MODE;

    TEST_ENA = 0;
    TEST_ENB = 0;
    RELAY_EN = 0;	
	BUZZ_EN = 0;
}

void jumpstart_vout_produce(void)
{
	static int relay_cnt = 0;
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
		if(jumpstar_relay_cnt>0&&(jumpstar_work_mode!=WORK_BOTH))
		{
			relay_cnt ++;
 			if(relay_cnt>40){
				jumpstar_relay_cnt = 0;
				printf("relay_cnt\r\n");
				relay_cnt = 0;
			}
		}
        cyc = 0;
    }
    cyc ++;
}

void jumpstart_been_wave(void)
{
    static int cyc = 0;	
    if(jumpstar_been_en==0)return;
	cyc++;
	if(cyc==1)
	{
		clr_PWM0CON0_PWM0RUN;
		DISABLE_PWM0_CH5_P03_OUTPUT;
		BUZZ_EN = 0;
	}
	else if(cyc==1000){
		set_PWM0CON0_PWM0RUN;
		ENABLE_PWM0_CH5_P03_OUTPUT;
	}
	else if(cyc>2000){
		cyc = 0;
	}
}

void jumpstart_been_enbale(char enable)
{
	static char pwm_been_init = 0;
	if(pwm_been_init==0)
	{
		pwm_been_init = 1;
		PWM0_ClockSource(PWM_FSYS,8);     
   		DISABLE_PWM0_CH5_P03_OUTPUT;                                       
    	P03_PUSHPULL_MODE;
    	PWM0_ConfigOutputChannel(5,Independent,EdgeAligned,0x0430,50);    // setting PWM channel 5 as 60% duty high of 0x6FF PWM period = 0x0432
		clr_PWM0CON0_PWM0RUN;
		BUZZ_EN = 0;
	}	
	jumpstar_been_en = enable;
	if(enable==0){
		BUZZ_EN= 0;
		clr_PWM0CON0_PWM0RUN;
		DISABLE_PWM0_CH5_P03_OUTPUT;
	}
}

void jumpstart_relay_enable(char enable)
{
	jumpstar_relay_en = enable;
	jumpstar_relay_cyc = 0;
	relay_release_flag = 0;	
	jumpstar_relay_first_vcc = 0;
	jumpstar_relay_low_vcc = 0;
	jumpstar_relay_cur_vcc = 0;
	if(enable==0){
		RELAY_EN = 0;
	}
	else{		
		RELAY_EN = 1;
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
			judge_disable_cnt = JUMP_JUDGE_VOUT_NUM;
			jumpstar_relay_cnt ++;
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
	static char vin_ledstatus = 0;
    if(junpstar_vin_vcc>140){
        led_gpio_contrl(J_OK,1);
        led_gpio_contrl(J_FAULT,0);
		vin_ledstatus = 1;
    }
    else{
		if(vin_ledstatus==1){
			if(junpstar_vin_vcc<140){
				led_gpio_contrl(J_OK,0);
				led_gpio_contrl(J_FAULT,1);
				vin_ledstatus = 0;
			}
		}
		else{
			led_gpio_contrl(J_OK,0);
			led_gpio_contrl(J_FAULT,1);
			vin_ledstatus = 0;
		}
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
        else if(led_cyc>(50/(speed+1))){
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
	static unsigned char delay_play = 5;
    char led_control_io = 0;
    char led_control_speed = 0;
    char i = 0;
    static unsigned int value_last = 0;
    char change_flag = 0;
    static char change_cnt = 0;

	if(delay_play>0)
	{
		delay_play--;
		return ;
	}
	else{
		delay_play = 5;
	}
	
    if(value_last>vout_vcc){
        if((value_last-vout_vcc)>1){
            change_flag = 1;
        }
    }
    else{
        if((vout_vcc - value_last)>1){
            change_flag = 1;
        }
    }
    if(change_flag==0){
        change_cnt ++;
        if(change_cnt>100){
            change_cnt = 0;
            change_flag = 1;
        }
    }
    if(change_flag==1){
        value_last = vout_vcc;
    }
    else{
        vout_vcc = value_last;
    }
    for(i = 0 ;i<5;i++)
    {
        if((vout_vcc>battery_vcc_table[i])&&(vout_vcc<=battery_vcc_table[i+1]))
        {
            led_control_io = i;
            led_control_speed = (vout_vcc - battery_vcc_table[i])*5/(battery_vcc_table[i+1]-battery_vcc_table[i]);
            break;
        }
		if(vout_vcc>JUMP_VOUT_OVER_ERROR){
			led_control_io = 4;
			led_control_speed  = 5;
			break;
		}
    }
    jumpstart_batter_ledcontrl(led_control_io,led_control_speed);
}

void jumpstar_waring_control(void)
{
	#if 0
	static char power_waring_cnt = 0;
	if(power_waring_cnt<1)power_waring_cnt++;
	if(power_waring_cnt==0)return ;
	#endif
	
    junpstar_relay_flag = 0;
	if(jumpstar_work_mode!=WORK_BATTERY)
	{
		if(junpstar_vin_vcc<JUMP_VIN_LOW&&jumpstar_relay_en==0){		  //vin low beep
			digital_ocr_change(DIGITAL_OCR_UV,1);
			jumpstart_been_enbale(1); 
			junpstar_relay_flag |=(0x01<<2);
			junpstar_waring_uv = 1;
			if(junpstar_vin_vcc>JUMP_VIN_LAST_LOW)jumpstar_digital_status=1;
		}
		else if(junpstar_waring_uv==1&&junpstar_vin_vcc<(JUMP_VIN_LOW+1)&&jumpstar_relay_en==0){
			digital_ocr_change(DIGITAL_OCR_UV,1);
			jumpstart_been_enbale(1); 
			junpstar_relay_flag |=(0x01<<2);
			junpstar_waring_uv = 1;
			if(junpstar_vin_vcc>JUMP_VIN_LAST_LOW)jumpstar_digital_status=1;
		}
		else{
			junpstar_waring_uv = 0;
			//digital_ocr_change(DIGITAL_OCR_UV,0);		
			//jumpstart_been_enbale(0);		
		}
	}
	
    if(P_NTC==1&&junpstar_vin_vcc>JUMP_VIN_NOT_ACCESS){       //过温    
        junpstar_relay_flag |=(0x01);
		digital_ocr_change(DIGITAL_OCR_OT,1);		
		jumpstart_been_enbale(1); 
		jumpstar_digital_status = 0;	// ---
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
		
		if(jumpstar_work_mode!=WORK_BATTERY){
			if(junpstar_vin_vcc<JUMP_VIN_LAST_LOW&&jumpstar_relay_en==0){ 	   //vin low beep
				digital_ocr_change(DIGITAL_OCR_UV,1);
				jumpstar_digital_status = 0;	// ---
				jumpstart_been_enbale(1);
				junpstar_relay_flag |=(0x01<<2);
			}
			if(jumpstar_digital_status==0&&junpstar_vin_vcc<(JUMP_VIN_LAST_LOW+1)&&jumpstar_relay_en==0){ 	   //vin low beep
				digital_ocr_change(DIGITAL_OCR_UV,1);
				jumpstar_digital_status = 0;	// ---
				jumpstart_been_enbale(1);
				junpstar_relay_flag |=(0x01<<2);
			}
		}
        if(jumpstar_work_mode!=WORK_JUMP)
        {
        	#if 0
            if(junpstar_out_vcc<JUMP_VOUT_BATTER_ERROR&&junpstar_out_vcc>JUMP_VOUT_SHORT_ERROR)     // battery error
            {
                jumpstart_been_enbale(1);
                jumpstar_digital_status = 0;                        // 
                junpstar_relay_flag |=(0x01<<3);
            }
			#endif
			
            if(junpstar_out_vcc>JUMP_VOUT_OVER_ERROR)          //  battery vcc high
            {
                digital_ocr_change(DIGITAL_OCR_OV,1); 
                jumpstart_been_enbale(1);
                jumpstar_digital_status = 0;    // 
                junpstar_relay_flag |=(0x01<<4);          
            }
			if(jumpstar_digital_status==0&&junpstar_out_vcc>(JUMP_VOUT_OVER_ERROR-1))          //  battery vcc high
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
			#if 0
            if(jumpstar_work_mode==WORK_BATTERY){           
                if(junpstar_out_vcc<JUMP_VOUT_BATTER_MCU)     // can't work
                {
                    digital_ocr_change(DIGITAL_OCR_UV,1);
                    jumpstart_been_enbale(1);
                    jumpstar_digital_status = 0;    // 
                    junpstar_relay_flag |=(0x01<<5);
                }
				if(jumpstar_digital_status==0&&junpstar_out_vcc<(JUMP_VOUT_BATTER_MCU+1))     // can't work
                {
                    digital_ocr_change(DIGITAL_OCR_UV,1);
                    jumpstart_been_enbale(1);
                    jumpstar_digital_status = 0;    // 
                    junpstar_relay_flag |=(0x01<<5);
                }
            }
			#endif
        }
    }
    if(junpstar_relay_flag==0||((jumpstar_work_mode==WORK_KEY)&&(jumpstar_relay_en&(0x01))==0)){
        digital_ocr_change(DIGITAL_OCR_OV,0);
        digital_ocr_change(DIGITAL_OCR_CB,0);
        digital_ocr_change(DIGITAL_OCR_OT,0);
        digital_ocr_change(DIGITAL_OCR_SC,0);		
		digital_ocr_change(DIGITAL_OCR_UV,0);		
        jumpstart_been_enbale(0);
        jumpstar_digital_status = 1;
    }
	if(junpstar_relay_flag!=0){		
		jumpstart_relay_enable(0);
		#if 0
		printf("mode %d waring %d v:%d,%d\r\n",(unsigned int)jumpstar_work_mode,(unsigned int)junpstar_relay_flag,\
			(unsigned int)junpstar_vin_vcc,(unsigned int)junpstar_out_vcc);
		#endif
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
        	#if 0
      		printf("mode %d relay %d v:%d,%d\r\n",(unsigned int)jumpstar_work_mode,(unsigned int)jumpstar_battery_vcc,\
			(unsigned int)junpstar_vin_vcc,(unsigned int)junpstar_out_vcc);
			#endif
			#if 0
            if(jumpstar_battery_vcc>140){
                if(junpstar_out_vcc>jumpstar_battery_vcc+5){
                    batter_star_ok = 1;
                }
            }
            else{
                if(junpstar_out_vcc>140){
                    batter_star_ok = 1;
                }
            }
			#endif
			if(jumpstar_relay_cnt>JUMP_RELAY_CNT_TIME){
				batter_star_ok = 1;
			}
			#if 0
			if(jumpstar_relay_first_vcc>135)
			{
				if(jumpstar_relay_low_vcc<(jumpstar_relay_first_vcc-5)&&\
					jumpstar_relay_cur_vcc>(jumpstar_relay_first_vcc+2)){
					batter_star_ok = 1;
				}
			}
			else{
				if(jumpstar_relay_low_vcc<(jumpstar_relay_first_vcc-5)&&\
					jumpstar_relay_cur_vcc>135){
					batter_star_ok = 1;
				}
			}
			#endif
			
			if(jumpstar_relay_cnt>0&&jumpstar_relay_low_vcc<(jumpstar_relay_first_vcc-5)&&\
				jumpstar_relay_cur_vcc>135){
				batter_star_ok = 1;
			}
			
            if(batter_star_ok==1){
                jumpstart_relay_enable(0);
                judge_disable_cnt = 20;
                batter_star_ok = 0;
                jumpstar_battery_over = 1;
				jumpstar_relay_cnt = 0;
				jumpstar_relay_first_vcc = 0;
				jumpstar_relay_cnt = 0;
				jumpstar_relay_low_vcc = 0;
				jumpstar_relay_cur_vcc = 0;
            }
			#if 0
      		printf("over %d,%d,%d,%d,%d\r\n",(unsigned int)jumpstar_battery_over,(unsigned int)jumpstar_relay_cnt,\
			(unsigned int)jumpstar_relay_first_vcc,(unsigned int)jumpstar_relay_low_vcc,(unsigned int)jumpstar_relay_cur_vcc);
			#endif			
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
    if(power_all_show>0){
        power_all_show--;
		if(power_all_show==150){
			led_gpio_all_on();
		}
		if(power_all_show==0){
			digital_ocr_change(DIGITAL_OCR_OV,0);
			digital_ocr_change(DIGITAL_OCR_CB,0);
			digital_ocr_change(DIGITAL_OCR_OT,0);
			digital_ocr_change(DIGITAL_OCR_SC,0);		
			digital_ocr_change(DIGITAL_OCR_UV,0);
		}
        return;
    }
	
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
        digital_vcc_display(junpstar_out_vcc,jumpstar_digital_status);
        jumpstart_batter_ledstatus(junpstar_out_vcc);
    }
    else if(jumpstar_work_mode==WORK_BOTH)
    {
        jumpstart_vin_ledstatus();
        if(jumpstar_battery_over==1){
            jumpstart_batter_ledstatus(junpstar_out_vcc);
            digital_vcc_display(junpstar_out_vcc,jumpstar_digital_status);
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
	
	#if 0
	vout_show ++;
	if(vout_show>50){
		vout_show = 0;
		printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\r\n",(unsigned int)judge_vcc_arr[0],(unsigned int)judge_vcc_arr[1],\
			(unsigned int)judge_vcc_arr[2],(unsigned int)judge_vcc_arr[3],(unsigned int)judge_vcc_arr[4],(unsigned int)judge_vcc_arr[5],\	
			(unsigned int)judge_vcc_arr[6],(unsigned int)judge_vcc_arr[7],(unsigned int)judge_vcc_arr[8],(unsigned int)judge_vcc_arr[9]);		
		printf("val=%d,avg=%d,max %d\r\n",(unsigned int)mul_value,(unsigned int)mul_avg,(unsigned int)mul_max);
	}
	if(jumpstar_relay_en){
		printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\r\n",(unsigned int)judge_vcc_arr[0],(unsigned int)judge_vcc_arr[1],\
			(unsigned int)judge_vcc_arr[2],(unsigned int)judge_vcc_arr[3],(unsigned int)judge_vcc_arr[4],(unsigned int)judge_vcc_arr[5],\	
			(unsigned int)judge_vcc_arr[6],(unsigned int)judge_vcc_arr[7],(unsigned int)judge_vcc_arr[8],(unsigned int)judge_vcc_arr[9]);		
		printf("val=%d,avg=%d,max %d\r\n",(unsigned int)mul_value,(unsigned int)mul_avg,(unsigned int)mul_max);
	}
	#endif
			
    if((mul_value>(JUMP_JUDGE_VOUT_NUM/2))&&(mul_value<7)&&(mul_max>6)&&mul_avg<JUMP_JUDGE_VOUT_NUM/2){
        judge_disable_cnt = JUMP_JUDGE_VOUT_NUM;
		check_wave_cnt = 0;
        vout_ret = 1;

		#if 0
        check_wave_cnt++;
        if(relay_release_flag==1){
            check_wave_cnt = 0;
            vout_ret = 1;
        }
        if(check_wave_cnt>1){
            check_wave_cnt = 0;
            vout_ret = 1;
        }
		#endif
    }
    else if(mul_avg<JUMP_JUDGE_VOUT_NUM&&mul_max<6&&junpstar_out_vcc>JUMP_VOUT_SHORT_ERROR){
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
unsigned char jumpstart_judge_voutwave(void)     // 0 not judge 1 vout wave  2 vout battey
{
	unsigned char vout_ret = 0;
    if(jumpstar_relay_en==0||relay_release_flag==1)
    {
        if(junpstar_adc_chanle==VIN_ADC){
            junpstar_vin_vcc = app_getadc_value(junpstar_adc_chanle);
            junpstar_adc_chanle = VOUT_ADC;
        }
        else{
            junpstar_out_vcc = app_getadc_value(junpstar_adc_chanle);
            vout_ret = jumpstart_vout_judge();             
            junpstar_adc_chanle = VIN_ADC;
					
            //printf("Out,%d\r\n",junpstar_out_vcc);
        }
    }
	else if(jumpstar_relay_cyc>100){
		jumpstar_relay_cur_vcc = app_getadc_value(VIN_ADC);
		if(jumpstar_relay_first_vcc==0){
			jumpstar_relay_first_vcc = jumpstar_relay_cur_vcc;
			jumpstar_relay_low_vcc = jumpstar_relay_cur_vcc;
		}
		if(jumpstar_relay_cur_vcc<jumpstar_relay_low_vcc){
			jumpstar_relay_low_vcc = jumpstar_relay_cur_vcc;
		}
	}
	return vout_ret;
}

void jumpstart_judge_mode(void)
{
    char voutstatus = 0;
	char jumpstar_work_back = jumpstar_work_mode;
    char key_value = jumpstart_key_handle();
    voutstatus = jumpstart_judge_voutwave();
	#if 0
	if(jumpstar_battery_over==1)
	{
		printf("over %d,%d,%d\r\n",(unsigned int)voutstatus,\
			(unsigned int)junpstar_vin_vcc,(unsigned int)junpstar_out_vcc);
	}
	#endif
	
    if(junpstar_vin_vcc<40){                // not vin
    	if(junpstar_vin_vcc<JUMP_VIN_NOT_ACCESS){
            jumpstar_work_mode = WORK_BATTERY;
            jumpstar_battery_over = 0;
		}
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
				if(jumpstar_work_mode!=WORK_BOTH){
					jumpstar_battery_vcc = junpstar_out_vcc;
				}
                jumpstar_work_mode = WORK_BOTH;
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
	if(jumpstar_work_back!=jumpstar_work_mode){
		printf("Mode %d\r\n",(unsigned int)jumpstar_work_mode);
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

