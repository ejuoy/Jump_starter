/*--------------------------------------------------------------------------
MS51_32K Function_define.h

All function define inital setting file for Nuvoton MS51 32K series
--------------------------------------------------------------------------*/
typedef bit                   BIT;
typedef unsigned char         UINT8;
typedef unsigned int          UINT16;
typedef unsigned long         UINT32;

typedef unsigned char         uint8_t;
typedef unsigned int          uint16_t;
typedef unsigned long         uint32_t;

extern bit BIT_TMP;

#define Disable  0
#define Enable   1

#define nop _nop_();

//16 --> 8 x 2
#define HIBYTE(v1)              ((UINT8)((v1)>>8))                      //v1 is UINT16
#define LOBYTE(v1)              ((UINT8)((v1)&0xFF))
//8 x 2 --> 16
#define MAKEWORD(v1,v2)         ((((UINT16)(v1))<<8)+(UINT16)(v2))      //v1,v2 is UINT8
//8 x 4 --> 32
#define MAKELONG(v1,v2,v3,v4)   (UINT32)((v1<<32)+(v2<<16)+(v3<<8)+v4)  //v1,v2,v3,v4 is UINT8
//32 --> 16 x 2
#define YBYTE1(v1)              ((UINT16)((v1)>>16))                    //v1 is UINT32
#define YBYTE0(v1)              ((UINT16)((v1)&0xFFFF))
//32 --> 8 x 4
#define TBYTE3(v1)              ((UINT8)((v1)>>24))                     //v1 is UINT32
#define TBYTE2(v1)              ((UINT8)((v1)>>16))
#define TBYTE1(v1)              ((UINT8)((v1)>>8)) 
#define TBYTE0(v1)              ((UINT8)((v1)&0xFF))

#define SET_BIT0        0x01  
#define SET_BIT1        0x02  
#define SET_BIT2        0x04  
#define SET_BIT3        0x08  
#define SET_BIT4        0x10  
#define SET_BIT5        0x20  
#define SET_BIT6        0x40  
#define SET_BIT7        0x80  
#define SET_BIT8        0x0100
#define SET_BIT9        0x0200
#define SET_BIT10       0x0400
#define SET_BIT11       0x0800
#define SET_BIT12       0x1000
#define SET_BIT13       0x2000
#define SET_BIT14       0x4000
#define SET_BIT15       0x8000
                              
#define CLR_BIT0        0xFE  
#define CLR_BIT1        0xFD  
#define CLR_BIT2        0xFB  
#define CLR_BIT3        0xF7  
#define CLR_BIT4        0xEF  
#define CLR_BIT5        0xDF  
#define CLR_BIT6        0xBF  
#define CLR_BIT7        0x7F  
#define CLR_BIT8        0xFEFF
#define CLR_BIT9        0xFDFF
#define CLR_BIT10       0xFBFF
#define CLR_BIT11       0xF7FF
#define CLR_BIT12       0xEFFF
#define CLR_BIT13       0xDFFF
#define CLR_BIT14       0xBFFF
#define CLR_BIT15       0x7FFF


#define FAIL            1
#define PASS            0

#define nop _nop_();

/****************************************************************************/
/* Software loop delay by HIRC, about 3ms 
/****************************************************************************/
#define _delay_()                      \
{                                      \
  unsigned char data i,j;             \
    for (j=0;j<0x1A;j++)               \
    {                                  \
       for (i=0;i<0xff;i++)            \
       {                               \
          _nop_();                     \
       }                               \
    }                                  \
}  

/*****************************************************************************************
* IAP function process 
*****************************************************************************************/
#define     READ_CID                0x0B
#define     READ_DID                0x0C
#define     READ_UID                0x04

#define     PAGE_ERASE_APROM        0x22
#define     BYTE_READ_APROM         0x00
#define     BYTE_PROGRAM_APROM      0x21

#define     PAGE_ERASE_LDROM        0x62
#define     BYTE_READ_LDROM         0x40
#define     BYTE_PROGRAM_LDROM      0x61

#define     PAGE_ERASE_SPROM        0xA2
#define     BYTE_READ_SPROM         0x80
#define     BYTE_PROGRAM_SPROM      0xA1

#define     PAGE_ERASE_CONFIG       0xE2
#define     BYTE_READ_CONFIG        0xC0
#define     BYTE_PROGRAM_CONFIG     0xE1

#define     CID_READ                0x0B
#define     DID_READ                0x0C

#define     PAGE_SIZE               128

/*****************************************************************************************/
/* Interrupt function process */
/*****************************************************************************************/
#define    ENABLE_GLOBAL_INTERRUPT       EA=1            //Check
#define    DISABLE_GLOBAL_INTERRUPT      EA=0
/*ENABLE INTERRUPT*/                     
#define    ENABLE_ADC_INTERRUPT          set_IE_EADC
#define    ENABLE_BOD_INTERRUPT          set_IE_EBOD
#define    ENABLE_UART0_INTERRUPT        set_IE_ES
#define    ENABLE_TIMER1_INTERRUPT       set_IE_ET1      //Check
#define    ENABLE_INT1_INTERRUPT         set_IE_EX1      //Check
#define    ENABLE_TIMER0_INTERRUPT       set_IE_ET0      //Check
#define    ENABLE_INT0_INTERRUPT         set_IE_EX0      //TBD
                                         
#define    ENABLE_TIMER2_INTERRUPT       set_EIE_ET2     //Check
#define    ENABLE_SPI0_INTERRUPT         set_EIE_ESPI   //Check
#define    ENABLE_PWM0_FB_INTERRUPT      set_EIE_EFB  
#define    ENABLE_WDT_INTERRUPT          set_EIE_EWDT  
#define    ENABLE_PWM0_INTERRUPT         set_EIE_EPWM0   //Check
#define    ENABLE_CAPTURE_INTERRUPT      set_EIE_ECAP    //Check
#define    ENABLE_PIN_INTERRUPT          set_EIE_EPI  
#define    ENABLE_I2C_INTERRUPT          set_EIE_EI2C
                                         
#define    ENABLE_PWM3_INTERRUPT         set_EIE1_EPWM3  //Check
#define    ENABLE_PWM2_INTERRUPT         set_EIE1_EPWM2  //Check
#define    ENABLE_PWM1_INTERRUPT         set_EIE1_EPWM1 //Check
#define    ENABLE_WKT_INTERRUPT          set_EIE1_EWKT
#define    ENABLE_TIMER3_INTERRUPT       set_EIE1_ET3    //Check
#define    ENABLE_UART1_INTERRUPT        set_EIE1_ES_1

#define    ENABLE_SC0_AUTO_CONVENTION_ERROR_INTERRUPT    SFRS=2;SC0IE|=0x10;SFRS=0
#define    ENABLE_SC0_BLOCK_GUARD_TIMER_INTERRUPT        SFRS=2;SC0IE|=0x08;SFRS=0
#define    ENABLE_SC0_TRANSFER_ERROR_INTERRUPT           SFRS=2;SC0IE|=0x04;SFRS=0
#define    ENABLE_SC0_TRASMIT_BUFFER_EMPTY_INTERRUPT     SFRS=2;SC0IE|=0x02;SFRS=0
#define    ENABLE_SC0_RECEIVE_DATA_REACH_INTERRUPT       SFRS=2;SC0IE|=0x01;SFRS=0

#define    ENABLE_SC1_AUTO_CONVENTION_ERROR_INTERRUPT    SFRS=2;SC1IE|=0x10;SFRS=0
#define    ENABLE_SC1_BLOCK_GUARD_TIMER_INTERRUPT        SFRS=2;SC1IE|=0x08;SFRS=0
#define    ENABLE_SC1_TRANSFER_ERROR_INTERRUPT           SFRS=2;SC1IE|=0x04;SFRS=0
#define    ENABLE_SC1_TRASMIT_BUFFER_EMPTY_INTERRUPT     SFRS=2;SC1IE|=0x02;SFRS=0
#define    ENABLE_SC1_RECEIVE_DATA_REACH_INTERRUPT       SFRS=2;SC1IE|=0x01;SFRS=0

#define    ENABLE_SC2_AUTO_CONVENTION_ERROR_INTERRUPT    SFRS=2;SC2IE|=0x10;SFRS=0
#define    ENABLE_SC2_BLOCK_GUARD_TIMER_INTERRUPT        SFRS=2;SC2IE|=0x08;SFRS=0
#define    ENABLE_SC2_TRANSFER_ERROR_INTERRUPT           SFRS=2;SC2IE|=0x04;SFRS=0
#define    ENABLE_SC2_TRASMIT_BUFFER_EMPTY_INTERRUPT     SFRS=2;SC2IE|=0x02;SFRS=0
#define    ENABLE_SC2_RECEIVE_DATA_REACH_INTERRUPT       SFRS=2;SC2IE|=0x01;SFRS=0

/*DISABLE INTERRUPT*/ 
#define    DISABLE_ADC_INTERRUPT         clr_IE_EADC
#define    DISABLE_BOD_INTERRUPT         clr_IE_EBOD
#define    DISABLE_UART0_INTERRUPT       clr_IE_ES
#define    DISABLE_TIMER1_INTERRUPT      clr_IE_ET1 
#define    DISABLE_INT1_INTERRUPT        clr_IE_EX1 
#define    DISABLE_TIMER0_INTERRUPT      clr_IE_ET0 
#define    DISABLE_INT0_INTERRUPT        clr_IE_EX0

//ERROR EIE0 -> EIE
#define    DISABLE_TIMER2_INTERRUPT      clr_EIE_ET2         //clr_EIE0_ET2 
#define    DISABLE_SPI0_INTERRUPT        clr_EIE_ESPI        //clr_EIE0_ESPI 
#define    DISABLE_PWM0_FB_INTERRUPT     clr_EIE_EFB         //clr_EIE0_EFB  
#define    DISABLE_WDT_INTERRUPT         clr_EIE_EWDT        //clr_EIE0_EWDT  
#define    DISABLE_PWM0_INTERRUPT        clr_EIE_EPWM0       //clr_EIE0_EPWM0  
#define    DISABLE_CAPTURE_INTERRUPT     clr_EIE_ECAP        //clr_EIE0_ECAP 
#define    DISABLE_PIN_INTERRUPT         clr_EIE_EPI         //clr_EIE0_EPI  
#define    DISABLE_I2C_INTERRUPT         clr_EIE_EI2C        //clr_EIE0_EI2C
          
#define    DISABLE_PWM3_INTERRUPT        clr_EIE1_EPWM3
#define    DISABLE_PWM2_INTERRUPT        clr_EIE1_EPWM2
#define    DISABLE_PWM1_INTERRUPT        clr_EIE1_EPWM1
#define    DISABLE_WKT_INTERRUPT         clr_EIE1_EWKT 
#define    DISABLE_TIMER3_INTERRUPT      clr_EIE1_ET3
#define    DISABLE_UART1_INTERRUPT       clr_EIE1_ES_1 

#define    DISABLE_SC0_AUTO_CONVENTION_ERROR_INTERRUPT    SFRS=2;SC0IE&=0xEF;SFRS=0
#define    DISABLE_SC0_BLOCK_GUARD_TIMER_INTERRUPT        SFRS=2;SC0IE&=0xF7;SFRS=0
#define    DISABLE_SC0_TRANSFER_ERROR_INTERRUPT           SFRS=2;SC0IE&=0xFB;SFRS=0
#define    DISABLE_SC0_TRASMIT_BUFFER_EMPTY_INTERRUPT     SFRS=2;SC0IE&=0xFD;SFRS=0
#define    DISABLE_SC0_RECEIVE_DATA_REACH_INTERRUPT       SFRS=2;SC0IE&=0xFE;SFRS=0

#define    DISABLE_SC1_AUTO_CONVENTION_ERROR_INTERRUPT    SFRS=2;SC1IE&=0xEF;SFRS=0
#define    DISABLE_SC1_BLOCK_GUARD_TIMER_INTERRUPT        SFRS=2;SC1IE&=0xF7;SFRS=0
#define    DISABLE_SC1_TRANSFER_ERROR_INTERRUPT           SFRS=2;SC1IE&=0xFB;SFRS=0
#define    DISABLE_SC1_TRASMIT_BUFFER_EMPTY_INTERRUPT     SFRS=2;SC1IE&=0xFD;SFRS=0
#define    DISABLE_SC1_RECEIVE_DATA_REACH_INTERRUPT       SFRS=2;SC1IE&=0xFE;SFRS=0

#define    DISABLE_SC2_AUTO_CONVENTION_ERROR_INTERRUPT    SFRS=2;SC2IE&=0xEF;SFRS=0
#define    DISABLE_SC2_BLOCK_GUARD_TIMER_INTERRUPT        SFRS=2;SC2IE&=0xF7;SFRS=0
#define    DISABLE_SC2_TRANSFER_ERROR_INTERRUPT           SFRS=2;SC2IE&=0xFB;SFRS=0
#define    DISABLE_SC2_TRASMIT_BUFFER_EMPTY_INTERRUPT     SFRS=2;SC2IE&=0xFD;SFRS=0
#define    DISABLE_SC2_RECEIVE_DATA_REACH_INTERRUPT       SFRS=2;SC2IE&=0xFE;SFRS=0

/****************************************************************************************************************/
/* Define TIMER VALUE setting is base on name with Fsys value
/****************************************************************************************************************/
/* define timer base value Fsys = 16MHz */
#define    TIMER_DIV12_VALUE_10us_FOSC_160000       65535-8        //13*12/16000000 = 10 uS,        // Timer divider = 12 for TM0/TM1 
#define    TIMER_DIV12_VALUE_100us_FOSC_160000      65535-130      //130*12/16000000 = 10 uS,       // Timer divider = 12            
#define    TIMER_DIV12_VALUE_1ms_FOSC_160000        65535-1334     //1334*12/16000000 = 1 mS,       // Timer divider = 12          
#define    TIMER_DIV12_VALUE_10ms_FOSC_160000       65535-13334    //13334*12/16000000 = 10 mS      // Timer divider = 12          
#define    TIMER_DIV12_VALUE_40ms_FOSC_160000       65535-53336    //53336*12/16000000 = 40 ms      // Timer divider = 12         
#define    TIMER_DIV4_VALUE_10us_FOSC_160000        65535-30       //40*4/16000000 = 10 uS,         // Timer divider = 4  for TM2/TM3 
#define    TIMER_DIV4_VALUE_100us_FOSC_160000       65535-400      //400*4/16000000 = 100 us        // Timer divider = 4            
#define    TIMER_DIV4_VALUE_200us_FOSC_160000       65535-800      //800*4/16000000 = 200 us        // Timer divider = 4            
#define    TIMER_DIV4_VALUE_416us_FOSC_160000       65535-1650
#define    TIMER_DIV4_VALUE_500us_FOSC_160000       65535-2000     //2000*4/16000000 = 500 us       // Timer divider = 4            
#define    TIMER_DIV4_VALUE_1ms_FOSC_160000         65535-4000     //4000*4/16000000 = 1 mS,        // Timer divider = 4            
#define    TIMER_DIV4_VALUE_10ms_FOSC_160000        65535-40000    //40000*4/16000000 = 10 mS,      // Timer divider = 4         
#define    TIMER_DIV16_VALUE_10ms_FOSC_160000       65535-10000    //10000*16/16000000 = 10 ms      // Timer  divider = 16        
#define    TIMER_DIV64_VALUE_30ms_FOSC_160000       65535-7500     //7500*64/16000000 = 30 ms       // Timer divider = 64           
#define    TIMER_DIV128_VALUE_1ms_FOSC_160000       65535-125      //125*128/16000000 = 1 ms        // Timer divider = 128            
#define    TIMER_DIV128_VALUE_10ms_FOSC_160000      65535-1250     //1250*128/16000000 = 10 ms      // Timer divider = 128           
#define    TIMER_DIV128_VALUE_100ms_FOSC_160000     65535-12500    //12500*128/16000000 = 100 ms    // Timer divider = 128        
#define    TIMER_DIV128_VALUE_200ms_FOSC_160000     65535-25000    //25000*128/16000000 = 200 ms    // Timer divider = 128        
#define    TIMER_DIV256_VALUE_500ms_FOSC_160000     65535-31250    //31250*256/16000000 = 500 ms    // Timer divider = 256         
#define    TIMER_DIV512_VALUE_100ms_FOSC_160000     65535-3125     //3125*512/16000000 = 100ms.     // Timer Divider = 512        
#define    TIMER_DIV512_VALUE_1s_FOSC_160000        65535-31250    //31250*512/16000000 = 1 s.      // Timer Divider = 512        

/* define timer base value Fsys = 16.6MHz */
#define    TIMER_DIV12_VALUE_10us_FOSC_166000       65535-14       //14*12/16600000 = 10 uS,        // Timer divider = 12 for TM0/TM1
#define    TIMER_DIV12_VALUE_100us_FOSC_166000      65535-138      //138*12/16600000 = 100 uS,      // Timer divider = 12           
#define    TIMER_DIV12_VALUE_1ms_FOSC_166000        65535-1384     //1384*12/16600000 = 1 mS,       // Timer divider = 12            
#define    TIMER_DIV12_VALUE_10ms_FOSC_166000       65535-13834    //13834*12/16600000 = 10 mS      // Timer divider = 12            
#define    TIMER_DIV12_VALUE_40ms_FOSC_166000       65535-55333    //55333*12/16600000 = 40 ms      // Timer divider = 12           
#define    TIMER_DIV4_VALUE_10us_FOSC_166000        65535-41       //41*4/16600000 = 10 uS,         // Timer divider = 4  for TM2/TM3 
#define    TIMER_DIV4_VALUE_100us_FOSC_166000       65535-415      //415*4/16600000 = 100 us        // Timer divider = 4            
#define    TIMER_DIV4_VALUE_200us_FOSC_166000       65535-830      //830*4/16600000 = 200 us        // Timer divider = 4            
#define    TIMER_DIV4_VALUE_500us_FOSC_166000       65535-2075     //2075*4/16600000 = 500 us       // Timer divider = 4              
#define    TIMER_DIV4_VALUE_1ms_FOSC_166000         65535-4150     //4150*4/16600000 = 1 mS,        // Timer divider = 4              
#define    TIMER_DIV16_VALUE_10ms_FOSC_166000       65535-10375    //10375*16/16600000 = 10 ms      // Timer  divider = 16          
#define    TIMER_DIV64_VALUE_30ms_FOSC_166000       65535-7781     //7781*64/16600000 = 30 ms       // Timer divider = 64             
#define    TIMER_DIV128_VALUE_100ms_FOSC_166000     65535-12969    //12969*128/16600000 = 100 ms    // Timer divider = 128          
#define    TIMER_DIV128_VALUE_200ms_FOSC_166000     65535-25937    //25937*128/16600000 = 200 ms    // Timer divider = 128          
#define    TIMER_DIV256_VALUE_500ms_FOSC_166000     65535-32422    //32422*256/16600000 = 500 ms    // Timer divider = 256           
#define    TIMER_DIV512_VALUE_1s_FOSC_166000        65535-32421    //32421*512/16600000 = 1 s.      // Timer Divider = 512          
/* define timer base value Fsys = 24 MHz*/
#define    TIMER_DIV12_VALUE_10us_FOSC_240000       65535-20       //20*12/24000000 = 10 uS,        // Timer divider = 12        
#define    TIMER_DIV12_VALUE_100us_FOSC_240000      65535-200      //130*12/16000000 = 10 uS,       // Timer divider = 12        
#define    TIMER_DIV12_VALUE_1ms_FOSC_240000        65535-2000     //2000*12/24000000 = 1 mS,       // Timer divider = 12        
#define    TIMER_DIV12_VALUE_10ms_FOSC_240000       65535-20000    //2000*12/24000000 = 10 mS       // Timer divider = 12       
#define    TIMER_DIV4_VALUE_10us_FOSC_240000        65535-60       //60*4/24000000 = 10 uS,         // Timer divider = 4        
#define    TIMER_DIV4_VALUE_100us_FOSC_240000       65535-600      //600*4/24000000 = 100 us        // Timer divider = 4          
#define    TIMER_DIV4_VALUE_200us_FOSC_240000       65535-1200     //1200*4/24000000 = 200 us       // Timer divider = 4          
#define    TIMER_DIV4_VALUE_500us_FOSC_240000       65535-3000     //3000*4/24000000 = 500 us       // Timer divider = 4          
#define    TIMER_DIV4_VALUE_1ms_FOSC_240000         65535-6000     //6000*4/24000000 = 1 mS,        // Timer divider = 4        
#define    TIMER_DIV4_VALUE_10ms_FOSC_240000        65535-60000    //60000*4/2400000 = 10 ms                                    
#define    TIMER_DIV16_VALUE_10ms_FOSC_240000       65535-15000    //15000*16/24000000 = 10 ms      // Timer divider = 16       
#define    TIMER_DIV64_VALUE_30ms_FOSC_240000       65535-11250    //11250*64/24000000 = 30 ms      // Timer divider = 64       
#define    TIMER_DIV128_VALUE_1ms_FOSC_240000       65535-187      //187*128/24000000 = 1 ms        // Timer divider = 128        
#define    TIMER_DIV128_VALUE_10ms_FOSC_240000      65535-1875     //1875*128/24000000 = 10 ms      // Timer divider = 128       
#define    TIMER_DIV128_VALUE_100ms_FOSC_240000     65535-18750    //18750*128/24000000 = 100 ms    // Timer divider = 128    
#define    TIMER_DIV128_VALUE_200ms_FOSC_240000     65535-37500    //37500*128/24000000 = 200 ms    // Timer divider = 128    
#define    TIMER_DIV256_VALUE_500ms_FOSC_240000     65535-46875    //46875*256/24000000 = 500 ms    // Timer divider = 256   
#define    TIMER_DIV512_VALUE_10ms_FOSC_240000      65535-468      //468*512/24000000 = 100 ms      // Timer divider = 512     
#define    TIMER_DIV512_VALUE_100ms_FOSC_240000     65535-4687     //4687*512/24000000 = 100 ms     // Timer divider = 512     
#define    TIMER_DIV512_VALUE_500ms_FOSC_240000     65535-23437    //4687*512/24000000 = 500 ms     // Timer divider = 512    
#define    TIMER_DIV512_VALUE_1s_FOSC_240000        65535-46875    //46875*512/24000000 = 1 s.      // Timer Divider = 512    

