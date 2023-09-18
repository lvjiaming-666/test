/**
* @file:    EXV_Cfg.h
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
#ifndef _EXV_CFG_H_
#define _EXV_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/
#define EXV_MOTOR_MAXNUM 2

/* These is EXV total length */
#define EXV_LEVEL_TOTALCLOSE 0
#define EXV_LEVEL_MAXOPEN 500

//0: Normal Mode, not in test mode. 
//1: With previous condition 
//2: without any condition, when you set, it will take action immediately
#define EXV_TEST_METHOD 0

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_EXV_CFG_H_
/*============================= END OF FILE: EXV_Cfg.h ============================*/
