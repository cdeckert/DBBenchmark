################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Tests/ATest.cpp \
../src/Tests/FullTableScan.cpp \
../src/Tests/IndexScan.cpp \
../src/Tests/IndexWrite.cpp \
../src/Tests/TestScenario.cpp \
../src/Tests/TransactionLog.cpp 

OBJS += \
./src/Tests/ATest.o \
./src/Tests/FullTableScan.o \
./src/Tests/IndexScan.o \
./src/Tests/IndexWrite.o \
./src/Tests/TestScenario.o \
./src/Tests/TransactionLog.o 

CPP_DEPS += \
./src/Tests/ATest.d \
./src/Tests/FullTableScan.d \
./src/Tests/IndexScan.d \
./src/Tests/IndexWrite.d \
./src/Tests/TestScenario.d \
./src/Tests/TransactionLog.d 


# Each subdirectory must supply rules for building sources it contributes
src/Tests/%.o: ../src/Tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/edv-hiwi/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -pthread -static -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


