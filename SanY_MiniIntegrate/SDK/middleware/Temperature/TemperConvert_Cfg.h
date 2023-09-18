/********************************************************************
File name: TemperConvert_Cfg.h
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

#ifndef _TEMPERCONVERT_CFG_H_
#define _TEMPERCONVERT_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#include "Std_Types.h"
#include "TemperConvert_Tab.h"

/******************************************************************************
* External temerature circuit and adc parameter config
*
*//*! @addtogroup TEMPER_External
* @{
*******************************************************************************/
#define TEMPER_ADCSAMPLE_EXTERNAL 4095L
#define TEMPER_VREF_EXTERNAL 5000L
	
#define TEMPER_VPULL_EXTERNAL 5000L
#define TEMPER_RPULL_EXTERNAL 3000LL

#define TEMPER_MAX_EXTERNAL (850)  //Physical value * 10
#define TEMPER_MIN_EXTERNAL (-400) //Physical value * 10

#define TEMPER_GAP_EXTERNAL (10)   //Physical value * 10

#define Temper_ResisTab_External Temper_RTTab_Inner_GaoLi //Temper_RTTab_External
/*! @} End of TEMPER_External                                               */

/******************************************************************************
* Battery water temerature circuit and adc parameter config
*
*//*! @addtogroup TEMPER_BattWater
* @{
*******************************************************************************/
#define TEMPER_ADCSAMPLE_BATTWATER 4095L
#define TEMPER_VREF_BATTWATER 5000L
	
#define TEMPER_VPULL_BATTWATER 5000L
#define TEMPER_RPULL_BATTWATER 3000LL

#define TEMPER_MAX_BATTWATER (800)  //Physical value * 10
#define TEMPER_MIN_BATTWATER (-300) //Physical value * 10

#define TEMPER_GAP_BATTWATER (50)   //Physical value * 10

#define Temper_ResisTab_BattWater Temper_RTTab_BattWater
/*! @} End of TEMPER_BattWater                                               */

/******************************************************************************
* Heat pump(both two pump: high/low) temerature circuit and adc parameter config
*
*//*! @addtogroup TEMPER_HeatPump
* @{
*******************************************************************************/
#define TEMPER_ADCSAMPLE_HEATPUMP 4095L
#define TEMPER_VREF_HEATPUMP 5000L
	
#define TEMPER_VPULL_HEATPUMP 5000L
#define TEMPER_RPULL_HEATPUMP 3000LL

#define TEMPER_MAX_HEATPUMP (1400) //Physical value * 10
#define TEMPER_MIN_HEATPUMP (-300) //Physical value * 10

#define TEMPER_GAP_HEATPUMP (100)   //Physical value * 10

#define Temper_ResisTab_HeatPump Temper_RTTab_HeatPump
/*! @} End of TEMPER_HeatPump                                               */

/******************************************************************************
* Evaporator temerature circuit and adc parameter config
*
*//*! @addtogroup TEMPER_Evaporator
* @{
*******************************************************************************/
#define TEMPER_ADCSAMPLE_EVAPORATOR 4095L
#define TEMPER_VREF_EVAPORATOR 5000L
		
#define TEMPER_VPULL_EVAPORATOR 5000L
#define TEMPER_RPULL_EVAPORATOR 3000LL
	
#define TEMPER_MAX_EVAPORATOR (850) //Physical value * 10
#define TEMPER_MIN_EVAPORATOR (-400) //Physical value * 10
	
#define TEMPER_GAP_EVAPORATOR (10)   //Physical value * 10
	
#define Temper_ResisTab_Evaporator Temper_RTTab_Evaporator_NE110
/*! @} End of TEMPER_Evaporator											  */

/******************************************************************************
* Motor water temerature circuit and adc parameter config
*
*//*! @addtogroup TEMPER_MotorWater
* @{
*******************************************************************************/
#define TEMPER_ADCSAMPLE_MOTORWATER 4095L
#define TEMPER_VREF_MOTORWATER 5000L
		
#define TEMPER_VPULL_MOTORWATER 5000L
#define TEMPER_RPULL_MOTORWATER 3000LL
	
#define TEMPER_MAX_MOTORWATER (1350) //Physical value * 10
#define TEMPER_MIN_MOTORWATER (-400) //Physical value * 10
	
#define TEMPER_GAP_MOTORWATER (10)   //Physical value * 10
	
#define Temper_ResisTab_MotorWater Temper_RTTab_MotorWater
/*! @} End of TEMPER_MotorWater											  */





/******************************************************************************
* Inner temerature circuit and adc parameter config
*
*//*! @addtogroup TEMPER_Inner
* @{
*******************************************************************************/
#define TEMPER_ADCSAMPLE_INNER 4095L
#define TEMPER_VREF_INNER 5000L
	
#define TEMPER_VPULL_INNER 5000L
#define TEMPER_RPULL_INNER 3000LL

#define TEMPER_MAX_INNER (500) //Physical value * 10
#define TEMPER_MIN_INNER (-300) //Physical value * 10

#define TEMPER_GAP_INNER (5)   //Physical value * 10

#define Temper_ResisTab_Inner Temper_RTTab_Inner
/*! @} End of TEMPER_Inner                                               */

#define TEMPER_ADCSAMPLE_INNER_GAOLI 4095L
#define TEMPER_VREF_INNER_GAOLI 5000L

#define TEMPER_VPULL_INNER_GAOLI 5000L
#define TEMPER_RPULL_INNER_GAOLI 3000LL

#define TEMPER_MAX_INNER_GAOLI (850) //Physical value * 10
#define TEMPER_MIN_INNER_GAOLI (-400) //Physical value * 10

#define TEMPER_GAP_INNER_GAOLI (10)   //Physical value * 10

#define Temper_ResisTab_Inner_GaoLi Temper_RTTab_Inner_GaoLi

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _TEMPERCONVERT_CFG_H_

/*============================= END OF FILE: TemperConvert_Cfg.h ============================*/
