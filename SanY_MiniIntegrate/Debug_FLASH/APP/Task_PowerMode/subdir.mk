################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Task_PowerMode/Task_PowerMode.c 

OBJS += \
./APP/Task_PowerMode/Task_PowerMode.o 

C_DEPS += \
./APP/Task_PowerMode/Task_PowerMode.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Task_PowerMode/%.o: ../APP/Task_PowerMode/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@APP/Task_PowerMode/Task_PowerMode.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


