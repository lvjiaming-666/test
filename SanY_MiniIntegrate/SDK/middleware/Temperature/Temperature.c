/********************************************************************
File name: Temperature.c
Author: Dimitri
Version: V1.0
Timestamp: 2018-12-23 21:55:26
Description:
Others:
Function List:
1. ....
History: /
1. Date:
Author:
Modification:
2. ...
********************************************************************/
#include "stdlib.h"
#include "Temperature.h"
#include "TemperConvert.h"
#include "AdcPal.h"
#include "Std_Types.h"

sint16 Temper_GetExternal(void)
{
    uint16 l_adcValue = 0;
    sint16 l_returnValue = 0;
	static sint16 l_preTemp = 0;
	static uint8 l_errCount = 0;
	static uint8 l_firstTime = 1;

	l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_EXTERNAL_TEMPER);

    l_returnValue = Temper_Convert_External(l_adcValue);
	if(1 == l_firstTime){
		l_firstTime = 0;
		l_preTemp = l_returnValue;
	}
	if(5 > abs(l_returnValue-l_preTemp)){
		l_preTemp = l_returnValue;
		l_errCount = 0;
	}else{
		l_errCount++;
		if(l_errCount > 3){
			l_preTemp = l_returnValue;
		}
	}
	return (l_preTemp + TEMPER_OFFSET_EXTERNAL);
}

//sint16 Temper_GetBattWater(void)
sint16 Temper_GetBattWaterIn(void)
{
    uint16 l_adcValue = 0;
    sint16 l_returnValue = 0;
	static sint16 l_preTemp = 0;
	static uint8 l_errCount = 0;
	static uint8 l_firstTime = 1;

	l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_BATT_WATER_TEMPER);

    l_returnValue = Temper_Convert_BattWater(l_adcValue);
	if(1 == l_firstTime){
		l_firstTime = 0;
		l_preTemp = l_returnValue;
	}
	if(5 > abs(l_returnValue-l_preTemp)){
		l_preTemp = l_returnValue;
		l_errCount = 0;
	}else{
		l_errCount++;
		if(l_errCount > 3){
			l_preTemp = l_returnValue;
		}
	}
	return (l_preTemp + TEMPER_OFFSET_BATTWATER);
}

sint16 Temper_GetHeatPump(Temper_HeatPumpEType index)
{
    uint16 l_adcValue = 0;
    sint16 l_returnValue = 0;
	static sint16 l_preTemp = 0;
	static uint8 l_firstTime = 1;
	static float l_newDataPercentage = 0.5; //0 < Value < 1

	switch(index)
	{
	case TEMPER_HEATPUMP_IDX1:
		l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_HEAT_PUMP1_TEMPER);
		break;
	case TEMPER_HEATPUMP_IDX2:
		l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_HEAT_PUMP2_TEMPER);
		break;
	default: 
		break;
	}
	
    l_returnValue = Temper_Convert_HeatPump(l_adcValue);
    if(1 == l_firstTime)
    {
		l_firstTime = 0;
		l_preTemp = l_returnValue;
	}
    else
    {
    	l_preTemp = l_preTemp * (1-l_newDataPercentage) + l_returnValue * l_newDataPercentage;
    }

	return l_preTemp;
}

sint16 Temper_GetEvaporator(void)
{
    uint16 l_adcValue = 0;
    sint16 l_returnValue = 0;
	static sint16 l_preTemp = 0;
	static uint8 l_errCount = 0;
	static uint8 l_firstTime = 1;

	l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_EXV_TEMPER);

    l_returnValue = Temper_Convert_Evaporator(l_adcValue);
		if(1 == l_firstTime){
		l_firstTime = 0;
		l_preTemp = l_returnValue;
	}
	if(5 > abs(l_returnValue-l_preTemp)){
		l_preTemp = l_returnValue;
		l_errCount = 0;
	}else{
		l_errCount++;
		if(l_errCount > 3){
			l_preTemp = l_returnValue;
		}
	}	
	/*if(l_preTemp >= 0){
		l_preTemp += TEMPER_OFFSET_EVAPORATOR1;
	} 
	else {
		l_preTemp += TEMPER_OFFSET_EVAPORATOR2;
	}*/
    return (l_preTemp + TEMPER_OFFSET_EVAPORATOR);
}

