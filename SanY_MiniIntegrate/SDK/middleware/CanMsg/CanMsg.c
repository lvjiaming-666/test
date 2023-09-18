/**
* @file:    CanMsg.c
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-03-06 20:33:33
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version History
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-03-06 20:33:33  First Create
When you update, please do not forgot to delete me and add your info at here.
</pre>
*/
#include "CanMsg.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
#include "can_pal.h"
#include "peripherals_can_pal_1.h"
#include "Temperature.h"
#include "LiquidLevel.h"
#include "Press.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
extern CanMsg_0x1814FAF1_CompAcType CanMsg_0x1814FAF1_CompAc;
extern CanMsg_0x18FF767D_Ptc2AcType CanMsg_0x18FF767D_Ptc2Ac;

extern CanMsg_0x18220145_AcCompType CanMsg_0x18220145_AcComp;
extern CanMsg_0x18FF7419_Ac2PtcType CanMsg_0x18FF7419_Ac2Ptc;

extern CanMsg_0x201_VcuAcReqType CanMsg_0x201_VcuAcReq;
extern CanMsg_0x301Type CanMsg_0x301;
extern CanMsg_0x302Type CanMsg_0x302;
extern CanMsg_0x303Type CanMsg_0x303;
extern CanMsg_0x304Type CanMsg_0x304;
extern CanMsg_0x305Type CanMsg_0x305;

can_buff_config_t Can0_TxStdBuff = { FALSE, FALSE, FALSE, CAN_MSG_ID_STD, FALSE};
can_buff_config_t Can0_TxExtBuff = { FALSE, FALSE, FALSE, CAN_MSG_ID_EXT, FALSE};
can_buff_config_t Can0_RxBuff = { FALSE, FALSE, FALSE, CAN_MSG_ID_EXT, FALSE};
can_message_t Can0_RxMsg;

can_message_t Can0_Tx_0x18220145_AcComp =
{
    .cs = 0,
    .id = 0x18220145,
    .data = {0,0,0,0,0,0,0,0},
    .length = 8
};

can_message_t Can0_Tx_0x18FF7419_Ac2Ptc =
{
    .cs = 0,
    .id = 0x18FF7419,
    .data = {0,0,0,0,0,0,0,0},
    .length = 8
};

can_message_t Can0_Tx_0x301 =
{
    .cs = 0,
    .id = 0x301,
    .data = {0,0,0,0,0,0,0,0},
    .length = 8
};

can_message_t Can0_Tx_0x302 =
{
    .cs = 0,
    .id = 0x302,
    .data = {0,0,0,0,0,0,0,0},
    .length = 8
};

can_message_t Can0_Tx_0x303 =
{
    .cs = 0,
    .id = 0x303,
    .data = {0,0,0,0,0,0,0,0},
    .length = 8
};

can_message_t Can0_Tx_0x304 =
{
    .cs = 0,
    .id = 0x304,
    .data = {0,0,0,0,0,0,0,0},
    .length = 8
};

can_message_t Can0_Tx_0x305 =
{
    .cs = 0,
    .id = 0x305,
    .data = {0,0,0,0,0,0,0,0},
    .length = 8
};

void Can0_RxCallback(uint32_t instance,
					 can_event_t eventType,
					 uint32_t objIdx,
					 void *driverState)
{
	uint8 index = 0;
	if(CAN_EVENT_RX_COMPLETE == eventType)
	{
		if(0x1814FAF1 == Can0_RxMsg.id)
		{
			for(index = 0; index < ((Can0_RxMsg.length >= 8)?8:Can0_RxMsg.length); index++)
			{
				CanMsg_0x1814FAF1_CompAc.Data[index] = Can0_RxMsg.data[index];
			}
			CAN_Receive(&can_instance0, 0, &Can0_RxMsg);
		}
		else if(0x18FF767D == Can0_RxMsg.id)
		{
			for(index = 0; index < ((Can0_RxMsg.length >= 8)?8:Can0_RxMsg.length); index++)
			{
				CanMsg_0x18FF767D_Ptc2Ac.Data[index] = Can0_RxMsg.data[index];
			}
			CAN_Receive(&can_instance0, 1, &Can0_RxMsg);
		}
		else if(0x201 == Can0_RxMsg.id)
		{
			CanMsg_0x201_VcuAcReq.Data[0] = Can0_RxMsg.data[0];
			CAN_Receive(&can_instance0, 2, &Can0_RxMsg);
		}
	}
}

