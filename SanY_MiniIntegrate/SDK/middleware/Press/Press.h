/**
* @file:    Press.h
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-02-13 21:04:55
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-02-13 21:04:55  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#ifndef _PRESS_H_
#define _PRESS_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "Press_Cfg.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/
typedef enum
{
    PRESS_DEV_HEATPUMP1,
    PRESS_DEV_HEATPUMP2,
    PRESS_DEV_AIRCOND,
}Press_DeviceEType;

/* 1psi=6.895kPa=0.0689476bar =0.006895MPa */
extern uint16 Press_GetDevicePsi(Press_DeviceEType device);
extern uint16 Press_GetDeviceKPa(Press_DeviceEType device);
extern uint16 Press_GetDeviceBar(Press_DeviceEType device);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_PRESS_H_
/*============================= END OF FILE: Press.h ============================*/
