/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software. The production use license in
 * Section 2.3 is expressly granted for this software.
 */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "S32K144.h"
#include "PowerCtr.h"
#include "sdk_project_config.h"
#include "interrupt_manager.h"
#include "can_pal.h"
#include "flexcan_irq.h"
#include "adc_pal.h"
#include "EXV.h"
#include "pwm_pal.h"
#include "peripherals_pwm_pal_1.h"
#include "peripherals_pwm_pal_2.h"
#include "Valve.h"
#include "Task_Cyclic.h"
#include "CanMsg.h"
#include "linMaster.h"

extern void Task_Com(void *pvParameters);
extern void Task_General(void *pvParameters);
extern void Task_PowerMode(void *pvParameters);

/* Priorities at which the tasks are created.
 * The larger the value, the higher the priority */
#define TASK_PRIORITY_COM       (tskIDLE_PRIORITY + 4U)
#define TASK_PRIORITY_GENERAL   (tskIDLE_PRIORITY + 1U)
#define TASK_PRIORITY_POWERMODE (tskIDLE_PRIORITY + 2U)
/* Stack size for each created task. */
#define TASK_STACK_SIZE_COM       (256)
#define TASK_STACK_SIZE_GENERAL   (512)
#define TASK_STACK_SIZE_POWERMODE (768)

/* Variable to store the task handle */
TaskHandle_t TaskHandle_Com;
TaskHandle_t TaskHandle_General;
TaskHandle_t TaskHandle_PowerMode;

/* Variable to store the software timer handle */
TimerHandle_t TimerHandle_Cyc5ms = NULL;
TimerHandle_t TimerHandle_Cyc10ms = NULL;
TimerHandle_t TimerHandle_Cyc20ms = NULL;
TimerHandle_t TimerHandle_Cyc50ms = NULL;
TimerHandle_t TimerHandle_Cyc100ms = NULL;

/* Variable to store the Queue handle when we create the queue */
QueueHandle_t QueueHandle_Timer5ms = NULL;
QueueHandle_t QueueHandle_Timer10ms = NULL;
QueueHandle_t QueueHandle_Timer20ms = NULL;
QueueHandle_t QueueHandle_Timer50ms = NULL;
QueueHandle_t QueueHandle_Timer100ms = NULL;

/* Application related event*/
QueueHandle_t QueueHandle_Ign = NULL;
QueueHandle_t QueueHandle_VcuReq = NULL;
QueueHandle_t QueueHandle_AcReq = NULL;

