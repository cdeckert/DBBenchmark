################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/rapidjson1/example/pretty/pretty.cpp 

OBJS += \
./include/rapidjson1/example/pretty/pretty.o 

CPP_DEPS += \
./include/rapidjson1/example/pretty/pretty.d 


# Each subdirectory must supply rules for building sources it contributes
include/rapidjson1/example/pretty/%.o: ../include/rapidjson1/example/pretty/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


