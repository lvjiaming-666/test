/**
* @file:    LiquidLevel.h
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
#ifndef _LIQUIDLEVEL_H_
#define _LIQUIDLEVEL_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "LiquidLevel_Cfg.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/

typedef enum
{
    LIQUIDLEVEL_DEV_BATT,
    LIQUIDLEVEL_DEV_MOTOR,
    LIQUIDLEVEL_DEV_AIRCOND,
}LiquidLevel_DeviceEType;

extern boolean LiquidLevel_IsEmpty(LiquidLevel_DeviceEType device);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_LIQUIDLEVEL_H_
/*============================= END OF FILE: LiquidLevel.h ============================*/
