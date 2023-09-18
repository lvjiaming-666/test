#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

#include "pins_driver.h"

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif


/*! @brief Definitions/Declarations for BOARD_InitPins Functional Group */
/*! @brief User definition pins */
#define DIRECTION_MOTOR1_PORT    PTB
#define DIRECTION_MOTOR1_PIN     10U
#define MCU_CRXD2_PORT    PTA
#define MCU_CRXD2_PIN     12U
#define MCU_CTXD2_PORT    PTA
#define MCU_CTXD2_PIN     13U
#define ENABLE_MOTOR2_PORT    PTB
#define ENABLE_MOTOR2_PIN     9U
#define ENABLE_MOTOR1_PORT    PTB
#define ENABLE_MOTOR1_PIN     11U
#define MCU_WVF_PWM2_PORT    PTD
#define MCU_WVF_PWM2_PIN     15U
#define MCU_WVF_PWM1_PORT    PTD
#define MCU_WVF_PWM1_PIN     16U
#define MCU_LN_PWM3_PORT    PTD
#define MCU_LN_PWM3_PIN     1U
#define MCU_LN_PWM4_PORT    PTD
#define MCU_LN_PWM4_PIN     0U
#define CAN0_SB1_PORT    PTE
#define CAN0_SB1_PIN     13U
#define MCU_CTXD1_PORT    PTE
#define MCU_CTXD1_PIN     5U
#define MCU_CRXD1_PORT    PTE
#define MCU_CRXD1_PIN     4U
#define MCU_PUMP_PWM2_PORT    PTE
#define MCU_PUMP_PWM2_PIN     9U
#define MCU_PUMP_PWM1_PORT    PTE
#define MCU_PUMP_PWM1_PIN     8U
#define MCU_LN_PWM1_PORT    PTB
#define MCU_LN_PWM1_PIN     5U
#define MCU_LN_PWM2_PORT    PTB
#define MCU_LN_PWM2_PIN     4U
#define LIN_TXD_PORT    PTD
#define LIN_TXD_PIN     7U
#define LIN_RXD_PORT    PTD
#define LIN_RXD_PIN     6U
#define LIN_STB2_PORT    PTD
#define LIN_STB2_PIN     5U
#define Sensor_5V_EN_PORT    PTD
#define Sensor_5V_EN_PIN     12U
#define MCU_PUMP_PWM3_PORT    PTC
#define MCU_PUMP_PWM3_PIN     13U
#define MCU_BLOW_PWM_PORT    PTC
#define MCU_BLOW_PWM_PIN     12U
#define MCU_Valve3_PORT    PTC
#define MCU_Valve3_PIN     9U
#define MCU_Valve2_PORT    PTC
#define MCU_Valve2_PIN     8U
#define MCU_Valve1_PORT    PTE
#define MCU_Valve1_PIN     7U
#define MCU_PWM24V_EN_PORT    PTA
#define MCU_PWM24V_EN_PIN     17U
#define DIRECTION_MOTOR2_PORT    PTB
#define DIRECTION_MOTOR2_PIN     8U
#define CAN1_SB1_PORT    PTA
#define CAN1_SB1_PIN     14U
#define PWM_MOTOR2_PORT    PTC
#define PWM_MOTOR2_PIN     10U
#define PWM_MOTOR1_PORT    PTC
#define PWM_MOTOR1_PIN     11U
#define Exv_Sleep2_PORT    PTE
#define Exv_Sleep2_PIN     0U
#define Exv_Sleep1_PORT    PTE
#define Exv_Sleep1_PIN     1U
/*! @brief User number of configured pins */
#define NUM_OF_CONFIGURED_PINS0 32
/*! @brief User configuration structure */
extern pin_settings_config_t g_pin_mux_InitConfigArr0[NUM_OF_CONFIGURED_PINS0];


#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/

