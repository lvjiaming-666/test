/**
* @file:    Press.c
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-02-13 21:04:55
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-02-13 21:04:55  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#include "Press.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
#include "AdcPal.h"

/*------------------------------ END: USER INCLUDE ------------------------------*/
static uint16 Press_GetDeviceMv(Press_DeviceEType device)
{
    uint16 adcValue = 0U;
    uint16 voltageMv = 0U;

    switch(device)
    {
    case PRESS_DEV_HEATPUMP1:
        adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_HEAT_PUMP1_PRESS);
        break;
    case PRESS_DEV_HEATPUMP2:
        adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_HEAT_PUMP2_PRESS);
        break;
    case PRESS_DEV_AIRCOND:
        adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_AIRCOND_PRESS);
        break;
    default:break;
    }
    voltageMv = (uint16)(adcValue*1000LL/819);
    return voltageMv;
}

/* 1psi=6.895kPa=0.0689476bar =0.006895MPa */
uint16 Press_GetDevicePsi(Press_DeviceEType device)
{
    uint16 adcValue = 0U;
    uint16 pressurePsi = 0U;
	static uint16 l_prePress = 0;
	static uint8 l_firstTime = 1;
	static float l_newDataPercentage = 0.5; //0 < Value < 1

#define AVG_MAX_TIMES 10
	static uint32 sumPress = 0;
	static uint16 avgPress = 0;
	static uint8 avgCount = 0;
	static uint8 avgIndex = 0;
	static uint16 bufPress[AVG_MAX_TIMES];

    switch(device)
    {
    case PRESS_DEV_HEATPUMP1:
        adcValue = Press_GetDeviceMv(PRESS_DEV_HEATPUMP1);
        pressurePsi = (uint16)((adcValue-278.15)/8.2735f);
        break;
    case PRESS_DEV_HEATPUMP2:
        adcValue = Press_GetDeviceMv(PRESS_DEV_HEATPUMP2);
        pressurePsi = (uint16)((adcValue-250)/28.571f);
        break;
    case PRESS_DEV_AIRCOND:
        adcValue = Press_GetDeviceMv(PRESS_DEV_AIRCOND);
        pressurePsi = (uint16)((adcValue-250)/28.571f);
        break;
    default:break;
    }

    if(1 == l_firstTime)
    {
  		l_firstTime = 0;
  		l_prePress = pressurePsi;
  	}
	else
	{
		l_prePress = l_prePress * (1-l_newDataPercentage) + pressurePsi * l_newDataPercentage;
	}

    if(avgCount < AVG_MAX_TIMES)
    {
    	bufPress[avgIndex] = l_prePress;
    	sumPress += l_prePress;
    	avgCount++;
    	avgIndex++;
    	avgIndex = avgIndex%AVG_MAX_TIMES;
    	avgPress = sumPress/avgCount;
    }
    else
    {
    	sumPress -= bufPress[avgIndex];
    	bufPress[avgIndex] = l_prePress;
    	sumPress += l_prePress;
    	avgIndex++;
    	avgIndex = avgIndex%AVG_MAX_TIMES;
    	avgPress = sumPress/AVG_MAX_TIMES;
    }

   // return l_prePress;
    return avgPress;
}

uint16 Press_GetDeviceKPa(Press_DeviceEType device)
{
#if 0
	return ((uint16)(6.895 * Press_GetDevicePsi(device)));
#else //return the raw adc value directly
	uint8 adcValue = 0;

	switch(device)
	{
	case PRESS_DEV_HEATPUMP1:
		adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_HEAT_PUMP1_PRESS);
		break;
	case PRESS_DEV_HEATPUMP2:
		adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_HEAT_PUMP2_PRESS);
		break;
	case PRESS_DEV_AIRCOND:
		adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_AIRCOND_PRESS);
		break;
	default:break;
	}
	return (adcValue);
#endif
}

uint16 Press_GetDeviceBar(Press_DeviceEType device)
{
	return ((uint16)(0.0689476 * Press_GetDevicePsi(device)));
}
/*============================= END OF FILE: Press.c ============================*/