void CanMsg_Init(void)
{
	CAN_ConfigRxBuff(&can_instance0, 0, &Can0_RxBuff, 0x1814FAF1);
	CAN_ConfigRxBuff(&can_instance0, 1, &Can0_RxBuff, 0x18FF767D);
	CAN_ConfigRxBuff(&can_instance0, 2, &Can0_RxBuff, 0x201);
	CAN_ConfigTxBuff(&can_instance0, 3, &Can0_TxExtBuff);
	CAN_ConfigTxBuff(&can_instance0, 4, &Can0_TxExtBuff);
	CAN_ConfigTxBuff(&can_instance0, 5, &Can0_TxStdBuff);
	CAN_ConfigTxBuff(&can_instance0, 6, &Can0_TxStdBuff);
	CAN_ConfigTxBuff(&can_instance0, 7, &Can0_TxStdBuff);
	CAN_ConfigTxBuff(&can_instance0, 8, &Can0_TxStdBuff);
	CAN_ConfigTxBuff(&can_instance0, 9, &Can0_TxStdBuff);
	CAN_InstallEventCallback(&can_instance0, Can0_RxCallback, NULL_PTR);
	CAN_Receive(&can_instance0, 0, &Can0_RxMsg);
	CAN_Receive(&can_instance0, 1, &Can0_RxMsg);
	CAN_Receive(&can_instance0, 2, &Can0_RxMsg);
}

void CanMsg_Main(void)
{
    uint8 index = 0;

    for(index = 0; index < 8; index++)
    {
    	Can0_Tx_0x18220145_AcComp.data[index] = CanMsg_0x18220145_AcComp.Data[index];
    }
    while(STATUS_BUSY == CAN_GetTransferStatus(&can_instance0, 3));
    CAN_Send(&can_instance0, 3, &Can0_Tx_0x18220145_AcComp);

	for(index = 0; index < 8; index++)
	{
		Can0_Tx_0x18FF7419_Ac2Ptc.data[index] = CanMsg_0x18FF7419_Ac2Ptc.Data[index];
	}
	while(STATUS_BUSY == CAN_GetTransferStatus(&can_instance0, 4));
	CAN_Send(&can_instance0, 4, &Can0_Tx_0x18FF7419_Ac2Ptc);

    for(index = 0; index < 8; index++)
    {
    	Can0_Tx_0x301.data[index] = CanMsg_0x301.Data[index];
    }
    while(STATUS_BUSY == CAN_GetTransferStatus(&can_instance0, 5));
    CAN_Send(&can_instance0, 5, &Can0_Tx_0x301);

	CanSig_SetTemperInner(Temper_GetInner());
	//CanSig_SetTemperBattWter(Temper_GetBattWater());
	CanSig_SetTemperBattWter(Temper_GetBattWaterIn());
	CanSig_SetTemperEvap(Temper_GetEvaporator());
	CanSig_SetTemperExternal(Temper_GetExternal());
	CanSig_SetTemperMotorWater1(Temper_GetMotorWater(TEMPER_MOTORWATER_IDX1));
	CanSig_SetTemperMotorWater2(Temper_GetMotorWater(TEMPER_MOTORWATER_IDX2));
	CanSig_SetTemperMotorWater3(Temper_GetMotorWater(TEMPER_MOTORWATER_IDX3));
	CanSig_SetTemperWarmAir(-400/*Temper_GetWarmAir()*/);
	for(index = 0; index < 8; index++)
	{
		Can0_Tx_0x302.data[index] = CanMsg_0x302.Data[index];
	}
    while(STATUS_BUSY == CAN_GetTransferStatus(&can_instance0, 6));
    CAN_Send(&can_instance0, 6, &Can0_Tx_0x302);

    CanSig_SetTemperHeatPump1(Temper_GetHeatPump(TEMPER_HEATPUMP_IDX1));
    CanSig_SetTemperHeatPump2(Temper_GetHeatPump(TEMPER_HEATPUMP_IDX2));
    CanSig_SetTemperHydpressOil1(-400/*Temper_GetHydPressOil(TEMPER_HYDPRESSOIL_IDX1)*/);
    CanSig_SetTemperHydpressOil2(Temper_GetBattWaterOut()/*Temper_GetHydPressOil(TEMPER_HYDPRESSOIL_IDX2)*/);
    CanSig_SetLiquidLevelAirCond(LiquidLevel_IsEmpty(LIQUIDLEVEL_DEV_AIRCOND));
	CanSig_SetLiquidLevelBatt(LiquidLevel_IsEmpty(LIQUIDLEVEL_DEV_BATT));
	CanSig_SetLiquidLevelMotor(LiquidLevel_IsEmpty(LIQUIDLEVEL_DEV_MOTOR));
    for(index = 0; index < 8; index++)
    {
    	Can0_Tx_0x303.data[index] = CanMsg_0x303.Data[index];
    }
    while(STATUS_BUSY == CAN_GetTransferStatus(&can_instance0, 7));
    CAN_Send(&can_instance0, 7, &Can0_Tx_0x303);

    for(index = 0; index < 8; index++)
    {
    	Can0_Tx_0x304.data[index] = CanMsg_0x304.Data[index];
    }
    while(STATUS_BUSY == CAN_GetTransferStatus(&can_instance0, 8));
    CAN_Send(&can_instance0, 8, &Can0_Tx_0x304);

	CanSig_SetPressHeatPump1(Press_GetDeviceKPa(PRESS_DEV_HEATPUMP1));
	CanSig_SetPressHeatPump2(Press_GetDeviceKPa(PRESS_DEV_HEATPUMP2));
	CanSig_SetPressAirCond(Press_GetDeviceKPa(PRESS_DEV_AIRCOND));
    for(index = 0; index < 8; index++)
    {
    	Can0_Tx_0x305.data[index] = CanMsg_0x305.Data[index];
    }
    while(STATUS_BUSY == CAN_GetTransferStatus(&can_instance0, 9));
    CAN_Send(&can_instance0, 9, &Can0_Tx_0x305);
}
/*------------------------------ TX SIGNAL API DEFINITION ------------------------------*/
/* Init:0    Resolution:1    Offset:0    Unit:rpm    Min:0    Max:0xFFFE    PhyMin:0    PhyMax:65534 */
void CanSig_SetCompTargetSpeed(uint16 sigValue)
{
	CanMsg_0x18220145_AcComp.Sig.TargetSpeed = sigValue;
}

