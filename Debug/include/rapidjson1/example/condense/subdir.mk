################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/rapidjson1/example/condense/condense.cpp 

OBJS += \
./include/rapidjson1/example/condense/condense.o 

CPP_DEPS += \
./include/rapidjson1/example/condense/condense.d 


# Each subdirectory must supply rules for building sources it contributes
include/rapidjson1/example/condense/%.o: ../include/rapidjson1/example/condense/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


