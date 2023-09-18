################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/clock_config.c \
../board/lin_cfg.c \
../board/peripherals_adc_pal_1.c \
../board/peripherals_adc_pal_2.c \
../board/peripherals_can_pal_1.c \
../board/peripherals_can_pal_2.c \
../board/peripherals_freertos_1.c \
../board/peripherals_lin_1.c \
../board/peripherals_linstack_config_1.c \
../board/peripherals_lptmr_1.c \
../board/peripherals_power_manager_1.c \
../board/peripherals_pwm_pal_1.c \
../board/peripherals_pwm_pal_2.c \
../board/pin_mux.c 

OBJS += \
./board/clock_config.o \
./board/lin_cfg.o \
./board/peripherals_adc_pal_1.o \
./board/peripherals_adc_pal_2.o \
./board/peripherals_can_pal_1.o \
./board/peripherals_can_pal_2.o \
./board/peripherals_freertos_1.o \
./board/peripherals_lin_1.o \
./board/peripherals_linstack_config_1.o \
./board/peripherals_lptmr_1.o \
./board/peripherals_power_manager_1.o \
./board/peripherals_pwm_pal_1.o \
./board/peripherals_pwm_pal_2.o \
./board/pin_mux.o 

C_DEPS += \
./board/clock_config.d \
./board/lin_cfg.d \
./board/peripherals_adc_pal_1.d \
./board/peripherals_adc_pal_2.d \
./board/peripherals_can_pal_1.d \
./board/peripherals_can_pal_2.d \
./board/peripherals_freertos_1.d \
./board/peripherals_lin_1.d \
./board/peripherals_linstack_config_1.d \
./board/peripherals_lptmr_1.d \
./board/peripherals_power_manager_1.d \
./board/peripherals_pwm_pal_1.d \
./board/peripherals_pwm_pal_2.d \
./board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@board/clock_config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


