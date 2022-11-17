################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../../../../asr/hardware_test/hardware_test.c \
../../../../asr/hardware_test/hardware_test_list.c 

OBJS += \
./hardware_test/hardware_test.o \
./hardware_test/hardware_test_list.o 

C_DEPS += \
./hardware_test/hardware_test.d \
./hardware_test/hardware_test_list.d 


# Each subdirectory must supply rules for building sources it contributes
hardware_test/hardware_test.o: ../../../../asr/hardware_test/hardware_test.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
hardware_test/hardware_test_list.o: ../../../../asr/hardware_test/hardware_test_list.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

