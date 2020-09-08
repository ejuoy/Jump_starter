#include "MS51_32K.h"
#include "app_type.h"
#include "digital_lcd.h"

// full display
//static char digital_display_arr[5] = {0xfe,0xfd,0xfb,0xf7,0xef};
static char digital_display_arr[5] = {0x00,0x00,0x00,0x00,0x00};

char code digital_num_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void digital_gpio_init(void)
{
	P22_PUSHPULL_MODE;
 	P23_PUSHPULL_MODE;
 	P24_PUSHPULL_MODE;
 	P13_PUSHPULL_MODE;
 	P14_PUSHPULL_MODE;
 	P25_PUSHPULL_MODE;
 	P15_PUSHPULL_MODE;

    LCD_GPIO_1 = 0;
    LCD_GPIO_2 = 0;
    LCD_GPIO_3 = 0;
    LCD_GPIO_4 = 0;
    LCD_GPIO_5 = 0;
    LCD_GPIO_6 = 0;
    LCD_GPIO_7 = 0;
  }

void digital_print_array(void)
{
    printf("dig arry :%x-%x-%x-%x-%x\r\n",(unsigned int )digital_display_arr[0],(unsigned int )digital_display_arr[1],\
        (unsigned int )digital_display_arr[2],(unsigned int )digital_display_arr[3],(unsigned int )digital_display_arr[4]);
}

void test_delay(unsigned int cnt)
{
    while(cnt--);
}
/*
sbit LCD_GPIO_1 = P2^2;
sbit LCD_GPIO_2 = P2^3;
sbit LCD_GPIO_3 = P2^4;
sbit LCD_GPIO_4 = P1^3;
sbit LCD_GPIO_5 = P1^4;
sbit LCD_GPIO_6 = P2^5;
sbit LCD_GPIO_7 = P1^5;
*/

static void digital_gpio_control(char seg,char control)
{
    char pos = 0;       // 0
    if((control>>pos)&0x01){
        P22_PUSHPULL_MODE;
        LCD_GPIO_1 = 1;
    }
    else{
        if(seg==pos){
            P22_PUSHPULL_MODE;
            LCD_GPIO_1 = 0;
        }
        else{
            LCD_GPIO_1 = 0;
            P22_INPUT_MODE;
        }
    }

    pos ++;         //1
    if((control>>1)&0x01){
        P23_PUSHPULL_MODE;
        LCD_GPIO_2 = 1;
    }
    else{
        if(seg==pos){
            P23_PUSHPULL_MODE;
            LCD_GPIO_2 = 0;
        }
        else{
            LCD_GPIO_2 = 1;
            P23_INPUT_MODE;
        }
    }

    pos ++;     //2
    if((control>>2)&0x01){
        P24_PUSHPULL_MODE;
        LCD_GPIO_3 = 1;
    }
    else{
        LCD_GPIO_3 = 0;
        if(seg==pos){
            P24_PUSHPULL_MODE;
            LCD_GPIO_3 = 0;
        }
        else{
            LCD_GPIO_3 = 0;
            P24_INPUT_MODE;
        }
    }

    pos ++;     //3
    if((control>>3)&0x01){
        P13_PUSHPULL_MODE;
        LCD_GPIO_4 = 1;
    }
    else{
        if(seg==pos){
            P13_PUSHPULL_MODE;
            LCD_GPIO_4 = 0;
        }
        else{
            LCD_GPIO_4 = 0;
            P13_INPUT_MODE;
        }
    }

    pos ++;     //4
    if((control>>4)&0x01){
        P14_PUSHPULL_MODE;
        LCD_GPIO_5 = 1;
    }
    else{
        if(seg==pos){
            P14_PUSHPULL_MODE;
            LCD_GPIO_5 = 0;
        }
        else{
            LCD_GPIO_5 = 0;
            P14_INPUT_MODE;
        }
    }

    pos ++;     //5
    if((control>>5)&0x01){
        P25_PUSHPULL_MODE;
        LCD_GPIO_6 = 1;
    }
    else{
        if(seg==pos){
            P25_PUSHPULL_MODE;
            LCD_GPIO_6 = 0;
        }
        else{
            LCD_GPIO_6 = 0;
            P25_INPUT_MODE;
        }
    }

    pos ++;     //6
    if((control>>6)&0x01){
        P15_PUSHPULL_MODE;
        LCD_GPIO_7 = 1;
    }
    else{
        if(seg==pos){
            //printf("7:PUSH 0\r\n");
            P15_PUSHPULL_MODE;
            LCD_GPIO_7 = 0;
        }
        else{
            //printf("7:PUll In\r\n");
            LCD_GPIO_7 = 0;
            P15_INPUT_MODE;
        }
    }
    #if 0
    LCD_GPIO_1 = (control>>0)&0x01;
    LCD_GPIO_2 = (control>>1)&0x01;
    LCD_GPIO_3 = (control>>2)&0x01;
    LCD_GPIO_4 = (control>>3)&0x01;
    LCD_GPIO_5 = (control>>4)&0x01;
    LCD_GPIO_6 = (control>>5)&0x01;
    LCD_GPIO_7 = (control>>6)&0x01;
    #endif

    #if 1
    printf("%x,%d  %bu,%bu,%bu,%bu,%bu,%bu,%bu\r\n",(unsigned int )control,(unsigned int )seg,(control>>0)&0x01,(control>>1)&0x01,(control>>2)&0x01,(control>>3)&0x01,(control>>4)&0x01,\
        (control>>5)&0x01,(control>>6)&0x01);
    #endif
}

