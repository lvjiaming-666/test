/**
* @file:    CanMsg.h
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
#ifndef _CANMSG_H_
#define _CANMSG_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "Std_Types.h"
#include "CanMsg_Cfg.h"
/*----------------------------- START: USER INCLUDED ----------------------------*/

/*------------------------------ END: USER INCLUDE ------------------------------*/
/* Type define for RX Message */
typedef union
{
    uint8 Data[8];
    struct
    {
        uint16 RealSpeed;
        uint8 Temperature;
        uint8 Status;
        uint8 ErrCode;
        uint8 PhaseCurrent;
        uint8 WorkingCurrent;
        uint8 DCVolt;
    } Sig;
}CanMsg_0x1814FAF1_CompAcType;

typedef union
{
    uint8 Data[8];
    struct
    {
        uint8 PtcStatus : 2;
        uint8 IgbtFault : 2;
        uint8 Reserve0 : 4;
        uint8 WorkingCurrent;
        uint16 WorkingVolt;
        uint8 WorkingPowerPercentage;
        uint8 ConsumptionPower;
        uint8 Temperature;
        uint8 Reserve1;
    } Sig;
}CanMsg_0x18FF767D_Ptc2AcType;

typedef union
{
    uint8 Data[8];
    struct
    {
        uint8 VcuReq : 2;
        uint8 AcReq  : 2;
        uint8 Reserve7 : 4;
        uint8 Reserve0;
        uint8 Reserve1;
        uint8 Reserve2;
        uint8 Reserve3;
        uint8 Reserve4;
        uint8 Reserve5;
        uint8 Reserve6;
    } Sig;
}CanMsg_0x201_VcuAcReqType;

/* Type define for TX Message */
typedef union
{
    uint8 Data[8];
    struct
    {
        uint16 TargetSpeed;
        uint8 MaxPower;
        uint8 Enable;
        uint8 Reserve0;
        uint8 Reserve1;
        uint8 Reserve2;
        uint8 Reserve3;
    } Sig;
}CanMsg_0x18220145_AcCompType;

typedef union
{
    uint8 Data[8];
    struct
    {
        uint8 StartStop : 2;
        uint8 Reserve0 : 6;
        uint8 SetPowerPercentage;
        uint8 SetMaxPower;
        uint8 Reserve1;
        uint8 Reserve2;
        uint8 Reserve3;
        uint8 Reserve4;
        uint8 Reserve5;
    } Sig;
}CanMsg_0x18FF7419_Ac2PtcType;

typedef union
{
    uint8 Data[8];
    struct
    {
        uint16 fanSpeed1;
        uint16 fanSpeed2;
        uint16 fanSpeed3;
        uint16 fanSpeed4;
    } Sig;
}CanMsg_0x301Type;

typedef union
{
    uint8 Data[8];
    struct
    {
        uint8 temperInner;
        uint8 temperExternal;
        uint8 temperBattWater;
        uint8 temperWarmAir;
        uint8 temperEvaporator;
        uint8 temperMotorWater1;
        uint8 temperMotorWater2;
        uint8 temperMotorWater3;
    } Sig;
}CanMsg_0x302Type;

typedef union
{
    uint8 Data[8];
    struct
    {
        uint8 temperHeatPump1;
        uint8 temperHeatPump2;
        uint8 temperHydpressOil1;
        uint8 temperHydpressOil2;
        uint16 exvBattPos : 9;
        uint16 liquidLevelAirCond : 1;
        uint16 liquidLevelBatt : 1;
        uint16 liquidLevelMotor : 1;
        uint16 Reserve : 4;
        uint16 exvHeatPumpPos : 9;
        uint16 ValveBattWater1 : 2;
        uint16 ValveBattWater2 : 2;
        uint16 ValveAc : 1;
        uint16 ValveHot : 1;
        uint16 ValveCutOff : 1;
    } Sig;
}CanMsg_0x303Type;

typedef union
{
    uint8 Data[8];
    struct
    {
        uint32 pumpSpeedAirCond : 12;
        uint32 pumpSpeedBattery : 12;
        uint32 systemCurMode : 4;
        uint32 systemPreMode : 4;
        uint16 pumpSpeedMotor : 12;
        uint16 stateMachineEvent : 4;
        uint16 Reserve1;
    } Sig;
}CanMsg_0x304Type;

typedef union
{
    uint8 Data[8];
    struct
    {
        uint16 pressAirCond;
        uint16 pressheatPump1;
        uint16 pressheatPump2;
        uint16 blower;
    } Sig;
}CanMsg_0x305Type;

extern void CanMsg_Init(void);
extern void CanMsg_Main(void);

