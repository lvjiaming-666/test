/**
* @file:    StateMachine.c
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
/*==============================================================================
 *                               INCLUDE FILES
 *============================================================================*/
/* Module Include */
#include "StateMachine.h"

/* User Includes */
#include "Pump.h"
#include "Temperature.h"
#include "EXV.h"
#include "Valve.h"
#include "Fan.h"
#include "Press.h"
#include "CanMsg.h"
/*==============================================================================
 *                           EXTERNAL DECLARATIONS
 *============================================================================*/

/*==============================================================================
 *                            MODULE PREPROCESSORS
 *============================================================================*/

/*==============================================================================
 *                              MODULE TYPEDEFS
 *============================================================================*/
typedef enum
{
    SM_MODE_FUNC_MAIN,
    SM_MODE_FUNC_ENTRY,
    SM_MODE_FUNC_EXIT,
    SM_MODE_FUNC_MAX,
} SMModeFuncType;

typedef struct
{
    SMModeType preMode;
    SMModeType curMode;
    SMModeType nextMode;
} SMManagerType;
/*==============================================================================
 *                              MODULE VARIABLES
 *============================================================================*/
SMManagerType SMManager =
{
    .preMode = SM_MODE_OFF,
    .curMode = SM_MODE_OFF,
    .nextMode = SM_MODE_OFF,
};

/*==============================================================================
 *                              MODULE PROTOTYPES
 *============================================================================*/

/*==============================================================================
 *                              MODULE FUNCTIONS
 *============================================================================*/
void SM_Mx_Ignore(void)
{

}

void SM_Mx_Error(void)
{

}

void SM_Mx_SysOff(void)
{
    SMManager.nextMode = SM_MODE_OFF;
}

/* Mode0: BatCyc_AcOff */
void SM_M0_AcOn(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACCOOL;
}

void SM_M0_PtcOn(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACWARM;
}

void SM_M0_TBigThan30(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_ACOFF;
}

/* Mode1: BatCyc_AcCool */
void SM_M12_AcOff(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACOFF;
}

void SM_M1_PtcOn(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACWARM;
}

void SM_M1_TBigThan30(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_ACCOOL;
}
/* Mode2: BatCyc_AcWarm */
void SM_M2_AcOn(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_DEFROST;
}

void SM_M2_PtcOff(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACOFF;
}

void SM_M2_TBigThan30(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_ACWARM;
}
/* Mode3: BatCyc_Defrost */
void SM_M3_AcOff(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACWARM;
}

void SM_M3_PtcOff(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACCOOL;
}

void SM_M3_TBigThan30(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_DEFROST;
}
/* Mode4: BatCool_AcOff */
void SM_M4_AcOn(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_ACCOOL;
}

void SM_M4_PtcOn(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_ACWARM;
}

void SM_M4_TSmallThan25(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACOFF;
}

/* Mode5: BatCool_AcCool */
void SM_M56_AcOff(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_ACOFF;
}

void SM_M5_PtcOn(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_DEFROST;
}

void SM_M5_TSmallThan25(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACCOOL;
}
/* Mode6: BatCool_AcWarm */
void SM_M6_AcOn(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_DEFROST;
}

void SM_M6_PtcOff(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_ACOFF;
}

void SM_M6_TSmallThan25(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACWARM;
}
/* Mode7: BatCool_Defrost */
void SM_M7_AcOff(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_ACWARM;
}

void SM_M7_PtcOff(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_ACCOOL;
}

void SM_M7_TSmallThan25(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_DEFROST;
}
/* Mode8: Off */
void SM_M8_SysOn(void)
{
    SMManager.nextMode = SM_MODE_BATCYC_ACOFF;
}
void SM_M2_XXX(void)
{
    SMManager.nextMode = SM_MODE_BATCOOL_ACCOOL;
}

float Test_KP = 20.0f;
float Test_KI = 2.0f;
float Test_KD = 5.0f;