/* Init:0    Resolution:0.1    Offset:0    Unit:kw    Min:0    Max:0xFE    PhyMin:0    PhyMax:25.4 */
void CanSig_SetCompMaxPower(uint8 sigValue)
{
	CanMsg_0x18220145_AcComp.Sig.MaxPower = sigValue;
}

/* Init:0    Resolution:1    Offset:0    Unit:    Min:0    Max:0xFE    PhyMin:0    PhyMax:255 */
/* ValueList: 0x00: CompOff    0x01:CompOn*/
void CanSig_SetCompEnable(uint8 sigValue)
{
	CanMsg_0x18220145_AcComp.Sig.Enable = sigValue;
}

/* Init:0    Resolution:1    Offset:0    Unit:rpm    Min:0    Max:0xFFFE    PhyMin:0    PhyMax:65534 */
uint16 CanSig_GetCompTargetSpeed(void)
{
    return CanMsg_0x18220145_AcComp.Sig.TargetSpeed;
}

/* Init:0    Resolution:0.1    Offset:0    Unit:kw    Min:0    Max:0xFE    PhyMin:0    PhyMax:25.4 */
uint8 CanSig_GetCompMaxPower(void)
{
    return CanMsg_0x18220145_AcComp.Sig.MaxPower;
}

/* Init:0    Resolution:1    Offset:0    Unit:    Min:0    Max:0xFF    PhyMin:0    PhyMax:255 */
/* ValueList: 0x00: CompOff    0x01:CompOn*/
uint8 CanSig_GetCompEnable(void)
{
    return CanMsg_0x18220145_AcComp.Sig.Enable;
}

//0x18FF7419

