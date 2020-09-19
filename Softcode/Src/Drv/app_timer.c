#include "MS51_32K.h"
#include "app_type.h"
#include "app_timer.h"
#include "digital_lcd.h"
#include "led.h"
#include "jump_star.h"


/* if define TIMER0_FSYS_DIV12, timer = (0xFFFF-0x1000)*12/24MHz = 36.58ms */
/* if define TIMER0_FSYS, timer = (0xFFFF-0x1000)/24MHz = 2.548ms */
#define TH0_INIT        0xD1 
#define TL0_INIT        0x1F

/************************************************************************************************************
*    TIMER 0 interrupt subroutine
************************************************************************************************************/
void Timer0_ISR (void) interrupt 1           /*interrupt address is 0x000B */
{
    _push_(SFRS);

    TH0 = TH0_INIT;
    TL0 = TL0_INIT;
    TF0 = 0 ;

    //LED_A_GOOD = ~LED_A_GOOD;
    digital_lcd_show_1();
    //if(digital_update_time==0)digital_update_time = 1;
    jumpstart_vout_produce();
	jumpstart_been_wave();
	jumpstart_relay_control();
    jumpstar_key_timecnt();
    _pop_(SFRS);
}



/************************************************************************************************************
*    app_timer0_init function 
************************************************************************************************************/
void app_timer0_init(void)
{
    ENABLE_TIMER0_MODE1;
    TIMER0_FSYS;

    TH0 = TH0_INIT;
    TL0 = TL0_INIT;
    
    ENABLE_TIMER0_INTERRUPT;                       //enable Timer0 interrupt
    ENABLE_GLOBAL_INTERRUPT;                       //enable interrupts
  
    set_TCON_TR0;                                  //Timer0 run
}