/*******************************************************************************
*   TIMER Function Define
********************************************************************************/
#define    ENABLE_CLOCK_OUT                     set_CKCON_CLOEN;
/*-------------------- Timer0 basic define --------------------*/
#define    ENABLE_TIMER0_MODE0                  SFRS=0;TMOD&=0xF0               
#define    ENABLE_TIMER0_MODE1                  SFRS=0;TMOD&=0xF0;TMOD|=0x01
#define    ENABLE_TIMER0_MODE2                  SFRS=0;TMOD&=0xF0;TMOD|=0x02
#define    ENABLE_TIMER0_MODE3                  SFRS=0;TMOD&=0xF0;TMOD|=0x03
#define    TIMER0_FSYS                          set_CKCON_T0M
#define    TIMER0_FSYS_DIV12                    clr_CKCON_T0M

/*-------------------- Timer1 basic define --------------------*/
#define    ENABLE_TIMER1_MODE0                  SFRS=0;TMOD&=0x0F             
#define    ENABLE_TIMER1_MODE1                  SFRS=0;TMOD&=0x0F;TMOD|=0x10  
#define    ENABLE_TIMER1_MODE2                  SFRS=0;TMOD&=0x0F;TMOD|=0x20  
#define    ENABLE_TIMER1_MODE3                  SFRS=0;TMOD&=0x0F;TMOD|=0x30  
#define    TIMER1_FSYS                          set_CKCON_T1M                 
#define    TIMER1_FSYS_DIV12                    clr_CKCON_T1M                 

//-------------------- Timer2 function define --------------------
#define    TIMER2_DIV_4                         SFRS=0;T2MOD|=0x10;T2MOD&=0x9F
#define    TIMER2_DIV_16                        SFRS=0;T2MOD|=0x20;T2MOD&=0xAF
#define    TIMER2_DIV_32                        SFRS=0;T2MOD|=0x30;T2MOD&=0xBF
#define    TIMER2_DIV_64                        SFRS=0;T2MOD|=0x40;T2MOD&=0xCF
#define    TIMER2_DIV_128                       SFRS=0;T2MOD|=0x50;T2MOD&=0xDF
#define    TIMER2_DIV_256                       SFRS=0;T2MOD|=0x60;T2MOD&=0xEF
#define    TIMER2_DIV_512                       SFRS=0;T2MOD|=0x70
#define    TIMER2_Auto_Reload_Delay_Mode        SFRS=0;T2CON&=0xFE;T2MOD|=0x80;T2MOD|=0x08
#define    TIMER2_Compare_Capture_Mode          SFRS=0;T2CON|=0x01;T2MOD&=0x7F;T2MOD|=0x04
           
#define    TIMER2_CAP0_Capture_Mode             SFRS=0;T2CON&=0xFE;T2MOD=0x89 
#define    TIMER2_CAP1_Capture_Mode             SFRS=0;T2CON&=0xFE;T2MOD=0x8A 
#define    TIMER2_CAP2_Capture_Mode             SFRS=0;T2CON&=0xFE;T2MOD=0x8B 
/*-------------------- Timer3 basic define --------------------*/                      
#define    TIMER3_DIV_1                         SFRS=0;T3CON&=0xF8;                                             
#define    TIMER3_DIV_2                         SFRS=0;T3CON&=0xF8;T3CON|=0x0                        
#define    TIMER3_DIV_4                         SFRS=0;T3CON&=0xF8;T3CON|=0x0                          
#define    TIMER3_DIV_8                         SFRS=0;T3CON&=0xF8;T3CON|=0x0                         
#define    TIMER3_DIV_16                        SFRS=0;T3CON&=0xF8;T3CON|=0x0                         
#define    TIMER3_DIV_32                        SFRS=0;T3CON&=0xF8;T3CON|=0x0                         
#define    TIMER3_DIV_64                        SFRS=0;T3CON&=0xF8;T3CON|=0x0                         
#define    TIMER3_DIV_128                       SFRS=0;T3CON|=0x07
//-------------------- Timer2 Capture define --------------------
//--- Falling Edge -----
#define  IC0_P12_CAP0_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x00;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC1_P11_CAP0_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x01;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC2_P10_CAP0_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x02;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC3_P00_CAP0_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x03;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC3_P04_CAP0_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x04;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC4_P01_CAP0_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x05;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC5_P03_CAP0_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x06;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC6_P05_CAP0_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x07;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC7_P15_CAP0_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x08;CAPCON0|=0x10;CAPCON2|=0x10
                                                
#define  IC0_P12_CAP1_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x00;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC1_P11_CAP1_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x10;CAPCON0|=0x20;CAPCON0|=0x20
#define  IC2_P10_CAP1_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x20;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC3_P00_CAP1_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x30;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC3_P04_CAP1_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x40;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC4_P01_CAP1_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x50;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC5_P03_CAP1_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x60;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC6_P05_CAP1_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x70;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC7_P15_CAP1_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x80;CAPCON0|=0x20;CAPCON2|=0x20
                                                
#define  IC0_P12_CAP2_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON3|=0x00;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC1_P11_CAP2_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x10;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC2_P10_CAP2_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x20;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC3_P00_CAP2_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x30;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC3_P04_CAP2_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x40;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC4_P01_CAP2_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x50;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC5_P03_CAP2_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x60;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC6_P05_CAP2_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x70;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC7_P15_CAP2_FALLINGEDGE_CAPTURE       SFRS=0;CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x80;CAPCON0|=0x40;CAPCON2|=0x40
                                                
//----- Rising edge ----//CAPTURE               
#define  IC0_P12_CAP0_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3|=0x00;CAPCON3&=0xF0;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC1_P11_CAP0_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x01;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC2_P10_CAP0_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x02;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC3_P00_CAP0_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x03;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC3_P04_CAP0_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x04;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC4_P01_CAP0_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x05;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC5_P03_CAP0_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x06;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC6_P05_CAP0_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x07;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC7_P15_CAP0_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x08;CAPCON0|=0x10;CAPCON2|=0x10
                                                
#define  IC0_P12_CAP1_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x00;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC1_P11_CAP1_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x10;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC2_P10_CAP1_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x20;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC3_P00_CAP1_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x30;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC3_P04_CAP1_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x40;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC4_P01_CAP1_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x50;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC5_P03_CAP1_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x60;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC6_P05_CAP1_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x70;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC7_P15_CAP1_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x80;CAPCON0|=0x20;CAPCON2|=0x20
                                                
#define  IC0_P12_CAP2_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x00;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC1_P11_CAP2_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x01;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC2_P10_CAP2_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x02;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC3_P00_CAP2_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x03;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC3_P04_CAP2_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x04;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC4_P01_CAP2_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x05;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC5_P03_CAP2_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x06;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC6_P05_CAP2_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x07;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC7_P15_CAP2_RISINGEDGE_CAPTURE        SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x08;CAPCON0|=0x40;CAPCON2|=0x40
                                                
//-----BOTH  edge ----                          
#define  IC0_P12_CAP0_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x00;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC1_P11_CAP0_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x01;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC2_P10_CAP0_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x02;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC3_P00_CAP0_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x03;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC3_P04_CAP0_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x04;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC4_P01_CAP0_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x05;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC5_P03_CAP0_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x06;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC6_P05_CAP0_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x07;CAPCON0|=0x10;CAPCON2|=0x10
#define  IC7_P15_CAP0_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x08;CAPCON0|=0x10;CAPCON2|=0x10
                                                
#define  IC0_P12_CAP1_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x00;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC1_P11_CAP1_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x10;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC2_P10_CAP1_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x20;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC3_P00_CAP1_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x30;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC3_P04_CAP1_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x40;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC4_P01_CAP1_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x50;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC5_P03_CAP1_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x60;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC6_P05_CAP1_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x70;CAPCON0|=0x20;CAPCON2|=0x20
#define  IC7_P15_CAP1_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x80;CAPCON0|=0x20;CAPCON2|=0x20
                                                
#define  IC0_P12_CAP2_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x00;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC1_P11_CAP2_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x01;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC2_P10_CAP2_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x02;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC3_P00_CAP2_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x03;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC3_P04_CAP2_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x04;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC4_P01_CAP2_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x05;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC5_P03_CAP2_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x06;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC6_P05_CAP2_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x07;CAPCON0|=0x40;CAPCON2|=0x40
#define  IC7_P15_CAP2_BOTHEDGE_CAPTURE          SFRS=0;CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x08;CAPCON0|=0x40;CAPCON2|=0x40
                                                
#define  TIMER2_IC2_DISABLE                     SFRS=0;CAPCON0&=0xBF         
#define  TIMER2_IC1_DISABLE                     SFRS=0;CAPCON0&=0xDF        
#define  TIMER2_IC0_DISABLE                     SFRS=0;CAPCON0&=0xEF  
     
/*****************************************************************************************/
/* For PWM setting                                                                       */
/*****************************************************************************************/
/*--------- PMW clock source select define ---------------------*/                
#define    ALL_PWM_CLOCK_FSYS                   SFRS=0;CKCON&=0xBF
#define    ALL_PWM_CLOCK_TIMER1                 SFRS=0;CKCON|=0x40
/*--------- PMW0 Setting ---------------------*/ 
/*--------- PWM type define ------------------------------------*/ 
#define    PWM0_EDGE_TYPE                       SFRS=0;PWM0CON1&=0xEF
#define    PWM0_CENTER_TYPE                     SFRS=0;PWM0CON1|=0x10      
/*--------- PWM mode define ------------------------------------*/ 
#define    PWM0_IMDEPENDENT_MODE                SFRS=0;PWM0CON1&=0x3F                
#define    PWM0_COMPLEMENTARY_MODE              SFRS=0;PWM0CON1&=0x3F;PWM0CON1|=0x40 
#define    PWM0_SYNCHRONIZED_MODE               SFRS=0;PWM0CON1&=0x3F;PWM0CON1|=0x80 
#define    PWM0_GP_MODE_ENABLE                  SFRS=0;PWM0CON1|=0x20                
#define    PWM0_GP_MODE_DISABLE                 SFRS=0;PWM0CON1&=0xDF                              
/*--------- PWM clock devide define ----------------------------*/
#define    PWM0_CLOCK_DIV_1                     SFRS=0;PWM0CON1&=0xF8               
#define    PWM0_CLOCK_DIV_2                     SFRS=0;PWM0CON1&=0xF8;PWM0CON1|=0x01
#define    PWM0_CLOCK_DIV_4                     SFRS=0;PWM0CON1&=0xF8;PWM0CON1|=0x02
#define    PWM0_CLOCK_DIV_8                     SFRS=0;PWM0CON1&=0xF8;PWM0CON1|=0x03
#define    PWM0_CLOCK_DIV_16                    SFRS=0;PWM0CON1&=0xF8;PWM0CON1|=0x04
#define    PWM0_CLOCK_DIV_32                    SFRS=0;PWM0CON1&=0xF8;PWM0CON1|=0x05
#define    PWM0_CLOCK_DIV_64                    SFRS=0;PWM0CON1&=0xF8;PWM0CON1|=0x06
#define    PWM0_CLOCK_DIV_128                   SFRS=0;PWM0CON1|=0x07               
/*--------- PWM ouput GPIO select define ------------------------------*/                 
#define    ENABLE_PWM0_CH5_P15_OUTPUT           set_PIOCON1_PIO15
#define    ENABLE_PWM0_CH5_P03_OUTPUT           set_PIOCON0_PIO03
#define    ENABLE_PWM0_CH4_P01_OUTPUT           set_PIOCON0_PIO01
#define    ENABLE_PWM0_CH3_P04_OUTPUT           set_PIOCON1_PIO04
#define    ENABLE_PWM0_CH3_P00_OUTPUT           set_PIOCON0_PIO00
#define    ENABLE_PWM0_CH2_P05_OUTPUT           set_PIOCON1_PIO05
#define    ENABLE_PWM0_CH2_P10_OUTPUT           set_PIOCON0_PIO10
#define    ENABLE_PWM0_CH1_P14_OUTPUT           set_PIOCON1_PIO14
#define    ENABLE_PWM0_CH1_P11_OUTPUT           set_PIOCON0_PIO11
#define    ENABLE_PWM0_CH0_P12_OUTPUT           set_PIOCON0_PIO12
#define    ENABLE_ALL_PWM0_OUTPUT               SFRS=0;PIOCON0=0xFF;SFRS=1;PIOCON1=0xFF                  
                                                
#define    DISABLE_PWM0_CH5_P15_OUTPUT          clr_PIOCON1_PIO15
#define    DISABLE_PWM0_CH5_P03_OUTPUT          clr_PIOCON0_PIO03
#define    DISABLE_PWM0_CH4_P01_OUTPUT          clr_PIOCON0_PIO01
#define    DISABLE_PWM0_CH3_P04_OUTPUT          clr_PIOCON1_PIO04
#define    DISABLE_PWM0_CH3_P00_OUTPUT          clr_PIOCON0_PIO00
#define    DISABLE_PWM0_CH2_P05_OUTPUT          clr_PIOCON1_PIO05
#define    DISABLE_PWM0_CH2_P10_OUTPUT          clr_PIOCON0_PIO10
#define    DISABLE_PWM0_CH1_P14_OUTPUT          clr_PIOCON1_PIO14
#define    DISABLE_PWM0_CH1_P11_OUTPUT          clr_PIOCON0_PIO11
#define    DISABLE_PWM0_CH0_P12_OUTPUT          clr_PIOCON0_PIO12
#define    DISABLE_ALL_PWM0_OUTPUT              SFRS=0;PIOCON0=0x00;SFRS=1;PIOCON1=0x00
/*--------- PWM0 I/O Polarity Control ---------------------------*/ 
#define    PWM0_CH5_OUTPUT_INVERSE              SFRS=0;PNP|=0x20     
#define    PWM0_CH4_OUTPUT_INVERSE              SFRS=0;PNP|=0x10        
#define    PWM0_CH3_OUTPUT_INVERSE              SFRS=0;PNP|=0x08        
#define    PWM0_CH2_OUTPUT_INVERSE              SFRS=0;PNP|=0x04        
#define    PWM0_CH1_OUTPUT_INVERSE              SFRS=0;PNP|=0x02        
#define    PWM0_CH0_OUTPUT_INVERSE              SFRS=0;PNP|=0x01        
#define    PWM0_OUTPUT_ALL_INVERSE              SFRS=0;PNP=0xFF 
#define    PWM0_CH5_OUTPUT_NORMAL               SFRS=0;PNP&=0xDF       
#define    PWM0_CH4_OUTPUT_NORMAL               SFRS=0;PNP&=0xEF       
#define    PWM0_CH3_OUTPUT_NORMAL               SFRS=0;PNP&=0xF7       
#define    PWM0_CH2_OUTPUT_NORMAL               SFRS=0;PNP&=0xFB       
#define    PWM0_CH1_OUTPUT_NORMAL               SFRS=0;PNP&=0xFD       
#define    PWM0_CH0_OUTPUT_NORMAL               SFRS=0;PNP&=0xFE       
#define    PWM0_OUTPUT_ALL_NORMAL               SFRS=0;PNP=0x00 
/*--------- PMM0 Mask Output ENABLE -----------------------*/       
#define    ENABLE_PWM0_CH0_MASK                 SFRS=0;PWM0MEN|=0x01                                        
#define    ENABLE_PWM0_CH1_MASK                 SFRS=0;PWM0MEN|=0x02                                         
#define    ENABLE_PWM0_CH2_MASK                 SFRS=0;PWM0MEN|=0x04                                       
#define    ENABLE_PWM0_CH3_MASK                 SFRS=0;PWM0MEN|=0x08                                         
#define    ENABLE_PWM0_CH4_MASK                 SFRS=0;PWM0MEN|=0x10                                         
#define    ENABLE_PWM0_CH5_MASK                 SFRS=0;PWM0MEN|=0x20                                         
                                                                                                        
#define    DISABLE_PWM0_CH0_MASK                SFRS=0;PWM0MEN&=0xFE                                         
#define    DISABLE_PWM0_CH1_MASK                SFRS=0;PWM0MEN&=0xFD                                         
#define    DISABLE_PWM0_CH2_MASK                SFRS=0;PWM0MEN&=0xFB                                         
#define    DISABLE_PWM0_CH3_MASK                SFRS=0;PWM0MEN&=0xF7                                         
#define    DISABLE_PWM0_CH4_MASK                SFRS=0;PWM0MEN&=0xEF                                         
#define    DISABLE_PWM0_CH5_MASK                SFRS=0;PWM0MEN&=0xDF                                         
/*--------- PMM0 Mask Output Value -----------------------*/ 
#define    PWM0_CH0_MASK_0                      SFRS=0;PWM0MD&=0xFE 
#define    PWM0_CH1_MASK_0                      SFRS=0;PWM0MD&=0xFD 
#define    PWM0_CH2_MASK_0                      SFRS=0;PWM0MD&=0xFB 
#define    PWM0_CH3_MASK_0                      SFRS=0;PWM0MD&=0xF7 
#define    PWM0_CH4_MASK_0                      SFRS=0;PWM0MD&=0xEF 
#define    PWM0_CH5_MASK_0                      SFRS=0;PWM0MD&=0xDF 
                                                
#define    PWM0_CH0_MASK_1                      SFRS=0;PWM0MD|=0x01 
#define    PWM0_CH1_MASK_1                      SFRS=0;PWM0MD|=0x02 
#define    PWM0_CH2_MASK_1                      SFRS=0;PWM0MD|=0x04 
#define    PWM0_CH3_MASK_1                      SFRS=0;PWM0MD|=0x08  
#define    PWM0_CH4_MASK_1                      SFRS=0;PWM0MD|=0x10  
#define    PWM0_CH5_MASK_1                      SFRS=0;PWM0MD|=0x20  
/*--------- PMW0 interrupt setting ------------------------------*/ 
#define    PWM0_FALLING_INT                     SFRS=1;PWM0INTC&=0xCF               ;SFRS=0
#define    PWM0_RISING_INT                      SFRS=1;PWM0INTC&=0xCF;PWM0INTC|=0x10;SFRS=0
#define    PWM0_CENTRAL_POINT_INT               SFRS=1;PWM0INTC&=0xCF;PWM0INTC|=0x20;SFRS=0
#define    PWM0_PERIOD_END_INT                  SFRS=1;PWM0INTC|=0x30               ;SFRS=0
/*--------- PWM0 interrupt pin select ---------------------------*/ 
#define    PWM0_CH0_INTERRUPT_SELECT            SFRS=1;PWM0INTC&=0xF8               ;SFRS=0
#define    PWM0_CH1_INTERRUPT_SELECT            SFRS=1;PWM0INTC&=0xF8;PWM0INTC|=0x01;SFRS=0
#define    PWM0_CH2_INTERRUPT_SELECT            SFRS=1;PWM0INTC&=0xF8;PWM0INTC|=0x02;SFRS=0
#define    PWM0_CH3_INTERRUPT_SELECT            SFRS=1;PWM0INTC&=0xF8;PWM0INTC|=0x03;SFRS=0
#define    PWM0_CH4_INTERRUPT_SELECT            SFRS=1;PWM0INTC&=0xF8;PWM0INTC|=0x04;SFRS=0
#define    PWM0_CH5_INTERRUPT_SELECT            SFRS=1;PWM0INTC&=0xF8;PWM0INTC|=0x05;SFRS=0
/*--------- PWM0 Dead time setting ------------------------------*/ 
#define    ENABLE_PWM0_CH45_DEADTIME            SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PWM0DTEN|=0x04;EA=BIT_TMP
#define    ENABLE_PWM0_CH34_DEADTIME            SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PWM0DTEN|=0x02;EA=BIT_TMP
#define    ENABLE_PWM0_CH01_DEADTIME            SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PWM0DTEN|=0x01;EA=BIT_TMP

/*--------- PMW1 Setting ---------------------*/ 
/*--------- PWM type define ------------------------------------*/ 
#define    PWM1_EDGE_TYPE                     SFRS=2;PWM1CON1&=0xEF;SFRS=0                               
#define    PWM1_CENTER_TYPE                   SFRS=2;PWM1CON1|=0x10;SFRS=0               
/*--------- PWM1 mode define ------------------------------------*/ 
#define    PWM1_IMDEPENDENT_MODE              SFRS=2;PWM1CON1&=0x3F               ;SFRS=0
#define    PWM1_COMPLEMENTARY_MODE            SFRS=2;PWM1CON1&=0x3F;PWM1CON1|=0x40;SFRS=0
#define    PWM1_SYNCHRONIZED_MODE             SFRS=2;PWM1CON1&=0x3F;PWM1CON1|=0x80;SFRS=0
//--------- PWM1 clock devide define ----------------------------
#define    PWM1_CLOCK_DIV_2                   SFRS=2;PWM1CON1&=0xF8;PWM1CON1|=0x01;SFRS=0
#define    PWM1_CLOCK_DIV_4                   SFRS=2;PWM1CON1&=0xF8;PWM1CON1|=0x02;SFRS=0
#define    PWM1_CLOCK_DIV_8                   SFRS=2;PWM1CON1&=0xF8;PWM1CON1|=0x03;SFRS=0
#define    PWM1_CLOCK_DIV_16                  SFRS=2;PWM1CON1&=0xF8;PWM1CON1|=0x04;SFRS=0
#define    PWM1_CLOCK_DIV_32                  SFRS=2;PWM1CON1&=0xF8;PWM1CON1|=0x05;SFRS=0
#define    PWM1_CLOCK_DIV_64                  SFRS=2;PWM1CON1&=0xF8;PWM1CON1|=0x06;SFRS=0
#define    PWM1_CLOCK_DIV_128                 SFRS=2;PWM1CON1|=0x07               ;SFRS=0
/*--------- PWM1 ouput GPIO select define ------------------------------*/  
#define    ENABLE_PWM1_CH0_P23_OUTPUT         SFRS=2;AUXR4&=0xFC;AUXR4|=0x01;set_PIOCON2_PIO23;SFRS=0
#define    ENABLE_PWM1_CH0_P12_OUTPUT         SFRS=2;AUXR4&=0xFC;AUXR4|=0x02;set_PIOCON0_PIO12;SFRS=0
#define    ENABLE_PWM1_CH1_P22_OUTPUT         SFRS=2;AUXR4&=0xF3;AUXR4|=0x04;set_PIOCON2_PIO22;SFRS=0
#define    ENABLE_PWM1_CH1_P14_OUTPUT         SFRS=2;AUXR4&=0xF3;AUXR4|=0x08;set_PIOCON1_PIO14;SFRS=0
#define    ENABLE_PWM1_CH1_P11_OUTPUT         SFRS=2;AUXR4&=0xF3;AUXR4|=0x0C;set_PIOCON0_PIO11;SFRS=0

