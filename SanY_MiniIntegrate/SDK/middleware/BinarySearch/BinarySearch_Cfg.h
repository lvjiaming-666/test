/**
* @file:    BinarySearch_Cfg.h
* @brief:   Add your description here for this file.
* @author:  Stephen Du
* @date:    2018-06-14 16:58:03
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  Stephen Du  2018-06-14 16:58:03  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#ifndef _BINARYSEARCH_CFG_H_
#define _BINARYSEARCH_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/

/*------------------------------ START: USER CONFIG -----------------------------*/
#define BSEARCH_EQUMATCH_FUNC_ENABLE    STD_OFF
#define BSEARCH_INTERVAL_FUNC_ENABLE    STD_ON
/*-------------------------------- END: USER CONFIG -----------------------------*/

#if (STD_ON == BSEARCH_EQUMATCH_FUNC_ENABLE)
/*------------------------------ START: USER CONFIG -----------------------------*/
#define BSEARCH_EQUMATCH_BUFTYPE_SINT8  STD_ON
#define BSEARCH_EQUMATCH_BUFTYPE_SINT16 STD_ON
#define BSEARCH_EQUMATCH_BUFTYPE_SINT32 STD_ON
#define BSEARCH_EQUMATCH_BUFTYPE_UINT8  STD_ON
#define BSEARCH_EQUMATCH_BUFTYPE_UINT16 STD_ON
#define BSEARCH_EQUMATCH_BUFTYPE_UINT32 STD_ON
/*-------------------------------- END: USER CONFIG -----------------------------*/
#else
#define BSEARCH_EQUMATCH_BUFTYPE_SINT8  STD_OFF
#define BSEARCH_EQUMATCH_BUFTYPE_SINT16 STD_OFF
#define BSEARCH_EQUMATCH_BUFTYPE_SINT32 STD_OFF
#define BSEARCH_EQUMATCH_BUFTYPE_UINT8  STD_OFF
#define BSEARCH_EQUMATCH_BUFTYPE_UINT16 STD_OFF
#define BSEARCH_EQUMATCH_BUFTYPE_UINT32 STD_OFF
#endif


#if (STD_ON == BSEARCH_INTERVAL_FUNC_ENABLE)
/*------------------------------ START: USER CONFIG -----------------------------*/
#define BSEARCH_INTERVAL_BUFTYPE_SINT8  STD_ON
#define BSEARCH_INTERVAL_BUFTYPE_SINT16 STD_ON
#define BSEARCH_INTERVAL_BUFTYPE_SINT32 STD_ON
#define BSEARCH_INTERVAL_BUFTYPE_UINT8  STD_ON
#define BSEARCH_INTERVAL_BUFTYPE_UINT16 STD_ON
#define BSEARCH_INTERVAL_BUFTYPE_UINT32 STD_ON
/*-------------------------------- END: USER CONFIG -----------------------------*/
#else
#define BSEARCH_INTERVAL_BUFTYPE_SINT8  STD_OFF
#define BSEARCH_INTERVAL_BUFTYPE_SINT16 STD_OFF
#define BSEARCH_INTERVAL_BUFTYPE_SINT32 STD_OFF
#define BSEARCH_INTERVAL_BUFTYPE_UINT8  STD_OFF
#define BSEARCH_INTERVAL_BUFTYPE_UINT16 STD_OFF
#define BSEARCH_INTERVAL_BUFTYPE_UINT32 STD_OFF
#endif

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_BINARYSEARCH_CFG_H_
/*============================= END OF FILE: BinarySearch_Cfg.h ============================*/
