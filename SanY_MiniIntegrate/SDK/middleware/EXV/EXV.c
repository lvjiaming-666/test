/**
* @file:    EXV.c
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
 V1.0.0                  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
*/
#include "EXV.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
#include "pins_driver.h"
#include "pin_mux.h"
#include "CanMsg.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
#define EXV_ENALBE_PIN_ENABLE STD_LOW
#define EXV_ENALBE_PIN_DISABLE STD_HIGH
#define EXV_SLEEP_PIN_ENABLE STD_HIGH
#define EXV_SLEEP_PIN_DISABLE STD_LOW

typedef enum{	
	EXV_DIRECT_NONE,
	EXV_DIRECT_CLOSE,
	EXV_DIRECT_OPEN,
}EXV_DirectEType;

typedef enum{	
	EXV_INIT_NONE,
	EXV_INIT_PENDING,
	EXV_INIT_DONE,
}EXV_InitEType;

static uint16 EXV_RealPos[EXV_MOTOR_MAXNUM] = {EXV_LEVEL_MAXOPEN, EXV_LEVEL_MAXOPEN};
static uint16 EXV_TargetPluse[EXV_MOTOR_MAXNUM] = {EXV_LEVEL_TOTALCLOSE, EXV_LEVEL_TOTALCLOSE};
static EXV_DirectEType EXV_Dirction[EXV_MOTOR_MAXNUM] = {EXV_DIRECT_NONE, EXV_DIRECT_NONE};
static EXV_InitEType EXV_InitFlag[EXV_MOTOR_MAXNUM] = {EXV_INIT_NONE, EXV_INIT_NONE};
static uint16 EXV_TargetOpenLevel[EXV_MOTOR_MAXNUM] = {EXV_LEVEL_TOTALCLOSE, EXV_LEVEL_TOTALCLOSE};
volatile uint8 EXV_InRunning[EXV_MOTOR_MAXNUM] = {FALSE, FALSE};

/**
*@par Service ID[hex]
*0x00
*@par Sync/Async
*Synchronous
*@par Reentrancy
*Non Reentrant
*@param[in] None
*@param[inout] None
*@param[out] None
*@retval None
*
*@brief Service for callacking by others moudle.
*/
/* @req REQ001*/
static void EXV_SetSleepPin(EXV_MotorIndexEType MotorIndex, boolean OnOff)
{
	switch(MotorIndex)
	{
		case EXV_MOTOR_HEATPUMP:
			PINS_DRV_WritePin(Exv_Sleep1_PORT,Exv_Sleep1_PIN, OnOff);
		break;

		case EXV_MOTOR_BATTERY:
			PINS_DRV_WritePin(Exv_Sleep2_PORT,Exv_Sleep2_PIN, OnOff);
		break;
		default:break;
	}
}

static void EXV_SetEnablePin(EXV_MotorIndexEType MotorIndex, boolean OnOff)
{
	switch(MotorIndex)
	{
		case EXV_MOTOR_HEATPUMP:
			PINS_DRV_WritePin(ENABLE_MOTOR1_PORT,ENABLE_MOTOR1_PIN, OnOff);
		break;

		case EXV_MOTOR_BATTERY:
			PINS_DRV_WritePin(ENABLE_MOTOR2_PORT,ENABLE_MOTOR2_PIN, OnOff);
		break;
		default:break;
	}
}

static void EXV_SetDirectPin(EXV_MotorIndexEType MotorIndex, EXV_DirectEType Direct)
{ 
	switch(MotorIndex)
	{
		case EXV_MOTOR_HEATPUMP:
			if(EXV_DIRECT_OPEN == Direct){
				PINS_DRV_WritePin(DIRECTION_MOTOR1_PORT,DIRECTION_MOTOR1_PIN, STD_LOW);
			}else if(EXV_DIRECT_CLOSE == Direct){
				PINS_DRV_WritePin(DIRECTION_MOTOR1_PORT,DIRECTION_MOTOR1_PIN, STD_HIGH);
			}
		break;

		case EXV_MOTOR_BATTERY:
			if(EXV_DIRECT_OPEN == Direct){
				PINS_DRV_WritePin(DIRECTION_MOTOR2_PORT,DIRECTION_MOTOR2_PIN, STD_LOW);
			}else if(EXV_DIRECT_CLOSE == Direct){
				PINS_DRV_WritePin(DIRECTION_MOTOR2_PORT,DIRECTION_MOTOR2_PIN, STD_HIGH);
			}
		break;
		default:break;
	}
	EXV_Dirction[(uint8)MotorIndex] = Direct;
}

void EXV_Init(void)
{
	uint8 motorIndex = 0;

	for(motorIndex = 0; motorIndex < EXV_MOTOR_MAXNUM; motorIndex++)
	{
		EXV_SetEnablePin((EXV_MotorIndexEType)motorIndex, EXV_ENALBE_PIN_ENABLE);
		EXV_SetSleepPin((EXV_MotorIndexEType)motorIndex, EXV_SLEEP_PIN_ENABLE);
		EXV_SetDirectPin((EXV_MotorIndexEType)motorIndex, EXV_DIRECT_CLOSE);
		EXV_RealPos[motorIndex] = EXV_LEVEL_MAXOPEN;
		EXV_TargetPluse[motorIndex] = EXV_LEVEL_MAXOPEN;
		EXV_InitFlag[motorIndex] = EXV_INIT_PENDING;
	}
}

