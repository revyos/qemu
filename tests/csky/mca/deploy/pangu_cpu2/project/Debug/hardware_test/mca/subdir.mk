################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../../../../asr/hardware_test/mca/csky_mca_asrc_test.c \
../../../../asr/hardware_test/mca/csky_mca_fft_test.c \
../../../../asr/hardware_test/mca/csky_mca_fir_test.c \
../../../../asr/hardware_test/mca/csky_mca_iir_test.c \
../../../../asr/hardware_test/mca/csky_mca_mac_test.c \
../../../../asr/hardware_test/mca/csky_mca_softmax_test.c \
../../../../asr/hardware_test/mca/csky_mca_test_helper.c \
../../../../asr/hardware_test/mca/csky_mca_vec_test.c \
../../../../asr/hardware_test/mca/fft_fxp.c 

OBJS += \
./hardware_test/mca/csky_mca_asrc_test.o \
./hardware_test/mca/csky_mca_fft_test.o \
./hardware_test/mca/csky_mca_fir_test.o \
./hardware_test/mca/csky_mca_iir_test.o \
./hardware_test/mca/csky_mca_mac_test.o \
./hardware_test/mca/csky_mca_softmax_test.o \
./hardware_test/mca/csky_mca_test_helper.o \
./hardware_test/mca/csky_mca_vec_test.o \
./hardware_test/mca/fft_fxp.o 

C_DEPS += \
./hardware_test/mca/csky_mca_asrc_test.d \
./hardware_test/mca/csky_mca_fft_test.d \
./hardware_test/mca/csky_mca_fir_test.d \
./hardware_test/mca/csky_mca_iir_test.d \
./hardware_test/mca/csky_mca_mac_test.d \
./hardware_test/mca/csky_mca_softmax_test.d \
./hardware_test/mca/csky_mca_test_helper.d \
./hardware_test/mca/csky_mca_vec_test.d \
./hardware_test/mca/fft_fxp.d 


# Each subdirectory must supply rules for building sources it contributes
hardware_test/mca/csky_mca_asrc_test.o: ../../../../asr/hardware_test/mca/csky_mca_asrc_test.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
hardware_test/mca/csky_mca_fft_test.o: ../../../../asr/hardware_test/mca/csky_mca_fft_test.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
hardware_test/mca/csky_mca_fir_test.o: ../../../../asr/hardware_test/mca/csky_mca_fir_test.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
hardware_test/mca/csky_mca_iir_test.o: ../../../../asr/hardware_test/mca/csky_mca_iir_test.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
hardware_test/mca/csky_mca_mac_test.o: ../../../../asr/hardware_test/mca/csky_mca_mac_test.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
hardware_test/mca/csky_mca_softmax_test.o: ../../../../asr/hardware_test/mca/csky_mca_softmax_test.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
hardware_test/mca/csky_mca_test_helper.o: ../../../../asr/hardware_test/mca/csky_mca_test_helper.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
hardware_test/mca/csky_mca_vec_test.o: ../../../../asr/hardware_test/mca/csky_mca_vec_test.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
hardware_test/mca/fft_fxp.o: ../../../../asr/hardware_test/mca/fft_fxp.c
	@echo 'Building file: $<'
	@csky-elfabiv2-gcc -mcpu=ck805ef -mhard-float -I.. -I../../dependencies/ck805f_v1_6/csi_dsp/include -I../../dependencies/ck805f_v1_6/csi_nn/include -I../../dependencies/ckcpu/inc -I../../dependencies/csky_mca/inc -I../../dependencies/csky_asr/inc -I../../kernel/include -I../../board/include -I../../libs/include -I../../core/include -I../../driver/include -I../../include -I../../../../asr/src -I../../../../asr/src/src -I../../../../asr/hardware_test -O0 -fdata-sections -g3 -Wall -c -ffunction-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

