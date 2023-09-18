################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/PowerCtr/PowerCtr.c 

OBJS += \
./SDK/middleware/PowerCtr/PowerCtr.o 

C_DEPS += \
./SDK/middleware/PowerCtr/PowerCtr.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/PowerCtr/%.o: ../SDK/middleware/PowerCtr/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/PowerCtr/PowerCtr.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


