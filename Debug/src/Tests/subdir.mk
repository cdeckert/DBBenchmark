################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Tests/ATest.cpp \
../src/Tests/FullTableScan.cpp \
../src/Tests/IndexScan.cpp \
../src/Tests/LogWriter.cpp 

OBJS += \
./src/Tests/ATest.o \
./src/Tests/FullTableScan.o \
./src/Tests/IndexScan.o \
./src/Tests/LogWriter.o 

CPP_DEPS += \
./src/Tests/ATest.d \
./src/Tests/FullTableScan.d \
./src/Tests/IndexScan.d \
./src/Tests/LogWriter.d 


# Each subdirectory must supply rules for building sources it contributes
src/Tests/%.o: ../src/Tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