sint32 error = 0;
sint32 pre_error = 0;
sint32 tempGap = 0;
sint32 tempGapInteg = 0;
uint16 SM_BatCool_Pid(sint16 targetTemp, sint16 curTemp);
uint16 SM_BatCool_Pid(sint16 targetTemp, sint16 curTemp)
{
	sint32 compSpeed = 0;

	tempGap = curTemp - targetTemp;
	error = tempGap - pre_error;
	pre_error = tempGap;
	tempGapInteg += tempGap;
	compSpeed =	(uint16)(tempGap * Test_KP + tempGapInteg * Test_KI + error * Test_KD);
	if(compSpeed < 0)
	{
		compSpeed = 0;
	}
	else if(compSpeed > 5000)
	{
		compSpeed = 5000;
	}
	return compSpeed;
}

/*================== Main/Entry/Exit Funcs for each mode =====================*/
void SM_BatCyc_AcOff_Main(SMSigType event)
{

}

void SM_BatCyc_AcOff_Entry(SMSigType event)
{
    /* 电池水泵：0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM */
    Pummp_Battry(PUMP_MAX_SPEED_RPM*70/100);
    /* 关闭压缩机 */
    CanSig_SetCompTargetSpeed(0);
    CanSig_SetCompMaxPower(0);
    CanSig_SetCompEnable(0);
    /* 关闭PTC */
    //CanSig_SetPTC();
    /* 电子膨胀阀 */
    EXV_SetOpenLevel(EXV_MOTOR_BATTERY, EXV_LEVEL_TOTALCLOSE);
    /* 电磁热力膨胀阀 */
    Valve_AC(STD_OFF);
    /* 鼓风机：0, 750rpm ~ 3750rpm */
    Fan_CtrBlower(0);
}

void SM_BatCyc_AcOff_Exit(SMSigType event)
{

}

void SM_BatCyc_AcCool_Main(SMSigType event)
{

}

void SM_BatCyc_AcCool_Entry(SMSigType event)
{
	/* 电池水泵：0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM */
	Pummp_Battry(PUMP_MAX_SPEED_RPM*70/100);
	/* 电磁热力膨胀阀 */
	Valve_AC(STD_ON);
	/* 鼓风机：0, 750rpm ~ 3750rpm */
	Fan_CtrBlower(2250);
	/* 打开压缩机 */
	CanSig_SetCompTargetSpeed(1500);
	CanSig_SetCompMaxPower(0);
	CanSig_SetCompEnable(1);
	/* 关闭PTC */
	//CanSig_SetPTC();
	/* 电子膨胀阀 */
	EXV_SetOpenLevel(EXV_MOTOR_BATTERY, EXV_LEVEL_TOTALCLOSE);
}

void SM_BatCyc_AcCool_Exit(SMSigType event)
{

}

void SM_BatCyc_AcWarm_Main(SMSigType event)
{

}

void SM_BatCyc_AcWarm_Entry(SMSigType event)
{
	/* 电池水泵：0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM */
	Pummp_Battry(PUMP_MAX_SPEED_RPM*70/100);
	/* 鼓风机：0, 750rpm ~ 3750rpm */
	Fan_CtrBlower(2250);
	/* 打开PTC */
	//CanSig_SetPTC(30%);
	/* 电磁热力膨胀阀 */
	Valve_AC(STD_OFF);
	/* 关闭压缩机 */
	CanSig_SetCompTargetSpeed(0);
	CanSig_SetCompMaxPower(0);
	CanSig_SetCompEnable(0);
	/* 电子膨胀阀 */
	EXV_SetOpenLevel(EXV_MOTOR_BATTERY, EXV_LEVEL_TOTALCLOSE);
}

void SM_BatCyc_AcWarm_Exit(SMSigType event)
{

}

void SM_BatCyc_Defrost_Main(SMSigType event)
{

}

