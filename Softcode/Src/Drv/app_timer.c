#include "MS51_32K.h"
#include "app_type.h"
#include "app_timer.h"
#include "digital_lcd.h"
#include "led.h"
/* if define TIMER0_FSYS_DIV12, timer = (0x1FFF-0x1000)*12/24MHz = 4.08ms */
/* if define TIMER0_FSYS, timer = (0x1FFF-0x0010)/24MHz = 340us */
#define TH0_INIT        0x80 
#define TL0_INIT        0x00
/************************************************************************************************************
*    TIMER 0 interrupt subroutine
************************************************************************************************************/
void Timer0_ISR (void) interrupt 1           /*interrupt address is 0x000B */
{
    _push_(SFRS);

    TH0 = TH0_INIT;
    TL0 = TL0_INIT;
    TF0 = 0 ;
    LED_A_GOOD = ~LED_A_GOOD;
    digital_lcd_show();

    _pop_(SFRS);
}



/************************************************************************************************************
*    app_timer0_init function 
************************************************************************************************************/
void app_timer0_init(void)
{
    ENABLE_TIMER1_MODE0;                           /* Timer 0 mode configuration */
    TIMER0_FSYS_DIV12;

    TH0 = TH0_INIT;
    TL0 = TL0_INIT;
      
    ENABLE_TIMER0_INTERRUPT;                       /* enable Timer0 interrupt  */ 
    ENABLE_GLOBAL_INTERRUPT;                       /* enable interrupts */

    set_TCON_TR0;                                  /* Timer0 run */
}