/**
* @file:    PowerCtr.c
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2022-09-11 21:20:14
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2022-09-11 21:20:14  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#include "PowerCtr.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
//#include "adc.h"
#include "pins_driver.h"
#include "pin_mux.h"
#include "AdcPal.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/

void PowerCtr_OnOffSensor5V(boolean onoff)
{
    PINS_DRV_WritePin(Sensor_5V_EN_PORT,Sensor_5V_EN_PIN, onoff);
}

void PowerCtr_OnOffPwm24V(boolean onoff)
{
    PINS_DRV_WritePin(MCU_PWM24V_EN_PORT,MCU_PWM24V_EN_PIN, onoff);
}

uint16 PowerCtr_GetBattVoltMv(void)
{
	uint16 adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_BATT_VOLTAGE);
	uint16 voltageMv = 0U;

	voltageMv = (uint16)(adcValue*8000LL/819);
	return voltageMv;
}

uint16 PowerCtr_GetIgnVoltMv(void)
{
	uint16 adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_IGN_VOLTAGE);
	uint16 voltageMv = 0U;

	voltageMv = (uint16)(adcValue*8000LL/819);
	return voltageMv;
}

/*============================= END OF FILE: PowerCtr.c ============================*/
