################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../littlefs/bd/lfs_filebd.c \
../littlefs/bd/lfs_rambd.c \
../littlefs/bd/lfs_testbd.c 

OBJS += \
./littlefs/bd/lfs_filebd.o \
./littlefs/bd/lfs_rambd.o \
./littlefs/bd/lfs_testbd.o 

C_DEPS += \
./littlefs/bd/lfs_filebd.d \
./littlefs/bd/lfs_rambd.d \
./littlefs/bd/lfs_testbd.d 


# Each subdirectory must supply rules for building sources it contributes
littlefs/bd/%.o littlefs/bd/%.su: ../littlefs/bd/%.c littlefs/bd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/freire/Projects/ST-Workspace/SAALRO-EVK/littlefs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-littlefs-2f-bd

clean-littlefs-2f-bd:
	-$(RM) ./littlefs/bd/lfs_filebd.d ./littlefs/bd/lfs_filebd.o ./littlefs/bd/lfs_filebd.su ./littlefs/bd/lfs_rambd.d ./littlefs/bd/lfs_rambd.o ./littlefs/bd/lfs_rambd.su ./littlefs/bd/lfs_testbd.d ./littlefs/bd/lfs_testbd.o ./littlefs/bd/lfs_testbd.su

.PHONY: clean-littlefs-2f-bd

