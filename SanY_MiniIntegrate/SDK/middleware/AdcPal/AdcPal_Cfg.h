/**
* @file:    AdcPal_Cfg.h
* @brief:   Add your description here for this file.
* @author:  Dimitri
* @date:    2020-04-26 17:40:37
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  Dimitri  2020-04-26 17:40:37  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#ifndef _ADCPAL_CFG_H_
#define _ADCPAL_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/

/******************************************************************************
* ADC channel type
*
*//*! @addtogroup ADC_channel_Type
* @{
*******************************************************************************/
/*! AdcPalCHEType type declaration                                                */
typedef enum
{
	ADCPAL_CH_BATT_VOLTAGE = 0,
	ADCPAL_CH_IGN_VOLTAGE = 1,
	ADCPAL_CH_CONDENSER_FAN1_FDBK = 2,
	ADCPAL_CH_CONDENSER_FAN2_FDBK = 3,
	ADCPAL_CH_CONDENSER_FAN3_FDBK = 4,
	ADCPAL_CH_CONDENSER_FAN4_FDBK = 5,
	ADCPAL_CH_MOTOR_PUMP_FDBK = 6,
	ADCPAL_CH_BATT_VALVE1_FDBK = 7,
	ADCPAL_CH_BATT_VALVE2_FDBK = 8,
	ADCPAL_CH_EXTERNAL_TEMPER = 9,
	ADCPAL_CH_BATT_WATER_TEMPER = 10,
	ADCPAL_CH_HEAT_PUMP1_TEMPER = 11,
	ADCPAL_CH_HEAT_PUMP2_TEMPER = 12,
	ADCPAL_CH_EXV_TEMPER = 13,
	ADCPAL_CH_MOTOR_WATER1_TEMPER = 14,
	ADCPAL_CH_WARM_AIR_TEMPER = 15,
	ADCPAL_CH_MOTOR_WATER2_TEMPER = 16,
	ADCPAL_CH_HYDPRESS_OIL1_TEMPER = 17,
	ADCPAL_CH_BATT_LIQUID_LEVEL = 18,
	ADCPAL_CH_MOTOR_LIQUID_LEVEL = 19,
	ADCPAL_CH_AIRCOND_LIQUID_LEVEL = 20,
	ADCPAL_CH_INNER_TEMPER = 21,
	ADCPAL_CH_AIRCOND_PRESS = 22,
	ADCPAL_CH_HEAT_PUMP1_PRESS = 23,
	ADCPAL_CH_HEAT_PUMP2_PRESS = 24,
	ADCPAL_CH_HYDPRESS_OIL2_TEMPER = 25,
	ADCPAL_CH_MOTOR_WATER_TEMPER_RESERVE = 26,
	ADCPAL_CH_MAX
}AdcPalCHEType;
/*! @} End of ADC_channel_Type                                                     */

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_ADCPAL_CFG_H_
/*============================= END OF FILE: AdcPal_Cfg.h ============================*/
