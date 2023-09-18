/**
* @file:    Task_Cyclic.c
* @brief:   Add your description here for this file.
* @author:  None
* @date:    2023-03-21 21:27:40
*
* @copyright None
* @warning   All rights reserved.
*
* @par Version History
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  None  2023-03-21 21:27:40  First Create
When you update, please do not forgot to delete me and add your info at here.
</pre>
*/
#include "Task_Cyclic.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
/* OS Kernel includes */
#include "queue.h"

#include "CanMsg.h"
#include "EXV.h"
#include "AdcPal.h"
#include "Valve.h"
#include "PowerCtr.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
/* Variable to store the software timer handle */
extern TimerHandle_t TimerHandle_Cyc5ms;
extern TimerHandle_t TimerHandle_Cyc10ms;
extern TimerHandle_t TimerHandle_Cyc20ms;
extern TimerHandle_t TimerHandle_Cyc50ms;
extern TimerHandle_t TimerHandle_Cyc100ms;
/* Variable to store the Queue handle when we create the queue */
extern QueueHandle_t QueueHandle_Timer5ms;
extern QueueHandle_t QueueHandle_Timer10ms;
extern QueueHandle_t QueueHandle_Timer20ms;
extern QueueHandle_t QueueHandle_Timer50ms;
extern QueueHandle_t QueueHandle_Timer100ms;

extern QueueHandle_t QueueHandle_Ign;

/* This is not a real task, but a software timer callback which implemented by the scheduler */
void Task_Cyclic(TimerHandle_t pxTimer)
{
	uint32 Timer_ValueGap = 0u;

	static uint8 lowVoltCounter = 0u;
	static uint8 highVoltCounter = 0u;
	uint16 battVoltMv = 0u;
	uint16 ignVoltMv = 0u;
	uint32 ignEvent = 0u;
	static uint32 preIgnEvent = 0xffffffff;

	if(pxTimer == TimerHandle_Cyc5ms)
	{
		EXV_ProcessPulse();
		EXV_Main();
		/* Send the event to other task if needed */
		Timer_ValueGap = 5u;
		xQueueSend(QueueHandle_Timer5ms, &Timer_ValueGap, 0);
	}
	else if(pxTimer == TimerHandle_Cyc10ms)
	{
		battVoltMv = PowerCtr_GetBattVoltMv();
		ignVoltMv = PowerCtr_GetIgnVoltMv();
		//if((battVoltMv < 10000)||(ignVoltMv < 10000))
		if(ignVoltMv < 10000)
		{
			highVoltCounter = 0;
			lowVoltCounter++;
			if(lowVoltCounter > 2)
			{
				lowVoltCounter = 2;
				ignEvent = 0;
				if(preIgnEvent != ignEvent)
				{
					preIgnEvent = ignEvent;
					xQueueSend(QueueHandle_Ign, &ignEvent, 0);
				}
			}
		}
		else
		{
			lowVoltCounter = 0;
			highVoltCounter++;
			if(highVoltCounter > 2)
			{
				highVoltCounter = 2;
				ignEvent = 1;
				if(preIgnEvent != ignEvent)
				{
					preIgnEvent = ignEvent;
					xQueueSend(QueueHandle_Ign, &ignEvent, 0);
				}
			}
		}
		AdcPal_Main();
		Valve_BattTripleWater_Main();
		/* Send the event to other task if needed */
		Timer_ValueGap = 10u;
		xQueueSend(QueueHandle_Timer10ms, &Timer_ValueGap, 0);
	}
	else if(pxTimer == TimerHandle_Cyc20ms)
	{
		/* Send the event to other task if needed */
		Timer_ValueGap = 20u;
		xQueueSend(QueueHandle_Timer20ms, &Timer_ValueGap, 0);
	}
	else if(pxTimer == TimerHandle_Cyc50ms)
	{
		/* Send the event to other task if needed */
		Timer_ValueGap = 50u;
		xQueueSend(QueueHandle_Timer50ms, &Timer_ValueGap, 0);
	}
	else if(pxTimer == TimerHandle_Cyc100ms)
	{
		CanMsg_Main();
		/* Send the event to other task if needed */
		Timer_ValueGap = 100u;
		xQueueSend(QueueHandle_Timer100ms, &Timer_ValueGap, 0);
	}
}

/*============================= END OF FILE: Task_Cyclic.c ============================*/
