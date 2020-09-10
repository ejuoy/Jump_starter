#ifndef _JUMP_START_H_
#define _JUMP_START_H_



sbit P_NTC    = P0^7;
sbit BUZZ_EN  = P0^3;
sbit TEST_ENA = P3^3;
sbit TEST_ENB = P0^1;
sbit RELAY_EN = P0^0;

void jump_star_test(void);
void jumpstart_handle_process(void);

#endif
