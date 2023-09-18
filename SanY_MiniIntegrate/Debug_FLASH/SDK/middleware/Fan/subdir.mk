################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/Fan/Fan.c \
../SDK/middleware/Fan/Fan_Cfg.c 

OBJS += \
./SDK/middleware/Fan/Fan.o \
./SDK/middleware/Fan/Fan_Cfg.o 

C_DEPS += \
./SDK/middleware/Fan/Fan.d \
./SDK/middleware/Fan/Fan_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/Fan/%.o: ../SDK/middleware/Fan/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/Fan/Fan.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


