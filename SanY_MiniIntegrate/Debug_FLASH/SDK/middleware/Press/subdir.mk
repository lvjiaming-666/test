################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/Press/Press.c \
../SDK/middleware/Press/Press_Cfg.c 

OBJS += \
./SDK/middleware/Press/Press.o \
./SDK/middleware/Press/Press_Cfg.o 

C_DEPS += \
./SDK/middleware/Press/Press.d \
./SDK/middleware/Press/Press_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/Press/%.o: ../SDK/middleware/Press/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/Press/Press.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


