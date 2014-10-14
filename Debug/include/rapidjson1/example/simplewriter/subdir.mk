################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/rapidjson1/example/simplewriter/simplewriter.cpp 

OBJS += \
./include/rapidjson1/example/simplewriter/simplewriter.o 

CPP_DEPS += \
./include/rapidjson1/example/simplewriter/simplewriter.d 


# Each subdirectory must supply rules for building sources it contributes
include/rapidjson1/example/simplewriter/%.o: ../include/rapidjson1/example/simplewriter/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


