/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2019 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Jun/21/2019
//***********************************************************************************************************

#include "MS51_32K.h"

unsigned char uart4rvbuffer=0;
bit uart4rvflag;

void SMC2_ISR(void) interrupt 23          // Vector @  0x9B
{
    _push_(SFRS);
        uart4rvflag = 1;
        uart4rvbuffer = SC2DR;
    _pop_(SFRS);
}
/**
 * @brief       UART3 transfer data without interrupt 
 * @param       u32SysClock , define Fsys value(value)
 * @param       u32Baudrate, Define baudrate (value)
 * @return      none
 * @details     none
 * @example:    UART3_Open(24000000,115200)
 */ 
void UART4_Open(unsigned long u32SysClock, unsigned long u32Baudrate)
{
    set_SC2CR0_SCEN;         /* Enable SC module */
    set_SC2CR1_UARTEN;       /* set as UART mode */
    set_SC2CR1_CLKKEEP;      
    clr_SC2CR0_CONSEL;       /* clr CONSEL and AUTOCEN*/
    clr_SC2CR0_AUTOCEN;
    SC2ETURD0 = LOBYTE(u32SysClock/8/u32Baudrate-1);  /* define baud rate low byte */
    SC2ETURD1 &= 0xF0;                                /* define baud rate high byte */
    SC2ETURD1 |= (HIBYTE(u32SysClock/8/u32Baudrate-1))&0x0F; 
    set_SC2CR1_PBOFF;     //parity bit disable
    SC2CR1&=0xCF;        //datalegth 8bit
    set_SC2CR0_NSB;      //stop bit = 1bit
  }

/**
 * @brief       UART3 receive data without interrupt 
 * @param       baudrate value
 * @return      received data
 * @details     none
 * @example:    temp = UART3_Receive_Data()
 */ 
unsigned char UART4_Receive_Data()
{
    unsigned char c;

    clr_SC2CR0_RXOFF;
    while((SC2TSR&&SET_BIT1)==SET_BIT1);
    c = SC1DR;
    return (c);
}

/**
 * @brief       UART3 transfer data without interrupt 
 * @param       baudrate value
 * @return      none
 * @details     none
 * @example:    UART3_Send_Data(0x55)
 */ 
void UART4_Send_Data(unsigned char c)
{
    clr_SC2CR0_TXOFF;
    SC2DR = c;
    while(!(SC2TSR&SET_BIT3));
    clr_SC2CR0_TXOFF;
}


/**
 * @brief       UART interrupt enable setting 
 * @param       u8UARTPort: UART0/UART1/UART2/UART3 baudrate value
 * @param       u8UARTINTStatus: Disable/Enable
 * @return      none
 * @details     none
 * @note        max baud rate = 1.5MHz when Fsys = 24MHz
 * @example:    UART3_Interrupt(UART3_TXD,Enable)
 */
//void UART4_Interrupt(unsigned char u8UART4INTSel,unsigned char u8UART4INTStatus)
//{
//        switch (u8UART4INTSel)
//        {
//          case UART3_TXD:
//            switch(u8UART4INTStatus)
//            {
//              case Disable: DISABLE_SC2_TRASMIT_BUFFER_EMPTY_INTERRUPT;   break;
//              case Enable: ENABLE_SC2_TRASMIT_BUFFER_EMPTY_INTERRUPT;    break;
//            }break;
//          case UART3_RXD:
//            switch(u8UART4INTStatus)
//            {
//              case Disable:  DISABLE_SC2_RECEIVE_DATA_REACH_INTERRUPT;   break;
//              case Enable:   ENABLE_SC2_RECEIVE_DATA_REACH_INTERRUPT;   break;
//            }break;
//        }
//}


