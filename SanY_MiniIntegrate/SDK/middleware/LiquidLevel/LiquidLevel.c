/**
* @file:    LiquidLevel.c
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-02-13 20:52:19
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-02-13 20:52:19  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#include "LiquidLevel.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
#include "AdcPal.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
static uint16 LiquidLevel_GetBattMv(LiquidLevel_DeviceEType device)
{
    uint16 adcValue = 0U;
    uint16 voltageMv = 0U;

    switch(device)
    {
    case LIQUIDLEVEL_DEV_BATT:
        adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_BATT_LIQUID_LEVEL);
        break;
    case LIQUIDLEVEL_DEV_MOTOR:
        adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_MOTOR_LIQUID_LEVEL);
        break;
    case LIQUIDLEVEL_DEV_AIRCOND:
        adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_AIRCOND_LIQUID_LEVEL);
        break;
    default:break;
    }
    voltageMv = (uint16)(adcValue*8000LL/819);
    return voltageMv;
}

boolean LiquidLevel_IsEmpty(LiquidLevel_DeviceEType device)
{
	boolean empty = TRUE;

	if(LiquidLevel_GetBattMv(device) < 5000)
	{
		empty = FALSE;
	}
	else if(LiquidLevel_GetBattMv(device) > 16000)
	{
		empty = TRUE;
	}
	return empty;
}

/*============================= END OF FILE: LiquidLevel.c ============================*/
