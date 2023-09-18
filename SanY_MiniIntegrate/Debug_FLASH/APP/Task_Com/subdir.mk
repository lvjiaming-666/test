################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Task_Com/Task_Com.c 

OBJS += \
./APP/Task_Com/Task_Com.o 

C_DEPS += \
./APP/Task_Com/Task_Com.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Task_Com/%.o: ../APP/Task_Com/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@APP/Task_Com/Task_Com.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