#define    DISABLE_PWM1_CH0_P23_OUTPUT        SFRS=2;AUXR4&=0xFC;clr_PIOCON2_PIO23;SFRS=0
#define    DISABLE_PWM1_CH0_P12_OUTPUT        SFRS=2;AUXR4&=0xFC;clr_PIOCON0_PIO12;SFRS=0
#define    DISABLE_PWM1_CH1_P22_OUTPUT        SFRS=2;AUXR4&=0xF3;clr_PIOCON2_PIO22;SFRS=0
#define    DISABLE_PWM1_CH1_P14_OUTPUT        SFRS=2;AUXR4&=0xF3;clr_PIOCON1_PIO14;SFRS=0
#define    DISABLE_PWM1_CH1_P11_OUTPUT        SFRS=2;AUXR4&=0xF3;clr_PIOCON0_PIO11;SFRS=0
/*--------- PMM1 Mask Output ENABLE -----------------------*/       
#define    ENABLE_PWM1_CH0_MASK               SFRS=2;PWM1MEN|=0x01;SFRS=0                                      
#define    ENABLE_PWM1_CH1_MASK               SFRS=2;PWM1MEN|=0x02;SFRS=0                                      

#define    DISABLE_PWM1_CH0_MASK              SFRS=2;PWM1MEN&=0xFE;SFRS=0                                      
#define    DISABLE_PWM1_CH1_MASK              SFRS=2;PWM1MEN&=0xFD;SFRS=0                                      
/*--------- PMM1 Mask Output Value -----------------------*/ 
#define    PWM1_CH0_MASK_0                    SFRS=2;PWM1MD&=0xFE 
#define    PWM1_CH1_MASK_0                    SFRS=2;PWM1MD&=0xFD 

#define    PWM1_CH0_MASK_1                    SFRS=2;PWM1MD|=0x01 
#define    PWM1_CH1_MASK_1                    SFRS=2;PWM1MD|=0x02 
/*--------- PMW1 interrupt setting ------------------------------*/ 
#define    PWM1_FALLING_INT                   SFRS=2;PWM1INTC&=0xCF               
#define    PWM1_RISING_INT                    SFRS=2;PWM1INTC&=0xCF;PWM1INTC|=0x10
#define    PWM1_CENTRAL_POINT_INT             SFRS=2;PWM1INTC&=0xCF;PWM1INTC|=0x20
#define    PWM1_PERIOD_END_INT                SFRS=2;PWM1INTC|=0x30               
/*--------- PWM1 interrupt pin select ---------------------------*/ 
#define    PWM1_CH0_INTERRUPT_SELECT          SFRS=2;PWM1INTC&=0xF8               
#define    PWM1_CH1_INTERRUPT_SELECT          SFRS=2;PWM1INTC&=0xF8;PWM1INTC|=0x01

/*--------- PMW2 Setting ---------------------*/ 
/*--------- PWM2 type define ------------------------------------*/ 
#define    PWM2_EDGE_TYPE                     SFRS=2;PWM2CON1&=0xEF               ;SFRS=0
#define    PWM2_CENTER_TYPE                   SFRS=2;PWM2CON1|=0x10               ;SFRS=0
/*--------- PWM2 mode define ------------------------------------*/              
#define    PWM2_IMDEPENDENT_MODE              SFRS=2;PWM2CON1&=0x3F               ;SFRS=0
#define    PWM2_COMPLEMENTARY_MODE            SFRS=2;PWM2CON1&=0x3F;PWM2CON1|=0x40;SFRS=0
#define    PWM2_SYNCHRONIZED_MODE             SFRS=2;PWM2CON1&=0x3F;PWM2CON1|=0x80;SFRS=0
//--------- PWM2 clock devide define ----------------------------                
#define    PWM2_CLOCK_DIV_2                   SFRS=2;PWM2CON1&=0xF8;PWM2CON1|=0x01;SFRS=0
#define    PWM2_CLOCK_DIV_4                   SFRS=2;PWM2CON1&=0xF8;PWM2CON1|=0x02;SFRS=0
#define    PWM2_CLOCK_DIV_8                   SFRS=2;PWM2CON1&=0xF8;PWM2CON1|=0x03;SFRS=0
#define    PWM2_CLOCK_DIV_16                  SFRS=2;PWM2CON1&=0xF8;PWM2CON1|=0x04;SFRS=0
#define    PWM2_CLOCK_DIV_32                  SFRS=2;PWM2CON1&=0xF8;PWM2CON1|=0x05;SFRS=0
#define    PWM2_CLOCK_DIV_64                  SFRS=2;PWM2CON1&=0xF8;PWM2CON1|=0x06;SFRS=0
#define    PWM2_CLOCK_DIV_128                 SFRS=2;PWM2CON1|=0x07               ;SFRS=0
/*--------- PWM2 ouput GPIO select define ------------------------------*/ 
#define    ENABLE_PWM2_CH0_P21_OUTPUT         SFRS=2;AUXR4&=0xCF;AUXR4|=0x10;set_PIOCON2_PIO21;SFRS=0
#define    ENABLE_PWM2_CH0_P10_OUTPUT         SFRS=2;AUXR4&=0xCF;AUXR4|=0x20;set_PIOCON0_PIO10;SFRS=0
#define    ENABLE_PWM2_CH0_P05_OUTPUT         SFRS=2;AUXR4&=0xCF;AUXR4|=0x30;set_PIOCON1_PIO05;SFRS=0
#define    ENABLE_PWM2_CH1_P30_OUTPUT         SFRS=2;AUXR4&=0x3F;AUXR4|=0x00;set_PIOCON2_PIO30;SFRS=0
#define    ENABLE_PWM2_CH1_P31_OUTPUT         SFRS=2;AUXR4&=0x3F;AUXR4|=0x40;set_PIOCON2_PIO31;SFRS=0
#define    ENABLE_PWM2_CH1_P00_OUTPUT         SFRS=2;AUXR4&=0x3F;AUXR4|=0x80;set_PIOCON0_PIO00;SFRS=0
#define    ENABLE_PWM2_CH1_P04_OUTPUT         SFRS=2;AUXR4&=0x3F;AUXR4|=0xC0;set_PIOCON1_PIO04;SFRS=0

#define    DISABLE_PWM2_CH0_P21_OUTPUT        SFRS=2;AUXR4&=0xCF;clr_PIOCON2_PIO21;SFRS=0            
#define    DISABLE_PWM2_CH0_P10_OUTPUT        SFRS=2;AUXR4&=0xCF;clr_PIOCON0_PIO10;SFRS=0            
#define    DISABLE_PWM2_CH0_P05_OUTPUT        SFRS=2;AUXR4&=0xCF;clr_PIOCON1_PIO05;SFRS=0            
#define    DISABLE_PWM2_CH1_P30_OUTPUT        SFRS=2;AUXR4&=0x3F;clr_PIOCON2_PIO30;SFRS=0            
#define    DISABLE_PWM2_CH1_P31_OUTPUT        SFRS=2;AUXR4&=0x3F;clr_PIOCON2_PIO31;SFRS=0            
#define    DISABLE_PWM2_CH1_P00_OUTPUT        SFRS=2;AUXR4&=0x3F;clr_PIOCON0_PIO00;SFRS=0            
#define    DISABLE_PWM2_CH1_P04_OUTPUT        SFRS=2;AUXR4&=0x3F;clr_PIOCON1_PIO04;SFRS=0            
/*--------- PMM2 Mask Output ENABLE -----------------------*/       
#define    ENABLE_PWM2_CH0_MASK               SFRS=2;PWM2MEN|=0x01;SFRS=0                                               
#define    ENABLE_PWM2_CH1_MASK               SFRS=2;PWM2MEN|=0x02;SFRS=0                                                
                                                                  
#define    DISABLE_PWM2_CH0_MASK              SFRS=2;PWM2MEN&=0xFE;SFRS=0                                                
#define    DISABLE_PWM2_CH1_MASK              SFRS=2;PWM2MEN&=0xFD;SFRS=0                                                
/*--------- PMM2 Mask Output Value -----------------------*/ 
#define    PWM2_CH0_MASK_0                    SFRS=2;PWM2MD&=0xFE;SFRS=0                             
#define    PWM2_CH1_MASK_0                    SFRS=2;PWM2MD&=0xFD;SFRS=0                             
                                                                 
#define    PWM2_CH0_MASK_1                    SFRS=2;PWM2MD|=0x01;SFRS=0                             
#define    PWM2_CH1_MASK_1                    SFRS=2;PWM2MD|=0x02;SFRS=0                             
/*--------- PMW2 interrupt setting ------------------------------*/   
#define    PWM2_FALLING_INT                   SFRS=2;PWM2INTC&=0xCF               ;SFRS=0            
#define    PWM2_RISING_INT                    SFRS=2;PWM2INTC&=0xCF;PWM2INTC|=0x10;SFRS=0            
#define    PWM2_CENTRAL_POINT_INT             SFRS=2;PWM2INTC&=0xCF;PWM2INTC|=0x20;SFRS=0            
#define    PWM2_PERIOD_END_INT                SFRS=2;PWM2INTC|=0x30               ;SFRS=0            
/*--------- PWM2 interrupt pin select ---------------------------*/
#define    PWM2_CH0_INTERRUPT_SELECT          SFRS=2;PWM2INTC&=0xF8               ;SFRS=0            
#define    PWM2_CH1_INTERRUPT_SELECT          SFRS=2;PWM2INTC&=0xF8;PWM2INTC|=0x01;SFRS=0            

/*--------- PMW3 Setting ---------------------*/ 
/*--------- PWM3 type define ------------------------------------*/ 
#define    PWM3_EDGE_TYPE                     SFRS=2;PWM3CON1&=0xEF;SFRS=0                           
#define    PWM3_CENTER_TYPE                   SFRS=2;PWM3CON1|=0x10;SFRS=0                           
/*--------- PWM3 mode define ------------------------------------*/ 
#define    PWM3_IMDEPENDENT_MODE              SFRS=2;PWM3CON1&=0x3F               ;SFRS=0            
#define    PWM3_COMPLEMENTARY_MODE            SFRS=2;PWM3CON1&=0x3F;PWM3CON1|=0x40;SFRS=0                     
#define    PWM3_SYNCHRONIZED_MODE             SFRS=2;PWM3CON1&=0x3F;PWM3CON1|=0x80;SFRS=0            
//--------- PWM3 clock devide define ----------------------------
#define    PWM3_CLOCK_DIV_2                   SFRS=2;PWM3CON1&=0xF8;PWM3CON1|=0x01;SFRS=0            
#define    PWM3_CLOCK_DIV_4                   SFRS=2;PWM3CON1&=0xF8;PWM3CON1|=0x02;SFRS=0            
#define    PWM3_CLOCK_DIV_8                   SFRS=2;PWM3CON1&=0xF8;PWM3CON1|=0x03;SFRS=0            
#define    PWM3_CLOCK_DIV_16                  SFRS=2;PWM3CON1&=0xF8;PWM3CON1|=0x04;SFRS=0            
#define    PWM3_CLOCK_DIV_32                  SFRS=2;PWM3CON1&=0xF8;PWM3CON1|=0x05;SFRS=0            
#define    PWM3_CLOCK_DIV_64                  SFRS=2;PWM3CON1&=0xF8;PWM3CON1|=0x06;SFRS=0            
#define    PWM3_CLOCK_DIV_128                 SFRS=2;PWM3CON1|=0x07               ;SFRS=0            
/*--------- PWM3 ouput GPIO select define ------------------------------*/ 
#define    ENABLE_PWM3_CH0_P32_OUTPUT         SFRS=2;AUXR5&=0xFC;AUXR5|=0x01;set_PIOCON2_PIO32;SFRS=0
#define    ENABLE_PWM3_CH0_P01_OUTPUT         SFRS=2;AUXR5&=0xFC;AUXR5|=0x02;set_PIOCON0_PIO01;SFRS=0
#define    ENABLE_PWM3_CH1_P34_OUTPUT         SFRS=2;AUXR5&=0xF3;AUXR5|=0x04;set_PIOCON2_PIO34;SFRS=0
#define    ENABLE_PWM3_CH1_P15_OUTPUT         SFRS=2;AUXR5&=0xF3;AUXR5|=0x08;set_PIOCON1_PIO15;SFRS=0 
#define    ENABLE_PWM3_CH1_P03_OUTPUT         SFRS=2;AUXR5&=0xF3;AUXR5|=0x0C;set_PIOCON0_PIO03;SFRS=0
                                              
#define    DISABLE_PWM3_CH0_P32_OUTPUT        SFRS=2;AUXR5&=0xFC;clr_PIOCON2_PIO32;SFRS=0
#define    DISABLE_PWM3_CH0_P01_OUTPUT        SFRS=2;AUXR5&=0xFC;clr_PIOCON0_PIO01;SFRS=0
#define    DISABLE_PWM3_CH1_P34_OUTPUT        SFRS=2;AUXR5&=0xF3;clr_PIOCON2_PIO34;SFRS=0
#define    DISABLE_PWM3_CH1_P15_OUTPUT        SFRS=2;AUXR5&=0xF3;clr_PIOCON1_PIO15;SFRS=0
#define    DISABLE_PWM3_CH1_P03_OUTPUT        SFRS=2;AUXR5&=0xF3;clr_PIOCON0_PIO03;SFRS=0
/*--------- PMM3 Mask Output ENABLE -----------------------*/                     
#define    ENABLE_PWM3_CH0_MASK               SFRS=2;PWM3MEN|=0x01;SFRS=0                
#define    ENABLE_PWM3_CH1_MASK               SFRS=2;PWM3MEN|=0x02;SFRS=0                
                                                                               
#define    DISABLE_PWM3_CH0_MASK              SFRS=2;PWM3MEN&=0xFE;SFRS=0                
#define    DISABLE_PWM3_CH1_MASK              SFRS=2;PWM3MEN&=0xFD;SFRS=0                
/*--------- PMM3 Mask Output Value -----------------------*/                      
#define    PWM3_CH0_MASK_0                    SFRS=2;PWM3MD&=0xFE;SFRS=0                 
#define    PWM3_CH1_MASK_0                    SFRS=2;PWM3MD&=0xFD;SFRS=0                 
                
#define    PWM3_CH0_MASK_1                    SFRS=2;PWM3MD|=0x01;SFRS=0                 
#define    PWM3_CH1_MASK_1                    SFRS=2;PWM3MD|=0x02;SFRS=0                 
/*--------- PMW3 interrupt setting ------------------------------*/               
#define    PWM3_FALLING_INT                   SFRS=2;PWM3INTC&=0xCF               ;SFRS=0
#define    PWM3_RISING_INT                    SFRS=2;PWM3INTC&=0xCF;PWM3INTC|=0x10;SFRS=0
#define    PWM3_CENTRAL_POINT_INT             SFRS=2;PWM3INTC&=0xCF;PWM3INTC|=0x20;SFRS=0
#define    PWM3_PERIOD_END_INT                SFRS=2;PWM3INTC|=0x30               ;SFRS=0
/*--------- PWM3 interrupt pin select ---------------------------*/               
#define    PWM3_CH0_INTERRUPT_SELECT          SFRS=2;PWM3INTC&=0xF8               ;SFRS=0
#define    PWM3_CH1_INTERRUPT_SELECT          SFRS=2;PWM3INTC&=0xF8;PWM3INTC|=0x01;SFRS=0

/*****************************************************************************************
* For ADC INIT setting 
*****************************************************************************************/
#define    ENABLE_ADC_CH0                     P17_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x00;AINDIDS0=0;AINDIDS0|=0x01;ADCCON1|=0x01    
#define    ENABLE_ADC_CH1                     P30_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x01;AINDIDS0=0;AINDIDS0|=0x02;ADCCON1|=0x01    
#define    ENABLE_ADC_CH2                     P07_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x02;AINDIDS0=0;AINDIDS0|=0x04;ADCCON1|=0x01    
#define    ENABLE_ADC_CH3                     P06_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x03;AINDIDS0=0;AINDIDS0|=0x08;ADCCON1|=0x01    
#define    ENABLE_ADC_CH4                     P05_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x04;AINDIDS0=0;AINDIDS0|=0x10;ADCCON1|=0x01    
#define    ENABLE_ADC_CH5                     P04_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x05;AINDIDS0=0;AINDIDS0|=0x20;ADCCON1|=0x01    
#define    ENABLE_ADC_CH6                     P03_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x06;AINDIDS0=0;AINDIDS0|=0x40;ADCCON1|=0x01    
#define    ENABLE_ADC_CH7                     P11_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x07;AINDIDS0=0;AINDIDS0|=0x80;ADCCON1|=0x01               
#define    ENABLE_ADC_BANDGAP                                SFRS=0;ADCCON0&=0x30;ADCCON0|=0x08;ADCCON1|=0x01          
#define    ENABLE_ADC_CH9                     P21_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x09;SFRS=2;AINDIDS1=0;AINDIDS1|=0x02;SFRS=0;ADCCON1|=0x01
#define    ENABLE_ADC_CH10                    P22_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x0A;SFRS=2;AINDIDS1=0;AINDIDS1|=0x04;SFRS=0;ADCCON1|=0x01
#define    ENABLE_ADC_CH11                    P23_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x0B;SFRS=2;AINDIDS1=0;AINDIDS1|=0x08;SFRS=0;ADCCON1|=0x01
#define    ENABLE_ADC_CH12                    P24_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x0C;SFRS=2;AINDIDS1=0;AINDIDS1|=0x10;SFRS=0;ADCCON1|=0x01
#define    ENABLE_ADC_CH13                    P13_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x0D;SFRS=2;AINDIDS1=0;AINDIDS1|=0x20;SFRS=0;ADCCON1|=0x01
#define    ENABLE_ADC_CH14                    P14_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x0E;SFRS=2;AINDIDS1=0;AINDIDS1|=0x40;SFRS=0;ADCCON1|=0x01
#define    ENABLE_ADC_CH15                    P25_INPUT_MODE;SFRS=0;ADCCON0&=0x30;ADCCON0|=0x0F;SFRS=2;AINDIDS1=0;AINDIDS1|=0x80;SFRS=0;ADCCON1|=0x01
/*------ ADC mode ------*/
#define    ENABLE_ADC_CONTINUES_MODE           SFRS=2;ADCCON3|=SET_BIT4;SFRS=0
#define    ENABLE_ADC_CONTINUES_HALFDONE_INT   SFRS=2;ADCCON3|=SET_BIT5;SFRS=0
#define    ENABLE_ADC_CONTINUES_FULLDONE_INT   SFRS=2;ADCCON3&=CLR_BIT5;SFRS=0

#define    DISABLE_ADC                        SFRS=0;ADCCON1&=0xFE;AINDIDS0=0;SFRS=2;AINDIDS1=0;SFRS=0;

#define    PWM0_FALLINGEDGE_TRIG_ADC          SFRS=0;ADCCON0&=0xDF;ADCCON0&=0xEF;ADCCON1&=0xF7;ADCCON1&=0xFB;ADCCON1|=0x02
#define    PWM2_FALLINGEDGE_TRIG_ADC          SFRS=0;ADCCON0&=0xDF;ADCCON0|=0x10;ADCCON1&=0xF7;ADCCON1&=0xFB;ADCCON1|=0x02
#define    PWM4_FALLINGEDGE_TRIG_ADC          SFRS=0;ADCCON0|=0x20;ADCCON0&=0xEF;ADCCON1&=0xF7;ADCCON1&=0xFB;ADCCON1|=0x02
#define    PWM0_RISINGEDGE_TRIG_ADC           SFRS=0;ADCCON0&=0xDF;ADCCON0&=0xEF;ADCCON1&=0xF7;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM2_RISINGEDGE_TRIG_ADC           SFRS=0;ADCCON0&=0xDF;ADCCON0|=0x10;ADCCON1&=0xF7;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM4_RISINGEDGE_TRIG_ADC           SFRS=0;ADCCON0|=0x20;ADCCON0&=0xEF;ADCCON1&=0xF7;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM0_CENTRAL_TRIG_ADC              SFRS=0;ADCCON0&=0xDF;ADCCON0&=0xEF;ADCCON1|=0x08;ADCCON1&=0xFB;ADCCON1|=0x02
#define    PWM2_CENTRAL_TRIG_ADC              SFRS=0;ADCCON0&=0xDF;ADCCON0|=0x10;ADCCON1|=0x08;ADCCON1&=0xFB;ADCCON1|=0x02
#define    PWM4_CENTRAL_TRIG_ADC              SFRS=0;ADCCON0|=0x20;ADCCON0&=0xEF;ADCCON1|=0x08;ADCCON1&=0xFB;ADCCON1|=0x02
#define    PWM0_END_TRIG_ADC                  SFRS=0;ADCCON0&=0xDF;ADCCON0&=0xEF;ADCCON1|=0x08;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM2_END_TRIG_ADC                  SFRS=0;ADCCON0&=0xDF;ADCCON0|=0x10;ADCCON1|=0x08;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM4_END_TRIG_ADC                  SFRS=0;ADCCON0|=0x20;ADCCON0&=0xEF;ADCCON1|=0x08;ADCCON1|=0x04;ADCCON1|=0x02
                                              
