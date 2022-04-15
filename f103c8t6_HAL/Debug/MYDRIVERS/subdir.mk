################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MYDRIVERS/hread_interface.c \
../MYDRIVERS/mymain.c \
../MYDRIVERS/oled.c 

OBJS += \
./MYDRIVERS/hread_interface.o \
./MYDRIVERS/mymain.o \
./MYDRIVERS/oled.o 

C_DEPS += \
./MYDRIVERS/hread_interface.d \
./MYDRIVERS/mymain.d \
./MYDRIVERS/oled.d 


# Each subdirectory must supply rules for building sources it contributes
MYDRIVERS/%.o: ../MYDRIVERS/%.c MYDRIVERS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/wuwen/Desktop/morse_code_trainer/f103c8t6_HAL/MYDRIVERS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MYDRIVERS

clean-MYDRIVERS:
	-$(RM) ./MYDRIVERS/hread_interface.d ./MYDRIVERS/hread_interface.o ./MYDRIVERS/mymain.d ./MYDRIVERS/mymain.o ./MYDRIVERS/oled.d ./MYDRIVERS/oled.o

.PHONY: clean-MYDRIVERS

