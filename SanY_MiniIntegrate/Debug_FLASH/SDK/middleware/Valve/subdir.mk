################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/Valve/Valve.c \
../SDK/middleware/Valve/Valve_Cfg.c 

OBJS += \
./SDK/middleware/Valve/Valve.o \
./SDK/middleware/Valve/Valve_Cfg.o 

C_DEPS += \
./SDK/middleware/Valve/Valve.d \
./SDK/middleware/Valve/Valve_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/Valve/%.o: ../SDK/middleware/Valve/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/Valve/Valve.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


