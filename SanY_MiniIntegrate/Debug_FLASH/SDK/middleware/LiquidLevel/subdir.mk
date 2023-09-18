################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/LiquidLevel/LiquidLevel.c \
../SDK/middleware/LiquidLevel/LiquidLevel_Cfg.c 

OBJS += \
./SDK/middleware/LiquidLevel/LiquidLevel.o \
./SDK/middleware/LiquidLevel/LiquidLevel_Cfg.o 

C_DEPS += \
./SDK/middleware/LiquidLevel/LiquidLevel.d \
./SDK/middleware/LiquidLevel/LiquidLevel_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/LiquidLevel/%.o: ../SDK/middleware/LiquidLevel/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/LiquidLevel/LiquidLevel.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