void SM_BatCyc_Defrost_Entry(SMSigType event)
{
	/* 电池水泵：0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM */
	Pummp_Battry(PUMP_MAX_SPEED_RPM*70/100);
	/* 鼓风机：0, 750rpm ~ 3750rpm */
	Fan_CtrBlower(2250);
	/* 电磁热力膨胀阀 */
	Valve_AC(STD_ON);
	/* 打开PTC */
	//CanSig_SetPTC(30%);
	/* 打开压缩机 */
	CanSig_SetCompTargetSpeed(1500);
	CanSig_SetCompMaxPower(0);
	CanSig_SetCompEnable(1);
	/* 电子膨胀阀 */
	EXV_SetOpenLevel(EXV_MOTOR_BATTERY, EXV_LEVEL_TOTALCLOSE);
}

void SM_BatCyc_Defrost_Exit(SMSigType event)
{

}

void SM_BatCool_AcOff_Main(SMSigType event)
{
	uint16 compSpeedPID = 0;
	static uint16 delayCtr = 0;

	if(event == SM_SIG_MAX)
	{
		delayCtr++;
		if(delayCtr > 200) //200*50 = 10000 = 10s
		{
			delayCtr = 0;
			compSpeedPID = SM_BatCool_Pid(200, Temper_GetBattWaterOut());
			CanSig_SetCompTargetSpeed(compSpeedPID);
		}
	}
}

void SM_BatCool_AcOff_Entry(SMSigType event)
{
	/* 电池水泵：0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM */
	Pummp_Battry(PUMP_MAX_SPEED_RPM);
	/* 电子膨胀阀 */
	EXV_SetOpenLevel(EXV_MOTOR_BATTERY, EXV_LEVEL_MAXOPEN);
	/* 电磁热力膨胀阀 */
	Valve_AC(STD_OFF);
	/* 打开压缩机 */
	CanSig_SetCompTargetSpeed(1500);
	CanSig_SetCompMaxPower(0XFE);
	CanSig_SetCompEnable(1);
	/* 鼓风机：0, 750rpm ~ 3750rpm */
	Fan_CtrBlower(0);
	/* 关闭PTC */
	//CanSig_SetPTC();
}

void SM_BatCool_AcOff_Exit(SMSigType event)
{

}

void SM_BatCool_AcCool_Main(SMSigType event)
{

}

void SM_BatCool_AcCool_Entry(SMSigType event)
{
	/* 电池水泵：0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM */
	Pummp_Battry(PUMP_MAX_SPEED_RPM);
	/* 电子膨胀阀 */
	EXV_SetOpenLevel(EXV_MOTOR_BATTERY, EXV_LEVEL_MAXOPEN);
	/* 电磁热力膨胀阀 */
	Valve_AC(STD_ON);
	/* 鼓风机：0, 750rpm ~ 3750rpm */
	Fan_CtrBlower(2250);
	/* 打开压缩机 */
	CanSig_SetCompTargetSpeed(1500);
	CanSig_SetCompMaxPower(0);
	CanSig_SetCompEnable(1);
	/* 关闭PTC */
	//CanSig_SetPTC();
}

void SM_BatCool_AcCool_Exit(SMSigType event)
{

}

void SM_BatCool_AcWarm_Main(SMSigType event)
{

}

void SM_BatCool_AcWarm_Entry(SMSigType event)
{
	/* 电池水泵：0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM */
	Pummp_Battry(PUMP_MAX_SPEED_RPM);
	/* 鼓风机：0, 750rpm ~ 3750rpm */
	Fan_CtrBlower(2250);
	/* 电子膨胀阀 */
	EXV_SetOpenLevel(EXV_MOTOR_BATTERY, EXV_LEVEL_MAXOPEN);
	/* 电磁热力膨胀阀 */
	Valve_AC(STD_OFF);
	/* 打开PTC */
	//CanSig_SetPTC(30%);
	/* 打开压缩机 */
	CanSig_SetCompTargetSpeed(1500);
	CanSig_SetCompMaxPower(0);
	CanSig_SetCompEnable(1);
}

void SM_BatCool_AcWarm_Exit(SMSigType event)
{

}


void SM_BatCool_Defrost_Main(SMSigType event)
{

}

