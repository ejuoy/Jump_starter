#include "MS51_32K.h"
#include "app_type.h"
#include "app_adc.h"
		
unsigned int app_getadc_value(char channle)
{  
    unsigned int adc_value = 0xFFFF;
    unsigned int vcc_value = 0xFFFF;
    if(channle==VIN_ADC)
    {
        /*Enable channel 5 */ 
        ENABLE_ADC_CH5; 
        ADC_ConvertTime(ADC_CH5,2,7);
        clr_ADCCON0_ADCF;
        set_ADCCON0_ADCS;                  // ADC start trig signal
        while(ADCF == 0);
        adc_value=(ADCRH<<4)+(ADCRL&0x0F);
    }
    else if(channle==VOUT_ADC)
    {
        /*Enable channel 4 */ 
        ENABLE_ADC_CH4;           
        ADC_ConvertTime(ADC_CH4,4,7);
        clr_ADCCON0_ADCF;
        set_ADCCON0_ADCS;                  // ADC start trig signal
        while(ADCF == 0);
        adc_value=(ADCRH<<4)+(ADCRL&0x0F);
    }
    vcc_value = (unsigned int)(((unsigned long)adc_value*518)/4095);
    //printf ("\n ADC CH %d = 0x%02X", (unsigned int) channle, adc_value);
    return vcc_value;

}

