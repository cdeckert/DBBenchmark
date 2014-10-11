################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ATest.cpp \
../src/ConfigReader.cpp \
../src/DBBenchmark.cpp \
../src/ExecutionManager.cpp \
../src/LogWriter.cpp 

OBJS += \
./src/ATest.o \
./src/ConfigReader.o \
./src/DBBenchmark.o \
./src/ExecutionManager.o \
./src/LogWriter.o 

CPP_DEPS += \
./src/ATest.d \
./src/ConfigReader.d \
./src/DBBenchmark.d \
./src/ExecutionManager.d \
./src/LogWriter.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


