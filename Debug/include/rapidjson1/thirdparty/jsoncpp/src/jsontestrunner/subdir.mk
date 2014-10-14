################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/rapidjson1/thirdparty/jsoncpp/src/jsontestrunner/main.cpp 

OBJS += \
./include/rapidjson1/thirdparty/jsoncpp/src/jsontestrunner/main.o 

CPP_DEPS += \
./include/rapidjson1/thirdparty/jsoncpp/src/jsontestrunner/main.d 


# Each subdirectory must supply rules for building sources it contributes
include/rapidjson1/thirdparty/jsoncpp/src/jsontestrunner/%.o: ../include/rapidjson1/thirdparty/jsoncpp/src/jsontestrunner/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


