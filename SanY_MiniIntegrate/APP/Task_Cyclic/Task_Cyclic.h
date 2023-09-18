/**
* @file:    Task_Cyclic.h
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-03-21 21:27:40
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version History
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-03-21 21:27:40  First Create
When you update, please do not forgot to delete me and add your info at here.
</pre>
*/
#ifndef _TASK_CYCLIC_H_
#define _TASK_CYCLIC_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "Task_Cyclic_Cfg.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/
#include "FreeRTOS.h"
#include "timers.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
extern void Task_Cyclic(TimerHandle_t pxTimer);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_TASK_CYCLIC_H_
/*============================= END OF FILE: Task_Cyclic.h ============================*/
