/**
* @file:    AdcPal.h
* @brief:   Add your description here for this file.
* @author:  Dimitri
* @date:    2020-04-26 17:40:37
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  Dimitri  2020-04-26 17:40:37  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#ifndef _ADCPAL_H_
#define _ADCPAL_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "AdcPal_Cfg.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/

/***************************************************************************//*!
 * @brief   Get 12bit ADC value
 * @details Get 12bit ADC value from ADC1.
 * @param   Channel  Channel of LUT ADC [0..11].
 * @return  12bit ADC value returned by API.
 ******************************************************************************/
extern uint16 AdcPal_GetCHRawValue(AdcPalCHEType Channel);

/***************************************************************************//*!
 * @brief   Get Original ADC value
 * @details Get Original ADC value from ADC1.
 * @note    Need circularly call.
 ******************************************************************************/
extern void AdcPal_Main(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_ADCPAL_H_
/*============================= END OF FILE: AdcPal.h ============================*/
