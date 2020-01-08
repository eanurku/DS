################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/C\ Programming.c 

OBJS += \
./src/C\ Programming.o 

C_DEPS += \
./src/C\ Programming.d 


# Each subdirectory must supply rules for building sources it contributes
src/C\ Programming.o: ../src/C\ Programming.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/C Programming.d" -MT"src/C\ Programming.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


