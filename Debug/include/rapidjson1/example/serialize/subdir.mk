################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/rapidjson1/example/serialize/serialize.cpp 

OBJS += \
./include/rapidjson1/example/serialize/serialize.o 

CPP_DEPS += \
./include/rapidjson1/example/serialize/serialize.d 


# Each subdirectory must supply rules for building sources it contributes
include/rapidjson1/example/serialize/%.o: ../include/rapidjson1/example/serialize/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


