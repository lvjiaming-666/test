/**
* @file:    StateMachine.h
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-03-23 21:08:18
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version History
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-03-23 21:08:18  First Create
When you update, please do not forgot to delete me and add your info at here.
</pre>
*/
#ifndef _STATEMACHINE_H_
#define _STATEMACHINE_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
/*==============================================================================
 *                               INCLUDE FILES
 *============================================================================*/
/* Module Include */
#include "Std_Types.h"
#include "StateMachine_Cfg.h"
/* User Includes */

/*==============================================================================
 *                            MODULE PREPROCESSORS
 *============================================================================*/

/*==============================================================================
 *                              MODULE TYPEDEFS
 *============================================================================*/
typedef enum
{
    SM_MODE_BATCYC_ACOFF,
    SM_MODE_BATCYC_ACCOOL,
    SM_MODE_BATCYC_ACWARM,
	SM_MODE_BATCYC_DEFROST,
    SM_MODE_BATCOOL_ACOFF,
    SM_MODE_BATCOOL_ACCOOL,
    SM_MODE_BATCOOL_ACWARM,
	SM_MODE_BATCOOL_DEFROST,
	SM_MODE_OFF,
    SM_MODE_MAX,
} SMModeType;

typedef enum
{
    SM_SIG_SYS_OFF = 0,
    SM_SIG_SYS_ON = 1,
    SM_SIG_AC_OFF = 2,
    SM_SIG_AC_ON = 3,
	SM_SIG_PTC_OFF = 4,
	SM_SIG_PTC_ON = 5,
	SM_SIG_TEMP_SMALL_THAN_25 = 6,
	SM_SIG_TEMP_SMALL_THAN_30 = 7,
	SM_SIG_TEMP_BIG_THAN_30 = 8,
    SM_SIG_MAX = 9,
} SMSigType;

/*==============================================================================
 *                            FUNCTION PROTOTYPES
 *============================================================================*/
void SM_Main(SMSigType event);
SMModeType SM_GetCurrentMode(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_STATEMACHINE_H_
/*================================ END OF FILE ===============================*/