#define    P04_FALLINGEDGE_TRIG_ADC           SFRS=0;ADCCON0|=0x30;ADCCON1&=0xF3;ADCCON1|=0x02;ADCCON1&=0xBF
#define    P13_FALLINGEDGE_TRIG_ADC           SFRS=0;ADCCON0|=0x30;ADCCON1&=0xF3;ADCCON1|=0x02;ADCCON1|=0x40
#define    P04_RISINGEDGE_TRIG_ADC            SFRS=0;ADCCON0|=0x30;ADCCON1&=0xF7;ADCCON1|=0x04;ADCCON1|=0x02;ADCCON1&=0xBF
#define    P13_RISINGEDGE_TRIG_ADC            SFRS=0;ADCCON0|=0x30;ADCCON1&=0xF7;ADCCON1|=0x04;ADCCON1|=0x02;ADCCON1|=0x40

/*****************************************************************************************
* For SPI INIT setting 
*****************************************************************************************/
#define    SPICLK_FSYS_DIV2                        SFRS=0;SPCR&=0xFC;SPCR|=0x00           
#define    SPICLK_FSYS_DIV4                        SFRS=0;SPCR&=0xFC;SPCR|=0x01           
#define    SPICLK_FSYS_DIV8                        SFRS=0;SPCR&=0xFC;SPCR|=0x02           
#define    SPICLK_FSYS_DIV16                       SFRS=0;SPCR&=0xFC;SPCR|=0x03           

#define    ENABLE_SPI0_SS_P15                 clr_AUXR7_SPI0NSSP1;clr_AUXR7_SPI0NSSP0;SFRS=0
#define    ENABLE_SPI0_SS_P35                 set_AUXR7_SPI0NSSP1;clr_AUXR7_SPI0NSSP0;SFRS=0
#define    ENABLE_SPI0_MOSI_P00               clr_AUXR7_SPI0MOSIP                    ;SFRS=0
#define    ENABLE_SPI0_MOSI_P30               set_AUXR7_SPI0MOSIP                    ;SFRS=0
#define    ENABLE_SPI0_MISO_P01               clr_AUXR7_SPI0MISOP                    ;SFRS=0
#define    ENABLE_SPI0_MISO_P25               set_AUXR7_SPI0MISOP                    ;SFRS=0
#define    ENABLE_SPI0_CLK_P10                clr_AUXR7_SPI0CKP                      ;SFRS=0
#define    ENABLE_SPI0_CLK_P17                set_AUXR7_SPI0CKP                      ;SFRS=0

/*****************************************************************************************
* For BOD enable/disable setting 
*****************************************************************************************/
#define    DISABLE_BOD                        SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=0x7B;EA=BIT_TMP
#define    ENABLE_BOD                         SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=0x80;EA=BIT_TMP
#define    ENABLE_BOD_RESET                   SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=0x84;EA=BIT_TMP

/*****************************************************************************************
* For UART0 and UART1 and printf funcion 
*****************************************************************************************/
#define    ENABLE_UART0_PRINTF                set_SCON_TI;PRINTFG=1            //For printf function must setting TI = 1
#define    DISABLE_UART0_PRINTF               clr_SCON_TI;PRINTFG=0
#define    ENABLE_UART1_PRINTF                set_SCON_1_TI_1;PRINTFG=1
#define    DISABLE_UART1_PRINTF               clr_SCON_1_TI_1;PRINTFG=0

/*****************************************************************************************/
/* For UART2 ~ UART4 output setting                                                      */
/*****************************************************************************************/
#define    ENABLE_UART2_TXD_P03          clr_AUXR2_UART2TXP1;set_AUXR2_UART2TXP0;SFRS=0
#define    ENABLE_UART2_TXD_P30          set_AUXR2_UART2TXP1;clr_AUXR2_UART2TXP0;SFRS=0
#define    ENABLE_UART2_RXD_P04          clr_AUXR2_UART2RXP1;set_AUXR2_UART2RXP0;SFRS=0
#define    ENABLE_UART2_RXD_P17          set_AUXR2_UART2RXP1;clr_AUXR2_UART2RXP0;SFRS=0
                                                                               
#define    ENABLE_UART1_TXD_P16          clr_AUXR2_UART1TXP1;set_AUXR2_UART1TXP0;SFRS=0
#define    ENABLE_UART1_TXD_P36          set_AUXR2_UART1TXP1;clr_AUXR2_UART1TXP0;SFRS=0
#define    ENABLE_UART1_TXD_P10          set_AUXR2_UART1TXP1;set_AUXR2_UART1TXP0;SFRS=0
#define    ENABLE_UART1_RXD_P02          clr_AUXR2_UART1RXP1;set_AUXR2_UART1RXP0;SFRS=0
#define    ENABLE_UART1_RXD_P37          set_AUXR2_UART1RXP1;clr_AUXR2_UART1RXP0;SFRS=0
#define    ENABLE_UART1_RXD_P00          set_AUXR2_UART1RXP1;set_AUXR2_UART1RXP0;SFRS=0
                                                                                
#define    ENABLE_UART4_TXD_P23          clr_AUXR3_UART4TXP1;set_AUXR3_UART4TXP0;SFRS=0
#define    ENABLE_UART4_RXD_P22          clr_AUXR3_UART4RXP1;set_AUXR3_UART4RXP0;SFRS=0
                                                                               
#define    ENABLE_UART3_TXD_P12          clr_AUXR3_UART3TXP1;set_AUXR3_UART3TXP0;SFRS=0
#define    ENABLE_UART3_TXD_P15          set_AUXR3_UART3TXP1;clr_AUXR3_UART3TXP0;SFRS=0
#define    ENABLE_UART3_TXD_P05          set_AUXR3_UART3TXP1;set_AUXR3_UART3TXP0;SFRS=0
#define    ENABLE_UART3_RXD_P11          clr_AUXR3_UART3RXP1;set_AUXR3_UART3RXP0;SFRS=0
#define    ENABLE_UART3_RXD_P25          set_AUXR3_UART3RXP1;clr_AUXR3_UART3RXP0;SFRS=0
#define    ENABLE_UART3_RXD_P34          set_AUXR3_UART3RXP1;set_AUXR3_UART3RXP0;SFRS=0
                                         
#define    ENABLE_UART4_RXD_DEGLITCH     set_AUXR6_UART4DG;SFRS=0
#define    ENABLE_UART3_RXD_DEGLITCH     set_AUXR6_UART3DG;SFRS=0
#define    ENABLE_UART2_RXD_DEGLITCH     set_AUXR6_UART2DG;SFRS=0
#define    ENABLE_UART1_RXD_DEGLITCH     set_AUXR6_UART1DG;SFRS=0
#define    ENABLE_UART0_RXD_DEGLITCH     set_AUXR6_UART0DG;SFRS=0
                                                          
#define    DISABLE_UART4_RXD_DEGLITCH    clr_AUXR6_UART4DG;SFRS=0
#define    DISABLE_UART3_RXD_DEGLITCH    clr_AUXR6_UART3DG;SFRS=0
#define    DISABLE_UART2_RXD_DEGLITCH    clr_AUXR6_UART2DG;SFRS=0
#define    DISABLE_UART1_RXD_DEGLITCH    clr_AUXR6_UART1DG;SFRS=0
#define    DISABLE_UART0_RXD_DEGLITCH    clr_AUXR6_UART0DG;SFRS=0

/****************************************************************************************/
/* INT0 setting                                                                         */
/****************************************************************************************/
#define    INT0_FALLING_EDGE_TRIG             set_TCON_IT0  //TBD
#define    INT0_LOW_LEVEL_TRIG                clr_TCON_IT0  //TBD

/****************************************************************************************/
/* INT1 setting                                                                         */
/****************************************************************************************/
#define    INT1_FALLING_EDGE_TRIG             set_TCON_IT1  //Check
#define    INT1_LOW_LEVEL_TRIG                clr_TCON_IT1  //Check

/*************************************************************************/
/*   PIN interrupt define                                                */
/*************************************************************************/
//---------------- Pin interrupt channel 0 PIT0 ------------------------
#define    ENABLE_PIT0_P00_LOWLEVEL          SFRS=2;PIPS0=0x00;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P01_LOWLEVEL          SFRS=2;PIPS0=0x01;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P02_LOWLEVEL          SFRS=2;PIPS0=0x02;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P03_LOWLEVEL          SFRS=2;PIPS0=0x03;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P04_LOWLEVEL          SFRS=2;PIPS0=0x04;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P05_LOWLEVEL          SFRS=2;PIPS0=0x05;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P06_LOWLEVEL          SFRS=2;PIPS0=0x06;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P07_LOWLEVEL          SFRS=2;PIPS0=0x07;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P10_LOWLEVEL          SFRS=2;PIPS0=0x10;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P11_LOWLEVEL          SFRS=2;PIPS0=0x11;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P12_LOWLEVEL          SFRS=2;PIPS0=0x12;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P13_LOWLEVEL          SFRS=2;PIPS0=0x13;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P14_LOWLEVEL          SFRS=2;PIPS0=0x14;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P15_LOWLEVEL          SFRS=2;PIPS0=0x15;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P16_LOWLEVEL          SFRS=2;PIPS0=0x16;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P17_LOWLEVEL          SFRS=2;PIPS0=0x17;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P20_LOWLEVEL          SFRS=2;PIPS0=0x20;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P21_LOWLEVEL          SFRS=2;PIPS0=0x21;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P22_LOWLEVEL          SFRS=2;PIPS0=0x22;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P23_LOWLEVEL          SFRS=2;PIPS0=0x23;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P24_LOWLEVEL          SFRS=2;PIPS0=0x24;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P25_LOWLEVEL          SFRS=2;PIPS0=0x25;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P30_LOWLEVEL          SFRS=2;PIPS0=0x30;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P31_LOWLEVEL          SFRS=2;PIPS0=0x31;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P32_LOWLEVEL          SFRS=2;PIPS0=0x32;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P33_LOWLEVEL          SFRS=2;PIPS0=0x33;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P34_LOWLEVEL          SFRS=2;PIPS0=0x34;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P35_LOWLEVEL          SFRS=2;PIPS0=0x35;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P36_LOWLEVEL          SFRS=2;PIPS0=0x36;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P37_LOWLEVEL          SFRS=2;PIPS0=0x37;SFRS=0;PICON&=0xFE;PINEN|=0x01;PIPEN&=0xFE
           
#define    ENABLE_PIT0_P00_HIGHLEVEL         SFRS=2;PIPS0=0x00;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P01_HIGHLEVEL         SFRS=2;PIPS0=0x01;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P02_HIGHLEVEL         SFRS=2;PIPS0=0x02;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P03_HIGHLEVEL         SFRS=2;PIPS0=0x03;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P04_HIGHLEVEL         SFRS=2;PIPS0=0x04;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P05_HIGHLEVEL         SFRS=2;PIPS0=0x05;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P06_HIGHLEVEL         SFRS=2;PIPS0=0x06;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P07_HIGHLEVEL         SFRS=2;PIPS0=0x07;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P10_HIGHLEVEL         SFRS=2;PIPS0=0x10;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P11_HIGHLEVEL         SFRS=2;PIPS0=0x11;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P12_HIGHLEVEL         SFRS=2;PIPS0=0x12;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P13_HIGHLEVEL         SFRS=2;PIPS0=0x13;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P14_HIGHLEVEL         SFRS=2;PIPS0=0x14;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P15_HIGHLEVEL         SFRS=2;PIPS0=0x15;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P16_HIGHLEVEL         SFRS=2;PIPS0=0x16;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P17_HIGHLEVEL         SFRS=2;PIPS0=0x17;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P20_HIGHLEVEL         SFRS=2;PIPS0=0x20;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P21_HIGHLEVEL         SFRS=2;PIPS0=0x21;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P22_HIGHLEVEL         SFRS=2;PIPS0=0x22;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P23_HIGHLEVEL         SFRS=2;PIPS0=0x23;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P24_HIGHLEVEL         SFRS=2;PIPS0=0x24;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P25_HIGHLEVEL         SFRS=2;PIPS0=0x25;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P30_HIGHLEVEL         SFRS=2;PIPS0=0x30;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P31_HIGHLEVEL         SFRS=2;PIPS0=0x31;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P32_HIGHLEVEL         SFRS=2;PIPS0=0x32;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P33_HIGHLEVEL         SFRS=2;PIPS0=0x33;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P34_HIGHLEVEL         SFRS=2;PIPS0=0x34;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P35_HIGHLEVEL         SFRS=2;PIPS0=0x35;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P36_HIGHLEVEL         SFRS=2;PIPS0=0x36;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P37_HIGHLEVEL         SFRS=2;PIPS0=0x37;SFRS=0;PICON&=0xFE;PINEN&=0xFE;PIPEN|=0x01
           
#define    ENABLE_PIT0_P00_FALLINGEDGE       SFRS=2;PIPS0=0x00;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P01_FALLINGEDGE       SFRS=2;PIPS0=0x01;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P02_FALLINGEDGE       SFRS=2;PIPS0=0x02;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P03_FALLINGEDGE       SFRS=2;PIPS0=0x03;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P04_FALLINGEDGE       SFRS=2;PIPS0=0x04;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P05_FALLINGEDGE       SFRS=2;PIPS0=0x05;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P06_FALLINGEDGE       SFRS=2;PIPS0=0x06;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P07_FALLINGEDGE       SFRS=2;PIPS0=0x07;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P10_FALLINGEDGE       SFRS=2;PIPS0=0x10;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P11_FALLINGEDGE       SFRS=2;PIPS0=0x11;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P12_FALLINGEDGE       SFRS=2;PIPS0=0x12;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P13_FALLINGEDGE       SFRS=2;PIPS0=0x13;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P14_FALLINGEDGE       SFRS=2;PIPS0=0x14;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P15_FALLINGEDGE       SFRS=2;PIPS0=0x15;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P16_FALLINGEDGE       SFRS=2;PIPS0=0x16;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P17_FALLINGEDGE       SFRS=2;PIPS0=0x17;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P20_FALLINGEDGE       SFRS=2;PIPS0=0x20;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P21_FALLINGEDGE       SFRS=2;PIPS0=0x21;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P22_FALLINGEDGE       SFRS=2;PIPS0=0x22;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P23_FALLINGEDGE       SFRS=2;PIPS0=0x23;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P24_FALLINGEDGE       SFRS=2;PIPS0=0x24;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P25_FALLINGEDGE       SFRS=2;PIPS0=0x25;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P30_FALLINGEDGE       SFRS=2;PIPS0=0x30;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P31_FALLINGEDGE       SFRS=2;PIPS0=0x31;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P32_FALLINGEDGE       SFRS=2;PIPS0=0x32;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P33_FALLINGEDGE       SFRS=2;PIPS0=0x33;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P34_FALLINGEDGE       SFRS=2;PIPS0=0x34;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P35_FALLINGEDGE       SFRS=2;PIPS0=0x35;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P36_FALLINGEDGE       SFRS=2;PIPS0=0x36;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
#define    ENABLE_PIT0_P37_FALLINGEDGE       SFRS=2;PIPS0=0x37;SFRS=0;PICON|=0x01;PINEN|=0x01;PIPEN&=0xFE
           
#define    ENABLE_PIT0_P00_RISINGEDGE        SFRS=2;PIPS0=0x00;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P01_RISINGEDGE        SFRS=2;PIPS0=0x01;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P02_RISINGEDGE        SFRS=2;PIPS0=0x02;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P03_RISINGEDGE        SFRS=2;PIPS0=0x03;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P04_RISINGEDGE        SFRS=2;PIPS0=0x04;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P05_RISINGEDGE        SFRS=2;PIPS0=0x05;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P06_RISINGEDGE        SFRS=2;PIPS0=0x06;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P07_RISINGEDGE        SFRS=2;PIPS0=0x07;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P10_RISINGEDGE        SFRS=2;PIPS0=0x10;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P11_RISINGEDGE        SFRS=2;PIPS0=0x11;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P12_RISINGEDGE        SFRS=2;PIPS0=0x12;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P13_RISINGEDGE        SFRS=2;PIPS0=0x13;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P14_RISINGEDGE        SFRS=2;PIPS0=0x14;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P15_RISINGEDGE        SFRS=2;PIPS0=0x15;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P16_RISINGEDGE        SFRS=2;PIPS0=0x16;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P17_RISINGEDGE        SFRS=2;PIPS0=0x17;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P20_RISINGEDGE        SFRS=2;PIPS0=0x20;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P21_RISINGEDGE        SFRS=2;PIPS0=0x21;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P22_RISINGEDGE        SFRS=2;PIPS0=0x22;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P23_RISINGEDGE        SFRS=2;PIPS0=0x23;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P24_RISINGEDGE        SFRS=2;PIPS0=0x24;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P25_RISINGEDGE        SFRS=2;PIPS0=0x25;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P30_RISINGEDGE        SFRS=2;PIPS0=0x30;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P31_RISINGEDGE        SFRS=2;PIPS0=0x31;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P32_RISINGEDGE        SFRS=2;PIPS0=0x32;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P33_RISINGEDGE        SFRS=2;PIPS0=0x33;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P34_RISINGEDGE        SFRS=2;PIPS0=0x34;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P35_RISINGEDGE        SFRS=2;PIPS0=0x35;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P36_RISINGEDGE        SFRS=2;PIPS0=0x36;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
#define    ENABLE_PIT0_P37_RISINGEDGE        SFRS=2;PIPS0=0x37;SFRS=0;PICON|=0x01;PINEN&=0xFE;PIPEN|=0x01
           
//-------- -------- Pin interrupt channel 1 PIT1 ------------------------
#define    ENABLE_PIT1_P00_LOWLEVEL          SFRS=2;PIPS1=0x00;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P01_LOWLEVEL          SFRS=2;PIPS1=0x01;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P02_LOWLEVEL          SFRS=2;PIPS1=0x02;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P03_LOWLEVEL          SFRS=2;PIPS1=0x03;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P04_LOWLEVEL          SFRS=2;PIPS1=0x04;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P05_LOWLEVEL          SFRS=2;PIPS1=0x05;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P06_LOWLEVEL          SFRS=2;PIPS1=0x06;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P07_LOWLEVEL          SFRS=2;PIPS1=0x07;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P10_LOWLEVEL          SFRS=2;PIPS1=0x10;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P11_LOWLEVEL          SFRS=2;PIPS1=0x11;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P12_LOWLEVEL          SFRS=2;PIPS1=0x12;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P13_LOWLEVEL          SFRS=2;PIPS1=0x13;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P14_LOWLEVEL          SFRS=2;PIPS1=0x14;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P15_LOWLEVEL          SFRS=2;PIPS1=0x15;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P16_LOWLEVEL          SFRS=2;PIPS1=0x16;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P17_LOWLEVEL          SFRS=2;PIPS1=0x17;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P20_LOWLEVEL          SFRS=2;PIPS1=0x20;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P21_LOWLEVEL          SFRS=2;PIPS1=0x21;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P22_LOWLEVEL          SFRS=2;PIPS1=0x22;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P23_LOWLEVEL          SFRS=2;PIPS1=0x23;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P24_LOWLEVEL          SFRS=2;PIPS1=0x24;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P25_LOWLEVEL          SFRS=2;PIPS1=0x25;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P30_LOWLEVEL          SFRS=2;PIPS1=0x30;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P31_LOWLEVEL          SFRS=2;PIPS1=0x31;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P32_LOWLEVEL          SFRS=2;PIPS1=0x32;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P33_LOWLEVEL          SFRS=2;PIPS1=0x33;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P34_LOWLEVEL          SFRS=2;PIPS1=0x34;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P35_LOWLEVEL          SFRS=2;PIPS1=0x35;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P36_LOWLEVEL          SFRS=2;PIPS1=0x36;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P37_LOWLEVEL          SFRS=2;PIPS1=0x37;SFRS=0;PICON&=0xFD;PINEN|=0x02;PIPEN&=0xFD
           
#define    ENABLE_PIT1_P00_HIGHLEVEL         SFRS=2;PIPS1=0x00;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P01_HIGHLEVEL         SFRS=2;PIPS1=0x01;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P02_HIGHLEVEL         SFRS=2;PIPS1=0x02;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P03_HIGHLEVEL         SFRS=2;PIPS1=0x03;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P04_HIGHLEVEL         SFRS=2;PIPS1=0x04;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P05_HIGHLEVEL         SFRS=2;PIPS1=0x05;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P06_HIGHLEVEL         SFRS=2;PIPS1=0x06;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P07_HIGHLEVEL         SFRS=2;PIPS1=0x07;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P10_HIGHLEVEL         SFRS=2;PIPS1=0x10;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P11_HIGHLEVEL         SFRS=2;PIPS1=0x11;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P12_HIGHLEVEL         SFRS=2;PIPS1=0x12;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P13_HIGHLEVEL         SFRS=2;PIPS1=0x13;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P14_HIGHLEVEL         SFRS=2;PIPS1=0x14;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P15_HIGHLEVEL         SFRS=2;PIPS1=0x15;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P16_HIGHLEVEL         SFRS=2;PIPS1=0x16;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P17_HIGHLEVEL         SFRS=2;PIPS1=0x17;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P20_HIGHLEVEL         SFRS=2;PIPS1=0x20;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P21_HIGHLEVEL         SFRS=2;PIPS1=0x21;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P22_HIGHLEVEL         SFRS=2;PIPS1=0x22;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P23_HIGHLEVEL         SFRS=2;PIPS1=0x23;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P24_HIGHLEVEL         SFRS=2;PIPS1=0x24;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P25_HIGHLEVEL         SFRS=2;PIPS1=0x25;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P30_HIGHLEVEL         SFRS=2;PIPS1=0x30;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P31_HIGHLEVEL         SFRS=2;PIPS1=0x31;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P32_HIGHLEVEL         SFRS=2;PIPS1=0x32;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P33_HIGHLEVEL         SFRS=2;PIPS1=0x33;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P34_HIGHLEVEL         SFRS=2;PIPS1=0x34;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P35_HIGHLEVEL         SFRS=2;PIPS1=0x35;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P36_HIGHLEVEL         SFRS=2;PIPS1=0x36;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P37_HIGHLEVEL         SFRS=2;PIPS1=0x37;SFRS=0;PICON&=0xFD;PINEN&=0xFD;PIPEN|=0x02
           
