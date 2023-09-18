/********************************************************************
File name: TemperConvert.c
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
#include "Std_Types.h"
#include "BinarySearch.h"
#include "TemperConvert_Cfg.h"

sint16 Temper_Convert_External(uint16 adcValue)
{
    /*
    AdcValue: current adc sample value
    AdcSample: adc max sample precision(10bit=1023  12bit=4095)
    Vref: Adc reference voltage value
    Vp: Temperature sensor circuit pullup voltage
    Rp: Temperature sensor circuit pullup resistance value

    l_resisValue = Vref*Rp*AdcValue/(Vp*AdcSample-Vref*AdcValue)
    */

    uint16 l_Index = 0xFFFF;
    uint16 l_sensorTabSize = sizeof(Temper_ResisTab_External) / sizeof(uint32);
    sint16 l_tempValue = 0;
    const uint32 *l_tabBufPtr = Temper_ResisTab_External;
    uint32 l_resisValue = 0u;

    //according to your circuit, you can optimize this algo.
    l_resisValue = (uint32)(adcValue * TEMPER_RPULL_EXTERNAL) / (TEMPER_ADCSAMPLE_EXTERNAL - adcValue);
    l_Index = BinSearch_Interval_uint32(l_sensorTabSize, l_tabBufPtr, l_resisValue);
    if (l_sensorTabSize == l_Index)
    {
        l_tempValue = TEMPER_MAX_EXTERNAL;
    }
    else if (0 == l_Index)
    {
        l_tempValue = TEMPER_MIN_EXTERNAL;
    }
    else
    {
        l_tempValue = l_Index * TEMPER_GAP_EXTERNAL - ((l_resisValue - l_tabBufPtr[l_Index]) * TEMPER_GAP_EXTERNAL) / (l_tabBufPtr[l_Index - 1] - l_tabBufPtr[l_Index]) + TEMPER_MIN_EXTERNAL;
    }
    return (l_tempValue);
}

sint16 Temper_Convert_BattWater(uint16 adcValue)
{
    /*
    AdcValue: current adc sample value
    AdcSample: adc max sample precision(10bit=1023  12bit=4095)
    Vref: Adc reference voltage value
    Vp: Temperature sensor circuit pullup voltage
    Rp: Temperature sensor circuit pullup resistance value

    l_resisValue = Vref*Rp*AdcValue/(Vp*AdcSample-Vref*AdcValue)
    */

    uint16 l_Index = 0xFFFF;
    uint16 l_sensorTabSize = sizeof(Temper_ResisTab_BattWater) / sizeof(uint32);
    sint16 l_tempValue = 0;
    const uint32 *l_tabBufPtr = Temper_ResisTab_BattWater;
    uint32 l_resisValue = 0u;

    //according to your circuit, you can optimize this algo.
    l_resisValue = (uint32)(adcValue * TEMPER_RPULL_BATTWATER) / (TEMPER_ADCSAMPLE_BATTWATER - adcValue);
    l_Index = BinSearch_Interval_uint32(l_sensorTabSize, l_tabBufPtr, l_resisValue);
    if (l_sensorTabSize == l_Index)
    {
        l_tempValue = TEMPER_MAX_BATTWATER;
    }
    else if (0 == l_Index)
    {
        l_tempValue = TEMPER_MIN_BATTWATER;
    }
    else
    {
        l_tempValue = l_Index * TEMPER_GAP_BATTWATER - ((l_resisValue - l_tabBufPtr[l_Index]) * TEMPER_GAP_BATTWATER) / (l_tabBufPtr[l_Index - 1] - l_tabBufPtr[l_Index]) + TEMPER_MIN_BATTWATER;
    }
    return (l_tempValue);
}

