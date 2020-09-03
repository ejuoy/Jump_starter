#include "MS51_32K.h"
#include "type.h"
#include "digital_lcd.h"

static char digital_display_arr[4] = {0x00};

void digital_gpio_init(void)
{
	P22_PUSHPULL_MODE;
 	P23_PUSHPULL_MODE;
 	P24_PUSHPULL_MODE;
 	P13_PUSHPULL_MODE;
 	P14_PUSHPULL_MODE;
 	P25_PUSHPULL_MODE;
 	P15_PUSHPULL_MODE;
}

void digital_ocr_change(char ocr)
{

}

void digital_num_change(char pos,char num)
{

}

void digital_vcc_display(int value,char status)
{

}

void digital_lcd_show(void)
{
	char i = 0;
	char j = 0;
	for(i = 0;i<4;i++)
	{
		for(j<0;j<7;j++)
		{

		}
	}
}