/* Init:0    Resolution:1    Offset:0    Unit:    Min:0    Max:3    PhyMin:0    PhyMax:3 */
/* ValueList: 0x00: Reserve    0x01:Stop    0x01:Start    0x03:Invalid Value*/
uint8 CanSig_GetPtcStartStop(void)
{
    return CanMsg_0x18FF7419_Ac2Ptc.Sig.StartStop;
}
void CanSig_SetPtcStartStop(uint8 sigValue)
{
	CanMsg_0x18FF7419_Ac2Ptc.Sig.StartStop = sigValue;
}
/* Init:0    Resolution:1    Offset:0    Unit:%    Min:0    Max:255    PhyMin:0    PhyMax:255 */
uint8 CanSig_GetPtcPowerPercentage(void)
{
    return CanMsg_0x18FF7419_Ac2Ptc.Sig.SetPowerPercentage;
}
void CanSig_SetPtcPowerPercentage(uint8 sigValue)
{
	CanMsg_0x18FF7419_Ac2Ptc.Sig.SetPowerPercentage = sigValue;
}
/* Init:0    Resolution:0.1    Offset:0    Unit:KW    Min:0    Max:255    PhyMin:0    PhyMax:25.5 */
float32 CanSig_GetPtcMaxPower(void)
{
    return (CanMsg_0x18FF7419_Ac2Ptc.Sig.SetMaxPower * 0.1);
}
void CanSig_SetPtcMaxPower(float sigValue)
{
	CanMsg_0x18FF7419_Ac2Ptc.Sig.SetMaxPower = (uint8)(sigValue * 10);
}

//0x301
void CanSig_SetCondenserSpeed1(uint16 fanSpeedRpm)
{
	CanMsg_0x301.Sig.fanSpeed1 = fanSpeedRpm;
}
void CanSig_SetCondenserSpeed2(uint16 fanSpeedRpm)
{
	CanMsg_0x301.Sig.fanSpeed2 = fanSpeedRpm;
}
void CanSig_SetCondenserSpeed3(uint16 fanSpeedRpm)
{
	CanMsg_0x301.Sig.fanSpeed3 = fanSpeedRpm;
}
void CanSig_SetCondenserSpeed4(uint16 fanSpeedRpm)
{
	CanMsg_0x301.Sig.fanSpeed4 = fanSpeedRpm;
}
//0x302
void CanSig_SetTemperInner(sint16 tempx10)
{
	uint8 temp = tempx10/10 + 40;

	CanMsg_0x302.Sig.temperInner = temp;
}

void CanSig_SetTemperBattWter(sint16 tempx10)
{
	uint8 temp = tempx10/10 + 40;

	CanMsg_0x302.Sig.temperBattWater = temp;
}

void CanSig_SetTemperEvap(sint16 tempx10)
{
	uint8 temp = tempx10/10 + 40;

	CanMsg_0x302.Sig.temperEvaporator = temp;
}

void CanSig_SetTemperExternal(sint16 tempx10)
{
	uint8 temp = tempx10/10 + 40;

	CanMsg_0x302.Sig.temperExternal = temp;
}

void CanSig_SetTemperMotorWater1(sint16 tempx10)
{
	uint8 temp = tempx10/10 + 40;

	CanMsg_0x302.Sig.temperMotorWater1 = temp;
}

void CanSig_SetTemperMotorWater2(sint16 tempx10)
{
	uint8 temp = tempx10/10 + 40;

	CanMsg_0x302.Sig.temperMotorWater2 = temp;
}

void CanSig_SetTemperMotorWater3(sint16 tempx10)
{
	uint8 temp = tempx10/10 + 40;

	CanMsg_0x302.Sig.temperMotorWater3 = temp;
}

void CanSig_SetTemperWarmAir(sint16 tempx10)
{
	uint8 temp = tempx10/10 + 40;

	CanMsg_0x302.Sig.temperWarmAir = temp;
}

