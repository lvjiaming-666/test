################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include board/subdir.mk
-include SDK/rtos/osif/subdir.mk
-include SDK/rtos/FreeRTOS/Source/portable/MemMang/subdir.mk
-include SDK/rtos/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include SDK/rtos/FreeRTOS/Source/subdir.mk
-include SDK/platform/pal/src/pwm/subdir.mk
-include SDK/platform/pal/src/can/subdir.mk
-include SDK/platform/pal/src/adc/subdir.mk
-include SDK/platform/drivers/src/wdog/subdir.mk
-include SDK/platform/drivers/src/trgmux/subdir.mk
-include SDK/platform/drivers/src/power/S32K1xx/subdir.mk
-include SDK/platform/drivers/src/power/subdir.mk
-include SDK/platform/drivers/src/pins/subdir.mk
-include SDK/platform/drivers/src/pdb/subdir.mk
-include SDK/platform/drivers/src/lpuart/subdir.mk
-include SDK/platform/drivers/src/lptmr/subdir.mk
-include SDK/platform/drivers/src/lin/subdir.mk
-include SDK/platform/drivers/src/interrupt/subdir.mk
-include SDK/platform/drivers/src/ftm/subdir.mk
-include SDK/platform/drivers/src/flexcan/subdir.mk
-include SDK/platform/drivers/src/flash/subdir.mk
-include SDK/platform/drivers/src/edma/subdir.mk
-include SDK/platform/drivers/src/clock/S32K1xx/subdir.mk
-include SDK/platform/drivers/src/adc/subdir.mk
-include SDK/platform/devices/S32K144/startup/subdir.mk
-include SDK/platform/devices/subdir.mk
-include SDK/middleware/lin/transport/subdir.mk
-include SDK/middleware/lin/lowlevel/subdir.mk
-include SDK/middleware/lin/diagnostic/subdir.mk
-include SDK/middleware/lin/coreapi/subdir.mk
-include SDK/middleware/lin/subdir.mk
-include SDK/middleware/Valve/subdir.mk
-include SDK/middleware/Temperature/subdir.mk
-include SDK/middleware/StateMachine/subdir.mk
-include SDK/middleware/Pump/subdir.mk
-include SDK/middleware/Press/subdir.mk
-include SDK/middleware/PowerCtr/subdir.mk
-include SDK/middleware/LiquidLevel/subdir.mk
-include SDK/middleware/Fan/subdir.mk
-include SDK/middleware/EXV/subdir.mk
-include SDK/middleware/CanMsg/subdir.mk
-include SDK/middleware/BinarySearch/subdir.mk
-include SDK/middleware/AdcPal/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include APP/Task_PowerMode/subdir.mk
-include APP/Task_General/subdir.mk
-include APP/Task_Cyclic/subdir.mk
-include APP/Task_Com/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
SanY_MiniIntegrate.srec \

SECONDARY_SIZE += \
SanY_MiniIntegrate.siz \


# All Target
all: SanY_MiniIntegrate.elf secondary-outputs

# Tool invocations
SanY_MiniIntegrate.elf: $(OBJS) C:\Users\ljm\workspaceS32DS.3.4\SanY_MiniIntegrate\Project_Settings\Linker_Files\S32K144_64_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "SanY_MiniIntegrate.elf" "@SanY_MiniIntegrate.args"  $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SanY_MiniIntegrate.srec: SanY_MiniIntegrate.elf
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O srec SanY_MiniIntegrate.elf  "SanY_MiniIntegrate.srec"
	@echo 'Finished building: $@'
	@echo ' '

SanY_MiniIntegrate.siz: SanY_MiniIntegrate.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley SanY_MiniIntegrate.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
