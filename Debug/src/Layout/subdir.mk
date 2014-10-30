################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Layout/Layout.cpp \
../src/Layout/Relationship.cpp 

OBJS += \
./src/Layout/Layout.o \
./src/Layout/Relationship.o 

CPP_DEPS += \
./src/Layout/Layout.d \
./src/Layout/Relationship.d 


# Each subdirectory must supply rules for building sources it contributes
src/Layout/%.o: ../src/Layout/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -pthread -static -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


