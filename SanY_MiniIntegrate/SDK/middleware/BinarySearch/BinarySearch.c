/**
* @file:    BinarySearch.c
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
#include "BinarySearch.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/
#define BINSEARCH_FUNC(funcName,bufType) funcName##_##bufType

#if (BSEARCH_EQUMATCH_BUFTYPE_SINT8 == STD_ON)
#define BINSEARCH_BUF_TYPE sint8
#define BSEARCH_EQUMATCH_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_EQUMATCH_BUFTYPE_SINT16 == STD_ON)
#define BINSEARCH_BUF_TYPE sint16
#define BSEARCH_EQUMATCH_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_EQUMATCH_BUFTYPE_SINT32 == STD_ON)
#define BINSEARCH_BUF_TYPE sint32
#define BSEARCH_EQUMATCH_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_EQUMATCH_BUFTYPE_UINT8 == STD_ON)
#define BINSEARCH_BUF_TYPE uint8
#define BSEARCH_EQUMATCH_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_EQUMATCH_BUFTYPE_UINT16 == STD_ON)
#define BINSEARCH_BUF_TYPE uint16
#define BSEARCH_EQUMATCH_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_EQUMATCH_BUFTYPE_UINT32 == STD_ON)
#define BINSEARCH_BUF_TYPE uint32
#define BSEARCH_EQUMATCH_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_SINT8 == STD_ON)
#define BINSEARCH_BUF_TYPE sint8
#define BSEARCH_INTERVAL_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_SINT16 == STD_ON)
#define BINSEARCH_BUF_TYPE sint16
#define BSEARCH_INTERVAL_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_SINT32 == STD_ON)
#define BINSEARCH_BUF_TYPE sint32
#define BSEARCH_INTERVAL_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_UINT8 == STD_ON)
#define BINSEARCH_BUF_TYPE uint8
#define BSEARCH_INTERVAL_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_UINT16 == STD_ON)
#define BINSEARCH_BUF_TYPE uint16
#define BSEARCH_INTERVAL_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

#if (BSEARCH_INTERVAL_BUFTYPE_UINT32 == STD_ON)
#define BINSEARCH_BUF_TYPE uint32
#define BSEARCH_INTERVAL_FUNC(funcName,bufType) BINSEARCH_FUNC(funcName,bufType)
#include "BinarySearch.temp"
#endif

/*============================= END OF FILE: BinarySearch.c ============================*/
