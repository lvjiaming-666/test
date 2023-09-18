/**
* @file:    BinarySearch.h
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
#ifndef _BINARYSEARCH_H_
#define _BINARYSEARCH_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "BinarySearch_Cfg.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/
#define BINSEARCH_ERROR 0xFFFF

#define BinSearch_Interval(type,bufLen,bufPtr,value) BinSearch_Interval_##type(bufLen,bufPtr,value)
#define BinSearch_EquMatch(type,bufLen,bufPtr,value) BinSearch_EquMatch_##type(bufLen,bufPtr,value)

#if (BSEARCH_EQUMATCH_BUFTYPE_SINT8 == STD_ON)
extern uint16 BinSearch_EquMatch_sint8(uint16 bufLen, const void* bufPtr, sint8 value);
#endif

#if (BSEARCH_EQUMATCH_BUFTYPE_SINT16 == STD_ON)
extern uint16 BinSearch_EquMatch_sint16(uint16 bufLen, const void* bufPtr, sint16 value);
#endif

#if (BSEARCH_EQUMATCH_BUFTYPE_SINT32 == STD_ON)
extern uint16 BinSearch_EquMatch_sint32(uint16 bufLen, const void* bufPtr, sint32 value);
#endif

#if (BSEARCH_EQUMATCH_BUFTYPE_UINT8 == STD_ON)
extern uint16 BinSearch_EquMatch_uint8(uint16 bufLen, const void* bufPtr, uint8 value);
#endif

#if (BSEARCH_EQUMATCH_BUFTYPE_UINT16 == STD_ON)
extern uint16 BinSearch_EquMatch_uint16(uint16 bufLen, const void* bufPtr, uint16 value);
#endif

#if (BSEARCH_EQUMATCH_BUFTYPE_UINT32 == STD_ON)
extern uint16 BinSearch_EquMatch_uint32(uint16 bufLen, const void* bufPtr, uint32 value);
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_SINT8 == STD_ON)
extern uint16 BinSearch_Interval_sint8(uint16 bufLen, const void* bufPtr, sint8 value);
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_SINT16 == STD_ON)
extern uint16 BinSearch_Interval_sint16(uint16 bufLen, const void* bufPtr, sint16 value);
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_SINT32 == STD_ON)
extern uint16 BinSearch_Interval_sint32(uint16 bufLen, const void* bufPtr, sint32 value);
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_UINT8 == STD_ON)
extern uint16 BinSearch_Interval_uint8(uint16 bufLen, const void* bufPtr, uint8 value);
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_UINT16 == STD_ON)
extern uint16 BinSearch_Interval_uint16(uint16 bufLen, const void* bufPtr, uint16 value);
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_UINT32 == STD_ON)
extern uint16 BinSearch_Interval_uint32(uint16 bufLen, const void* bufPtr, uint32 value);
#endif

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_BINARYSEARCH_H_
/*============================= END OF FILE: BinarySearch.h ============================*/