#define    ENABLE_PIT1_P00_FALLINGEDGE       SFRS=2;PIPS1=0x00;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P01_FALLINGEDGE       SFRS=2;PIPS1=0x01;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P02_FALLINGEDGE       SFRS=2;PIPS1=0x02;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P03_FALLINGEDGE       SFRS=2;PIPS1=0x03;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P04_FALLINGEDGE       SFRS=2;PIPS1=0x04;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P05_FALLINGEDGE       SFRS=2;PIPS1=0x05;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P06_FALLINGEDGE       SFRS=2;PIPS1=0x06;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P07_FALLINGEDGE       SFRS=2;PIPS1=0x07;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P10_FALLINGEDGE       SFRS=2;PIPS1=0x10;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P11_FALLINGEDGE       SFRS=2;PIPS1=0x11;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P12_FALLINGEDGE       SFRS=2;PIPS1=0x12;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P13_FALLINGEDGE       SFRS=2;PIPS1=0x13;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P14_FALLINGEDGE       SFRS=2;PIPS1=0x14;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P15_FALLINGEDGE       SFRS=2;PIPS1=0x15;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P16_FALLINGEDGE       SFRS=2;PIPS1=0x16;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P17_FALLINGEDGE       SFRS=2;PIPS1=0x17;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P20_FALLINGEDGE       SFRS=2;PIPS1=0x20;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P21_FALLINGEDGE       SFRS=2;PIPS1=0x21;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P22_FALLINGEDGE       SFRS=2;PIPS1=0x22;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P23_FALLINGEDGE       SFRS=2;PIPS1=0x23;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P24_FALLINGEDGE       SFRS=2;PIPS1=0x24;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P25_FALLINGEDGE       SFRS=2;PIPS1=0x25;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P30_FALLINGEDGE       SFRS=2;PIPS1=0x30;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P31_FALLINGEDGE       SFRS=2;PIPS1=0x31;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P32_FALLINGEDGE       SFRS=2;PIPS1=0x32;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P33_FALLINGEDGE       SFRS=2;PIPS1=0x33;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P34_FALLINGEDGE       SFRS=2;PIPS1=0x34;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P35_FALLINGEDGE       SFRS=2;PIPS1=0x35;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P36_FALLINGEDGE       SFRS=2;PIPS1=0x36;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_PIT1_P37_FALLINGEDGE       SFRS=2;PIPS1=0x37;SFRS=0;PICON|=0x02;PINEN|=0x02;PIPEN&=0xFD
           
#define    ENABLE_PIT1_P00_RISINGEDGE        SFRS=2;PIPS1=0x00;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P01_RISINGEDGE        SFRS=2;PIPS1=0x01;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P02_RISINGEDGE        SFRS=2;PIPS1=0x02;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P03_RISINGEDGE        SFRS=2;PIPS1=0x03;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P04_RISINGEDGE        SFRS=2;PIPS1=0x04;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P05_RISINGEDGE        SFRS=2;PIPS1=0x05;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P06_RISINGEDGE        SFRS=2;PIPS1=0x06;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P07_RISINGEDGE        SFRS=2;PIPS1=0x07;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P10_RISINGEDGE        SFRS=2;PIPS1=0x10;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P11_RISINGEDGE        SFRS=2;PIPS1=0x11;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P12_RISINGEDGE        SFRS=2;PIPS1=0x12;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P13_RISINGEDGE        SFRS=2;PIPS1=0x13;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P14_RISINGEDGE        SFRS=2;PIPS1=0x14;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P15_RISINGEDGE        SFRS=2;PIPS1=0x15;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P16_RISINGEDGE        SFRS=2;PIPS1=0x16;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P17_RISINGEDGE        SFRS=2;PIPS1=0x17;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P20_RISINGEDGE        SFRS=2;PIPS1=0x20;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P21_RISINGEDGE        SFRS=2;PIPS1=0x21;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P22_RISINGEDGE        SFRS=2;PIPS1=0x22;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P23_RISINGEDGE        SFRS=2;PIPS1=0x23;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P24_RISINGEDGE        SFRS=2;PIPS1=0x24;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P25_RISINGEDGE        SFRS=2;PIPS1=0x25;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P30_RISINGEDGE        SFRS=2;PIPS1=0x30;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P31_RISINGEDGE        SFRS=2;PIPS1=0x31;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P32_RISINGEDGE        SFRS=2;PIPS1=0x32;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P33_RISINGEDGE        SFRS=2;PIPS1=0x33;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P34_RISINGEDGE        SFRS=2;PIPS1=0x34;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P35_RISINGEDGE        SFRS=2;PIPS1=0x35;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P36_RISINGEDGE        SFRS=2;PIPS1=0x36;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_PIT1_P37_RISINGEDGE        SFRS=2;PIPS1=0x37;SFRS=0;PICON|=0x02;PINEN&=0xFD;PIPEN|=0x02
           
//-------- -------- Pin interrupt channel 2 PIT2 ------------------------
#define    ENABLE_PIT2_P00_LOWLEVEL          SFRS=2;PIPS2=0x00;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P01_LOWLEVEL          SFRS=2;PIPS2=0x01;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P02_LOWLEVEL          SFRS=2;PIPS2=0x02;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P03_LOWLEVEL          SFRS=2;PIPS2=0x03;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P04_LOWLEVEL          SFRS=2;PIPS2=0x04;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P05_LOWLEVEL          SFRS=2;PIPS2=0x05;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P06_LOWLEVEL          SFRS=2;PIPS2=0x06;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P07_LOWLEVEL          SFRS=2;PIPS2=0x07;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P10_LOWLEVEL          SFRS=2;PIPS2=0x10;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P11_LOWLEVEL          SFRS=2;PIPS2=0x11;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P12_LOWLEVEL          SFRS=2;PIPS2=0x12;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P13_LOWLEVEL          SFRS=2;PIPS2=0x13;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P14_LOWLEVEL          SFRS=2;PIPS2=0x14;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P15_LOWLEVEL          SFRS=2;PIPS2=0x15;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P16_LOWLEVEL          SFRS=2;PIPS2=0x16;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P17_LOWLEVEL          SFRS=2;PIPS2=0x17;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P20_LOWLEVEL          SFRS=2;PIPS2=0x20;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P21_LOWLEVEL          SFRS=2;PIPS2=0x21;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P22_LOWLEVEL          SFRS=2;PIPS2=0x22;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P23_LOWLEVEL          SFRS=2;PIPS2=0x23;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P24_LOWLEVEL          SFRS=2;PIPS2=0x24;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P25_LOWLEVEL          SFRS=2;PIPS2=0x25;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P30_LOWLEVEL          SFRS=2;PIPS2=0x30;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P31_LOWLEVEL          SFRS=2;PIPS2=0x31;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P32_LOWLEVEL          SFRS=2;PIPS2=0x32;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P33_LOWLEVEL          SFRS=2;PIPS2=0x33;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P34_LOWLEVEL          SFRS=2;PIPS2=0x34;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P35_LOWLEVEL          SFRS=2;PIPS2=0x35;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P36_LOWLEVEL          SFRS=2;PIPS2=0x36;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P37_LOWLEVEL          SFRS=2;PIPS2=0x37;SFRS=0;PICON&=0xFB;PINEN|=0x04;PIPEN&=0xFB
           
#define    ENABLE_PIT2_P00_HIGHLEVEL         SFRS=2;PIPS2=0x00;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P01_HIGHLEVEL         SFRS=2;PIPS2=0x01;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P02_HIGHLEVEL         SFRS=2;PIPS2=0x02;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P03_HIGHLEVEL         SFRS=2;PIPS2=0x03;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P04_HIGHLEVEL         SFRS=2;PIPS2=0x04;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P05_HIGHLEVEL         SFRS=2;PIPS2=0x05;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P06_HIGHLEVEL         SFRS=2;PIPS2=0x06;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P07_HIGHLEVEL         SFRS=2;PIPS2=0x07;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P10_HIGHLEVEL         SFRS=2;PIPS2=0x10;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P11_HIGHLEVEL         SFRS=2;PIPS2=0x11;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P12_HIGHLEVEL         SFRS=2;PIPS2=0x12;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P13_HIGHLEVEL         SFRS=2;PIPS2=0x13;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P14_HIGHLEVEL         SFRS=2;PIPS2=0x14;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P15_HIGHLEVEL         SFRS=2;PIPS2=0x15;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P16_HIGHLEVEL         SFRS=2;PIPS2=0x16;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P17_HIGHLEVEL         SFRS=2;PIPS2=0x17;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P20_HIGHLEVEL         SFRS=2;PIPS2=0x20;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P21_HIGHLEVEL         SFRS=2;PIPS2=0x21;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P22_HIGHLEVEL         SFRS=2;PIPS2=0x22;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P23_HIGHLEVEL         SFRS=2;PIPS2=0x23;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P24_HIGHLEVEL         SFRS=2;PIPS2=0x24;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P25_HIGHLEVEL         SFRS=2;PIPS2=0x25;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P30_HIGHLEVEL         SFRS=2;PIPS2=0x30;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P31_HIGHLEVEL         SFRS=2;PIPS2=0x31;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P32_HIGHLEVEL         SFRS=2;PIPS2=0x32;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P33_HIGHLEVEL         SFRS=2;PIPS2=0x33;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P34_HIGHLEVEL         SFRS=2;PIPS2=0x34;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P35_HIGHLEVEL         SFRS=2;PIPS2=0x35;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P36_HIGHLEVEL         SFRS=2;PIPS2=0x36;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P37_HIGHLEVEL         SFRS=2;PIPS2=0x37;SFRS=0;PICON&=0xFB;PINEN&=0xFB;PIPEN|=0x04
           
#define    ENABLE_PIT2_P00_FALLINGEDGE       SFRS=2;PIPS2=0x00;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P01_FALLINGEDGE       SFRS=2;PIPS2=0x01;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P02_FALLINGEDGE       SFRS=2;PIPS2=0x02;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P03_FALLINGEDGE       SFRS=2;PIPS2=0x03;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P04_FALLINGEDGE       SFRS=2;PIPS2=0x04;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P05_FALLINGEDGE       SFRS=2;PIPS2=0x05;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P06_FALLINGEDGE       SFRS=2;PIPS2=0x06;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P07_FALLINGEDGE       SFRS=2;PIPS2=0x07;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P10_FALLINGEDGE       SFRS=2;PIPS2=0x10;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P11_FALLINGEDGE       SFRS=2;PIPS2=0x11;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P12_FALLINGEDGE       SFRS=2;PIPS2=0x12;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P13_FALLINGEDGE       SFRS=2;PIPS2=0x13;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P14_FALLINGEDGE       SFRS=2;PIPS2=0x14;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P15_FALLINGEDGE       SFRS=2;PIPS2=0x15;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P16_FALLINGEDGE       SFRS=2;PIPS2=0x16;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P17_FALLINGEDGE       SFRS=2;PIPS2=0x17;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P20_FALLINGEDGE       SFRS=2;PIPS2=0x20;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P21_FALLINGEDGE       SFRS=2;PIPS2=0x21;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P22_FALLINGEDGE       SFRS=2;PIPS2=0x22;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P23_FALLINGEDGE       SFRS=2;PIPS2=0x23;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P24_FALLINGEDGE       SFRS=2;PIPS2=0x24;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P25_FALLINGEDGE       SFRS=2;PIPS2=0x25;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P30_FALLINGEDGE       SFRS=2;PIPS2=0x30;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P31_FALLINGEDGE       SFRS=2;PIPS2=0x31;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P32_FALLINGEDGE       SFRS=2;PIPS2=0x32;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P33_FALLINGEDGE       SFRS=2;PIPS2=0x33;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P34_FALLINGEDGE       SFRS=2;PIPS2=0x34;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P35_FALLINGEDGE       SFRS=2;PIPS2=0x35;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P36_FALLINGEDGE       SFRS=2;PIPS2=0x36;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_PIT2_P37_FALLINGEDGE       SFRS=2;PIPS2=0x37;SFRS=0;PICON|=0x04;PINEN|=0x04;PIPEN&=0xFB
           
#define    ENABLE_PIT2_P00_RISINGEDGE        SFRS=2;PIPS2=0x00;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P01_RISINGEDGE        SFRS=2;PIPS2=0x01;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P02_RISINGEDGE        SFRS=2;PIPS2=0x02;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P03_RISINGEDGE        SFRS=2;PIPS2=0x03;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P04_RISINGEDGE        SFRS=2;PIPS2=0x04;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P05_RISINGEDGE        SFRS=2;PIPS2=0x05;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P06_RISINGEDGE        SFRS=2;PIPS2=0x06;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P07_RISINGEDGE        SFRS=2;PIPS2=0x07;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P10_RISINGEDGE        SFRS=2;PIPS2=0x10;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P11_RISINGEDGE        SFRS=2;PIPS2=0x11;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P12_RISINGEDGE        SFRS=2;PIPS2=0x12;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P13_RISINGEDGE        SFRS=2;PIPS2=0x13;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P14_RISINGEDGE        SFRS=2;PIPS2=0x14;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P15_RISINGEDGE        SFRS=2;PIPS2=0x15;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P16_RISINGEDGE        SFRS=2;PIPS2=0x16;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P17_RISINGEDGE        SFRS=2;PIPS2=0x17;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P20_RISINGEDGE        SFRS=2;PIPS2=0x20;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P21_RISINGEDGE        SFRS=2;PIPS2=0x21;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P22_RISINGEDGE        SFRS=2;PIPS2=0x22;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P23_RISINGEDGE        SFRS=2;PIPS2=0x23;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P24_RISINGEDGE        SFRS=2;PIPS2=0x24;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P25_RISINGEDGE        SFRS=2;PIPS2=0x25;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P30_RISINGEDGE        SFRS=2;PIPS2=0x30;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P31_RISINGEDGE        SFRS=2;PIPS2=0x31;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P32_RISINGEDGE        SFRS=2;PIPS2=0x32;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P33_RISINGEDGE        SFRS=2;PIPS2=0x33;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P34_RISINGEDGE        SFRS=2;PIPS2=0x34;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P35_RISINGEDGE        SFRS=2;PIPS2=0x35;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P36_RISINGEDGE        SFRS=2;PIPS2=0x36;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_PIT2_P37_RISINGEDGE        SFRS=2;PIPS2=0x37;SFRS=0;PICON|=0x04;PINEN&=0xFB;PIPEN|=0x04
           
//-------- -------- Pin interrupt channel 3 PIT3 ------------------------
#define    ENABLE_PIT3_P00_LOWLEVEL          SFRS=2;PIPS3=0x00;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P01_LOWLEVEL          SFRS=2;PIPS3=0x01;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P02_LOWLEVEL          SFRS=2;PIPS3=0x02;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P03_LOWLEVEL          SFRS=2;PIPS3=0x03;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P04_LOWLEVEL          SFRS=2;PIPS3=0x04;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P05_LOWLEVEL          SFRS=2;PIPS3=0x05;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P06_LOWLEVEL          SFRS=2;PIPS3=0x06;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P07_LOWLEVEL          SFRS=2;PIPS3=0x07;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P10_LOWLEVEL          SFRS=2;PIPS3=0x10;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P11_LOWLEVEL          SFRS=2;PIPS3=0x11;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P12_LOWLEVEL          SFRS=2;PIPS3=0x12;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P13_LOWLEVEL          SFRS=2;PIPS3=0x13;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P14_LOWLEVEL          SFRS=2;PIPS3=0x14;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P15_LOWLEVEL          SFRS=2;PIPS3=0x15;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P16_LOWLEVEL          SFRS=2;PIPS3=0x16;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P17_LOWLEVEL          SFRS=2;PIPS3=0x17;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P20_LOWLEVEL          SFRS=2;PIPS3=0x20;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P21_LOWLEVEL          SFRS=2;PIPS3=0x21;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P22_LOWLEVEL          SFRS=2;PIPS3=0x22;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P23_LOWLEVEL          SFRS=2;PIPS3=0x23;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P24_LOWLEVEL          SFRS=2;PIPS3=0x24;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P25_LOWLEVEL          SFRS=2;PIPS3=0x25;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P30_LOWLEVEL          SFRS=2;PIPS3=0x30;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P31_LOWLEVEL          SFRS=2;PIPS3=0x31;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P32_LOWLEVEL          SFRS=2;PIPS3=0x32;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P33_LOWLEVEL          SFRS=2;PIPS3=0x33;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P34_LOWLEVEL          SFRS=2;PIPS3=0x34;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P35_LOWLEVEL          SFRS=2;PIPS3=0x35;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P36_LOWLEVEL          SFRS=2;PIPS3=0x36;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P37_LOWLEVEL          SFRS=2;PIPS3=0x37;SFRS=0;PICON&=0xF7;PINEN|=0x08;PIPEN&=0xF7
           
#define    ENABLE_PIT3_P00_HIGHLEVEL         SFRS=2;PIPS3=0x00;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P01_HIGHLEVEL         SFRS=2;PIPS3=0x01;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P02_HIGHLEVEL         SFRS=2;PIPS3=0x02;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P03_HIGHLEVEL         SFRS=2;PIPS3=0x03;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P04_HIGHLEVEL         SFRS=2;PIPS3=0x04;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P05_HIGHLEVEL         SFRS=2;PIPS3=0x05;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P06_HIGHLEVEL         SFRS=2;PIPS3=0x06;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P07_HIGHLEVEL         SFRS=2;PIPS3=0x07;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P10_HIGHLEVEL         SFRS=2;PIPS3=0x10;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P11_HIGHLEVEL         SFRS=2;PIPS3=0x11;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P12_HIGHLEVEL         SFRS=2;PIPS3=0x12;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P13_HIGHLEVEL         SFRS=2;PIPS3=0x13;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P14_HIGHLEVEL         SFRS=2;PIPS3=0x14;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P15_HIGHLEVEL         SFRS=2;PIPS3=0x15;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P16_HIGHLEVEL         SFRS=2;PIPS3=0x16;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P17_HIGHLEVEL         SFRS=2;PIPS3=0x17;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P20_HIGHLEVEL         SFRS=2;PIPS3=0x20;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P21_HIGHLEVEL         SFRS=2;PIPS3=0x21;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P22_HIGHLEVEL         SFRS=2;PIPS3=0x22;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P23_HIGHLEVEL         SFRS=2;PIPS3=0x23;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P24_HIGHLEVEL         SFRS=2;PIPS3=0x24;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P25_HIGHLEVEL         SFRS=2;PIPS3=0x25;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P30_HIGHLEVEL         SFRS=2;PIPS3=0x30;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P31_HIGHLEVEL         SFRS=2;PIPS3=0x31;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P32_HIGHLEVEL         SFRS=2;PIPS3=0x32;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P33_HIGHLEVEL         SFRS=2;PIPS3=0x33;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P34_HIGHLEVEL         SFRS=2;PIPS3=0x34;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P35_HIGHLEVEL         SFRS=2;PIPS3=0x35;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P36_HIGHLEVEL         SFRS=2;PIPS3=0x36;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P37_HIGHLEVEL         SFRS=2;PIPS3=0x37;SFRS=0;PICON&=0xF7;PINEN&=0xF7;PIPEN|=0x08
           
#define    ENABLE_PIT3_P00_FALLINGEDGE       SFRS=2;PIPS3=0x00;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P01_FALLINGEDGE       SFRS=2;PIPS3=0x01;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P02_FALLINGEDGE       SFRS=2;PIPS3=0x02;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P03_FALLINGEDGE       SFRS=2;PIPS3=0x03;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P04_FALLINGEDGE       SFRS=2;PIPS3=0x04;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P05_FALLINGEDGE       SFRS=2;PIPS3=0x05;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P06_FALLINGEDGE       SFRS=2;PIPS3=0x06;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P07_FALLINGEDGE       SFRS=2;PIPS3=0x07;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P10_FALLINGEDGE       SFRS=2;PIPS3=0x10;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P11_FALLINGEDGE       SFRS=2;PIPS3=0x11;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P12_FALLINGEDGE       SFRS=2;PIPS3=0x12;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P13_FALLINGEDGE       SFRS=2;PIPS3=0x13;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P14_FALLINGEDGE       SFRS=2;PIPS3=0x14;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P15_FALLINGEDGE       SFRS=2;PIPS3=0x15;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P16_FALLINGEDGE       SFRS=2;PIPS3=0x16;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P17_FALLINGEDGE       SFRS=2;PIPS3=0x17;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P20_FALLINGEDGE       SFRS=2;PIPS3=0x20;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P21_FALLINGEDGE       SFRS=2;PIPS3=0x21;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P22_FALLINGEDGE       SFRS=2;PIPS3=0x22;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P23_FALLINGEDGE       SFRS=2;PIPS3=0x23;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P24_FALLINGEDGE       SFRS=2;PIPS3=0x24;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P25_FALLINGEDGE       SFRS=2;PIPS3=0x25;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P30_FALLINGEDGE       SFRS=2;PIPS3=0x30;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P31_FALLINGEDGE       SFRS=2;PIPS3=0x31;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P32_FALLINGEDGE       SFRS=2;PIPS3=0x32;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P33_FALLINGEDGE       SFRS=2;PIPS3=0x33;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P34_FALLINGEDGE       SFRS=2;PIPS3=0x34;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P35_FALLINGEDGE       SFRS=2;PIPS3=0x35;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P36_FALLINGEDGE       SFRS=2;PIPS3=0x36;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_PIT3_P37_FALLINGEDGE       SFRS=2;PIPS3=0x37;SFRS=0;PICON|=0x08;PINEN|=0x08;PIPEN&=0xF7
           