void SM_BatCool_Defrost_Entry(SMSigType event)
{
	/* 电池水泵：0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM */
	Pummp_Battry(PUMP_MAX_SPEED_RPM);
	/* 鼓风机：0, 750rpm ~ 3750rpm */
	Fan_CtrBlower(2250);
	/* 电子膨胀阀 */
	EXV_SetOpenLevel(EXV_MOTOR_BATTERY, EXV_LEVEL_MAXOPEN);
	/* 电磁热力膨胀阀 */
	Valve_AC(STD_ON);
	/* 打开PTC */
	//CanSig_SetPTC(30%);
	/* 打开压缩机 */
	CanSig_SetCompTargetSpeed(1500);
	CanSig_SetCompMaxPower(0);
	CanSig_SetCompEnable(1);
}

void SM_BatCool_Defrost_Exit(SMSigType event)
{

}

void SM_Off_Main(SMSigType event)
{

}

void SM_Off_Entry(SMSigType event)
{
	/* 电池水泵：0, PUMP_MIN_SPEED_RPM ~ PUMP_MAX_SPEED_RPM */
	Pummp_Battry(0);
	/* 鼓风机：0, 750rpm ~ 3750rpm */
	Fan_CtrBlower(0);
	/* 电子膨胀阀 */
	EXV_SetOpenLevel(EXV_MOTOR_BATTERY, EXV_LEVEL_TOTALCLOSE);
	/* 电磁热力膨胀阀 */
	Valve_AC(STD_OFF);
	/* 关闭PTC */
	//CanSig_SetPTC();
	/* 关闭压缩机 */
	CanSig_SetCompTargetSpeed(0);
	CanSig_SetCompMaxPower(0);
	CanSig_SetCompEnable(0);
}

void SM_Off_Exit(SMSigType event)
{

}
/*==============================================================================
 *                              GLOBAL FUNCTIONS
 *============================================================================*/
void (*SM_ModeFuncList[][SM_MODE_FUNC_MAX])(SMSigType event) =
{
    {SM_BatCyc_AcOff_Main,    SM_BatCyc_AcOff_Entry,    SM_BatCyc_AcOff_Exit},
    {SM_BatCyc_AcCool_Main,   SM_BatCyc_AcCool_Entry,   SM_BatCyc_AcCool_Exit},
    {SM_BatCyc_AcWarm_Main,   SM_BatCyc_AcWarm_Entry,   SM_BatCyc_AcWarm_Exit},
	{SM_BatCyc_Defrost_Main,  SM_BatCyc_Defrost_Entry,  SM_BatCyc_Defrost_Exit},
    {SM_BatCool_AcOff_Main,   SM_BatCool_AcOff_Entry,   SM_BatCool_AcOff_Exit},
    {SM_BatCool_AcCool_Main,  SM_BatCool_AcCool_Entry,  SM_BatCool_AcCool_Exit},
    {SM_BatCool_AcWarm_Main,  SM_BatCool_AcWarm_Entry,  SM_BatCool_AcWarm_Exit},
	{SM_BatCool_Defrost_Main, SM_BatCool_Defrost_Entry, SM_BatCool_Defrost_Exit},
    {SM_Off_Main,             SM_Off_Entry,             SM_Off_Exit},
};

