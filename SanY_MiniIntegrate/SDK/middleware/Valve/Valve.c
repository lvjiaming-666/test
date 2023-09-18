/**
* @file:    Valve.c
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-02-04 22:33:28
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-02-04 22:33:28  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#include "Valve.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
#include "pins_driver.h"
#include "pin_mux.h"
#include "pwm_pal.h"
#include "peripherals_pwm_pal_1.h"
#include "AdcPal.h"
#include "CanMsg.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
typedef struct {
	Valve_BattTripleWaterPosEType tarPos;
	Valve_BattTripleWaterPosEType curPos;
}Valve_BattTripStatusType;

Valve_BattTripStatusType Valve_BattTripStatus[VALVE_BATT_TRIPWATER_MAX] =
{
		{VALVE_BATT_TRIPWATER_POS_V1_V2, VALVE_BATT_TRIPWATER_POS_V1_V2},
		{VALVE_BATT_TRIPWATER_POS_V1_V2, VALVE_BATT_TRIPWATER_POS_V1_V2},
};

void Valve_Hot(boolean OnOff)
{
    if(STD_ON == OnOff)
	{
    	PINS_DRV_WritePin(MCU_Valve2_PORT,MCU_Valve2_PIN, STD_OFF);
	}
	else
	{
		PINS_DRV_WritePin(MCU_Valve2_PORT,MCU_Valve2_PIN, STD_ON);
	}
    CanSig_SetValveHot(OnOff);
}

void Valve_AC(boolean OnOff)
{
    if(STD_ON == OnOff)
	{
    	PINS_DRV_WritePin(MCU_Valve3_PORT,MCU_Valve3_PIN, STD_OFF);
	}
	else
	{
		PINS_DRV_WritePin(MCU_Valve3_PORT,MCU_Valve3_PIN, STD_ON);
	}
    CanSig_SetValveAc(OnOff);
}

void Valve_CutOff(boolean OnOff)
{
	if(STD_ON == OnOff)
	{
		PINS_DRV_WritePin(MCU_Valve1_PORT,MCU_Valve1_PIN, STD_OFF);
	}
	else
	{
		PINS_DRV_WritePin(MCU_Valve1_PORT,MCU_Valve1_PIN, STD_ON);
	}
	CanSig_SetValveCutOff(OnOff);
}

uint16 Valve_GetBattTripleWaterFdbkMv(Valve_BattTripleWaterIdxEType Index)
{
	uint16 adcValue = 0U;
	uint16 voltageMv = 0U;

    switch(Index)
    {
        case VALVE_BATT_TRIPWATER_IDX1:
        	adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_BATT_VALVE1_FDBK);
            break;

        case VALVE_BATT_TRIPWATER_IDX2:
        	adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_BATT_VALVE2_FDBK);
            break;
        default:
            break;
    }
    voltageMv = (uint16)(adcValue*1000LL/819);
    return voltageMv;
}

void Valve_BattTripWater_Init(void)
{
	uint8 index = 0;

	for(index = 0; index < VALVE_BATT_TRIPWATER_MAX; index++)
	{
		Valve_BattTripleWater((Valve_BattTripleWaterIdxEType)index, VALVE_BATT_TRIPWATER_POS_HALF_V1_V2_V3);
	}
}

void Valve_BattTripleWater(Valve_BattTripleWaterIdxEType Index, Valve_BattTripleWaterPosEType Position)
{
    uint32 l_duty = 25000;

    if((uint8)Index < VALVE_BATT_TRIPWATER_MAX)
    {
    	Valve_BattTripStatus[(uint8)Index].tarPos = Position;
		switch(Position)
		{
			/* P2:4.7V    (P2+P3)/2:2.5V   P3:0.3V*/
			case VALVE_BATT_TRIPWATER_POS_V1_V2:
				if(Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)Index) < (4700 - TRIPWATER_POS_DELTA_MV))
				{
					l_duty = 50000;
				}
				else if ((4700 + TRIPWATER_POS_DELTA_MV) < Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)Index))
				{
					l_duty = 0;
				}
				else
				{
					l_duty = 25000;
				}
				break;
			case VALVE_BATT_TRIPWATER_POS_V1_V3:
				if(Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)Index) < (300 - TRIPWATER_POS_DELTA_MV))
				{
					l_duty = 50000;
				}
				else if ((300 + TRIPWATER_POS_DELTA_MV) < Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)Index))
				{
					l_duty = 0;
				}
				else
				{
					l_duty = 25000;
				}
				break;
			case VALVE_BATT_TRIPWATER_POS_HALF_V1_V2_V3:
				if(Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)Index) < (2500 - TRIPWATER_POS_DELTA_MV))
				{
					l_duty = 50000;
				}
				else if ((2500 + TRIPWATER_POS_DELTA_MV) < Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)Index))
				{
					l_duty = 0;
				}
				else
				{
					l_duty = 25000;
				}
				break;
			default:
				break;
		}
		switch(Index)
		{
			case VALVE_BATT_TRIPWATER_IDX1:
				PWM_UpdateDuty(&pwm_pal_1_instance, 1, l_duty);
    			CanSig_SetValveBattWater1((uint8)Position);

				break;

			case VALVE_BATT_TRIPWATER_IDX2:
				PWM_UpdateDuty(&pwm_pal_1_instance, 0, l_duty);
				CanSig_SetValveBattWater2((uint8)Position);
				break;
			default:
				break;
		}
    }
}

void Valve_BattTripleWater_Main(void)
{
	uint8 index = 0;
	uint32 l_duty = 25000;

	for(index = 0; index < VALVE_BATT_TRIPWATER_MAX; index++)
	{
		switch(Valve_BattTripStatus[index].tarPos)
		{
			/* P2:4.7V    (P2+P3)/2:2.5V   P3:0.3V*/
			case VALVE_BATT_TRIPWATER_POS_V1_V2:
				if(Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)index) < (4700 - TRIPWATER_POS_DELTA_MV))
				{
					l_duty = 50000;
				}
				else if ((4700 + TRIPWATER_POS_DELTA_MV) < Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)index))
				{
					l_duty = 0;
				}
				else
				{
					l_duty = 25000;
				}
				break;
			case VALVE_BATT_TRIPWATER_POS_V1_V3:
				if(Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)index) < (300 - TRIPWATER_POS_DELTA_MV))
				{
					l_duty = 50000;
				}
				else if ((300 + TRIPWATER_POS_DELTA_MV) < Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)index))
				{
					l_duty = 0;
				}
				else
				{
					l_duty = 25000;
				}
				break;
			case VALVE_BATT_TRIPWATER_POS_HALF_V1_V2_V3:
				if(Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)index) < (2500 - TRIPWATER_POS_DELTA_MV))
				{
					l_duty = 50000;
				}
				else if ((2500 + TRIPWATER_POS_DELTA_MV) < Valve_GetBattTripleWaterFdbkMv((Valve_BattTripleWaterIdxEType)index))
				{
					l_duty = 0;
				}
				else
				{
					l_duty = 25000;
				}
				break;
			default:
				break;
		}
		switch((Valve_BattTripleWaterIdxEType)index)
		{
			case VALVE_BATT_TRIPWATER_IDX1:
				PWM_UpdateDuty(&pwm_pal_1_instance, 1, l_duty);
				break;

			case VALVE_BATT_TRIPWATER_IDX2:
				PWM_UpdateDuty(&pwm_pal_1_instance, 0, l_duty);
				break;
			default:
				break;
		}
	}
}

//0% ~ 100% Control by CAN signal
void Valve_MotorTriple(uint8 Position)
{

}

/*============================= END OF FILE: Valve.c ============================*/
