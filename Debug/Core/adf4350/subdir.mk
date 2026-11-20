################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/adf4350/adf4350.c \
../Core/adf4350/no_os_spi.c \
../Core/adf4350/stm32_dma.c \
../Core/adf4350/stm32_gpio.c \
../Core/adf4350/stm32_irq.c \
../Core/adf4350/stm32_spi.c \
../Core/adf4350/stm32_uart.c 

OBJS += \
./Core/adf4350/adf4350.o \
./Core/adf4350/no_os_spi.o \
./Core/adf4350/stm32_dma.o \
./Core/adf4350/stm32_gpio.o \
./Core/adf4350/stm32_irq.o \
./Core/adf4350/stm32_spi.o \
./Core/adf4350/stm32_uart.o 

C_DEPS += \
./Core/adf4350/adf4350.d \
./Core/adf4350/no_os_spi.d \
./Core/adf4350/stm32_dma.d \
./Core/adf4350/stm32_gpio.d \
./Core/adf4350/stm32_irq.d \
./Core/adf4350/stm32_spi.d \
./Core/adf4350/stm32_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/adf4350/%.o Core/adf4350/%.su Core/adf4350/%.cyclo: ../Core/adf4350/%.c Core/adf4350/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32G4xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-adf4350

clean-Core-2f-adf4350:
	-$(RM) ./Core/adf4350/adf4350.cyclo ./Core/adf4350/adf4350.d ./Core/adf4350/adf4350.o ./Core/adf4350/adf4350.su ./Core/adf4350/no_os_spi.cyclo ./Core/adf4350/no_os_spi.d ./Core/adf4350/no_os_spi.o ./Core/adf4350/no_os_spi.su ./Core/adf4350/stm32_dma.cyclo ./Core/adf4350/stm32_dma.d ./Core/adf4350/stm32_dma.o ./Core/adf4350/stm32_dma.su ./Core/adf4350/stm32_gpio.cyclo ./Core/adf4350/stm32_gpio.d ./Core/adf4350/stm32_gpio.o ./Core/adf4350/stm32_gpio.su ./Core/adf4350/stm32_irq.cyclo ./Core/adf4350/stm32_irq.d ./Core/adf4350/stm32_irq.o ./Core/adf4350/stm32_irq.su ./Core/adf4350/stm32_spi.cyclo ./Core/adf4350/stm32_spi.d ./Core/adf4350/stm32_spi.o ./Core/adf4350/stm32_spi.su ./Core/adf4350/stm32_uart.cyclo ./Core/adf4350/stm32_uart.d ./Core/adf4350/stm32_uart.o ./Core/adf4350/stm32_uart.su

.PHONY: clean-Core-2f-adf4350