void (*SM_ModeEventFuncList[SM_MODE_MAX][SM_SIG_MAX])(void) =
{
    //Sig: SYSOFF     SYSON       ACOFF        ACON             PTCOFF     PTCON           T<25                  T<30        T>30
    /* Mode0: BatCyc_AcOff */
    {SM_Mx_SysOff, SM_Mx_Error, SM_Mx_Error,  SM_M0_AcOn,   SM_Mx_Error,  SM_M0_PtcOn,  SM_Mx_Ignore,       SM_Mx_Ignore, SM_M0_TBigThan30},
    /* Mode1: BatCyc_AcCool */
    {SM_Mx_SysOff, SM_Mx_Error, SM_M12_AcOff, SM_Mx_Error,  SM_Mx_Error,  SM_M1_PtcOn,  SM_Mx_Ignore,       SM_Mx_Error,  SM_M1_TBigThan30},
    /* Mode2: BatCyc_AcWarm */
    {SM_Mx_SysOff, SM_Mx_Error, SM_M12_AcOff, SM_M2_AcOn,   SM_M2_PtcOff, SM_Mx_Error,  SM_Mx_Ignore,       SM_Mx_Error,  SM_M2_TBigThan30},
    /* Mode3: BatCyc_Defrost */
    {SM_Mx_SysOff, SM_Mx_Error, SM_M3_AcOff,  SM_Mx_Error,  SM_M3_PtcOff, SM_Mx_Error,  SM_Mx_Ignore,       SM_Mx_Error,  SM_M3_TBigThan30},
    /* Mode4: BatCool_AcOff */
    {SM_Mx_SysOff, SM_Mx_Error, SM_Mx_Error,  SM_M4_AcOn,   SM_Mx_Error,  SM_M4_PtcOn,  SM_M4_TSmallThan25, SM_Mx_Ignore, SM_Mx_Ignore},
    /* Mode5: BatCool_AcCool */
    {SM_Mx_SysOff, SM_Mx_Error, SM_M56_AcOff, SM_Mx_Error,  SM_Mx_Error,  SM_M5_PtcOn,  SM_M5_TSmallThan25, SM_Mx_Ignore, SM_Mx_Ignore},
    /* Mode6: BatCool_AcWarm */
    {SM_Mx_SysOff, SM_Mx_Error, SM_M56_AcOff, SM_M6_AcOn,   SM_M6_PtcOff, SM_Mx_Error,  SM_M6_TSmallThan25, SM_Mx_Ignore, SM_Mx_Ignore},
    /* Mode7: BatCool_Defrost */
    {SM_Mx_SysOff, SM_Mx_Error, SM_M7_AcOff,  SM_Mx_Error,  SM_M7_PtcOff, SM_Mx_Error,  SM_M7_TSmallThan25, SM_Mx_Ignore, SM_Mx_Ignore},
    /* Mode8: Off */
    {SM_Mx_Ignore, SM_M8_SysOn, SM_Mx_Ignore, SM_Mx_Ignore, SM_Mx_Ignore, SM_Mx_Ignore, SM_Mx_Ignore,       SM_Mx_Ignore, SM_Mx_Ignore},
};

void SM_ModeChangeCallback(SMModeType oldMode, SMModeType newMode)
{
    (void)oldMode;
    (void)newMode;
    
    //UserCallbackFunc();
}

SMModeType SM_GetPreviousMode(void)
{
    return SMManager.preMode;
}

SMModeType SM_GetCurrentMode(void)
{
    return SMManager.curMode;
}

SMModeType SM_GetNextMode(void)
{
    return SMManager.nextMode;
}

void SM_Main(SMSigType event)
{
	return;
    if (SM_SIG_MAX > event)
    {
        if (NULL != SM_ModeEventFuncList[SMManager.curMode][event])
        {
            (*SM_ModeEventFuncList[SMManager.curMode][event])();
        }
        CanSig_SetStateMachineEvent((uint8)event);
    }
    //state change
    if (SMManager.curMode != SMManager.nextMode)
    {
        SM_ModeChangeCallback(SMManager.curMode, SMManager.nextMode);
        if (NULL != SM_ModeFuncList[SMManager.curMode][SM_MODE_FUNC_EXIT])
        {
            (*SM_ModeFuncList[SMManager.curMode][SM_MODE_FUNC_EXIT])(event);
        }
        SMManager.preMode = SMManager.curMode;
        SMManager.curMode = SMManager.nextMode;
        if (NULL != SM_ModeFuncList[SMManager.curMode][SM_MODE_FUNC_ENTRY])
        {
            (*SM_ModeFuncList[SMManager.curMode][SM_MODE_FUNC_ENTRY])(event);
        }
    }

    //main function
    (*SM_ModeFuncList[SMManager.curMode][SM_MODE_FUNC_MAIN])(event);
    CanSig_SetSystemPreMode((uint8)SMManager.preMode);
    CanSig_SetSystemCurMode((uint8)SMManager.curMode);
}

/*================================ END OF FILE ===============================*/
