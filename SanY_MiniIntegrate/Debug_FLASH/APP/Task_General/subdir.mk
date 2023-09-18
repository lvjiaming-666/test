################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Task_General/Task_General.c 

OBJS += \
./APP/Task_General/Task_General.o 

C_DEPS += \
./APP/Task_General/Task_General.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Task_General/%.o: ../APP/Task_General/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@APP/Task_General/Task_General.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


