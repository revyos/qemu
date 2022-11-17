all:
	arm-linux-gnueabihf-gcc neon.c -mfloat-abi=hard -mfpu=neon-vfpv4 -static -o neon.elf
	arm-linux-gnueabihf-gcc float.c -mfloat-abi=hard -mfpu=vfpv3-fp16 -static -o float.elf -mfp16-format=ieee
