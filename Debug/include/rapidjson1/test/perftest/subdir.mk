################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/rapidjson1/test/perftest/jsoncpptest.cpp \
../include/rapidjson1/test/perftest/misctest.cpp \
../include/rapidjson1/test/perftest/perftest.cpp \
../include/rapidjson1/test/perftest/platformtest.cpp \
../include/rapidjson1/test/perftest/rapidjsontest.cpp \
../include/rapidjson1/test/perftest/ultrajsontest.cpp \
../include/rapidjson1/test/perftest/yajltest.cpp 

C_SRCS += \
../include/rapidjson1/test/perftest/yajl_all.c 

OBJS += \
./include/rapidjson1/test/perftest/jsoncpptest.o \
./include/rapidjson1/test/perftest/misctest.o \
./include/rapidjson1/test/perftest/perftest.o \
./include/rapidjson1/test/perftest/platformtest.o \
./include/rapidjson1/test/perftest/rapidjsontest.o \
./include/rapidjson1/test/perftest/ultrajsontest.o \
./include/rapidjson1/test/perftest/yajl_all.o \
./include/rapidjson1/test/perftest/yajltest.o 

C_DEPS += \
./include/rapidjson1/test/perftest/yajl_all.d 

CPP_DEPS += \
./include/rapidjson1/test/perftest/jsoncpptest.d \
./include/rapidjson1/test/perftest/misctest.d \
./include/rapidjson1/test/perftest/perftest.d \
./include/rapidjson1/test/perftest/platformtest.d \
./include/rapidjson1/test/perftest/rapidjsontest.d \
./include/rapidjson1/test/perftest/ultrajsontest.d \
./include/rapidjson1/test/perftest/yajltest.d 


# Each subdirectory must supply rules for building sources it contributes
include/rapidjson1/test/perftest/%.o: ../include/rapidjson1/test/perftest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

include/rapidjson1/test/perftest/%.o: ../include/rapidjson1/test/perftest/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