//0x303
void CanSig_SetTemperHeatPump1(sint16 tempx10)
{
	uint8 temp = tempx10/10 + 40;

	CanMsg_0x303.Sig.temperHeatPump1 = temp;
}
void CanSig_SetTemperHeatPump2(sint16 tempx10)
{
    uint8 temp = tempx10/10 + 40;

    CanMsg_0x303.Sig.temperHeatPump2 = temp;
}
void CanSig_SetTemperHydpressOil1(sint16 tempx10)
{
    uint8 temp = tempx10/10 + 40;

    CanMsg_0x303.Sig.temperHydpressOil1 = temp;
}
void CanSig_SetTemperHydpressOil2(sint16 tempx10)
{
    uint8 temp = tempx10/10 + 40;

    CanMsg_0x303.Sig.temperHydpressOil2 = temp;
}
void CanSig_SetExvBattPos (uint16 exvPos)
{
    CanMsg_0x303.Sig.exvBattPos = exvPos;
}
void CanSig_SetExvHeatPumpPos(uint16 exvPos)
{
    CanMsg_0x303.Sig.exvHeatPumpPos = exvPos;
}
void CanSig_SetLiquidLevelAirCond(boolean isEmpty)
{
    CanMsg_0x303.Sig.liquidLevelAirCond = isEmpty;
}
void CanSig_SetLiquidLevelBatt(boolean isEmpty)
{
    CanMsg_0x303.Sig.liquidLevelBatt = isEmpty;
}
void CanSig_SetLiquidLevelMotor(boolean isEmpty)
{
    CanMsg_0x303.Sig.liquidLevelMotor = isEmpty;
}
void CanSig_SetValveAc(boolean onOff)
{
    CanMsg_0x303.Sig.ValveAc = onOff;
}
void CanSig_SetValveHot(boolean onOff)
{
    CanMsg_0x303.Sig.ValveHot = onOff;
}
void CanSig_SetValveCutOff(boolean onOff)
{
    CanMsg_0x303.Sig.ValveCutOff = onOff;
}
void CanSig_SetValveBattWater1(uint8 pos)
{
    CanMsg_0x303.Sig.ValveBattWater1 = pos;
}
void CanSig_SetValveBattWater2(uint8 pos)
{
    CanMsg_0x303.Sig.ValveBattWater2 = pos;
}

//0x304
void CanSig_SetPumpSpeedAirCond(uint16 pumpSpeedRpm)
{
    CanMsg_0x304.Sig.pumpSpeedAirCond = pumpSpeedRpm;
}
void CanSig_SetPumpSpeedBattery(uint16 pumpSpeedRpm)
{
    CanMsg_0x304.Sig.pumpSpeedBattery = pumpSpeedRpm;
}
void CanSig_SetPumpSpeedMotor(uint16 pumpSpeedRpm)
{
    CanMsg_0x304.Sig.pumpSpeedMotor = pumpSpeedRpm;
}
void CanSig_SetSystemCurMode(uint8 mode)
{
    CanMsg_0x304.Sig.systemCurMode = mode;
}
void CanSig_SetSystemPreMode(uint8 mode)
{
    CanMsg_0x304.Sig.systemPreMode = mode;
}
void CanSig_SetStateMachineEvent(uint8 event)
{
    CanMsg_0x304.Sig.stateMachineEvent = event;
}

//0x305
void CanSig_SetBlowerSpeed(uint16 speedRpm)
{
    CanMsg_0x305.Sig.blower = speedRpm;
}
void CanSig_SetPressHeatPump1(uint16 pressKpa)
{
    CanMsg_0x305.Sig.pressheatPump1 = pressKpa;
}
void CanSig_SetPressHeatPump2(uint16 pressKpa)
{
    CanMsg_0x305.Sig.pressheatPump2 = pressKpa;
}
void CanSig_SetPressAirCond(uint16 pressKpa)
{
    CanMsg_0x305.Sig.pressAirCond = pressKpa;
}
/*------------------------------ RX SIGNAL API DEFINITION ------------------------------*/
/* Init:0    Resolution:1    Offset:0    Unit:rpm    Min:0    Max:0xFFFE    PhyMin:0    PhyMax:66534 */
uint16 CanSig_GetCompRealSpeed(void)
{
    return CanMsg_0x1814FAF1_CompAc.Sig.RealSpeed;
}

/* Init:0    Resolution:1    Offset:-40    Unit:¡ãC    Min:0    Max:160    PhyMin:-40    PhyMax:120 */
sint16 CanSig_GetCompTemperature(void)
{
	return (sint16)(CanMsg_0x1814FAF1_CompAc.Sig.Temperature - 40);
}

/* Init:0    Resolution:1    Offset:0    Unit:    Min:0    Max:0x03    PhyMin:0    PhyMax:3 */
/* ValueList: 0x00: CompOff    0x01:CompOn    0x02:CompError */
uint8 CanSig_GetCompStatus(void)
{
    return CanMsg_0x1814FAF1_CompAc.Sig.Status;
}

/* Init:0    Resolution:1    Offset:0    Unit:    Min:0    Max:0xFF    PhyMin:0    PhyMax:255 */
/* ValueList: 0x00: NoErr    0x01:OverCurrent    0x02:OverVoltage    0x04:UnderVolt    0x08:StandbyOverVolt
 *            0x10:StandbyUnderVolt    0x20:ComErr    0x40:OverCurrentDropFreq    0x80:OverPowerDropFreq */
