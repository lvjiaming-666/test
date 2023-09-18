################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/Pump/Pump.c \
../SDK/middleware/Pump/Pump_Cfg.c 

OBJS += \
./SDK/middleware/Pump/Pump.o \
./SDK/middleware/Pump/Pump_Cfg.o 

C_DEPS += \
./SDK/middleware/Pump/Pump.d \
./SDK/middleware/Pump/Pump_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/Pump/%.o: ../SDK/middleware/Pump/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/Pump/Pump.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


