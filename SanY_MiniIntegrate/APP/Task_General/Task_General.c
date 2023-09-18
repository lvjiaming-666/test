/*!Warning!:Please don't modify this file,this is generated by tools!*/
/********************************************************************
File name: Task_General.c
Author: None
Version: V1.0
Timestamp: 2022-09-03 11:39:40
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
#include "Task_General_Cfg.h"

/*----------------------------- START: USER INCLUDED ----------------------------*/
/* OS Kernel includes */
#include "FreeRTOS.h"
#include "queue.h"
#include "pwm_pal.h"
#include "peripherals_pwm_pal_1.h"
#include "peripherals_pwm_pal_2.h"
#include "pins_driver.h"
#include "System_Portable.h"
#include "EXV.h"
#include "AdcPal.h"
#include "Pump.h"
#include "Valve.h"
#include "Fan.h"
/*------------------------------ END: USER INCLUDE ------------------------------*/
extern QueueHandle_t QueueHandle_Timer20ms;

void Task_General(void * pvParameters)
{
	static QueueSetHandle_t xQueueSet;
	QueueSetMemberHandle_t xActivateMember;
	uint32 xReceivedFromQueue;

	/***************************** START: VARIABLE DEFINE ****************************/


	/****************************** END: VARIABLE DEFINE *****************************/
	(void) pvParameters;

	/* Create the queue set large enough to hold an event for every space in every queue
	 * and semaphore that is to be added to the set. */
	xQueueSet = xQueueCreateSet(1);
	/* Add the queues or semaphores to the set. Reading from these queues can only be performed
	 * after a call to xQueueSelectFromSet() has returned the queue. You can't add too many elements.
	 * The number of elements is limited when creating a list. */
	xQueueAddToSet(QueueHandle_Timer20ms, xQueueSet);
    float duty = 0.5;
    int r_duty;
	r_duty = 50000 * duty;

	/********************* START: SOMETHING ONLY NEED EXEC ONCE **********************/
	PWM_UpdateDuty(&pwm_pal_1_instance, 5, r_duty);
	PWM_UpdateDuty(&pwm_pal_1_instance, 4, r_duty);
	PWM_UpdateDuty(&pwm_pal_1_instance, 3, r_duty);
	PWM_UpdateDuty(&pwm_pal_1_instance, 6, r_duty);

//	Fan_CtrCondenser(FAN_CONDENSER_IDX_1,4750);
//	Fan_CtrCondenser(FAN_CONDENSER_IDX_2,4750);
//	Fan_CtrCondenser(FAN_CONDENSER_IDX_3,4750);
	/********************** END: SOMETHING ONLY NEED EXEC ONCE ***********************/

	for(;;)
	{
		/* Block to wait for something to be available from the queues that have been added to the set. */
		xActivateMember = xQueueSelectFromSet(xQueueSet, portMAX_DELAY);
		xQueueReceive(xActivateMember, &xReceivedFromQueue, 0);
		/* Which set member was selected? Receives/takes can use a block time of zero
		 * as they are guaranteed to pass because xQueueSelectFromSet() would not have returned
		 * the handle unless something has available. */
		if(xActivateMember == QueueHandle_Timer20ms)
		{

		}

	}
}
/*=========================== END OF FILE: Task_General.c ===========================*/
