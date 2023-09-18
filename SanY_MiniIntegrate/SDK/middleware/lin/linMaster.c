/*
 * lin.c
 *
 *  Created on: 2022年6月25日
 *      Author: Administrator
 */
/* Including necessary configuration files. */
#include "sdk_project_config.h"
#include "lin_cfg.h"
#include "lin_common_api.h"
#include "lin_diagnostic_service.h"
#include "peripherals_linstack_config_1.h"
#include "Std_Types.h"

/* (CLK (MHz)* timer period (us) / Prescaler) */
#define TIMER_COMPARE_VAL (uint16_t)(2000)
#define TIMER_TICKS_1US   (uint16_t)(4U)

static uint16_t timerOverflowInterruptCount = 0U;

/*!
 * @brief LPTMR Interrupt Service Routine
 * The ISR will call LIN timeout service every 500us
 * and will provide the required tick for LIN (every 5 ms)
 */
void LPTMR_ISR(void)
{
    /* Static variable, used to count if the timeout has passed to
     * provide the LIN scheme tick.
     */
    static uint32_t interruptCount = 0UL;
    /* Timer Interrupt Handler */

    /* If 5 ms have passed, provide the required tick */
    lin_lld_timeout_service(LI0);
    if(++interruptCount == 10UL)
    {
        l_sch_tick(LI0);
        interruptCount = 0UL;
    }

    /* Increment overflow count */
    timerOverflowInterruptCount++;
    /* Clear compare flag */
    LPTMR_DRV_ClearCompareFlag(INST_LPTMR_1);
}

/*!
 * @brief Callback function to get time interval in nano seconds
 * @param[out] ns - number of nanoseconds passed since the last call of the function
 * @return dummy value
 */
uint32_t lin0TimerGetTimeIntervalCallback0(uint32_t *ns)
{
    static uint32_t previousCountValue = 0UL;
    uint32_t counterValue;

    counterValue = LPTMR_DRV_GetCounterValueByCount(INST_LPTMR_1);
    *ns = ((uint32_t)(counterValue + timerOverflowInterruptCount * TIMER_COMPARE_VAL - previousCountValue)) * 1000 / TIMER_TICKS_1US;
    timerOverflowInterruptCount = 0UL;
    previousCountValue = counterValue;
    return 0UL;
}

/*FUNCTION**********************************************************************
 * Function Name : Lin_Enable
 * Description   : 使能LIN芯片
 *END**************************************************************************/

void LinMaster_Enable(void)
{
	PINS_DRV_WritePin(LIN_STB2_PORT,LIN_STB2_PIN,STD_HIGH);
}


/*FUNCTION**********************************************************************
 * Function Name : Lin_Enable
 * Description   : 失能LIN芯片
 *END**************************************************************************/

void LinMaster_Disable(void)
{
	PINS_DRV_WritePin(LIN_STB2_PORT,LIN_STB2_PIN,STD_LOW);
}

/*FUNCTION**********************************************************************
 * Function Name : Lin_Init
 * Description   : 初始化LIN
 *END**************************************************************************/

void LinMaster_Init(void)
{
	LinMaster_Enable();
    /* Initialize LPTMR */
    LPTMR_DRV_Init(INST_LPTMR_1, &lptmr_1_config0, false);
    INT_SYS_InstallHandler(LPTMR0_IRQn, LPTMR_ISR, (isr_t *)NULL);
    INT_SYS_EnableIRQ(LPTMR0_IRQn);

    /* Initialize LIN network interface */
    l_sys_init();
    l_ifc_init(LI0);
    //l_ifc_wake_up(LI0);
    /* Set Schedule table to Normal */
    l_sch_set(LI0, LI0_NormalTable, 0u);
    l_u8_wr_LI0_Motor1Selection(0x55);
    LPTMR_DRV_StartCounter(INST_LPTMR_1);
}



