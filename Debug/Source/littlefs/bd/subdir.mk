################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/littlefs/bd/lfs_filebd.c \
../Source/littlefs/bd/lfs_rambd.c \
../Source/littlefs/bd/lfs_testbd.c 

OBJS += \
./Source/littlefs/bd/lfs_filebd.o \
./Source/littlefs/bd/lfs_rambd.o \
./Source/littlefs/bd/lfs_testbd.o 

C_DEPS += \
./Source/littlefs/bd/lfs_filebd.d \
./Source/littlefs/bd/lfs_rambd.d \
./Source/littlefs/bd/lfs_testbd.d 


# Each subdirectory must supply rules for building sources it contributes
Source/littlefs/bd/%.o Source/littlefs/bd/%.su: ../Source/littlefs/bd/%.c Source/littlefs/bd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Files/Personal/SAALRO-EVK/Source/littlefs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Source-2f-littlefs-2f-bd

clean-Source-2f-littlefs-2f-bd:
	-$(RM) ./Source/littlefs/bd/lfs_filebd.d ./Source/littlefs/bd/lfs_filebd.o ./Source/littlefs/bd/lfs_filebd.su ./Source/littlefs/bd/lfs_rambd.d ./Source/littlefs/bd/lfs_rambd.o ./Source/littlefs/bd/lfs_rambd.su ./Source/littlefs/bd/lfs_testbd.d ./Source/littlefs/bd/lfs_testbd.o ./Source/littlefs/bd/lfs_testbd.su

.PHONY: clean-Source-2f-littlefs-2f-bd

