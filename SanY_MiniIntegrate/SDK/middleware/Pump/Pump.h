/**
* @file:    Pump.h
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-02-04 23:24:07
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-02-04 23:24:07  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#ifndef _PUMP_H_
#define _PUMP_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "Pump_Cfg.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/
/* speedRpm: 0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM*/
extern void Pummp_Battry(uint16 speedRpm);
/* speedRpm: 0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM*/
extern void Pummp_AirCondition(uint16 speedRpm);
/* speedRpm: 0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM*/
extern void Pummp_Motor(uint16 speedRpm);
extern uint16 Pump_GetMotorFdbk(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_PUMP_H_
/*============================= END OF FILE: Pump.h ============================*/
