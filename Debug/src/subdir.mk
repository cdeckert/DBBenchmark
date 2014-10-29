################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Configurator.cpp \
../src/DBBenchmark.cpp \
../src/ExecutionManager.cpp 

OBJS += \
./src/Configurator.o \
./src/DBBenchmark.o \
./src/ExecutionManager.o 

CPP_DEPS += \
./src/Configurator.d \
./src/DBBenchmark.d \
./src/ExecutionManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/edv-hiwi/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -pthread -static -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


