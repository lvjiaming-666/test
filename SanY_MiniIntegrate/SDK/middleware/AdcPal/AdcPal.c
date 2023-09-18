/**
* @file:    AdcPal.c
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
#include "AdcPal.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
#include "adc_pal.h"
#include "peripherals_adc_pal_1.h"
#include "peripherals_adc_pal_2.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
static uint16 AdcPal_Buffer[27] =
{
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0
};

void adc_pal_1_callback0(const adc_callback_info_t * const callbackInfo, void * userData)
{
    //uint16_t resultLastOffset = 0;
	(void) userData;
	(void) callbackInfo;

    //resultLastOffset = callbackInfo->resultBufferTail;
    ADC_StartGroupConversion(&adc_pal_1_instance, 1);
}

void adc_pal_1_callback1(const adc_callback_info_t * const callbackInfo, void * userData)
{
    //uint16_t resultLastOffset = 0;
	(void) userData;
	(void) callbackInfo;

    //resultLastOffset = callbackInfo->resultBufferTail;
}

void adc_pal_2_callback0(const adc_callback_info_t * const callbackInfo, void * userData)
{
	//uint16_t resultLastOffset = 0;
    (void) userData;
    (void) callbackInfo;

    //resultLastOffset = callbackInfo->resultBufferTail;
    ADC_StartGroupConversion(&adc_pal_2_instance, 1);
}

void adc_pal_2_callback1(const adc_callback_info_t * const callbackInfo, void * userData)
{
	//uint16_t resultLastOffset = 0;
    (void) userData;
    (void) callbackInfo;

    //resultLastOffset = callbackInfo->resultBufferTail;
}

uint16 AdcPal_GetCHRawValue(AdcPalCHEType Channel)
{
	uint16 adcValue = 0;
	if(Channel < ADCPAL_CH_MAX)
	{
		adcValue = AdcPal_Buffer[(uint8)Channel];
	}
	return adcValue;
}

void AdcPal_Main(void)
{
	uint8 chIdx = 0;

	for(chIdx = 0; chIdx < 8; chIdx++)
	{
		AdcPal_Buffer[chIdx] = adc_pal_1_results0[chIdx];
	}
	for(chIdx = 8; chIdx < 12; chIdx++)
	{
		AdcPal_Buffer[chIdx] = adc_pal_1_results1[chIdx-8];
	}
	for(chIdx = 12; chIdx < 20; chIdx++)
	{
		AdcPal_Buffer[chIdx] = adc_pal_2_results0[chIdx-12];
	}
	for(chIdx = 20; chIdx < 27; chIdx++)
	{
		AdcPal_Buffer[chIdx] = adc_pal_2_results1[chIdx-20];
	}
	ADC_StartGroupConversion(&adc_pal_1_instance, 0);
	ADC_StartGroupConversion(&adc_pal_2_instance, 0);
}
/*============================= END OF FILE: AdcPal.c ============================*/