#define    ENABLE_PIT3_P00_RISINGEDGE        SFRS=2;PIPS3=0x00;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P01_RISINGEDGE        SFRS=2;PIPS3=0x01;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P02_RISINGEDGE        SFRS=2;PIPS3=0x02;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P03_RISINGEDGE        SFRS=2;PIPS3=0x03;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P04_RISINGEDGE        SFRS=2;PIPS3=0x04;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P05_RISINGEDGE        SFRS=2;PIPS3=0x05;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P06_RISINGEDGE        SFRS=2;PIPS3=0x06;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P07_RISINGEDGE        SFRS=2;PIPS3=0x07;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P10_RISINGEDGE        SFRS=2;PIPS3=0x10;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P11_RISINGEDGE        SFRS=2;PIPS3=0x11;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P12_RISINGEDGE        SFRS=2;PIPS3=0x12;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P13_RISINGEDGE        SFRS=2;PIPS3=0x13;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P14_RISINGEDGE        SFRS=2;PIPS3=0x14;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P15_RISINGEDGE        SFRS=2;PIPS3=0x15;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P16_RISINGEDGE        SFRS=2;PIPS3=0x16;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P17_RISINGEDGE        SFRS=2;PIPS3=0x17;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P20_RISINGEDGE        SFRS=2;PIPS3=0x20;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P21_RISINGEDGE        SFRS=2;PIPS3=0x21;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P22_RISINGEDGE        SFRS=2;PIPS3=0x22;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P23_RISINGEDGE        SFRS=2;PIPS3=0x23;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P24_RISINGEDGE        SFRS=2;PIPS3=0x24;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P25_RISINGEDGE        SFRS=2;PIPS3=0x25;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P30_RISINGEDGE        SFRS=2;PIPS3=0x30;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P31_RISINGEDGE        SFRS=2;PIPS3=0x31;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P32_RISINGEDGE        SFRS=2;PIPS3=0x32;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P33_RISINGEDGE        SFRS=2;PIPS3=0x33;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P34_RISINGEDGE        SFRS=2;PIPS3=0x34;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P35_RISINGEDGE        SFRS=2;PIPS3=0x35;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P36_RISINGEDGE        SFRS=2;PIPS3=0x36;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_PIT3_P37_RISINGEDGE        SFRS=2;PIPS3=0x37;SFRS=0;PICON|=0x08;PINEN&=0xF7;PIPEN|=0x08
           
//-------- -------- Pin interrupt channel 4 PIT4 ------------------------
#define    ENABLE_PIT4_P00_LOWLEVEL          SFRS=2;PIPS4=0x00;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P01_LOWLEVEL          SFRS=2;PIPS4=0x01;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P02_LOWLEVEL          SFRS=2;PIPS4=0x02;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P03_LOWLEVEL          SFRS=2;PIPS4=0x03;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P04_LOWLEVEL          SFRS=2;PIPS4=0x04;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P05_LOWLEVEL          SFRS=2;PIPS4=0x05;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P06_LOWLEVEL          SFRS=2;PIPS4=0x06;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P07_LOWLEVEL          SFRS=2;PIPS4=0x07;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P10_LOWLEVEL          SFRS=2;PIPS4=0x10;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P11_LOWLEVEL          SFRS=2;PIPS4=0x11;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P12_LOWLEVEL          SFRS=2;PIPS4=0x12;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P13_LOWLEVEL          SFRS=2;PIPS4=0x13;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P14_LOWLEVEL          SFRS=2;PIPS4=0x14;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P15_LOWLEVEL          SFRS=2;PIPS4=0x15;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P16_LOWLEVEL          SFRS=2;PIPS4=0x16;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P17_LOWLEVEL          SFRS=2;PIPS4=0x17;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P20_LOWLEVEL          SFRS=2;PIPS4=0x20;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P21_LOWLEVEL          SFRS=2;PIPS4=0x21;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P22_LOWLEVEL          SFRS=2;PIPS4=0x22;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P23_LOWLEVEL          SFRS=2;PIPS4=0x23;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P24_LOWLEVEL          SFRS=2;PIPS4=0x24;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P25_LOWLEVEL          SFRS=2;PIPS4=0x25;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P30_LOWLEVEL          SFRS=2;PIPS4=0x30;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P31_LOWLEVEL          SFRS=2;PIPS4=0x31;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P32_LOWLEVEL          SFRS=2;PIPS4=0x32;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P33_LOWLEVEL          SFRS=2;PIPS4=0x33;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P34_LOWLEVEL          SFRS=2;PIPS4=0x34;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P35_LOWLEVEL          SFRS=2;PIPS4=0x35;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P36_LOWLEVEL          SFRS=2;PIPS4=0x36;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P37_LOWLEVEL          SFRS=2;PIPS4=0x37;SFRS=0;PICON&=0xEF;PINEN|=0x10;PIPEN&=0xEF
           
#define    ENABLE_PIT4_P00_HIGHLEVEL         SFRS=2;PIPS4=0x00;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P01_HIGHLEVEL         SFRS=2;PIPS4=0x01;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P02_HIGHLEVEL         SFRS=2;PIPS4=0x02;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P03_HIGHLEVEL         SFRS=2;PIPS4=0x03;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P04_HIGHLEVEL         SFRS=2;PIPS4=0x04;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P05_HIGHLEVEL         SFRS=2;PIPS4=0x05;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P06_HIGHLEVEL         SFRS=2;PIPS4=0x06;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P07_HIGHLEVEL         SFRS=2;PIPS4=0x07;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P10_HIGHLEVEL         SFRS=2;PIPS4=0x10;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P11_HIGHLEVEL         SFRS=2;PIPS4=0x11;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P12_HIGHLEVEL         SFRS=2;PIPS4=0x12;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P13_HIGHLEVEL         SFRS=2;PIPS4=0x13;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P14_HIGHLEVEL         SFRS=2;PIPS4=0x14;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P15_HIGHLEVEL         SFRS=2;PIPS4=0x15;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P16_HIGHLEVEL         SFRS=2;PIPS4=0x16;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P17_HIGHLEVEL         SFRS=2;PIPS4=0x17;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P20_HIGHLEVEL         SFRS=2;PIPS4=0x20;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P21_HIGHLEVEL         SFRS=2;PIPS4=0x21;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P22_HIGHLEVEL         SFRS=2;PIPS4=0x22;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P23_HIGHLEVEL         SFRS=2;PIPS4=0x23;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P24_HIGHLEVEL         SFRS=2;PIPS4=0x24;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P25_HIGHLEVEL         SFRS=2;PIPS4=0x25;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P30_HIGHLEVEL         SFRS=2;PIPS4=0x30;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P31_HIGHLEVEL         SFRS=2;PIPS4=0x31;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P32_HIGHLEVEL         SFRS=2;PIPS4=0x32;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P33_HIGHLEVEL         SFRS=2;PIPS4=0x33;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P34_HIGHLEVEL         SFRS=2;PIPS4=0x34;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P35_HIGHLEVEL         SFRS=2;PIPS4=0x35;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P36_HIGHLEVEL         SFRS=2;PIPS4=0x36;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P37_HIGHLEVEL         SFRS=2;PIPS4=0x37;SFRS=0;PICON&=0xEF;PINEN&=0xEF;PIPEN|=0x10
           
#define    ENABLE_PIT4_P00_FALLINGEDGE       SFRS=2;PIPS4=0x00;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P01_FALLINGEDGE       SFRS=2;PIPS4=0x01;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P02_FALLINGEDGE       SFRS=2;PIPS4=0x02;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P03_FALLINGEDGE       SFRS=2;PIPS4=0x03;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P04_FALLINGEDGE       SFRS=2;PIPS4=0x04;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P05_FALLINGEDGE       SFRS=2;PIPS4=0x05;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P06_FALLINGEDGE       SFRS=2;PIPS4=0x06;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P07_FALLINGEDGE       SFRS=2;PIPS4=0x07;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P10_FALLINGEDGE       SFRS=2;PIPS4=0x10;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P11_FALLINGEDGE       SFRS=2;PIPS4=0x11;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P12_FALLINGEDGE       SFRS=2;PIPS4=0x12;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P13_FALLINGEDGE       SFRS=2;PIPS4=0x13;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P14_FALLINGEDGE       SFRS=2;PIPS4=0x14;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P15_FALLINGEDGE       SFRS=2;PIPS4=0x15;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P16_FALLINGEDGE       SFRS=2;PIPS4=0x16;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P17_FALLINGEDGE       SFRS=2;PIPS4=0x17;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P20_FALLINGEDGE       SFRS=2;PIPS4=0x20;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P21_FALLINGEDGE       SFRS=2;PIPS4=0x21;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P22_FALLINGEDGE       SFRS=2;PIPS4=0x22;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P23_FALLINGEDGE       SFRS=2;PIPS4=0x23;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P24_FALLINGEDGE       SFRS=2;PIPS4=0x24;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P25_FALLINGEDGE       SFRS=2;PIPS4=0x25;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P30_FALLINGEDGE       SFRS=2;PIPS4=0x30;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P31_FALLINGEDGE       SFRS=2;PIPS4=0x31;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P32_FALLINGEDGE       SFRS=2;PIPS4=0x32;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P33_FALLINGEDGE       SFRS=2;PIPS4=0x33;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P34_FALLINGEDGE       SFRS=2;PIPS4=0x34;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P35_FALLINGEDGE       SFRS=2;PIPS4=0x35;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P36_FALLINGEDGE       SFRS=2;PIPS4=0x36;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_PIT4_P37_FALLINGEDGE       SFRS=2;PIPS4=0x37;SFRS=0;PICON|=0x10;PINEN|=0x10;PIPEN&=0xEF
           
#define    ENABLE_PIT4_P00_RISINGEDGE        SFRS=2;PIPS4=0x00;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P01_RISINGEDGE        SFRS=2;PIPS4=0x01;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P02_RISINGEDGE        SFRS=2;PIPS4=0x02;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P03_RISINGEDGE        SFRS=2;PIPS4=0x03;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P04_RISINGEDGE        SFRS=2;PIPS4=0x04;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P05_RISINGEDGE        SFRS=2;PIPS4=0x05;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P06_RISINGEDGE        SFRS=2;PIPS4=0x06;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P07_RISINGEDGE        SFRS=2;PIPS4=0x07;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P10_RISINGEDGE        SFRS=2;PIPS4=0x10;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P11_RISINGEDGE        SFRS=2;PIPS4=0x11;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P12_RISINGEDGE        SFRS=2;PIPS4=0x12;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P13_RISINGEDGE        SFRS=2;PIPS4=0x13;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P14_RISINGEDGE        SFRS=2;PIPS4=0x14;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P15_RISINGEDGE        SFRS=2;PIPS4=0x15;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P16_RISINGEDGE        SFRS=2;PIPS4=0x16;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P17_RISINGEDGE        SFRS=2;PIPS4=0x17;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P20_RISINGEDGE        SFRS=2;PIPS4=0x20;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P21_RISINGEDGE        SFRS=2;PIPS4=0x21;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P22_RISINGEDGE        SFRS=2;PIPS4=0x22;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P23_RISINGEDGE        SFRS=2;PIPS4=0x23;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P24_RISINGEDGE        SFRS=2;PIPS4=0x24;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P25_RISINGEDGE        SFRS=2;PIPS4=0x25;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P30_RISINGEDGE        SFRS=2;PIPS4=0x30;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P31_RISINGEDGE        SFRS=2;PIPS4=0x31;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P32_RISINGEDGE        SFRS=2;PIPS4=0x32;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P33_RISINGEDGE        SFRS=2;PIPS4=0x33;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P34_RISINGEDGE        SFRS=2;PIPS4=0x34;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P35_RISINGEDGE        SFRS=2;PIPS4=0x35;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P36_RISINGEDGE        SFRS=2;PIPS4=0x36;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_PIT4_P37_RISINGEDGE        SFRS=2;PIPS4=0x37;SFRS=0;PICON|=0x10;PINEN&=0xEF;PIPEN|=0x10
           
//-------- -------- Pin interrupt channel 5 PIT5 ------------------------
#define    ENABLE_PIT5_P00_LOWLEVEL          SFRS=2;PIPS5=0x00;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P01_LOWLEVEL          SFRS=2;PIPS5=0x01;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P02_LOWLEVEL          SFRS=2;PIPS5=0x02;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P03_LOWLEVEL          SFRS=2;PIPS5=0x03;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P04_LOWLEVEL          SFRS=2;PIPS5=0x04;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P05_LOWLEVEL          SFRS=2;PIPS5=0x05;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P06_LOWLEVEL          SFRS=2;PIPS5=0x06;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P07_LOWLEVEL          SFRS=2;PIPS5=0x07;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P10_LOWLEVEL          SFRS=2;PIPS5=0x10;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P11_LOWLEVEL          SFRS=2;PIPS5=0x11;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P12_LOWLEVEL          SFRS=2;PIPS5=0x12;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P13_LOWLEVEL          SFRS=2;PIPS5=0x13;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P14_LOWLEVEL          SFRS=2;PIPS5=0x14;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P15_LOWLEVEL          SFRS=2;PIPS5=0x15;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P16_LOWLEVEL          SFRS=2;PIPS5=0x16;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P17_LOWLEVEL          SFRS=2;PIPS5=0x17;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P20_LOWLEVEL          SFRS=2;PIPS5=0x20;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P21_LOWLEVEL          SFRS=2;PIPS5=0x21;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P22_LOWLEVEL          SFRS=2;PIPS5=0x22;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P23_LOWLEVEL          SFRS=2;PIPS5=0x23;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P24_LOWLEVEL          SFRS=2;PIPS5=0x24;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P25_LOWLEVEL          SFRS=2;PIPS5=0x25;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P30_LOWLEVEL          SFRS=2;PIPS5=0x30;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P31_LOWLEVEL          SFRS=2;PIPS5=0x31;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P32_LOWLEVEL          SFRS=2;PIPS5=0x32;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P33_LOWLEVEL          SFRS=2;PIPS5=0x33;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P34_LOWLEVEL          SFRS=2;PIPS5=0x34;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P35_LOWLEVEL          SFRS=2;PIPS5=0x35;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P36_LOWLEVEL          SFRS=2;PIPS5=0x36;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P37_LOWLEVEL          SFRS=2;PIPS5=0x37;SFRS=0;PICON&=0xDF;PINEN|=0x20;PIPEN&=0xDF
           
#define    ENABLE_PIT5_P00_HIGHLEVEL         SFRS=2;PIPS5=0x00;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P01_HIGHLEVEL         SFRS=2;PIPS5=0x01;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P02_HIGHLEVEL         SFRS=2;PIPS5=0x02;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P03_HIGHLEVEL         SFRS=2;PIPS5=0x03;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P04_HIGHLEVEL         SFRS=2;PIPS5=0x04;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P05_HIGHLEVEL         SFRS=2;PIPS5=0x05;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P06_HIGHLEVEL         SFRS=2;PIPS5=0x06;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P07_HIGHLEVEL         SFRS=2;PIPS5=0x07;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P10_HIGHLEVEL         SFRS=2;PIPS5=0x10;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P11_HIGHLEVEL         SFRS=2;PIPS5=0x11;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P12_HIGHLEVEL         SFRS=2;PIPS5=0x12;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P13_HIGHLEVEL         SFRS=2;PIPS5=0x13;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P14_HIGHLEVEL         SFRS=2;PIPS5=0x14;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P15_HIGHLEVEL         SFRS=2;PIPS5=0x15;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P16_HIGHLEVEL         SFRS=2;PIPS5=0x16;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P17_HIGHLEVEL         SFRS=2;PIPS5=0x17;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P20_HIGHLEVEL         SFRS=2;PIPS5=0x20;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P21_HIGHLEVEL         SFRS=2;PIPS5=0x21;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P22_HIGHLEVEL         SFRS=2;PIPS5=0x22;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P23_HIGHLEVEL         SFRS=2;PIPS5=0x23;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P24_HIGHLEVEL         SFRS=2;PIPS5=0x24;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P25_HIGHLEVEL         SFRS=2;PIPS5=0x25;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P30_HIGHLEVEL         SFRS=2;PIPS5=0x30;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P31_HIGHLEVEL         SFRS=2;PIPS5=0x31;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P32_HIGHLEVEL         SFRS=2;PIPS5=0x32;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P33_HIGHLEVEL         SFRS=2;PIPS5=0x33;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P34_HIGHLEVEL         SFRS=2;PIPS5=0x34;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P35_HIGHLEVEL         SFRS=2;PIPS5=0x35;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P36_HIGHLEVEL         SFRS=2;PIPS5=0x36;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P37_HIGHLEVEL         SFRS=2;PIPS5=0x37;SFRS=0;PICON&=0xDF;PINEN&=0xDF;PIPEN|=0x20
           
#define    ENABLE_PIT5_P00_FALLINGEDGE       SFRS=2;PIPS5=0x00;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P01_FALLINGEDGE       SFRS=2;PIPS5=0x01;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P02_FALLINGEDGE       SFRS=2;PIPS5=0x02;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P03_FALLINGEDGE       SFRS=2;PIPS5=0x03;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P04_FALLINGEDGE       SFRS=2;PIPS5=0x04;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P05_FALLINGEDGE       SFRS=2;PIPS5=0x05;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P06_FALLINGEDGE       SFRS=2;PIPS5=0x06;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P07_FALLINGEDGE       SFRS=2;PIPS5=0x07;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P10_FALLINGEDGE       SFRS=2;PIPS5=0x10;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P11_FALLINGEDGE       SFRS=2;PIPS5=0x11;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P12_FALLINGEDGE       SFRS=2;PIPS5=0x12;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P13_FALLINGEDGE       SFRS=2;PIPS5=0x13;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P14_FALLINGEDGE       SFRS=2;PIPS5=0x14;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P15_FALLINGEDGE       SFRS=2;PIPS5=0x15;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P16_FALLINGEDGE       SFRS=2;PIPS5=0x16;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P17_FALLINGEDGE       SFRS=2;PIPS5=0x17;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P20_FALLINGEDGE       SFRS=2;PIPS5=0x20;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P21_FALLINGEDGE       SFRS=2;PIPS5=0x21;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P22_FALLINGEDGE       SFRS=2;PIPS5=0x22;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P23_FALLINGEDGE       SFRS=2;PIPS5=0x23;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P24_FALLINGEDGE       SFRS=2;PIPS5=0x24;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P25_FALLINGEDGE       SFRS=2;PIPS5=0x25;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P30_FALLINGEDGE       SFRS=2;PIPS5=0x30;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P31_FALLINGEDGE       SFRS=2;PIPS5=0x31;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P32_FALLINGEDGE       SFRS=2;PIPS5=0x32;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P33_FALLINGEDGE       SFRS=2;PIPS5=0x33;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P34_FALLINGEDGE       SFRS=2;PIPS5=0x34;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P35_FALLINGEDGE       SFRS=2;PIPS5=0x35;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P36_FALLINGEDGE       SFRS=2;PIPS5=0x36;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_PIT5_P37_FALLINGEDGE       SFRS=2;PIPS5=0x37;SFRS=0;PICON|=0x20;PINEN|=0x20;PIPEN&=0xDF
           
#define    ENABLE_PIT5_P00_RISINGEDGE        SFRS=2;PIPS5=0x00;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P01_RISINGEDGE        SFRS=2;PIPS5=0x01;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P02_RISINGEDGE        SFRS=2;PIPS5=0x02;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P03_RISINGEDGE        SFRS=2;PIPS5=0x03;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P04_RISINGEDGE        SFRS=2;PIPS5=0x04;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P05_RISINGEDGE        SFRS=2;PIPS5=0x05;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P06_RISINGEDGE        SFRS=2;PIPS5=0x06;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P07_RISINGEDGE        SFRS=2;PIPS5=0x07;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P10_RISINGEDGE        SFRS=2;PIPS5=0x10;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P11_RISINGEDGE        SFRS=2;PIPS5=0x11;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P12_RISINGEDGE        SFRS=2;PIPS5=0x12;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P13_RISINGEDGE        SFRS=2;PIPS5=0x13;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P14_RISINGEDGE        SFRS=2;PIPS5=0x14;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P15_RISINGEDGE        SFRS=2;PIPS5=0x15;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P16_RISINGEDGE        SFRS=2;PIPS5=0x16;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P17_RISINGEDGE        SFRS=2;PIPS5=0x17;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P20_RISINGEDGE        SFRS=2;PIPS5=0x20;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P21_RISINGEDGE        SFRS=2;PIPS5=0x21;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P22_RISINGEDGE        SFRS=2;PIPS5=0x22;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P23_RISINGEDGE        SFRS=2;PIPS5=0x23;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P24_RISINGEDGE        SFRS=2;PIPS5=0x24;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P25_RISINGEDGE        SFRS=2;PIPS5=0x25;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P30_RISINGEDGE        SFRS=2;PIPS5=0x30;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P31_RISINGEDGE        SFRS=2;PIPS5=0x31;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P32_RISINGEDGE        SFRS=2;PIPS5=0x32;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P33_RISINGEDGE        SFRS=2;PIPS5=0x33;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P34_RISINGEDGE        SFRS=2;PIPS5=0x34;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P35_RISINGEDGE        SFRS=2;PIPS5=0x35;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P36_RISINGEDGE        SFRS=2;PIPS5=0x36;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_PIT5_P37_RISINGEDGE        SFRS=2;PIPS5=0x37;SFRS=0;PICON|=0x20;PINEN&=0xDF;PIPEN|=0x20
           
