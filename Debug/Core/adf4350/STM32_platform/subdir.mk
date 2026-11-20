################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/adf4350/STM32_platform/stm32_gpio.c \
../Core/adf4350/STM32_platform/stm32_spi.c 

OBJS += \
./Core/adf4350/STM32_platform/stm32_gpio.o \
./Core/adf4350/STM32_platform/stm32_spi.o 

C_DEPS += \
./Core/adf4350/STM32_platform/stm32_gpio.d \
./Core/adf4350/STM32_platform/stm32_spi.d 


# Each subdirectory must supply rules for building sources it contributes
Core/adf4350/STM32_platform/%.o Core/adf4350/STM32_platform/%.su Core/adf4350/STM32_platform/%.cyclo: ../Core/adf4350/STM32_platform/%.c Core/adf4350/STM32_platform/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32G4xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-adf4350-2f-STM32_platform

clean-Core-2f-adf4350-2f-STM32_platform:
	-$(RM) ./Core/adf4350/STM32_platform/stm32_gpio.cyclo ./Core/adf4350/STM32_platform/stm32_gpio.d ./Core/adf4350/STM32_platform/stm32_gpio.o ./Core/adf4350/STM32_platform/stm32_gpio.su ./Core/adf4350/STM32_platform/stm32_spi.cyclo ./Core/adf4350/STM32_platform/stm32_spi.d ./Core/adf4350/STM32_platform/stm32_spi.o ./Core/adf4350/STM32_platform/stm32_spi.su

.PHONY: clean-Core-2f-adf4350-2f-STM32_platform

