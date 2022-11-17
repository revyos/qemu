################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include libs/mm/subdir.mk
-include libs/libc/subdir.mk
-include hardware_test/mca/subdir.mk
-include hardware_test/subdir.mk
-include driver/subdir.mk
-include board/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: pangu_cpu2.elf pangu_cpu2.ihex

# Output Target
pangu_cpu2.ihex: pangu_cpu2.elf
	@echo 'Outputing file $@'
	@csky-elfabiv2-objcopy -O ihex "$<" "$@"

# Tool invocations
pangu_cpu2.elf: $(OBJS) $(USER_OBJS) ../ckcpu.ld
	@echo 'Building target: $@'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -nostartfiles -Wl,--gc-sections       -L../../dependencies/csky_asr/lib/YunVoice2_Debug -L../../dependencies/ckcpu/lib/Debug -L../../dependencies/csky_mca/lib/Debug -L../../dependencies/ck805f_v1_6/csi_nn/lib -L../../dependencies/ck805f_v1_6/csi_dsp/lib -Wl,-zmax-page-size=1024 -T"../ckcpu.ld" -o "pangu_cpu2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo ' '
	@echo 'Size of $@:'
	@csky-elfabiv2-size "$@"
	@echo ' '

# Other Targets
clean:
	-$(RM) pangu_cpu2.ihex
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS) pangu_cpu2.elf
	-@echo ' '

.PHONY: all clean dependents


-include ../makefile.targets
