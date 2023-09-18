################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/StateMachine/StateMachine.c \
../SDK/middleware/StateMachine/StateMachine_Cfg.c 

OBJS += \
./SDK/middleware/StateMachine/StateMachine.o \
./SDK/middleware/StateMachine/StateMachine_Cfg.o 

C_DEPS += \
./SDK/middleware/StateMachine/StateMachine.d \
./SDK/middleware/StateMachine/StateMachine_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/StateMachine/%.o: ../SDK/middleware/StateMachine/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/StateMachine/StateMachine.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


