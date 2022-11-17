################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../../libs/libc/_init.c \
../../libs/libc/malloc.c \
../../libs/libc/minilibc_port.c 

OBJS += \
./libs/libc/_init.o \
./libs/libc/malloc.o \
./libs/libc/minilibc_port.o 

C_DEPS += \
./libs/libc/_init.d \
./libs/libc/malloc.d \
./libs/libc/minilibc_port.d 


# Each subdirectory must supply rules for building sources it contributes
libs/libc/_init.o: ../../libs/libc/_init.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
libs/libc/malloc.o: ../../libs/libc/malloc.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
libs/libc/minilibc_port.o: ../../libs/libc/minilibc_port.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

