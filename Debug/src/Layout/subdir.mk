################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Layout/ConfigGenerator.cpp \
../src/Layout/HDDModePageReader.cpp 

OBJS += \
./src/Layout/ConfigGenerator.o \
./src/Layout/HDDModePageReader.o 

CPP_DEPS += \
./src/Layout/ConfigGenerator.d \
./src/Layout/HDDModePageReader.d 


# Each subdirectory must supply rules for building sources it contributes
src/Layout/%.o: ../src/Layout/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/edv-hiwi/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


