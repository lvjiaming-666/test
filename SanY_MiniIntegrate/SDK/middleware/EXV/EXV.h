/**
* @file:    EXV.h
* @brief:   Add your description here for this file.
* @author:  
* @date:    
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0                                   First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#ifndef _EXV_H_
#define _EXV_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "EXV_Cfg.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/
typedef enum
{
	EXV_MOTOR_BATTERY,
	EXV_MOTOR_HEATPUMP
}EXV_MotorIndexEType;

extern void EXV_Init(void);
extern uint8 EXV_IsRunning(EXV_MotorIndexEType MotorIndex);
extern uint16 EXV_GetRealPos(EXV_MotorIndexEType MotorIndex);
//Range: EXV_LEVEL_TOTALCLOSE ~ EXV_LEVEL_MAXOPEN
extern void EXV_SetOpenLevel(EXV_MotorIndexEType MotorIndex, uint16 openLevel);
extern void EXV_Pause(EXV_MotorIndexEType MotorIndex);
extern void EXV_ProcessPulse(void);
extern void EXV_Main(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_EXV_H_
/*============================= END OF FILE: EXV.h ============================*/
