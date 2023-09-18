################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/Temperature/TemperConvert.c \
../SDK/middleware/Temperature/Temperature.c 

OBJS += \
./SDK/middleware/Temperature/TemperConvert.o \
./SDK/middleware/Temperature/Temperature.o 

C_DEPS += \
./SDK/middleware/Temperature/TemperConvert.d \
./SDK/middleware/Temperature/Temperature.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/Temperature/%.o: ../SDK/middleware/Temperature/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/Temperature/TemperConvert.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


