################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ConfigReader.cpp \
../src/DBBenchmark.cpp \
../src/ExecutionManager.cpp 

OBJS += \
./src/ConfigReader.o \
./src/DBBenchmark.o \
./src/ExecutionManager.o 

CPP_DEPS += \
./src/ConfigReader.d \
./src/DBBenchmark.d \
./src/ExecutionManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