sint16 Temper_Convert_HeatPump(uint16 adcValue)
{
    /*
    AdcValue: current adc sample value
    AdcSample: adc max sample precision(10bit=1023  12bit=4095)
    Vref: Adc reference voltage value
    Vp: Temperature sensor circuit pullup voltage
    Rp: Temperature sensor circuit pullup resistance value

    l_resisValue = Vref*Rp*AdcValue/(Vp*AdcSample-Vref*AdcValue)
    */

    uint16 l_Index = 0xFFFF;
    uint16 l_sensorTabSize = sizeof(Temper_ResisTab_HeatPump) / sizeof(uint32);
    sint16 l_tempValue = 0;
    const uint32 *l_tabBufPtr = Temper_ResisTab_HeatPump;
    uint32 l_resisValue = 0u;

    //according to your circuit, you can optimize this algo.
    l_resisValue = (uint32)(adcValue * TEMPER_RPULL_HEATPUMP) / (TEMPER_ADCSAMPLE_HEATPUMP - adcValue);
    l_Index = BinSearch_Interval_uint32(l_sensorTabSize, l_tabBufPtr, l_resisValue);
    if (l_sensorTabSize == l_Index)
    {
        l_tempValue = TEMPER_MAX_HEATPUMP;
    }
    else if (0 == l_Index)
    {
        l_tempValue = TEMPER_MIN_HEATPUMP;
    }
    else
    {
        l_tempValue = l_Index * TEMPER_GAP_HEATPUMP - ((l_resisValue - l_tabBufPtr[l_Index]) * TEMPER_GAP_HEATPUMP) / (l_tabBufPtr[l_Index - 1] - l_tabBufPtr[l_Index]) + TEMPER_MIN_HEATPUMP;
    }
    return (l_tempValue);
}

sint16 Temper_Convert_Evaporator(uint16 adcValue)
{
    /*
    AdcValue: current adc sample value
    AdcSample: adc max sample precision(10bit=1023  12bit=4095)
    Vref: Adc reference voltage value
    Vp: Temperature sensor circuit pullup voltage
    Rp: Temperature sensor circuit pullup resistance value

    l_resisValue = Vref*Rp*AdcValue/(Vp*AdcSample-Vref*AdcValue)
    */

    uint16 l_Index = 0xFFFF;
    uint16 l_sensorTabSize = sizeof(Temper_ResisTab_Evaporator) / sizeof(uint32);
    sint16 l_tempValue = 0;
    const uint32 *l_tabBufPtr = Temper_ResisTab_Evaporator;
    uint32 l_resisValue = 0u;

    //according to your circuit, you can optimize this algo.
    l_resisValue = (uint32)(adcValue * TEMPER_RPULL_EVAPORATOR) / (TEMPER_ADCSAMPLE_EVAPORATOR - adcValue);
    l_Index = BinSearch_Interval_uint32(l_sensorTabSize, l_tabBufPtr, l_resisValue);
    if (l_sensorTabSize == l_Index)
    {
        l_tempValue = TEMPER_MAX_EVAPORATOR;
    }
    else if (0 == l_Index)
    {
        l_tempValue = TEMPER_MIN_EVAPORATOR;
    }
    else
    {
        l_tempValue = l_Index * TEMPER_GAP_EVAPORATOR - ((l_resisValue - l_tabBufPtr[l_Index]) * TEMPER_GAP_EVAPORATOR) / (l_tabBufPtr[l_Index - 1] - l_tabBufPtr[l_Index]) + TEMPER_MIN_EVAPORATOR;
    }
    return (l_tempValue);
}


sint16 Temper_Convert_MotorWater(uint16 adcValue)
{
    /*
    AdcValue: current adc sample value
    AdcSample: adc max sample precision(10bit=1023  12bit=4095)
    Vref: Adc reference voltage value
    Vp: Temperature sensor circuit pullup voltage
    Rp: Temperature sensor circuit pullup resistance value

    l_resisValue = Vref*Rp*AdcValue/(Vp*AdcSample-Vref*AdcValue)
    */

    uint16 l_Index = 0xFFFF;
    uint16 l_sensorTabSize = sizeof(Temper_ResisTab_MotorWater) / sizeof(uint32);
    sint16 l_tempValue = 0;
    const uint32 *l_tabBufPtr = Temper_ResisTab_MotorWater;
    uint32 l_resisValue = 0u;

    //according to your circuit, you can optimize this algo.
    l_resisValue = (uint32)(adcValue * TEMPER_RPULL_MOTORWATER) / (TEMPER_ADCSAMPLE_MOTORWATER - adcValue);
    l_Index = BinSearch_Interval_uint32(l_sensorTabSize, l_tabBufPtr, l_resisValue);
    if (l_sensorTabSize == l_Index)
    {
        l_tempValue = TEMPER_MAX_MOTORWATER;
    }
    else if (0 == l_Index)
    {
        l_tempValue = TEMPER_MIN_MOTORWATER;
    }
    else
    {
        l_tempValue = l_Index * TEMPER_GAP_MOTORWATER - ((l_resisValue - l_tabBufPtr[l_Index]) * TEMPER_GAP_MOTORWATER) / (l_tabBufPtr[l_Index - 1] - l_tabBufPtr[l_Index]) + TEMPER_MIN_MOTORWATER;
    }
    return (l_tempValue);
}