void EXV_SetOpenLevel(EXV_MotorIndexEType MotorIndex, uint16 openLevel)
{
	uint16 l_openLevel[EXV_MOTOR_MAXNUM];

	#if (0 == EXV_TEST_METHOD)
	l_openLevel[(uint8)MotorIndex] = openLevel;
	#elif(1 == EXV_TEST_METHOD)
	l_openLevel[(uint8)MotorIndex] = 0;//l_u8_rd_AC_EXV_Opening()*5; TODO: May receive from CAN
	#endif

	#if (2 != EXV_TEST_METHOD)
	if(l_openLevel[(uint8)MotorIndex]  <= EXV_LEVEL_MAXOPEN)
	{
		EXV_TargetOpenLevel[(uint8)MotorIndex]  = l_openLevel[(uint8)MotorIndex];
		EXV_InRunning[(uint8)MotorIndex]  = TRUE;
	}
	#endif
}

uint8 EXV_IsRunning(EXV_MotorIndexEType MotorIndex)
{
	return(EXV_InRunning[(uint8)MotorIndex]);
}

void EXV_Pause(EXV_MotorIndexEType MotorIndex)
{
	if(EXV_INIT_DONE == EXV_InitFlag[(uint8)MotorIndex]){
		EXV_TargetPluse[(uint8)MotorIndex] = 1;
	}
}

void EXV_ProcessPulse(void)
{
	uint8 motorIndex = 0;

	for(motorIndex = 0; motorIndex < EXV_MOTOR_MAXNUM; motorIndex++)
	{
		if (EXV_TargetPluse[motorIndex] >= 1){
			//Motor1 and Motor2 have the same port
			if(STD_HIGH == ((PINS_DRV_GetPinsOutput(PWM_MOTOR2_PORT)>>(motorIndex+10))&0x01)){
				EXV_TargetPluse[motorIndex]--;
				if(0 == EXV_TargetPluse[motorIndex]){
					EXV_SetEnablePin((EXV_MotorIndexEType)motorIndex, EXV_ENALBE_PIN_DISABLE);
					EXV_SetSleepPin((EXV_MotorIndexEType)motorIndex, EXV_SLEEP_PIN_DISABLE);
					EXV_InRunning[motorIndex] = FALSE;
				}
				if(EXV_DIRECT_CLOSE == EXV_Dirction[motorIndex]){
					if(EXV_RealPos[motorIndex] >= 1){
						EXV_RealPos[motorIndex]--;
					}
				}else if(EXV_DIRECT_OPEN == EXV_Dirction[motorIndex]){
					if(EXV_RealPos[motorIndex] < EXV_LEVEL_MAXOPEN){
						EXV_RealPos[motorIndex]++;
					}
				}
			}
			//Motor1 and Motor2 have the same port,PTC10 & PTC11
			PINS_DRV_TogglePins(PWM_MOTOR2_PORT, (0x01<<(motorIndex+10)));
		}
	}
}

uint16 EXV_GetRealPos(EXV_MotorIndexEType MotorIndex) 
{
  return EXV_RealPos[(uint8)MotorIndex] ;
}

void EXV_Main(void)
{
	uint8 motorIndex = 0;
	#if (2 == EXV_TEST_METHOD)
	uint16 l_openLevel[EXV_MOTOR_MAXNUM];
	#endif

	for(motorIndex = 0; motorIndex < EXV_MOTOR_MAXNUM; motorIndex++)
	{
		#if (2 == EXV_TEST_METHOD)
		l_openLevel[motorIndex] = 0; //l_u8_rd_AC_EXV_Opening()*5; TODO: May receive from CAN
		if(EXV_INIT_DONE == EXV_InitFlag[motorIndex])
		{
			if(l_openLevel[motorIndex] <= EXV_LEVEL_MAXOPEN)
			{
				EXV_TargetOpenLevel[motorIndex] = l_openLevel[motorIndex];
				EXV_InRunning[motorIndex] = TRUE;
			}
		}
		#endif
		if((EXV_INIT_PENDING == EXV_InitFlag[motorIndex])&&(0 == EXV_RealPos[motorIndex])){
			EXV_InitFlag[motorIndex] = EXV_INIT_DONE;
		}
		if((EXV_INIT_DONE == EXV_InitFlag[motorIndex])&&(EXV_TargetOpenLevel[motorIndex] != EXV_RealPos[motorIndex])){
			EXV_SetEnablePin((EXV_MotorIndexEType)motorIndex, EXV_ENALBE_PIN_ENABLE);
			EXV_SetSleepPin((EXV_MotorIndexEType)motorIndex, EXV_SLEEP_PIN_ENABLE);
			if(EXV_TargetOpenLevel[motorIndex] > EXV_RealPos[motorIndex]){
				EXV_SetDirectPin((EXV_MotorIndexEType)motorIndex, EXV_DIRECT_OPEN);
				EXV_TargetPluse[motorIndex] = EXV_TargetOpenLevel[motorIndex] - EXV_RealPos[motorIndex];
			}else{
				EXV_SetDirectPin((EXV_MotorIndexEType)motorIndex, EXV_DIRECT_CLOSE);
				EXV_TargetPluse[motorIndex] = EXV_RealPos[motorIndex] - EXV_TargetOpenLevel[motorIndex];
			}
		}
		CanSig_SetExvBattPos (EXV_RealPos[0]);
		CanSig_SetExvHeatPumpPos(EXV_RealPos[1]);
	}
} 

/*============================= END OF FILE: EXV.c ============================*/
