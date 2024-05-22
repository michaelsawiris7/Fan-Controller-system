################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DC_MOTOR.c \
../GPIO2.c \
../KEYPAD.c \
../LCD2.c \
../PWM_TIM0.c \
../SEVEN_SEG.c \
../TEMP_SENSOR_LM35.c \
../TEST.c 

OBJS += \
./ADC.o \
./DC_MOTOR.o \
./GPIO2.o \
./KEYPAD.o \
./LCD2.o \
./PWM_TIM0.o \
./SEVEN_SEG.o \
./TEMP_SENSOR_LM35.o \
./TEST.o 

C_DEPS += \
./ADC.d \
./DC_MOTOR.d \
./GPIO2.d \
./KEYPAD.d \
./LCD2.d \
./PWM_TIM0.d \
./SEVEN_SEG.d \
./TEMP_SENSOR_LM35.d \
./TEST.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


