################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/AdcPal/AdcPal.c \
../SDK/middleware/AdcPal/AdcPal_Cfg.c 

OBJS += \
./SDK/middleware/AdcPal/AdcPal.o \
./SDK/middleware/AdcPal/AdcPal_Cfg.o 

C_DEPS += \
./SDK/middleware/AdcPal/AdcPal.d \
./SDK/middleware/AdcPal/AdcPal_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/AdcPal/%.o: ../SDK/middleware/AdcPal/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/AdcPal/AdcPal.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


