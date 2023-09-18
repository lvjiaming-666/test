################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/CanMsg/CanMsg.c \
../SDK/middleware/CanMsg/CanMsg_Cfg.c 

OBJS += \
./SDK/middleware/CanMsg/CanMsg.o \
./SDK/middleware/CanMsg/CanMsg_Cfg.o 

C_DEPS += \
./SDK/middleware/CanMsg/CanMsg.d \
./SDK/middleware/CanMsg/CanMsg_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/CanMsg/%.o: ../SDK/middleware/CanMsg/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/CanMsg/CanMsg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


