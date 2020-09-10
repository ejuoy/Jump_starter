#ifndef _APP_ADC_H_
#define _APP_ADC_H_

enum _ADC_VCHANLE_CONTROL_
{
    VIN_ADC = 0,
    VOUT_ADC ,
};

unsigned int app_getadc_value(char channle);

#endif
