/**
* @file:    Fan.h
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-02-04 23:23:48
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-02-04 23:23:48  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#ifndef _FAN_H_
#define _FAN_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "Fan_Cfg.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/
typedef enum
{
    FAN_CONDENSER_IDX_1,
    FAN_CONDENSER_IDX_2,
    FAN_CONDENSER_IDX_3,
    FAN_CONDENSER_IDX_4,
}Fan_CondenserIdxEType;

/* speedRpm: 0, 1200rpm ~ 4750rpm */
void Fan_CtrCondenser(Fan_CondenserIdxEType index, uint16 speedRpm);

/* speedRpm: 0, 750rpm ~ 3750rpm */
void Fan_CtrBlower(uint16 speedRpm);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_FAN_H_
/*============================= END OF FILE: Fan.h ============================*/
