################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/middleware/BinarySearch/BinarySearch.c 

OBJS += \
./SDK/middleware/BinarySearch/BinarySearch.o 

C_DEPS += \
./SDK/middleware/BinarySearch/BinarySearch.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/middleware/BinarySearch/%.o: ../SDK/middleware/BinarySearch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/middleware/BinarySearch/BinarySearch.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


