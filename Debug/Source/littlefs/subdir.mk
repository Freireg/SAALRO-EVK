################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/littlefs/lfs.c \
../Source/littlefs/lfs_util.c 

OBJS += \
./Source/littlefs/lfs.o \
./Source/littlefs/lfs_util.o 

C_DEPS += \
./Source/littlefs/lfs.d \
./Source/littlefs/lfs_util.d 


# Each subdirectory must supply rules for building sources it contributes
Source/littlefs/%.o Source/littlefs/%.su: ../Source/littlefs/%.c Source/littlefs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Files/Personal/SAALRO-EVK/Source/littlefs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Source-2f-littlefs

clean-Source-2f-littlefs:
	-$(RM) ./Source/littlefs/lfs.d ./Source/littlefs/lfs.o ./Source/littlefs/lfs.su ./Source/littlefs/lfs_util.d ./Source/littlefs/lfs_util.o ./Source/littlefs/lfs_util.su

.PHONY: clean-Source-2f-littlefs

