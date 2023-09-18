/**
* @file:    PowerCtr.h
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
#ifndef _POWERCTR_H_
#define _POWERCTR_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
#include "S32K144.h"
#include "pins_driver.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
extern void PowerCtr_OnOffSensor5V(boolean onoff);
extern void PowerCtr_OnOffPwm24V(boolean onoff);

extern uint16 PowerCtr_GetBattVoltMv(void);
extern uint16 PowerCtr_GetIgnVoltMv(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_POWERCTR_H_
/*============================= END OF FILE: PowerCtr.h ============================*/
