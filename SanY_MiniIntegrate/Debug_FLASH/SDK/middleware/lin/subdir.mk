################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/lin/linMaster.c 

OBJS += \
./SDK/middleware/lin/linMaster.o 

C_DEPS += \
./SDK/middleware/lin/linMaster.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/lin/%.o: ../SDK/middleware/lin/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/lin/linMaster.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


