################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Util/Configurator.cpp \
../src/Util/Disk.cpp \
../src/Util/Log.cpp \
../src/Util/Progressbar.cpp \
../src/Util/Randomizer.cpp 

OBJS += \
./src/Util/Configurator.o \
./src/Util/Disk.o \
./src/Util/Log.o \
./src/Util/Progressbar.o \
./src/Util/Randomizer.o 

CPP_DEPS += \
./src/Util/Configurator.d \
./src/Util/Disk.d \
./src/Util/Log.d \
./src/Util/Progressbar.d \
./src/Util/Randomizer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Util/%.o: ../src/Util/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/christiandeckert/workspace/DBBenchmark/include" -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -pthread -static -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