/*------------------------------ TX SIGNAL API DEFINITION ------------------------------*/
//0x18220145
/* Init:0    Resolution:1    Offset:0    Unit:rpm    Min:0    Max:0xFFFE    PhyMin:0    PhyMax:65534 */
extern void CanSig_SetCompTargetSpeed(uint16 sigValue);
/* Init:0    Resolution:0.1    Offset:0    Unit:kw    Min:0    Max:0xFE    PhyMin:0    PhyMax:25.4 */
extern void CanSig_SetCompMaxPower(uint8 sigValue);
/* Init:0    Resolution:1    Offset:0    Unit:    Min:0    Max:0xFE    PhyMin:0    PhyMax:255 */
/* ValueList: 0x00: CompOff    0x01:CompOn*/
extern void CanSig_SetCompEnable(uint8 sigValue);
/* Init:0    Resolution:1    Offset:0    Unit:rpm    Min:0    Max:0xFFFE    PhyMin:0    PhyMax:65534 */
extern uint16 CanSig_GetCompTargetSpeed(void);
/* Init:0    Resolution:0.1    Offset:0    Unit:kw    Min:0    Max:0xFE    PhyMin:0    PhyMax:25.4 */
extern uint8 CanSig_GetCompMaxPower(void);
/* Init:0    Resolution:1    Offset:0    Unit:    Min:0    Max:0xFF    PhyMin:0    PhyMax:255 */
/* ValueList: 0x00: CompOff    0x01:CompOn*/
extern uint8 CanSig_GetCompEnable(void);
//0x18FF7419
/* Init:0    Resolution:1    Offset:0    Unit:    Min:0    Max:3    PhyMin:0    PhyMax:3 */
/* ValueList: 0x00: Reserve    0x01:Stop    0x01:Start    0x03:Invalid Value*/
extern uint8 CanSig_GetPtcStartStop(void);
extern void CanSig_SetPtcStartStop(uint8 sigValue);
/* Init:0    Resolution:1    Offset:0    Unit:%    Min:0    Max:255    PhyMin:0    PhyMax:255 */
extern uint8 CanSig_GetPtcPowerPercentage(void);
extern void CanSig_SetPtcPowerPercentage(uint8 sigValue);
/* Init:0    Resolution:0.1    Offset:0    Unit:KW    Min:0    Max:255    PhyMin:0    PhyMax:25.5 */
extern float32 CanSig_GetPtcMaxPower(void);
extern void CanSig_SetPtcMaxPower(float sigValue);

//0x301
extern void CanSig_SetCondenserSpeed1(uint16 fanSpeedRpm);
extern void CanSig_SetCondenserSpeed2(uint16 fanSpeedRpm);
extern void CanSig_SetCondenserSpeed3(uint16 fanSpeedRpm);
extern void CanSig_SetCondenserSpeed4(uint16 fanSpeedRpm);
//0x302
extern void CanSig_SetTemperInner(sint16 tempx10);
extern void CanSig_SetTemperBattWter(sint16 tempx10);
extern void CanSig_SetTemperEvap(sint16 tempx10);
extern void CanSig_SetTemperExternal(sint16 tempx10);
extern void CanSig_SetTemperMotorWater1(sint16 tempx10);
extern void CanSig_SetTemperMotorWater2(sint16 tempx10);
extern void CanSig_SetTemperMotorWater3(sint16 tempx10);
extern void CanSig_SetTemperWarmAir(sint16 tempx10);

//0x303
extern void CanSig_SetTemperHeatPump1(sint16 tempx10);
extern void CanSig_SetTemperHeatPump2(sint16 tempx10);
extern void CanSig_SetTemperHydpressOil1(sint16 tempx10);
extern void CanSig_SetTemperHydpressOil2(sint16 tempx10);
extern void CanSig_SetExvBattPos (uint16 exvPos);
extern void CanSig_SetExvHeatPumpPos(uint16 exvPos);
extern void CanSig_SetLiquidLevelAirCond(boolean isEmpty);
extern void CanSig_SetLiquidLevelBatt(boolean isEmpty);
extern void CanSig_SetLiquidLevelMotor(boolean isEmpty);
extern void CanSig_SetValveAc(boolean onOff);
extern void CanSig_SetValveHot(boolean onOff);
extern void CanSig_SetValveCutOff(boolean onOff);
extern void CanSig_SetValveBattWater1(uint8 pos);
extern void CanSig_SetValveBattWater2(uint8 pos);