//-------- -------- Pin interrupt channel 6 PIT6 ------------------------
#define    ENABLE_PIT6_P00_LOWLEVEL          SFRS=2;PIPS6=0x00;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P01_LOWLEVEL          SFRS=2;PIPS6=0x01;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P02_LOWLEVEL          SFRS=2;PIPS6=0x02;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P03_LOWLEVEL          SFRS=2;PIPS6=0x03;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P04_LOWLEVEL          SFRS=2;PIPS6=0x04;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P05_LOWLEVEL          SFRS=2;PIPS6=0x05;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P06_LOWLEVEL          SFRS=2;PIPS6=0x06;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P07_LOWLEVEL          SFRS=2;PIPS6=0x07;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P10_LOWLEVEL          SFRS=2;PIPS6=0x10;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P11_LOWLEVEL          SFRS=2;PIPS6=0x11;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P12_LOWLEVEL          SFRS=2;PIPS6=0x12;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P13_LOWLEVEL          SFRS=2;PIPS6=0x13;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P14_LOWLEVEL          SFRS=2;PIPS6=0x14;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P15_LOWLEVEL          SFRS=2;PIPS6=0x15;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P16_LOWLEVEL          SFRS=2;PIPS6=0x16;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P17_LOWLEVEL          SFRS=2;PIPS6=0x17;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P20_LOWLEVEL          SFRS=2;PIPS6=0x20;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P21_LOWLEVEL          SFRS=2;PIPS6=0x21;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P22_LOWLEVEL          SFRS=2;PIPS6=0x22;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P23_LOWLEVEL          SFRS=2;PIPS6=0x23;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P24_LOWLEVEL          SFRS=2;PIPS6=0x24;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P25_LOWLEVEL          SFRS=2;PIPS6=0x25;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P30_LOWLEVEL          SFRS=2;PIPS6=0x30;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P31_LOWLEVEL          SFRS=2;PIPS6=0x31;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P32_LOWLEVEL          SFRS=2;PIPS6=0x32;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P33_LOWLEVEL          SFRS=2;PIPS6=0x33;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P34_LOWLEVEL          SFRS=2;PIPS6=0x34;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P35_LOWLEVEL          SFRS=2;PIPS6=0x35;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P36_LOWLEVEL          SFRS=2;PIPS6=0x36;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P37_LOWLEVEL          SFRS=2;PIPS6=0x37;SFRS=0;PICON&=0xBF;PINEN|=0x40;PIPEN&=0xBF
           
#define    ENABLE_PIT6_P00_HIGHLEVEL         SFRS=2;PIPS6=0x00;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P01_HIGHLEVEL         SFRS=2;PIPS6=0x01;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P02_HIGHLEVEL         SFRS=2;PIPS6=0x02;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P03_HIGHLEVEL         SFRS=2;PIPS6=0x03;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P04_HIGHLEVEL         SFRS=2;PIPS6=0x04;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P05_HIGHLEVEL         SFRS=2;PIPS6=0x05;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P06_HIGHLEVEL         SFRS=2;PIPS6=0x06;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P07_HIGHLEVEL         SFRS=2;PIPS6=0x07;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P10_HIGHLEVEL         SFRS=2;PIPS6=0x10;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P11_HIGHLEVEL         SFRS=2;PIPS6=0x11;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P12_HIGHLEVEL         SFRS=2;PIPS6=0x12;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P13_HIGHLEVEL         SFRS=2;PIPS6=0x13;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P14_HIGHLEVEL         SFRS=2;PIPS6=0x14;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P15_HIGHLEVEL         SFRS=2;PIPS6=0x15;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P16_HIGHLEVEL         SFRS=2;PIPS6=0x16;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P17_HIGHLEVEL         SFRS=2;PIPS6=0x17;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P20_HIGHLEVEL         SFRS=2;PIPS6=0x20;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P21_HIGHLEVEL         SFRS=2;PIPS6=0x21;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P22_HIGHLEVEL         SFRS=2;PIPS6=0x22;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P23_HIGHLEVEL         SFRS=2;PIPS6=0x23;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P24_HIGHLEVEL         SFRS=2;PIPS6=0x24;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P25_HIGHLEVEL         SFRS=2;PIPS6=0x25;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P30_HIGHLEVEL         SFRS=2;PIPS6=0x30;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P31_HIGHLEVEL         SFRS=2;PIPS6=0x31;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P32_HIGHLEVEL         SFRS=2;PIPS6=0x32;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P33_HIGHLEVEL         SFRS=2;PIPS6=0x33;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P34_HIGHLEVEL         SFRS=2;PIPS6=0x34;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P35_HIGHLEVEL         SFRS=2;PIPS6=0x35;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P36_HIGHLEVEL         SFRS=2;PIPS6=0x36;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P37_HIGHLEVEL         SFRS=2;PIPS6=0x37;SFRS=0;PICON&=0xBF;PINEN&=0xBF;PIPEN|=0x40
           
#define    ENABLE_PIT6_P00_FALLINGEDGE       SFRS=2;PIPS6=0x00;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P01_FALLINGEDGE       SFRS=2;PIPS6=0x01;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P02_FALLINGEDGE       SFRS=2;PIPS6=0x02;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P03_FALLINGEDGE       SFRS=2;PIPS6=0x03;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P04_FALLINGEDGE       SFRS=2;PIPS6=0x04;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P05_FALLINGEDGE       SFRS=2;PIPS6=0x05;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P06_FALLINGEDGE       SFRS=2;PIPS6=0x06;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P07_FALLINGEDGE       SFRS=2;PIPS6=0x07;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P10_FALLINGEDGE       SFRS=2;PIPS6=0x10;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P11_FALLINGEDGE       SFRS=2;PIPS6=0x11;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P12_FALLINGEDGE       SFRS=2;PIPS6=0x12;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P13_FALLINGEDGE       SFRS=2;PIPS6=0x13;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P14_FALLINGEDGE       SFRS=2;PIPS6=0x14;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P15_FALLINGEDGE       SFRS=2;PIPS6=0x15;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P16_FALLINGEDGE       SFRS=2;PIPS6=0x16;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P17_FALLINGEDGE       SFRS=2;PIPS6=0x17;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P20_FALLINGEDGE       SFRS=2;PIPS6=0x20;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P21_FALLINGEDGE       SFRS=2;PIPS6=0x21;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P22_FALLINGEDGE       SFRS=2;PIPS6=0x22;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P23_FALLINGEDGE       SFRS=2;PIPS6=0x23;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P24_FALLINGEDGE       SFRS=2;PIPS6=0x24;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P25_FALLINGEDGE       SFRS=2;PIPS6=0x25;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P30_FALLINGEDGE       SFRS=2;PIPS6=0x30;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P31_FALLINGEDGE       SFRS=2;PIPS6=0x31;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P32_FALLINGEDGE       SFRS=2;PIPS6=0x32;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P33_FALLINGEDGE       SFRS=2;PIPS6=0x33;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P34_FALLINGEDGE       SFRS=2;PIPS6=0x34;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P35_FALLINGEDGE       SFRS=2;PIPS6=0x35;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P36_FALLINGEDGE       SFRS=2;PIPS6=0x36;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_PIT6_P37_FALLINGEDGE       SFRS=2;PIPS6=0x37;SFRS=0;PICON|=0x40;PINEN|=0x40;PIPEN&=0xBF
             
#define    ENABLE_PIT6_P00_RISINGEDGE        SFRS=2;PIPS6=0x00;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P01_RISINGEDGE        SFRS=2;PIPS6=0x01;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P02_RISINGEDGE        SFRS=2;PIPS6=0x02;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P03_RISINGEDGE        SFRS=2;PIPS6=0x03;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P04_RISINGEDGE        SFRS=2;PIPS6=0x04;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P05_RISINGEDGE        SFRS=2;PIPS6=0x05;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P06_RISINGEDGE        SFRS=2;PIPS6=0x06;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P07_RISINGEDGE        SFRS=2;PIPS6=0x07;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P10_RISINGEDGE        SFRS=2;PIPS6=0x10;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P11_RISINGEDGE        SFRS=2;PIPS6=0x11;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P12_RISINGEDGE        SFRS=2;PIPS6=0x12;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P13_RISINGEDGE        SFRS=2;PIPS6=0x13;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P14_RISINGEDGE        SFRS=2;PIPS6=0x14;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P15_RISINGEDGE        SFRS=2;PIPS6=0x15;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P16_RISINGEDGE        SFRS=2;PIPS6=0x16;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P17_RISINGEDGE        SFRS=2;PIPS6=0x17;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P20_RISINGEDGE        SFRS=2;PIPS6=0x20;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P21_RISINGEDGE        SFRS=2;PIPS6=0x21;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P22_RISINGEDGE        SFRS=2;PIPS6=0x22;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P23_RISINGEDGE        SFRS=2;PIPS6=0x23;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P24_RISINGEDGE        SFRS=2;PIPS6=0x24;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P25_RISINGEDGE        SFRS=2;PIPS6=0x25;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P30_RISINGEDGE        SFRS=2;PIPS6=0x30;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P31_RISINGEDGE        SFRS=2;PIPS6=0x31;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P32_RISINGEDGE        SFRS=2;PIPS6=0x32;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P33_RISINGEDGE        SFRS=2;PIPS6=0x33;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P34_RISINGEDGE        SFRS=2;PIPS6=0x34;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P35_RISINGEDGE        SFRS=2;PIPS6=0x35;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P36_RISINGEDGE        SFRS=2;PIPS6=0x36;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_PIT6_P37_RISINGEDGE        SFRS=2;PIPS6=0x37;SFRS=0;PICON|=0x40;PINEN&=0xBF;PIPEN|=0x40
//---------------- Pin interrupt channel 7 PIT7 ------------------------
#define    ENABLE_PIT7_P00_LOWLEVEL          SFRS=2;PIPS7=0x00;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P01_LOWLEVEL          SFRS=2;PIPS7=0x01;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P02_LOWLEVEL          SFRS=2;PIPS7=0x02;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P03_LOWLEVEL          SFRS=2;PIPS7=0x03;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P04_LOWLEVEL          SFRS=2;PIPS7=0x04;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P05_LOWLEVEL          SFRS=2;PIPS7=0x05;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P06_LOWLEVEL          SFRS=2;PIPS7=0x06;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P07_LOWLEVEL          SFRS=2;PIPS7=0x07;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P10_LOWLEVEL          SFRS=2;PIPS7=0x10;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P11_LOWLEVEL          SFRS=2;PIPS7=0x11;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P12_LOWLEVEL          SFRS=2;PIPS7=0x12;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P13_LOWLEVEL          SFRS=2;PIPS7=0x13;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P14_LOWLEVEL          SFRS=2;PIPS7=0x14;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P15_LOWLEVEL          SFRS=2;PIPS7=0x15;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P16_LOWLEVEL          SFRS=2;PIPS7=0x16;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P17_LOWLEVEL          SFRS=2;PIPS7=0x17;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P20_LOWLEVEL          SFRS=2;PIPS7=0x20;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P21_LOWLEVEL          SFRS=2;PIPS7=0x21;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P22_LOWLEVEL          SFRS=2;PIPS7=0x22;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P23_LOWLEVEL          SFRS=2;PIPS7=0x23;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P24_LOWLEVEL          SFRS=2;PIPS7=0x24;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P25_LOWLEVEL          SFRS=2;PIPS7=0x25;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P30_LOWLEVEL          SFRS=2;PIPS7=0x30;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P31_LOWLEVEL          SFRS=2;PIPS7=0x31;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P32_LOWLEVEL          SFRS=2;PIPS7=0x32;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P33_LOWLEVEL          SFRS=2;PIPS7=0x33;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P34_LOWLEVEL          SFRS=2;PIPS7=0x34;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P35_LOWLEVEL          SFRS=2;PIPS7=0x35;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P36_LOWLEVEL          SFRS=2;PIPS7=0x36;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P37_LOWLEVEL          SFRS=2;PIPS7=0x37;SFRS=0;PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
           
#define    ENABLE_PIT7_P00_HIGHLEVEL         SFRS=2;PIPS7=0x00;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P01_HIGHLEVEL         SFRS=2;PIPS7=0x01;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P02_HIGHLEVEL         SFRS=2;PIPS7=0x02;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P03_HIGHLEVEL         SFRS=2;PIPS7=0x03;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P04_HIGHLEVEL         SFRS=2;PIPS7=0x04;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P05_HIGHLEVEL         SFRS=2;PIPS7=0x05;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P06_HIGHLEVEL         SFRS=2;PIPS7=0x06;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P07_HIGHLEVEL         SFRS=2;PIPS7=0x07;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P10_HIGHLEVEL         SFRS=2;PIPS7=0x10;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P11_HIGHLEVEL         SFRS=2;PIPS7=0x11;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P12_HIGHLEVEL         SFRS=2;PIPS7=0x12;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P13_HIGHLEVEL         SFRS=2;PIPS7=0x13;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P14_HIGHLEVEL         SFRS=2;PIPS7=0x14;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P15_HIGHLEVEL         SFRS=2;PIPS7=0x15;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P16_HIGHLEVEL         SFRS=2;PIPS7=0x16;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P17_HIGHLEVEL         SFRS=2;PIPS7=0x17;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P20_HIGHLEVEL         SFRS=2;PIPS7=0x20;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P21_HIGHLEVEL         SFRS=2;PIPS7=0x21;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P22_HIGHLEVEL         SFRS=2;PIPS7=0x22;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P23_HIGHLEVEL         SFRS=2;PIPS7=0x23;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P24_HIGHLEVEL         SFRS=2;PIPS7=0x24;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P25_HIGHLEVEL         SFRS=2;PIPS7=0x25;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P30_HIGHLEVEL         SFRS=2;PIPS7=0x30;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P31_HIGHLEVEL         SFRS=2;PIPS7=0x31;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P32_HIGHLEVEL         SFRS=2;PIPS7=0x32;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P33_HIGHLEVEL         SFRS=2;PIPS7=0x33;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P34_HIGHLEVEL         SFRS=2;PIPS7=0x34;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P35_HIGHLEVEL         SFRS=2;PIPS7=0x35;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P36_HIGHLEVEL         SFRS=2;PIPS7=0x36;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P37_HIGHLEVEL         SFRS=2;PIPS7=0x37;SFRS=0;PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
           
#define    ENABLE_PIT7_P00_FALLINGEDGE       SFRS=2;PIPS7=0x00;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P01_FALLINGEDGE       SFRS=2;PIPS7=0x01;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P02_FALLINGEDGE       SFRS=2;PIPS7=0x02;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P03_FALLINGEDGE       SFRS=2;PIPS7=0x03;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P04_FALLINGEDGE       SFRS=2;PIPS7=0x04;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P05_FALLINGEDGE       SFRS=2;PIPS7=0x05;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P06_FALLINGEDGE       SFRS=2;PIPS7=0x06;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P07_FALLINGEDGE       SFRS=2;PIPS7=0x07;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P10_FALLINGEDGE       SFRS=2;PIPS7=0x10;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P11_FALLINGEDGE       SFRS=2;PIPS7=0x11;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P12_FALLINGEDGE       SFRS=2;PIPS7=0x12;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P13_FALLINGEDGE       SFRS=2;PIPS7=0x13;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P14_FALLINGEDGE       SFRS=2;PIPS7=0x14;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P15_FALLINGEDGE       SFRS=2;PIPS7=0x15;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P16_FALLINGEDGE       SFRS=2;PIPS7=0x16;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P17_FALLINGEDGE       SFRS=2;PIPS7=0x17;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P20_FALLINGEDGE       SFRS=2;PIPS7=0x20;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P21_FALLINGEDGE       SFRS=2;PIPS7=0x21;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P22_FALLINGEDGE       SFRS=2;PIPS7=0x22;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P23_FALLINGEDGE       SFRS=2;PIPS7=0x23;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P24_FALLINGEDGE       SFRS=2;PIPS7=0x24;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P25_FALLINGEDGE       SFRS=2;PIPS7=0x25;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P30_FALLINGEDGE       SFRS=2;PIPS7=0x30;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P31_FALLINGEDGE       SFRS=2;PIPS7=0x31;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P32_FALLINGEDGE       SFRS=2;PIPS7=0x32;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P33_FALLINGEDGE       SFRS=2;PIPS7=0x33;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P34_FALLINGEDGE       SFRS=2;PIPS7=0x34;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P35_FALLINGEDGE       SFRS=2;PIPS7=0x35;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P36_FALLINGEDGE       SFRS=2;PIPS7=0x36;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_PIT7_P37_FALLINGEDGE       SFRS=2;PIPS7=0x37;SFRS=0;PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
             
#define    ENABLE_PIT7_P00_RISINGEDGE        SFRS=2;PIPS7=0x00;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P01_RISINGEDGE        SFRS=2;PIPS7=0x01;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P02_RISINGEDGE        SFRS=2;PIPS7=0x02;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P03_RISINGEDGE        SFRS=2;PIPS7=0x03;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P04_RISINGEDGE        SFRS=2;PIPS7=0x04;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P05_RISINGEDGE        SFRS=2;PIPS7=0x05;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P06_RISINGEDGE        SFRS=2;PIPS7=0x06;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P07_RISINGEDGE        SFRS=2;PIPS7=0x07;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P10_RISINGEDGE        SFRS=2;PIPS7=0x10;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P11_RISINGEDGE        SFRS=2;PIPS7=0x11;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P12_RISINGEDGE        SFRS=2;PIPS7=0x12;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P13_RISINGEDGE        SFRS=2;PIPS7=0x13;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P14_RISINGEDGE        SFRS=2;PIPS7=0x14;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P15_RISINGEDGE        SFRS=2;PIPS7=0x15;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P16_RISINGEDGE        SFRS=2;PIPS7=0x16;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P17_RISINGEDGE        SFRS=2;PIPS7=0x17;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P20_RISINGEDGE        SFRS=2;PIPS7=0x20;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P21_RISINGEDGE        SFRS=2;PIPS7=0x21;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P22_RISINGEDGE        SFRS=2;PIPS7=0x22;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P23_RISINGEDGE        SFRS=2;PIPS7=0x23;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P24_RISINGEDGE        SFRS=2;PIPS7=0x24;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P25_RISINGEDGE        SFRS=2;PIPS7=0x25;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P30_RISINGEDGE        SFRS=2;PIPS7=0x30;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P31_RISINGEDGE        SFRS=2;PIPS7=0x31;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P32_RISINGEDGE        SFRS=2;PIPS7=0x32;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P33_RISINGEDGE        SFRS=2;PIPS7=0x33;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P34_RISINGEDGE        SFRS=2;PIPS7=0x34;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P35_RISINGEDGE        SFRS=2;PIPS7=0x35;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P36_RISINGEDGE        SFRS=2;PIPS7=0x36;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_PIT7_P37_RISINGEDGE        SFRS=2;PIPS7=0x37;SFRS=0;PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
                                                      
