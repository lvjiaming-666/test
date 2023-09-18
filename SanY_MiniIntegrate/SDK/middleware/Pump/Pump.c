/**
* @file:    Pump.c
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-02-04 23:24:07
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-02-04 23:24:07  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#include "Pump.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
#include "pwm_pal.h"
#include "peripherals_pwm_pal_1.h"
#include "peripherals_pwm_pal_2.h"
#include "AdcPal.h"
#include "CanMsg.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
uint16 Pump_GetMotorFdbk(void)
{
	uint16 adcValue = AdcPal_GetCHRawValue(ADCPAL_CH_MOTOR_PUMP_FDBK);
    uint16 voltageMv = 0U;

    voltageMv = (uint16)(adcValue*8000LL/819);
    return voltageMv;
}

/* speedRpm: 0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM*/
void Pummp_Battry(uint16 speedRpm)
{
	uint8 l_pwmUpdate = 0;
	uint8 l_duty = 0;
	uint32 l_pwmValue = 0;

	if((PUMP_MIN_SPEED_RPM <= speedRpm) && (speedRpm <= PUMP_MAX_SPEED_RPM))
	{
		l_duty = (speedRpm - PUMP_MIN_SPEED_RPM)*35/(PUMP_MAX_SPEED_RPM - PUMP_MIN_SPEED_RPM) + 55;
		l_pwmValue = PWM_CYCLE_MAX_VALUE * l_duty / 100;
		l_pwmUpdate = 1;
	}
	else if(0 == speedRpm)
	{
		//Stopped by user
		l_pwmValue = 2500; //2500: %5. According to real test, only can stopped in the range of: 1% ~ 10%
		l_pwmUpdate = 1;
	}
	if(1 == l_pwmUpdate)
	{
		PWM_UpdateDuty(&pwm_pal_1_instance, 6, l_pwmValue);
		CanSig_SetPumpSpeedBattery(speedRpm);
	}
}

/* speedRpm: 0, PUMP_MIN_SPEED_RPM rpm ~ PUMP_MAX_SPEED_RPM rpm*/
void Pummp_AirCondition(uint16 speedRpm)
{
	uint8 l_pwmUpdate = 0;
	uint8 l_duty = 0;
	uint32 l_pwmValue = 0;

	if((PUMP_MIN_SPEED_RPM <= speedRpm) && (speedRpm <= PUMP_MAX_SPEED_RPM))
	{
		l_duty = (speedRpm - PUMP_MIN_SPEED_RPM)*35/(PUMP_MAX_SPEED_RPM - PUMP_MIN_SPEED_RPM) + 55;
		l_pwmValue = PWM_CYCLE_MAX_VALUE * l_duty / 100;
		l_pwmUpdate = 1;
	}
	else if(0 == speedRpm)
	{
		//Stopped by user
		l_pwmValue = 2500; //2500: %5. According to real test, only can stopped in the range of: 1% ~ 10%
		l_pwmUpdate = 1;
	}
	if(1 == l_pwmUpdate)
	{
		PWM_UpdateDuty(&pwm_pal_1_instance, 7, l_pwmValue);
		CanSig_SetPumpSpeedAirCond(speedRpm);
	}
}

/* speedRpm: 0, PUMP_MIN_SPEED_RPM rpm ~ PUMP_MAX_SPEED_RPM rpm*/
void Pummp_Motor(uint16 speedRpm)
{
	uint8 l_pwmUpdate = 0;
	uint8 l_duty = 0;
	uint32 l_pwmValue = 0;

	if(Pump_GetMotorFdbk() < 1000)
	{
		if((PUMP_MIN_SPEED_RPM <= speedRpm) && (speedRpm <= PUMP_MAX_SPEED_RPM))
		{
			l_duty = (speedRpm - PUMP_MIN_SPEED_RPM)*69/(PUMP_MAX_SPEED_RPM - PUMP_MIN_SPEED_RPM) + 16;
			l_pwmValue = PWM_CYCLE_MAX_VALUE * l_duty / 100;
			l_pwmUpdate = 1;
		}
		else if(0 == speedRpm)
		{
			//Stopped by user
			l_pwmValue = 5000; //5000: %10. According to real test, only can stopped in the range of: 6% ~ 15%
			l_pwmUpdate = 1;
		}
	}
	else
	{
		//Error happened according to the feedback, stop it.
		l_pwmUpdate = 1;
	}
	if(1 == l_pwmUpdate)
	{
		PWM_UpdateDuty(&pwm_pal_2_instance, 7, l_pwmValue);
		CanSig_SetPumpSpeedMotor(speedRpm);
	}
}

/*============================= END OF FILE: Pump.c ============================*/
