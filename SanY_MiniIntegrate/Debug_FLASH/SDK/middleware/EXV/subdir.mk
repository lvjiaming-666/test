################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/EXV/EXV.c \
../SDK/middleware/EXV/EXV_Cfg.c 

OBJS += \
./SDK/middleware/EXV/EXV.o \
./SDK/middleware/EXV/EXV_Cfg.o 

C_DEPS += \
./SDK/middleware/EXV/EXV.d \
./SDK/middleware/EXV/EXV_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/EXV/%.o: ../SDK/middleware/EXV/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/EXV/EXV.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