//sint16 Temper_GetWarmAir(void)
sint16 Temper_GetInner(void)
{
    uint16 l_adcValue = 0;
    sint16 l_returnValue = 0;
	static sint16 l_preTemp = 0;
	static uint8 l_errCount = 0;
	static uint8 l_firstTime = 1;

	l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_WARM_AIR_TEMPER);
	//The warm air use the same type sensor with the evaporator.
    //l_returnValue = Temper_Convert_Evaporator(l_adcValue);
	//for mini integrate, this port connected the inner temperature.
	l_returnValue = Temper_Convert_Inner_GaoLi(l_adcValue);
		if(1 == l_firstTime){
		l_firstTime = 0;
		l_preTemp = l_returnValue;
	}
	if(5 > abs(l_returnValue-l_preTemp)){
		l_preTemp = l_returnValue;
		l_errCount = 0;
	}else{
		l_errCount++;
		if(l_errCount > 3){
			l_preTemp = l_returnValue;
		}
	}	
    return (l_preTemp + TEMPER_OFFSET_WARMAIR);
}


sint16 Temper_GetMotorWater(Temper_MotorWaterEType index)
{
    uint16 l_adcValue = 0;
    sint16 l_returnValue = 0;
	static sint16 l_preTemp = 0;
	static uint8 l_errCount = 0;
	static uint8 l_firstTime = 1;

	switch(index)
	{
	case TEMPER_MOTORWATER_IDX1:
		l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_MOTOR_WATER1_TEMPER);
		break;
	case TEMPER_MOTORWATER_IDX2:
		l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_MOTOR_WATER2_TEMPER);
		break;
	case TEMPER_MOTORWATER_IDX3:
		l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_MOTOR_WATER_TEMPER_RESERVE);
		break;
	default: 
		break;
	}
	
    l_returnValue = Temper_Convert_MotorWater(l_adcValue);
	if(1 == l_firstTime){
		l_firstTime = 0;
		l_preTemp = l_returnValue;
	}
	if(5 > abs(l_returnValue-l_preTemp)){
		l_preTemp = l_returnValue;
		l_errCount = 0;
	}else{
		l_errCount++;
		if(l_errCount > 3){
			l_preTemp = l_returnValue;
		}
	}
	return (l_preTemp + TEMPER_OFFSET_MOTORWATER);
}

//Hydraulic pressure oil
//sint16 Temper_GetHydPressOil(Temper_HydPressOilEType index)
sint16 Temper_GetBattWaterOut(void)
{
    uint16 l_adcValue = 0;
    sint16 l_returnValue = 0;
	static sint16 l_preTemp = 0;
	static uint8 l_errCount = 0;
	static uint8 l_firstTime = 1;
#if 0
	switch(index)
	{
	case TEMPER_HYDPRESSOIL_IDX1:
		return -400;//for mini integrate, has removed this sensor
		//l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_HYDPRESS_OIL1_TEMPER);
		break;
	case TEMPER_HYDPRESSOIL_IDX2:
		l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_HYDPRESS_OIL2_TEMPER);
		break;
	default: 
		break;
	}
#endif
	l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_HYDPRESS_OIL2_TEMPER);
	//The Hydraulic pressure oil use the same type sensor with the motor water.
    //l_returnValue = Temper_Convert_MotorWater(l_adcValue);
	//for mini integrate, this port connect the batt water out and have the same RT with in
	l_returnValue = Temper_Convert_BattWater(l_adcValue);
		if(1 == l_firstTime){
		l_firstTime = 0;
		l_preTemp = l_returnValue;
	}
	if(5 > abs(l_returnValue-l_preTemp)){
		l_preTemp = l_returnValue;
		l_errCount = 0;
	}else{
		l_errCount++;
		if(l_errCount > 3){
			l_preTemp = l_returnValue;
		}
	}	
    return (l_preTemp + TEMPER_OFFSET_HYDPRESSOIL);
}

#if 0
sint16 Temper_GetInner(void)
{
    uint16 l_adcValue = 0;
    sint16 l_returnValue = 0;
	static sint16 l_preTemp = 0;
	static uint8 l_errCount = 0;
	static uint8 l_firstTime = 1;

	l_adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_INNER_TEMPER);
	
	//The Internal air condition use the same type sensor with the heat pump.
    l_returnValue = Temper_Convert_HeatPump(l_adcValue);
	if(1 == l_firstTime){
		l_firstTime = 0;
		l_preTemp = l_returnValue;
	}
	if(5 > abs(l_returnValue-l_preTemp)){
		l_preTemp = l_returnValue;
		l_errCount = 0;
	}else{
		l_errCount++;
		if(l_errCount > 3){
			l_preTemp = l_returnValue;
		}
	}
	return (l_preTemp + TEMPER_OFFSET_INNER);
}

#endif

/*============================= END OF FILE: Temperature.c ============================*/

