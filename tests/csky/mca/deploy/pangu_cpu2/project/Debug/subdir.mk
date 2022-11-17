################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

S_UPPER_SRCS += \
../crt0.S 

OBJS += \
./crt0.o \
./main.o 

C_DEPS += \
./main.d 

S_UPPER_DEPS += \
./crt0.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.S
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -c -I.. -Wa,--gdwarf2 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
%.o: ../%.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