//0x304
extern void CanSig_SetPumpSpeedAirCond(uint16 pumpSpeedRpm);
extern void CanSig_SetPumpSpeedBattery(uint16 pumpSpeedRpm);
extern void CanSig_SetPumpSpeedMotor(uint16 pumpSpeedRpm);
extern void CanSig_SetSystemCurMode(uint8 mode);
extern void CanSig_SetSystemPreMode(uint8 mode);
extern void CanSig_SetStateMachineEvent(uint8 event);

//0x305
extern void CanSig_SetBlowerSpeed(uint16 speedRpm);
extern void CanSig_SetPressHeatPump1(uint16 pressKpa);
extern void CanSig_SetPressHeatPump2(uint16 pressKpa);
extern void CanSig_SetPressAirCond(uint16 pressKpa);

/*------------------------------ RX SIGNAL API DEFINITION ------------------------------*/
/* Init:0    Resolution:1    Offset:0    Unit:rpm    Min:0    Max:0xFFFE    PhyMin:0    PhyMax:66534 */
extern uint16 CanSig_GetCompRealSpeed(void);
/* Init:0    Resolution:1    Offset:-40    Unit:°„C    Min:0    Max:160    PhyMin:-40    PhyMax:120 */
extern sint16 CanSig_GetCompTemperature(void);
/* Init:0    Resolution:1    Offset:0    Unit:    Min:0    Max:0x03    PhyMin:0    PhyMax:3 */
/* ValueList: 0x00: CompOff    0x01:CompOn    0x02:CompError */
extern uint8 CanSig_GetCompStatus(void);
/* Init:0    Resolution:1    Offset:0    Unit:    Min:0    Max:0xFF    PhyMin:0    PhyMax:255 */
/* ValueList: 0x00: NoErr    0x01:OverCurrent    0x02:OverVoltage    0x04:UnderVolt    0x08:StandbyOverVolt
 *            0x10:StandbyUnderVolt    0x20:ComErr    0x40:OverCurrentDropFreq    0x80:OverPowerDropFreq */
extern uint8 CanSig_GetCompErrCode(void);
/* Init:0    Resolution:0.2    Offset:0    Unit:A    Min:0    Max:0xFF    PhyMin:0    PhyMax:51 */
extern float32 CanSig_GetCompPhaseCurrent(void);
/* Init:0    Resolution:0.1    Offset:0    Unit:A    Min:0    Max:0xFE    PhyMin:0    PhyMax:25.4 */
extern float32 CanSig_GetCompCurrent(void);
/* Init:0    Resolution:4    Offset:0    Unit:V    Min:0    Max:0xFE    PhyMin:0    PhyMax:1016 */
extern uint16 CanSig_GetCompDCVolt(void);

/* Init:0    Resolution:1    Offset:0    Unit:-    Min:0    Max:3    PhyMin:0    PhyMax:3 */
extern uint8 CanSig_GetVcuReq(void);
/* Init:0    Resolution:1    Offset:0    Unit:-    Min:0    Max:3    PhyMin:0    PhyMax:3 */
extern uint8 CanSig_GetAcReq(void);

/* Init:0    Resolution:1    Offset:0    Unit:-    Min:0    Max:3    PhyMin:0    PhyMax:3 */
/* ValueList: 0x00: Stopped    0x01:Running    0x02:Fault    0x03:Invalid Value */
extern uint8 CanSig_GetPtcStauts(void);
/* Init:0    Resolution:1    Offset:0    Unit:-    Min:0    Max:3    PhyMin:0    PhyMax:3 */
/* ValueList: 0x00: No Fault    0x01:IGBT Short    0x02:IGBT Open    0x03:Invalid Value */
extern uint8 CanSig_GetPtcIgbtFault(void);
/* Init:0    Resolution:0.1    Offset:0    Unit:A    Min:0    Max:255    PhyMin:0    PhyMax:25.5 */
extern float32 CanSig_GetPtcWorkingCurrent(void);
/* Init:0    Resolution:0.1    Offset:0    Unit:V    Min:0    Max:9999    PhyMin:0    PhyMax:999.9 */
extern float32 CanSig_GetPtcWorkingVolt(void);
/* Init:0    Resolution:1    Offset:0    Unit:%    Min:0    Max:255    PhyMin:0    PhyMax:255 */
extern uint8 CanSig_GetPtcWorkingPowerPercentage(void);
/* Init:0    Resolution:0.1    Offset:0    Unit:KW    Min:0    Max:255    PhyMin:0    PhyMax:25.5 */
extern float32 CanSig_GetPtcConsumptionPower(void);
/* Init:0    Resolution:1    Offset:-40    Unit:°„C    Min:0    Max:255    PhyMin:0    PhyMax:215 */
extern sint16 CanSig_GetPtcTemperature(void);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_CANMSG_H_
/*============================= END OF FILE: CanMsg.h ============================*/
