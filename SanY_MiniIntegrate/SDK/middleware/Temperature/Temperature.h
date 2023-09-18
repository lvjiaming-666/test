/********************************************************************
File name: Temperature.h
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
#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "Temperature_Cfg.h"

typedef enum
{
    TEMPER_HEATPUMP_IDX1,
    TEMPER_HEATPUMP_IDX2,
}Temper_HeatPumpEType;

typedef enum
{
    TEMPER_MOTORWATER_IDX1,
    TEMPER_MOTORWATER_IDX2,
	TEMPER_MOTORWATER_IDX3,
}Temper_MotorWaterEType;

typedef enum
{
    TEMPER_HYDPRESSOIL_IDX1, //removed
    TEMPER_HYDPRESSOIL_IDX2, //batter water out
}Temper_HydPressOilEType;

/***************************************************************************//*!
 * @brief   Get temperature
 * @details Get temperature
 * @return  @ref Temperature value. 100 means 10.0° 35 means 3.5°
 * @note    None
 ******************************************************************************/
extern sint16 Temper_GetExternal(void);
//extern sint16 Temper_GetBattWater(void); -> //Temper_GetBattWaterIn
extern sint16 Temper_GetBattWaterIn(void);
extern sint16 Temper_GetBattWaterOut(void);
extern sint16 Temper_GetHeatPump(Temper_HeatPumpEType index);
extern sint16 Temper_GetEvaporator(void);
//extern sint16 Temper_GetWarmAir(void); -> //Temper_GetInner
//extern sint16 Temper_GetMotorWater(Temper_MotorWaterEType index);
//extern sint16 Temper_GetHydPressOil(Temper_HydPressOilEType index); -> Temper_GetBattWaterOut
extern sint16 Temper_GetInner(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _TEMPERATURE_H_
/*============================= END OF FILE: Temperature.h ============================*/

