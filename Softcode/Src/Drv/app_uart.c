#include "MS51_32K.h"
#include "app_uart.h"

void app_uart_init(void)
{
   	P10_PUSHPULL_MODE;                      // For I/O toggle display
    P00_INPUT_MODE;
    ENABLE_UART1_TXD_P10;
    ENABLE_UART1_RXD_P00;

    UART_Open(24000000,UART1_Timer3,115200);
	ENABLE_UART1_PRINTF;
}
