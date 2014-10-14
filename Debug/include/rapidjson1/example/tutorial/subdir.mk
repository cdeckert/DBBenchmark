################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/rapidjson1/example/tutorial/tutorial.cpp 

OBJS += \
./include/rapidjson1/example/tutorial/tutorial.o 

CPP_DEPS += \
./include/rapidjson1/example/tutorial/tutorial.d 


# Each subdirectory must supply rules for building sources it contributes
include/rapidjson1/example/tutorial/%.o: ../include/rapidjson1/example/tutorial/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


