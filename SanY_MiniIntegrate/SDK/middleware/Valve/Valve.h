/**
* @file:    Valve.h
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-02-04 22:33:28
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-02-04 22:33:28  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#ifndef _VALVE_H_
#define _VALVE_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "Valve_Cfg.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/
typedef enum
{
    VALVE_BATT_TRIPWATER_IDX1,
    VALVE_BATT_TRIPWATER_IDX2,
	VALVE_BATT_TRIPWATER_MAX
}Valve_BattTripleWaterIdxEType;

typedef enum
{
    VALVE_BATT_TRIPWATER_POS_V1_V2,
    VALVE_BATT_TRIPWATER_POS_V1_V3,
    VALVE_BATT_TRIPWATER_POS_HALF_V1_V2_V3
}Valve_BattTripleWaterPosEType;

extern void Valve_Hot(boolean OnOff);
extern void Valve_AC(boolean OnOff);
extern void Valve_CutOff(boolean OnOff);

extern void Valve_BattTripWater_Init(void);
extern void Valve_BattTripleWater(Valve_BattTripleWaterIdxEType Index, Valve_BattTripleWaterPosEType Position);
extern void Valve_BattTripleWater_Main(void);

extern void Valve_MotorTriple(uint8 Position);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_VALVE_H_
/*============================= END OF FILE: Valve.h ============================*/
