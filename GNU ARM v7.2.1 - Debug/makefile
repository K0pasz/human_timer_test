################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFM32GG/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: hazi.axf

# Tool invocations
hazi.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "hazi.ld" -Xlinker --gc-sections -Xlinker -Map="hazi.map" --specs=nano.specs -o hazi.axf "./CMSIS/EFM32GG/startup_gcc_efm32gg.o" "./CMSIS/EFM32GG/system_efm32gg.o" "./emlib/bsp_stk.o" "./emlib/bsp_stk_leds.o" "./emlib/em_cmu.o" "./emlib/em_gpio.o" "./emlib/em_lcd.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./emlib/segmentlcd.o" "./src/countdown.o" "./src/delay.o" "./src/getrandom.o" "./src/main.o" "./src/measure.o" "./src/sendtousart.o" "./src/wait_to_start.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: hazi.hex'
	arm-none-eabi-objcopy -O ihex "hazi.axf" "hazi.hex"
	@echo ' '

	@echo 'Building bin file: hazi.bin'
	arm-none-eabi-objcopy -O binary "hazi.axf" "hazi.bin"
	@echo ' '

	@echo 'Building s37 file: hazi.s37'
	arm-none-eabi-objcopy -O srec "hazi.axf" "hazi.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "hazi.axf" -A
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) hazi.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