#define    DISABLE_ALL_PIT                   SFRS=0;PICON=0
/*****************************************************************************************/
/* For GPIO Mode setting                                                                 */
/*****************************************************************************************/
/*------------------- Define Port as Quasi mode  -------------------*/
#define    P00_QUASI_MODE         SFRS=0;P0M1&=0xFE;P0M2&=0xFE
#define    P01_QUASI_MODE         SFRS=0;P0M1&=0xFD;P0M2&=0xFD
#define    P02_QUASI_MODE         SFRS=0;P0M1&=0xFB;P0M2&=0xFB
#define    P03_QUASI_MODE         SFRS=0;P0M1&=0xF7;P0M2&=0xF7
#define    P04_QUASI_MODE         SFRS=0;P0M1&=0xEF;P0M2&=0xEF
#define    P05_QUASI_MODE         SFRS=0;P0M1&=0xDF;P0M2&=0xDF
#define    P06_QUASI_MODE         SFRS=0;P0M1&=0xBF;P0M2&=0xBF
#define    P07_QUASI_MODE         SFRS=0;P0M1&=0x7F;P0M2&=0x7F
#define    P10_QUASI_MODE         SFRS=0;P1M1&=0xFE;P1M2&=0xFE
#define    P11_QUASI_MODE         SFRS=0;P1M1&=0xFD;P1M2&=0xFD
#define    P12_QUASI_MODE         SFRS=0;P1M1&=0xFB;P1M2&=0xFB
#define    P13_QUASI_MODE         SFRS=0;P1M1&=0xF7;P1M2&=0xF7
#define    P14_QUASI_MODE         SFRS=0;P1M1&=0xEF;P1M2&=0xEF
#define    P15_QUASI_MODE         SFRS=0;P1M1&=0xDF;P1M2&=0xDF
#define    P16_QUASI_MODE         SFRS=0;P1M1&=0xBF;P1M2&=0xBF
#define    P17_QUASI_MODE         SFRS=0;P1M1&=0x7F;P1M2&=0x7F
#define    P20_QUASI_MODE         SFRS=2;P2M1&=0xFE;P2M2&=0xFE
#define    P21_QUASI_MODE         SFRS=2;P2M1&=0xFD;P2M2&=0xFD
#define    P22_QUASI_MODE         SFRS=2;P2M1&=0xFB;P2M2&=0xFB
#define    P23_QUASI_MODE         SFRS=2;P2M1&=0xF7;P2M2&=0xF7
#define    P24_QUASI_MODE         SFRS=2;P2M1&=0xEF;P2M2&=0xEF
#define    P25_QUASI_MODE         SFRS=2;P2M1&=0xDF;P2M2&=0xDF
#define    P30_QUASI_MODE         SFRS=0;P3M1&=0xFE;P3M2&=0xFE
#define    P31_QUASI_MODE         SFRS=0;P3M1&=0xFD;P3M2&=0xFD
#define    P32_QUASI_MODE         SFRS=0;P3M1&=0xFB;P3M2&=0xFB
#define    P33_QUASI_MODE         SFRS=0;P3M1&=0xF7;P3M2&=0xF7
#define    P34_QUASI_MODE         SFRS=0;P3M1&=0xEF;P3M2&=0xEF
#define    P35_QUASI_MODE         SFRS=0;P3M1&=0xDF;P3M2&=0xDF
#define    P36_QUASI_MODE         SFRS=0;P3M1&=0xBF;P3M2&=0xBF
#define    P37_QUASI_MODE         SFRS=0;P3M1&=0x7F;P3M2&=0x7F
#define    ALL_GPIO_QUASI_MODE         SFRS=0;P0M1=0x00;P0M2=0x00;P1M1=0x00;P1M2=0x00;SFRS=2;P2M1=0x00;P2M2=0x00;SFRS=0;P3M1=0x00;P3M2=0x00
//------------------- Define Port as Push Pull mode -------------------*/
#define    P00_PUSHPULL_MODE      SFRS=0;P0M1&=0xFE;P0M2|=0x01
#define    P01_PUSHPULL_MODE      SFRS=0;P0M1&=0xFD;P0M2|=0x02
#define    P02_PUSHPULL_MODE      SFRS=0;P0M1&=0xFB;P0M2|=0x04
#define    P03_PUSHPULL_MODE      SFRS=0;P0M1&=0xF7;P0M2|=0x08
#define    P04_PUSHPULL_MODE      SFRS=0;P0M1&=0xEF;P0M2|=0x10
#define    P05_PUSHPULL_MODE      SFRS=0;P0M1&=0xDF;P0M2|=0x20
#define    P06_PUSHPULL_MODE      SFRS=0;P0M1&=0xBF;P0M2|=0x40
#define    P07_PUSHPULL_MODE      SFRS=0;P0M1&=0x7F;P0M2|=0x80
#define    P10_PUSHPULL_MODE      SFRS=0;P1M1&=0xFE;P1M2|=0x01
#define    P11_PUSHPULL_MODE      SFRS=0;P1M1&=0xFD;P1M2|=0x02
#define    P12_PUSHPULL_MODE      SFRS=0;P1M1&=0xFB;P1M2|=0x04
#define    P13_PUSHPULL_MODE      SFRS=0;P1M1&=0xF7;P1M2|=0x08
#define    P14_PUSHPULL_MODE      SFRS=0;P1M1&=0xEF;P1M2|=0x10
#define    P15_PUSHPULL_MODE      SFRS=0;P1M1&=0xDF;P1M2|=0x20
#define    P16_PUSHPULL_MODE      SFRS=0;P1M1&=0xBF;P1M2|=0x40
#define    P17_PUSHPULL_MODE      SFRS=0;P1M1&=0x7F;P1M2|=0x80
#define    P20_PUSHPULL_MODE      SFRS=2;P2M1&=0xFE;P2M2|=0x01
#define    P21_PUSHPULL_MODE      SFRS=2;P2M1&=0xFD;P2M2|=0x02
#define    P22_PUSHPULL_MODE      SFRS=2;P2M1&=0xFB;P2M2|=0x04
#define    P23_PUSHPULL_MODE      SFRS=2;P2M1&=0xF7;P2M2|=0x08
#define    P24_PUSHPULL_MODE      SFRS=2;P2M1&=0xEF;P2M2|=0x10
#define    P25_PUSHPULL_MODE      SFRS=2;P2M1&=0xDF;P2M2|=0x20
#define    P30_PUSHPULL_MODE      SFRS=0;P3M1&=0xFE;P3M2|=0x01
#define    P31_PUSHPULL_MODE      SFRS=0;P3M1&=0xFD;P3M2|=0x02
#define    P32_PUSHPULL_MODE      SFRS=0;P3M1&=0xFB;P3M2|=0x04
#define    P33_PUSHPULL_MODE      SFRS=0;P3M1&=0xF7;P3M2|=0x08
#define    P34_PUSHPULL_MODE      SFRS=0;P3M1&=0xEF;P3M2|=0x10
#define    P35_PUSHPULL_MODE      SFRS=0;P3M1&=0xDF;P3M2|=0x20
#define    P36_PUSHPULL_MODE      SFRS=0;P3M1&=0xBF;P3M2|=0x40
#define    P37_PUSHPULL_MODE      SFRS=0;P3M1&=0x7F;P3M2|=0x80
#define    ALL_GPIO_PUSHPULL_MODE         SFRS=0;P0M1=0x00;P0M2=0xFF;P1M1=0x00;P1M2=0xFF;SFRS=2;P2M1=0x00;P2M2=0xFF;SFRS=0;P3M1=0x00;P3M2=0xFF
//------------------- Define Port as Input Only mode -------------------*/
#define    P00_INPUT_MODE         SFRS=0;P0M1|=0x01;P0M2&=0xFE
#define    P01_INPUT_MODE         SFRS=0;P0M1|=0x02;P0M2&=0xFD
#define    P02_INPUT_MODE         SFRS=0;P0M1|=0x04;P0M2&=0xFB
#define    P03_INPUT_MODE         SFRS=0;P0M1|=0x08;P0M2&=0xF7
#define    P04_INPUT_MODE         SFRS=0;P0M1|=0x10;P0M2&=0xEF
#define    P05_INPUT_MODE         SFRS=0;P0M1|=0x20;P0M2&=0xDF
#define    P06_INPUT_MODE         SFRS=0;P0M1|=0x40;P0M2&=0xBF
#define    P07_INPUT_MODE         SFRS=0;P0M1|=0x80;P0M2&=0x7F
#define    P10_INPUT_MODE         SFRS=0;P1M1|=0x01;P1M2&=0xFE
#define    P11_INPUT_MODE         SFRS=0;P1M1|=0x02;P1M2&=0xFD
#define    P12_INPUT_MODE         SFRS=0;P1M1|=0x04;P1M2&=0xFB
#define    P13_INPUT_MODE         SFRS=0;P1M1|=0x08;P1M2&=0xF7
#define    P14_INPUT_MODE         SFRS=0;P1M1|=0x10;P1M2&=0xEF
#define    P15_INPUT_MODE         SFRS=0;P1M1|=0x20;P1M2&=0xDF
#define    P16_INPUT_MODE         SFRS=0;P1M1|=0x40;P1M2&=0xBF
#define    P17_INPUT_MODE         SFRS=0;P1M1|=0x80;P1M2&=0x7F
#define    P20_INPUT_MODE         SFRS=2;P2M1|=0x01;P2M2&=0xFE
#define    P21_INPUT_MODE         SFRS=2;P2M1|=0x02;P2M2&=0xFD
#define    P22_INPUT_MODE         SFRS=2;P2M1|=0x04;P2M2&=0xFB
#define    P23_INPUT_MODE         SFRS=2;P2M1|=0x08;P2M2&=0xF7
#define    P24_INPUT_MODE         SFRS=2;P2M1|=0x10;P2M2&=0xEF
#define    P25_INPUT_MODE         SFRS=2;P2M1|=0x20;P2M2&=0xDF
#define    P26_INPUT_MODE         SFRS=2;P2M1|=0x40;P2M2&=0xBF
#define    P27_INPUT_MODE         SFRS=2;P2M1|=0x80;P2M2&=0x7F
#define    P30_INPUT_MODE         SFRS=0;P3M1|=0x01;P3M2&=0xFE
#define    P31_INPUT_MODE         SFRS=0;P3M1|=0x02;P3M2&=0xFD
#define    P32_INPUT_MODE         SFRS=0;P3M1|=0x04;P3M2&=0xFB
#define    P33_INPUT_MODE         SFRS=0;P3M1|=0x08;P3M2&=0xF7
#define    P34_INPUT_MODE         SFRS=0;P3M1|=0x10;P3M2&=0xEF
#define    P35_INPUT_MODE         SFRS=0;P3M1|=0x20;P3M2&=0xDF
#define    P36_INPUT_MODE         SFRS=0;P3M1|=0x40;P3M2&=0xBF
#define    P37_INPUT_MODE         SFRS=0;P3M1|=0x80;P3M2&=0x7F
#define    ALL_GPIO_INPUT_MODE         SFRS=0;P0M1=0xFF;P0M2=0x00;P1M1=0xFF;P1M2=0x00;SFRS=2;P2M1=0xFF;P2M2=0x00;SFRS=0;P3M1=0xFF;P3M2=0x00
//-------------------Define Port as Open Drain mode -------------------*/
#define    P00_OPENDRAIN_MODE     SFRS=0;P0M1|=0x01;P0M2|=0x01
#define    P01_OPENDRAIN_MODE     SFRS=0;P0M1|=0x02;P0M2|=0x02
#define    P02_OPENDRAIN_MODE     SFRS=0;P0M1|=0x04;P0M2|=0x04
#define    P03_OPENDRAIN_MODE     SFRS=0;P0M1|=0x08;P0M2|=0x08
#define    P04_OPENDRAIN_MODE     SFRS=0;P0M1|=0x10;P0M2|=0x10
#define    P05_OPENDRAIN_MODE     SFRS=0;P0M1|=0x20;P0M2|=0x20
#define    P06_OPENDRAIN_MODE     SFRS=0;P0M1|=0x40;P0M2|=0x40
#define    P07_OPENDRAIN_MODE     SFRS=0;P0M1|=0x80;P0M2|=0x80
#define    P10_OPENDRAIN_MODE     SFRS=0;P1M1|=0x01;P1M2|=0x01
#define    P11_OPENDRAIN_MODE     SFRS=0;P1M1|=0x02;P1M2|=0x02
#define    P12_OPENDRAIN_MODE     SFRS=0;P1M1|=0x04;P1M2|=0x04
#define    P13_OPENDRAIN_MODE     SFRS=0;P1M1|=0x08;P1M2|=0x08
#define    P14_OPENDRAIN_MODE     SFRS=0;P1M1|=0x10;P1M2|=0x10
#define    P15_OPENDRAIN_MODE     SFRS=0;P1M1|=0x20;P1M2|=0x20
#define    P16_OPENDRAIN_MODE     SFRS=0;P1M1|=0x40;P1M2|=0x40
#define    P17_OPENDRAIN_MODE     SFRS=0;P1M1|=0x80;P1M2|=0x80
#define    P20_OPENDRAIN_MODE     SFRS=2;P2M1|=0x01;P2M2|=0x01
#define    P21_OPENDRAIN_MODE     SFRS=2;P2M1|=0x02;P2M2|=0x02
#define    P22_OPENDRAIN_MODE     SFRS=2;P2M1|=0x04;P2M2|=0x04
#define    P23_OPENDRAIN_MODE     SFRS=2;P2M1|=0x08;P2M2|=0x08
#define    P24_OPENDRAIN_MODE     SFRS=2;P2M1|=0x10;P2M2|=0x10
#define    P25_OPENDRAIN_MODE     SFRS=2;P2M1|=0x20;P2M2|=0x20
#define    P30_OPENDRAIN_MODE     SFRS=0;P3M1|=0x01;P3M2|=0x01
#define    P31_OPENDRAIN_MODE     SFRS=0;P3M1|=0x02;P3M2|=0x02
#define    P32_OPENDRAIN_MODE     SFRS=0;P3M1|=0x04;P3M2|=0x04
#define    P33_OPENDRAIN_MODE     SFRS=0;P3M1|=0x08;P3M2|=0x08
#define    P34_OPENDRAIN_MODE     SFRS=0;P3M1|=0x10;P3M2|=0x10
#define    P35_OPENDRAIN_MODE     SFRS=0;P3M1|=0x20;P3M2|=0x20
#define    P36_OPENDRAIN_MODE     SFRS=0;P3M1|=0x40;P3M2|=0x40
#define    P37_OPENDRAIN_MODE     SFRS=0;P3M1|=0x80;P3M2|=0x80
#define    ALL_GPIO_OPENDRAIN_MODE         SFRS=0;P0M1=0xFF;P0M2=0xFF;P1M1=0xFF;P1M2=0xFF;SFRS=2;P2M1=0xFF;P2M2=0xFF;SFRS=0;P3M1=0xFF;P3M2=0xFF
/*****************************************************************************************/
/* For GPIO internal pull up/pull down setting                                                                 */
/*****************************************************************************************/
/*------------------- GPIO pull up enable -------------------*/  
#define    ENABLE_P00_PULLUP       set_P0UP_0;SFRS=0
#define    ENABLE_P01_PULLUP       set_P0UP_1;SFRS=0
#define    ENABLE_P02_PULLUP       set_P0UP_2;SFRS=0
#define    ENABLE_P03_PULLUP       set_P0UP_3;SFRS=0
#define    ENABLE_P04_PULLUP       set_P0UP_4;SFRS=0
#define    ENABLE_P05_PULLUP       set_P0UP_5;SFRS=0
#define    ENABLE_P06_PULLUP       set_P0UP_6;SFRS=0
#define    ENABLE_P07_PULLUP       set_P0UP_7;SFRS=0
#define    ENABLE_P10_PULLUP       set_P1UP_0;SFRS=0
#define    ENABLE_P11_PULLUP       set_P1UP_1;SFRS=0
#define    ENABLE_P12_PULLUP       set_P1UP_2;SFRS=0
#define    ENABLE_P13_PULLUP       set_P1UP_3;SFRS=0
#define    ENABLE_P14_PULLUP       set_P1UP_4;SFRS=0
#define    ENABLE_P15_PULLUP       set_P1UP_5;SFRS=0
#define    ENABLE_P16_PULLUP       set_P1UP_6;SFRS=0
#define    ENABLE_P17_PULLUP       set_P1UP_7;SFRS=0
#define    ENABLE_P20_PULLUP       set_P2UP_0;SFRS=0
#define    ENABLE_P21_PULLUP       set_P2UP_1;SFRS=0
#define    ENABLE_P22_PULLUP       set_P2UP_2;SFRS=0
#define    ENABLE_P23_PULLUP       set_P2UP_3;SFRS=0
#define    ENABLE_P24_PULLUP       set_P2UP_4;SFRS=0
#define    ENABLE_P25_PULLUP       set_P2UP_5;SFRS=0
#define    ENABLE_P30_PULLUP       set_P3UP_0;SFRS=0
#define    ENABLE_P31_PULLUP       set_P3UP_1;SFRS=0
#define    ENABLE_P32_PULLUP       set_P3UP_2;SFRS=0
#define    ENABLE_P33_PULLUP       set_P3UP_3;SFRS=0
#define    ENABLE_P34_PULLUP       set_P3UP_4;SFRS=0
#define    ENABLE_P35_PULLUP       set_P3UP_5;SFRS=0
#define    ENABLE_P36_PULLUP       set_P3UP_6;SFRS=0
#define    ENABLE_P37_PULLUP       set_P3UP_7;SFRS=0
/*------------------- GPIO pull up disable -------------------*/                              
#define    DISABLE_P00_PULLUP      clr_P0UP_0;SFRS=0
#define    DISABLE_P01_PULLUP      clr_P0UP_1;SFRS=0
#define    DISABLE_P02_PULLUP      clr_P0UP_2;SFRS=0
#define    DISABLE_P03_PULLUP      clr_P0UP_3;SFRS=0
#define    DISABLE_P04_PULLUP      clr_P0UP_4;SFRS=0
#define    DISABLE_P05_PULLUP      clr_P0UP_5;SFRS=0
#define    DISABLE_P06_PULLUP      clr_P0UP_6;SFRS=0
#define    DISABLE_P07_PULLUP      clr_P0UP_7;SFRS=0
#define    DISABLE_P10_PULLUP      clr_P1UP_0;SFRS=0
#define    DISABLE_P11_PULLUP      clr_P1UP_1;SFRS=0
#define    DISABLE_P12_PULLUP      clr_P1UP_2;SFRS=0
#define    DISABLE_P13_PULLUP      clr_P1UP_3;SFRS=0
#define    DISABLE_P14_PULLUP      clr_P1UP_4;SFRS=0
#define    DISABLE_P15_PULLUP      clr_P1UP_5;SFRS=0
#define    DISABLE_P16_PULLUP      clr_P1UP_6;SFRS=0
#define    DISABLE_P17_PULLUP      clr_P1UP_7;SFRS=0
#define    DISABLE_P20_PULLUP      clr_P2UP_0;SFRS=0
#define    DISABLE_P21_PULLUP      clr_P2UP_1;SFRS=0
#define    DISABLE_P22_PULLUP      clr_P2UP_2;SFRS=0
#define    DISABLE_P23_PULLUP      clr_P2UP_3;SFRS=0
#define    DISABLE_P24_PULLUP      clr_P2UP_4;SFRS=0
#define    DISABLE_P25_PULLUP      clr_P2UP_5;SFRS=0
#define    DISABLE_P30_PULLUP      clr_P3UP_0;SFRS=0
#define    DISABLE_P31_PULLUP      clr_P3UP_1;SFRS=0
#define    DISABLE_P32_PULLUP      clr_P3UP_2;SFRS=0
#define    DISABLE_P33_PULLUP      clr_P3UP_3;SFRS=0
#define    DISABLE_P34_PULLUP      clr_P3UP_4;SFRS=0
#define    DISABLE_P35_PULLUP      clr_P3UP_5;SFRS=0
#define    DISABLE_P36_PULLUP      clr_P3UP_6;SFRS=0
#define    DISABLE_P37_PULLUP      clr_P3UP_7;SFRS=0
/*------------------- GPIO pull down enable -------------------*/  
#define    ENABLE_P00_PULLDOWN     set_P0DW_0;SFRS=0
#define    ENABLE_P01_PULLDOWN     set_P0DW_1;SFRS=0
#define    ENABLE_P02_PULLDOWN     set_P0DW_2;SFRS=0
#define    ENABLE_P03_PULLDOWN     set_P0DW_3;SFRS=0
#define    ENABLE_P04_PULLDOWN     set_P0DW_4;SFRS=0
#define    ENABLE_P05_PULLDOWN     set_P0DW_5;SFRS=0
#define    ENABLE_P06_PULLDOWN     set_P0DW_6;SFRS=0
#define    ENABLE_P07_PULLDOWN     set_P0DW_7;SFRS=0
#define    ENABLE_P10_PULLDOWN     set_P1DW_0;SFRS=0
#define    ENABLE_P11_PULLDOWN     set_P1DW_1;SFRS=0
#define    ENABLE_P12_PULLDOWN     set_P1DW_2;SFRS=0
#define    ENABLE_P13_PULLDOWN     set_P1DW_3;SFRS=0
#define    ENABLE_P14_PULLDOWN     set_P1DW_4;SFRS=0
#define    ENABLE_P15_PULLDOWN     set_P1DW_5;SFRS=0
#define    ENABLE_P16_PULLDOWN     set_P1DW_6;SFRS=0
#define    ENABLE_P17_PULLDOWN     set_P1DW_7;SFRS=0
#define    ENABLE_P20_PULLDOWN     set_P2DW_0;SFRS=0
#define    ENABLE_P21_PULLDOWN     set_P2DW_1;SFRS=0
#define    ENABLE_P22_PULLDOWN     set_P2DW_2;SFRS=0
#define    ENABLE_P23_PULLDOWN     set_P2DW_3;SFRS=0
#define    ENABLE_P24_PULLDOWN     set_P2DW_4;SFRS=0
#define    ENABLE_P25_PULLDOWN     set_P2DW_5;SFRS=0
#define    ENABLE_P30_PULLDOWN     set_P3DW_0;SFRS=0
#define    ENABLE_P31_PULLDOWN     set_P3DW_1;SFRS=0
#define    ENABLE_P32_PULLDOWN     set_P3DW_2;SFRS=0
#define    ENABLE_P33_PULLDOWN     set_P3DW_3;SFRS=0
#define    ENABLE_P34_PULLDOWN     set_P3DW_4;SFRS=0
#define    ENABLE_P35_PULLDOWN     set_P3DW_5;SFRS=0
#define    ENABLE_P36_PULLDOWN     set_P3DW_6;SFRS=0
#define    ENABLE_P37_PULLDOWN     set_P3DW_7;SFRS=0
/*------------------ GPIO pull down disable -------------------*/
#define    DISABLE_P00_PULLDOWN    clr_P0DW_0;SFRS=0
#define    DISABLE_P01_PULLDOWN    clr_P0DW_1;SFRS=0
#define    DISABLE_P02_PULLDOWN    clr_P0DW_2;SFRS=0
#define    DISABLE_P03_PULLDOWN    clr_P0DW_3;SFRS=0
#define    DISABLE_P04_PULLDOWN    clr_P0DW_4;SFRS=0
#define    DISABLE_P05_PULLDOWN    clr_P0DW_5;SFRS=0
#define    DISABLE_P06_PULLDOWN    clr_P0DW_6;SFRS=0
#define    DISABLE_P07_PULLDOWN    clr_P0DW_7;SFRS=0
#define    DISABLE_P10_PULLDOWN    clr_P1DW_0;SFRS=0
#define    DISABLE_P11_PULLDOWN    clr_P1DW_1;SFRS=0
#define    DISABLE_P12_PULLDOWN    clr_P1DW_2;SFRS=0
#define    DISABLE_P13_PULLDOWN    clr_P1DW_3;SFRS=0
#define    DISABLE_P14_PULLDOWN    clr_P1DW_4;SFRS=0
#define    DISABLE_P15_PULLDOWN    clr_P1DW_5;SFRS=0
#define    DISABLE_P16_PULLDOWN    clr_P1DW_6;SFRS=0
#define    DISABLE_P17_PULLDOWN    clr_P1DW_7;SFRS=0
#define    DISABLE_P20_PULLDOWN    clr_P2DW_0;SFRS=0
#define    DISABLE_P21_PULLDOWN    clr_P2DW_1;SFRS=0
#define    DISABLE_P22_PULLDOWN    clr_P2DW_2;SFRS=0
#define    DISABLE_P23_PULLDOWN    clr_P2DW_3;SFRS=0
#define    DISABLE_P24_PULLDOWN    clr_P2DW_4;SFRS=0
#define    DISABLE_P25_PULLDOWN    clr_P2DW_5;SFRS=0
#define    DISABLE_P30_PULLDOWN    clr_P3DW_0;SFRS=0
#define    DISABLE_P31_PULLDOWN    clr_P3DW_1;SFRS=0
#define    DISABLE_P32_PULLDOWN    clr_P3DW_2;SFRS=0
#define    DISABLE_P33_PULLDOWN    clr_P3DW_3;SFRS=0
#define    DISABLE_P34_PULLDOWN    clr_P3DW_4;SFRS=0
#define    DISABLE_P35_PULLDOWN    clr_P3DW_5;SFRS=0
#define    DISABLE_P36_PULLDOWN    clr_P3DW_6;SFRS=0
#define    DISABLE_P37_PULLDOWN    clr_P3DW_7;SFRS=0
