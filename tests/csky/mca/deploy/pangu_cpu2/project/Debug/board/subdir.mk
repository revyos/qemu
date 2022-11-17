################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../../board/board_init.c 

OBJS += \
./board/board_init.o 

C_DEPS += \
./board/board_init.d 


# Each subdirectory must supply rules for building sources it contributes
board/board_init.o: ../../board/board_init.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