uint8 CanSig_GetCompErrCode(void)
{
    return CanMsg_0x1814FAF1_CompAc.Sig.ErrCode;
}

/* Init:0    Resolution:0.2    Offset:0    Unit:A    Min:0    Max:0xFF    PhyMin:0    PhyMax:51 */
float32 CanSig_GetCompPhaseCurrent(void)
{
    return (CanMsg_0x1814FAF1_CompAc.Sig.PhaseCurrent * 0.2);
}

/* Init:0    Resolution:0.1    Offset:0    Unit:A    Min:0    Max:0xFE    PhyMin:0    PhyMax:25.4 */
float32 CanSig_GetCompWorkingCurrent(void)
{
    return (CanMsg_0x1814FAF1_CompAc.Sig.WorkingCurrent * 0.1);
}

/* Init:0    Resolution:4    Offset:0    Unit:V    Min:0    Max:0xFE    PhyMin:0    PhyMax:1016 */
uint16 CanSig_GetCompDCVolt(void)
{
    return (CanMsg_0x1814FAF1_CompAc.Sig.DCVolt * 4);
}


/* Init:0    Resolution:1    Offset:0    Unit:-    Min:0    Max:3    PhyMin:0    PhyMax:3 */
uint8 CanSig_GetVcuReq(void)
{
    return CanMsg_0x201_VcuAcReq.Sig.VcuReq;
}

/* Init:0    Resolution:1    Offset:0    Unit:-    Min:0    Max:3    PhyMin:0    PhyMax:3 */
uint8 CanSig_GetAcReq(void)
{
    return CanMsg_0x201_VcuAcReq.Sig.AcReq;
}

/* Init:0    Resolution:1    Offset:0    Unit:-    Min:0    Max:3    PhyMin:0    PhyMax:3 */
/* ValueList: 0x00: Stopped    0x01:Running    0x02:Fault    0x03:InvalidValue */
uint8 CanSig_GetPtcStauts(void)
{
    return CanMsg_0x18FF767D_Ptc2Ac.Sig.PtcStatus;
}

/* Init:0    Resolution:1    Offset:0    Unit:-    Min:0    Max:3    PhyMin:0    PhyMax:3 */
/* ValueList: 0x00: No Fault    0x01:IGBT Short    0x02:IGBT Open    0x03:Invalid Value */
uint8 CanSig_GetPtcIgbtFault(void)
{
	return CanMsg_0x18FF767D_Ptc2Ac.Sig.IgbtFault;
}

/* Init:0    Resolution:0.1    Offset:0    Unit:A    Min:0    Max:255    PhyMin:0    PhyMax:25.5 */
float32 CanSig_GetPtcWorkingCurrent(void)
{
	return (CanMsg_0x18FF767D_Ptc2Ac.Sig.WorkingCurrent * 0.1);
}

/* Init:0    Resolution:0.1    Offset:0    Unit:V    Min:0    Max:9999    PhyMin:0    PhyMax:999.9 */
float32 CanSig_GetPtcWorkingVolt(void)
{
	return (CanMsg_0x18FF767D_Ptc2Ac.Sig.WorkingVolt * 0.1);
}

/* Init:0    Resolution:1    Offset:0    Unit:%    Min:0    Max:255    PhyMin:0    PhyMax:255 */
uint8 CanSig_GetPtcWorkingPowerPercentage(void)
{
	return CanMsg_0x18FF767D_Ptc2Ac.Sig.WorkingPowerPercentage;
}

/* Init:0    Resolution:0.1    Offset:0    Unit:KW    Min:0    Max:255    PhyMin:0    PhyMax:25.5 */
float32 CanSig_GetPtcConsumptionPower(void)
{
	return (CanMsg_0x18FF767D_Ptc2Ac.Sig.ConsumptionPower * 0.1);
}

/* Init:0    Resolution:1    Offset:-40    Unit:¡ãC    Min:0    Max:255    PhyMin:0    PhyMax:215 */
sint16 CanSig_GetPtcTemperature(void)
{
	return (CanMsg_0x18FF767D_Ptc2Ac.Sig.Temperature - 40);
}

/*============================= END OF FILE: CanMsg.c ============================*/