int main(void)
{
	status_t error;

	/* Initialize and configure clocks
	 *  -   Setup system clocks, dividers
	 *  -   see clock manager component for more details
	 */
	error = CLOCK_DRV_Init(&clockMan1_InitConfig0);
	DEV_ASSERT(error == STATUS_SUCCESS);

	error = PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
	DEV_ASSERT(error == STATUS_SUCCESS);

	POWER_SYS_Init(&powerConfigsArr, POWER_MANAGER_CONFIG_CNT, &powerStaticCallbacksConfigsArr, POWER_MANAGER_CALLBACK_CNT);
	INT_SYS_EnableIRQGlobal();
	//Eep_Init();

	PowerCtr_OnOffSensor5V(STD_ON);
	PowerCtr_OnOffPwm24V(STD_ON);
	EXV_Init();

	PWM_Init(&pwm_pal_1_instance, &pwm_pal_1_configs);
	PWM_Init(&pwm_pal_2_instance, &pwm_pal_2_configs);

	LinMaster_Init();
	CAN_Init(&can_instance0, &can_config0);
	PINS_DRV_WritePin(CAN0_SB1_PORT,CAN0_SB1_PIN, STD_LOW);
	INT_SYS_InstallHandler(CAN0_ORed_0_15_MB_IRQn, CAN0_ORed_0_15_MB_IRQHandler, (isr_t*) 0);
	INT_SYS_EnableIRQ(CAN0_ORed_0_15_MB_IRQn);
	INT_SYS_InstallHandler(CAN0_ORed_16_31_MB_IRQn, CAN0_ORed_16_31_MB_IRQHandler, (isr_t*) 0);
	INT_SYS_EnableIRQ(CAN0_ORed_16_31_MB_IRQn);
	CanMsg_Init();
	CAN_Init(&can_instance1,&can_config1);
	PINS_DRV_WritePin(CAN1_SB1_PORT,CAN1_SB1_PIN, STD_ON);

	ADC_Init(&adc_pal_1_instance,&adc_pal_1_config);
	ADC_StartGroupConversion(&adc_pal_1_instance, 0);
	ADC_Init(&adc_pal_2_instance,&adc_pal_2_config);
	ADC_StartGroupConversion(&adc_pal_2_instance, 0);

	Valve_BattTripWater_Init();
	Valve_Hot(STD_OFF);
	Valve_AC(STD_OFF);
	Valve_CutOff(STD_OFF);
	Valve_MotorTriple(0);


	/*while((PowerCtr_GetBattVoltMv() < 10000) && (delayCount < 20000))
	{
		delayCount++;
	}
	if(delayCount >= 20000)
	{
		SystemSoftwareReset();
	}*/


	/* Create the software timer */

	TimerHandle_Cyc5ms = xTimerCreate("Timer_Cyc5ms", pdMS_TO_TICKS(5), pdTRUE, 0, Task_Cyclic);
	if((NULL == TimerHandle_Cyc5ms) || (pdPASS != xTimerStart(TimerHandle_Cyc5ms, 0)))
	{
		/* Error happened, create timer failed or start failed */
		configASSERT(0);
	}
	TimerHandle_Cyc10ms = xTimerCreate("Timer_Cyc10ms", pdMS_TO_TICKS(10), pdTRUE, 0, Task_Cyclic);
	if((NULL == TimerHandle_Cyc10ms) || (pdPASS != xTimerStart(TimerHandle_Cyc10ms, 0)))
	{
		/* Error happened, create timer failed or start failed */
		configASSERT(0);
	}
	TimerHandle_Cyc20ms = xTimerCreate("Timer_Cyc20ms", pdMS_TO_TICKS(20), pdTRUE, 0, Task_Cyclic);
	if((NULL == TimerHandle_Cyc20ms) || (pdPASS != xTimerStart(TimerHandle_Cyc20ms, 0)))
	{
		/* Error happened, create timer failed or start failed */
		configASSERT(0);
	}
	TimerHandle_Cyc50ms = xTimerCreate("Timer_Cyc50ms", pdMS_TO_TICKS(50), pdTRUE, 0, Task_Cyclic);
	if((NULL == TimerHandle_Cyc50ms) || (pdPASS != xTimerStart(TimerHandle_Cyc50ms, 0)))
	{
		/* Error happened, create timer failed or start failed */
		configASSERT(0);
	}
	TimerHandle_Cyc100ms = xTimerCreate("Timer_Cyc100ms", pdMS_TO_TICKS(100), pdTRUE, 0, Task_Cyclic);
	if((NULL == TimerHandle_Cyc100ms) || (pdPASS != xTimerStart(TimerHandle_Cyc100ms, 0)))
	{
		/* Error happened, create timer failed or start failed */
		configASSERT(0);
	}

	/* Create the queue */
	/* The number of items the queue can hold. This is 1 as the receive task will remove
	 * items as they are added, meaning the send task should always find the queue empty */
	QueueHandle_Timer5ms = xQueueCreate(1, sizeof(uint32));
	if(NULL == QueueHandle_Timer5ms)
	{
		/* Error happened, create the queue failed, commonly it caused by the memory limitation, you can try to increase the heap size. */
		configASSERT(0);
	}
	QueueHandle_Timer10ms = xQueueCreate(1, sizeof(uint32));
	if(NULL == QueueHandle_Timer10ms)
	{
		/* Error happened, create the queue failed, commonly it caused by the memory limitation, you can try to increase the heap size. */
		configASSERT(0);
	}
	QueueHandle_Timer20ms = xQueueCreate(1, sizeof(uint32));
	if(NULL == QueueHandle_Timer20ms)
	{
		/* Error happened, create the queue failed, commonly it caused by the memory limitation, you can try to increase the heap size. */
		configASSERT(0);
	}
	QueueHandle_Timer50ms = xQueueCreate(1, sizeof(uint32));
	if(NULL == QueueHandle_Timer50ms)
	{
		/* Error happened, create the queue failed, commonly it caused by the memory limitation, you can try to increase the heap size. */
		configASSERT(0);
	}
	QueueHandle_Timer100ms = xQueueCreate(1, sizeof(uint32));
	if(NULL == QueueHandle_Timer100ms)
	{
		/* Error happened, create the queue failed, commonly it caused by the memory limitation, you can try to increase the heap size. */
		configASSERT(0);
	}
	QueueHandle_Ign = xQueueCreate(1, sizeof(uint32));
	if(NULL == QueueHandle_Ign)
	{
		/* Error happened, create the queue failed, commonly it caused by the memory limitation, you can try to increase the heap size. */
		configASSERT(0);
	}
	QueueHandle_VcuReq = xQueueCreate(1, sizeof(uint32));
	if(NULL == QueueHandle_VcuReq)
	{
		/* Error happened, create the queue failed, commonly it caused by the memory limitation, you can try to increase the heap size. */
		configASSERT(0);
	}
	QueueHandle_AcReq = xQueueCreate(1, sizeof(uint32));
	if(NULL == QueueHandle_AcReq)
	{
		/* Error happened, create the queue failed, commonly it caused by the memory limitation, you can try to increase the heap size. */
		configASSERT(0);
	}

	/* Create the user tasks */
	xTaskCreate(Task_Com, "Com", TASK_STACK_SIZE_COM, NULL, TASK_PRIORITY_COM, &TaskHandle_Com);
	//vTaskSuspend(TaskHandle_Com);
	xTaskCreate(Task_General, "General", TASK_STACK_SIZE_GENERAL, NULL, TASK_PRIORITY_GENERAL, &TaskHandle_General);
	//vTaskSuspend(TaskHandle_General);
	xTaskCreate(Task_PowerMode, "PowerMode", TASK_STACK_SIZE_POWERMODE, NULL, TASK_PRIORITY_POWERMODE, &TaskHandle_PowerMode);
	//vTaskSuspend(TaskHandle_PowerMode);
	/* Start the tasks and timer running. */
	vTaskStartScheduler();
	/* If all is well, the scheduler will now be running, and the following line
	will never be reached.  If the following line does execute, then there was
	insufficient FreeRTOS heap memory available for the idle and/or timer tasks
	to be created.  See the memory management section on the FreeRTOS web site
	for more details. */
	for( ;; );
	return 0;
}

