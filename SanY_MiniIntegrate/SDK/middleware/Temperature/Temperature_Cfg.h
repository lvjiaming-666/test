/********************************************************************
File name: Temperature_Cfg.h
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
#ifndef _TEMPERATURE_CFG_H_
#define _TEMPERATURE_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"

#ifdef __cplusplus
}
#endif // __cplusplus

/******************************************************************************
* Temperature Sensor Offset
*
*//*! @addtogroup TEMPER_OFFSET
* @{
*******************************************************************************/
#define TEMPER_OFFSET_EXTERNAL   0  //physical value*10
#define TEMPER_OFFSET_BATTWATER  0  //physical value*10
#define TEMPER_OFFSET_HEATPUMP   0  //physical value*10
#define TEMPER_OFFSET_EVAPORATOR 0  //physical value*10
#define TEMPER_OFFSET_WARMAIR    0  //physical value*10
#define TEMPER_OFFSET_MOTORWATER 0  //physical value*10
#define TEMPER_OFFSET_HYDPRESSOIL 0  //physical value*10
#define TEMPER_OFFSET_INNER      0  //physical value*10
/*! @} End of TEMPER_OFFSET                                                   */

#endif // _TEMPERATURE_CFG_H_
/*============================= END OF FILE: Temperature_Cfg.h ============================*/

