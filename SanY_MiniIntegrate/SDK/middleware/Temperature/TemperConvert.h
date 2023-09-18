/********************************************************************
File name: TemperConvert.h
Author: Dimitri
Version: V1.0
Date: 2018-12-23 21:55:26
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

#ifndef _TEMPERCONVERT_H_
#define _TEMPERCONVERT_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"

/***************************************************************************//*!
 * @brief   灏嗗綋鍓嶆俯搴︿紶鎰熷櫒鐨� Adc 鍊艰浆鍖栨垚瀵瑰簲鐨勬俯搴�
 * @details 灏嗗綋鍓嶆俯搴︿紶鎰熷櫒鐨� Adc 鍊艰浆鍖栨垚瀵瑰簲鐨勬俯搴�
 * @para    adcValue 瀵勫瓨鍣ㄨ鍒扮殑 Value
 * @return  @ref 褰撳墠娓╁害浼犳劅鍣ㄦ俯搴�
 * @note    None
 ******************************************************************************/
extern sint16 Temper_Convert_External(uint16 adcValue);
extern sint16 Temper_Convert_BattWater(uint16 adcValue);
extern sint16 Temper_Convert_HeatPump(uint16 adcValue);
extern sint16 Temper_Convert_Evaporator(uint16 adcValue);
extern sint16 Temper_Convert_MotorWater(uint16 adcValue);



extern sint16 Temper_Convert_Inner(uint16 adcValue);
extern sint16 Temper_Convert_Inner_GaoLi(uint16 adcValue);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _TEMPERCONVERT_H_
/*============================= END OF FILE: TemperConvert.h ============================*/

