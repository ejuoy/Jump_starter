#include "MS51_32K.h"
#include "app_type.h"
#include "digital_lcd.h"

// full display
//static char digital_display_arr[5] = {0xfe,0xfd,0xfb,0xf7,0xef};
static char digital_display_arr[5] = {0x0C,0xfd,0xfb,0xf7,0xef};

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

static void digital_gpio_control(char control)
{
    LCD_GPIO_1 = (control>>0)&0x01;
    LCD_GPIO_2 = (control>>1)&0x01;
    LCD_GPIO_3 = (control>>2)&0x01;
    LCD_GPIO_4 = (control>>3)&0x01;
    LCD_GPIO_5 = (control>>4)&0x01;
    LCD_GPIO_6 = (control>>5)&0x01;
    LCD_GPIO_7 = (control>>6)&0x01;
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

void digital_lcd_show(void)
{
	char i = 0;
	for(i = 0;i<5;i++)
	{
        digital_gpio_control(digital_display_arr[i]);
	}
}

