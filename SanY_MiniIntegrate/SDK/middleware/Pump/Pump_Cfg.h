/**
* @file:    Pump_Cfg.h
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
#ifndef _PUMP_CFG_H_
#define _PUMP_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/
/*This value must equal the configuration cycle value in the CT*/
#define PWM_CYCLE_MAX_VALUE 50000U
#define PUMP_MAX_SPEED_RPM 3000U //TODO: Need to check with the data sheet or Tier1
#define PUMP_MIN_SPEED_RPM 1000U //TODO: Need to check with the data sheet or Tier1

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_PUMP_CFG_H_
/*============================= END OF FILE: Pump_Cfg.h ============================*/
