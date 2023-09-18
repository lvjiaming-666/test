################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Task_Cyclic/Task_Cyclic.c \
../APP/Task_Cyclic/Task_Cyclic_Cfg.c 

OBJS += \
./APP/Task_Cyclic/Task_Cyclic.o \
./APP/Task_Cyclic/Task_Cyclic_Cfg.o 

C_DEPS += \
./APP/Task_Cyclic/Task_Cyclic.d \
./APP/Task_Cyclic/Task_Cyclic_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Task_Cyclic/%.o: ../APP/Task_Cyclic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@APP/Task_Cyclic/Task_Cyclic.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