sint16 Temper_Convert_Inner(uint16 adcValue)
{
    /*
    AdcValue: current adc sample value
    AdcSample: adc max sample precision(10bit=1023  12bit=4095)
    Vref: Adc reference voltage value
    Vp: Temperature sensor circuit pullup voltage
    Rp: Temperature sensor circuit pullup resistance value

    l_resisValue = Vref*Rp*AdcValue/(Vp*AdcSample-Vref*AdcValue)
    */

    uint16 l_Index = 0xFFFF;
    uint16 l_sensorTabSize = sizeof(Temper_ResisTab_Inner) / sizeof(uint32);
    sint16 l_tempValue = 0;
    const uint32 *l_tabBufPtr = (Temper_ResisTab_Inner);
    uint32 l_resisValue = 0u;

    //according to your circuit, you can optimize this algo.
    l_resisValue = (uint32)(adcValue * TEMPER_RPULL_INNER) / (TEMPER_ADCSAMPLE_INNER - adcValue);
    l_Index = BinSearch_Interval_uint32(l_sensorTabSize, l_tabBufPtr, l_resisValue);
    if (l_sensorTabSize == l_Index)
    {
        l_tempValue = TEMPER_MAX_INNER;
    }
    else if (0 == l_Index)
    {
        l_tempValue = TEMPER_MIN_INNER;
    }
    else
    {
        l_tempValue = l_Index * TEMPER_GAP_INNER - ((l_resisValue - l_tabBufPtr[l_Index]) * TEMPER_GAP_INNER) / (l_tabBufPtr[l_Index - 1] - l_tabBufPtr[l_Index]) + TEMPER_MIN_INNER;
    }
    return (l_tempValue);
}

sint16 Temper_Convert_Inner_GaoLi(uint16 adcValue)
{
    /*
    AdcValue: current adc sample value
    AdcSample: adc max sample precision(10bit=1023  12bit=4095)
    Vref: Adc reference voltage value
    Vp: Temperature sensor circuit pullup voltage
    Rp: Temperature sensor circuit pullup resistance value

    l_resisValue = Vref*Rp*AdcValue/(Vp*AdcSample-Vref*AdcValue)
    */

    uint16 l_Index = 0xFFFF;
    uint16 l_sensorTabSize = sizeof(Temper_ResisTab_Inner_GaoLi) / sizeof(uint32);
    sint16 l_tempValue = 0;
    const uint32 *l_tabBufPtr = (Temper_ResisTab_Inner_GaoLi);
    uint32 l_resisValue = 0u;

    //according to your circuit, you can optimize this algo.
    l_resisValue = (uint32)(adcValue * TEMPER_RPULL_INNER_GAOLI) / (TEMPER_ADCSAMPLE_INNER_GAOLI - adcValue);
    l_Index = BinSearch_Interval_uint32(l_sensorTabSize, l_tabBufPtr, l_resisValue);
    if (l_sensorTabSize == l_Index)
    {
        l_tempValue = TEMPER_MAX_INNER_GAOLI;
    }
    else if (0 == l_Index)
    {
        l_tempValue = TEMPER_MIN_INNER_GAOLI;
    }
    else
    {
        l_tempValue = l_Index * TEMPER_GAP_INNER_GAOLI - ((l_resisValue - l_tabBufPtr[l_Index]) * TEMPER_GAP_INNER_GAOLI) / (l_tabBufPtr[l_Index - 1] - l_tabBufPtr[l_Index]) + TEMPER_MIN_INNER_GAOLI;
    }
    return (l_tempValue);
}
/*============================= END OF FILE: TemperConvert.c ============================*/

