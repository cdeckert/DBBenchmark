################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/rapidjson1/test/unittest/documenttest.cpp \
../include/rapidjson1/test/unittest/encodedstreamtest.cpp \
../include/rapidjson1/test/unittest/encodingstest.cpp \
../include/rapidjson1/test/unittest/filestreamtest.cpp \
../include/rapidjson1/test/unittest/jsoncheckertest.cpp \
../include/rapidjson1/test/unittest/readertest.cpp \
../include/rapidjson1/test/unittest/unittest.cpp \
../include/rapidjson1/test/unittest/valuetest.cpp \
../include/rapidjson1/test/unittest/writertest.cpp 

OBJS += \
./include/rapidjson1/test/unittest/documenttest.o \
./include/rapidjson1/test/unittest/encodedstreamtest.o \
./include/rapidjson1/test/unittest/encodingstest.o \
./include/rapidjson1/test/unittest/filestreamtest.o \
./include/rapidjson1/test/unittest/jsoncheckertest.o \
./include/rapidjson1/test/unittest/readertest.o \
./include/rapidjson1/test/unittest/unittest.o \
./include/rapidjson1/test/unittest/valuetest.o \
./include/rapidjson1/test/unittest/writertest.o 

CPP_DEPS += \
./include/rapidjson1/test/unittest/documenttest.d \
./include/rapidjson1/test/unittest/encodedstreamtest.d \
./include/rapidjson1/test/unittest/encodingstest.d \
./include/rapidjson1/test/unittest/filestreamtest.d \
./include/rapidjson1/test/unittest/jsoncheckertest.d \
./include/rapidjson1/test/unittest/readertest.d \
./include/rapidjson1/test/unittest/unittest.d \
./include/rapidjson1/test/unittest/valuetest.d \
./include/rapidjson1/test/unittest/writertest.d 


# Each subdirectory must supply rules for building sources it contributes
include/rapidjson1/test/unittest/%.o: ../include/rapidjson1/test/unittest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


