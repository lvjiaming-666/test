/**
* @file:    Fan.c
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-02-04 23:23:48
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-02-04 23:23:48  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#include "Fan.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
#include "pwm_pal.h"
#include "peripherals_pwm_pal_1.h"
#include "peripherals_pwm_pal_2.h"
#include "AdcPal.h"
#include "CanMsg.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
uint16 Fan_GetCondenserFdbk(Fan_CondenserIdxEType index)
{
    uint16 adcValue = 0U;
    uint16 voltageMv = 0U;

    switch(index)
    {
        case FAN_CONDENSER_IDX_1:
            adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_CONDENSER_FAN1_FDBK);
            break;
        case FAN_CONDENSER_IDX_2:
            adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_CONDENSER_FAN2_FDBK);
            break;
        case FAN_CONDENSER_IDX_3:
            adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_CONDENSER_FAN3_FDBK);
            break;
        case FAN_CONDENSER_IDX_4:
            adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_CONDENSER_FAN4_FDBK);
            break;
        default:
            break;
    }
    voltageMv = (uint16)(adcValue*8000LL/819);
    return voltageMv;
}

/* speedRpm: 0, 1200rpm ~ 4750rpm*/
void Fan_CtrCondenser(Fan_CondenserIdxEType index, uint16 speedRpm)
{
	uint8 l_pwmUpdate = 0;
	uint8 l_duty = 0;
	uint16 l_fdbkVolt = 0;
	uint32 l_pwmValue = 0;

	l_fdbkVolt = 0;//Fan_GetCondenserFdbk(index);
	if(l_fdbkVolt < 1000)
	{
		if((1200 <= speedRpm) && (speedRpm <= 4750))
		{
			l_duty = (speedRpm - 1200)*13/710+25;
			l_pwmValue = 50000 * l_duty / 100;
			l_pwmUpdate = 1;
		}
		else if(0 == speedRpm)
		{
			//Stopped by user
			l_pwmUpdate = 1;
		}
	}
	else
	{
		//Error happened according to the feedback, stop it.
		l_pwmUpdate = 1;
	}
	if(1 == l_pwmUpdate)
	{
		switch(index)
		{
			case FAN_CONDENSER_IDX_1:
				PWM_UpdateDuty(&pwm_pal_1_instance, 5, l_pwmValue);
				CanSig_SetCondenserSpeed1(speedRpm);
				break;
			case FAN_CONDENSER_IDX_2:
				PWM_UpdateDuty(&pwm_pal_1_instance, 4, l_pwmValue);
				CanSig_SetCondenserSpeed2(speedRpm);
				break;
			case FAN_CONDENSER_IDX_3:
				PWM_UpdateDuty(&pwm_pal_1_instance, 3, l_pwmValue);
				CanSig_SetCondenserSpeed3(speedRpm);
				break;
			case FAN_CONDENSER_IDX_4:
				PWM_UpdateDuty(&pwm_pal_1_instance, 2, l_pwmValue);
				CanSig_SetCondenserSpeed4(speedRpm);
				break;
			default:
				break;
		}
	}
}

/* speedRpm: 0, 750rpm ~ 3750rpm*/
void Fan_CtrBlower(uint16 speedRpm)
{
	uint8 l_pwmUpdate = 0;
	uint8 l_duty = 0;
	uint32 l_pwmValue = 0;

	if((750 <= speedRpm) && (speedRpm <= 3750))
	{
		l_duty = (speedRpm - 750)/40 + 15;
		l_pwmValue = 50000 * l_duty / 100; //14k: 357 * duty / 100;
		l_pwmUpdate = 1;
	}
	else if(0 == speedRpm)
	{
		//Stopped by user
		l_pwmUpdate = 1;
	}
	if(1 == l_pwmUpdate)
	{
		PWM_UpdateDuty(&pwm_pal_2_instance, 6, l_pwmValue);
		CanSig_SetBlowerSpeed(speedRpm);
	}
}

/*============================= END OF FILE: Fan.c ============================*/