void digital_ocr_change(char ocr,char status)
{
    char seg = 0;
    char check_com = 0;
    char com = 0;
    if(ocr>30)return;
    seg = ocr/6;
    com = ocr%6;
    if(com<seg)
    {
        check_com = com;
    }
    else{
        check_com = com + 1;
    }
    printf("ocr=%d %d,seg %d,check_com = %d\r\n",(unsigned int )ocr,(unsigned int )status,(unsigned int )seg,(unsigned int )check_com);
    if(status==0)
    {
        digital_display_arr[seg] &=~(0x01<<seg);
        digital_display_arr[seg] &=~(0x01<<check_com);
    }
    else
    {
        digital_display_arr[seg] &=~(0x01<<seg);
        digital_display_arr[seg] |=(0x01<<check_com);
    }
    //digital_print_array();
}


void digital_num_change(char pos,char num)
{
    char i = 0;
    char status = 0;
    char ocr = 0;
    printf("dig %d-%d,%x\r\n",(unsigned int )pos,(unsigned int )num,(unsigned int )digital_num_table[num]);
    for(i = 0;i<7;i++)
    {
        ocr = pos * 7 + i;
        if(digital_num_table[num]&(0x01<<i)){
            status = 1;
        }
        else{
            status = 0;
        }
        digital_ocr_change(ocr,status);
    }
    digital_print_array();
}

void digital_vcc_display(int value,char status)
{

}

void digital_lcd_test(void)
{
    static char count = 0;
    if(count==4)count = 0;
    printf("count=%d\r\n",(unsigned int)count);
    if(count==0)
    {
        LCD_GPIO_1 = 0;
        LCD_GPIO_2 = 1;
        LCD_GPIO_3 = 1;
        LCD_GPIO_4 = 1;
        LCD_GPIO_5 = 1;
        LCD_GPIO_6 = 1;
        LCD_GPIO_7 = 1;
    }
    else if(count==1)
    {
        LCD_GPIO_1 = 1;
        LCD_GPIO_2 = 0;
        LCD_GPIO_3 = 0;
        LCD_GPIO_4 = 1;
        LCD_GPIO_5 = 1;
        LCD_GPIO_6 = 1;
        LCD_GPIO_7 = 1;
    }
    else if(count==2)
    {
        LCD_GPIO_1 = 1;
        LCD_GPIO_2 = 1;
        LCD_GPIO_3 = 0;
        LCD_GPIO_4 = 0;
        LCD_GPIO_5 = 1;
        LCD_GPIO_6 = 1;
        LCD_GPIO_7 = 1;
    }
    else if(count==3)
    {
        LCD_GPIO_1 = 1;
        LCD_GPIO_2 = 1;
        LCD_GPIO_3 = 1;
        LCD_GPIO_4 = 0;
        LCD_GPIO_5 = 0;
        LCD_GPIO_6 = 1;
        LCD_GPIO_7 = 1;
    }
    count ++;
}

#if 1
void digital_lcd_show(void)
{
	char i = 0;
	for(i = 0;i<5;i++)
	{
        digital_gpio_control(i,digital_display_arr[i]);
	}
}
#endif

#if 0
void digital_lcd_show(void)
{
    static char i = 0;
    digital_gpio_control(i,digital_display_arr[i]);
    i++;
    if(i==5)i=0;
}
#endif

