#ifndef _JUMP_START_H_
#define _JUMP_START_H_



sbit P_NTC    = P0^7;
sbit BUZZ_EN  = P0^3;
sbit TEST_ENA = P3^3;
sbit TEST_ENB = P0^1;
sbit RELAY_EN = P0^0;

enum _JUMP_BATTERY_STATUS_
{
    WORK_BATTERY = 0,
    WORK_JUMP ,
};


#define JUMP_VOUT_AVG_MAX	140
#define JUMP_VOUT_AVG_MIN	110
#define JUMP_VOUT_MUL_VALUE	4

#define JUMP_JUDGE_VOUT_NUM 10

#define JUMP_VIN_LOW   140

#define JUMP_VOUT_SHORT_ERROR   10
#define JUMP_VOUT_OVER_ERROR    157

#define JUMP_VOUT_BATTER_ERROR   40
#define JUMP_VOUT_BATTER_LOW     115
#define JUMP_VOUT_BATTER_MIDDLE  120
#define JUMP_VOUT_BATTER_FULL    130
#define JUMP_VOUT_BATTER_GOOD    139
#define JUMP_VOUT_BATTER_FAULT   150

void jump_star_test(void);
void jumpstart_gpio_init(void);
void jumpstart_handle_process(void);
void jumpstart_vout_produce(void);
void jumpstart_been_control(char enable);
void jumpstart_been_wave(void);
void jumpstart_vout_judge(void);
void jumpstart_control_status(void);
void jumpstart_batter_ledcontrl(char led_io,char speed);
void jumpstart_relay_control(void);


#endif
