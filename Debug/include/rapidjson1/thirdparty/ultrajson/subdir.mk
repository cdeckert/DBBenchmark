################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../include/rapidjson1/thirdparty/ultrajson/ultrajsondec.c \
../include/rapidjson1/thirdparty/ultrajson/ultrajsonenc.c 

OBJS += \
./include/rapidjson1/thirdparty/ultrajson/ultrajsondec.o \
./include/rapidjson1/thirdparty/ultrajson/ultrajsonenc.o 

C_DEPS += \
./include/rapidjson1/thirdparty/ultrajson/ultrajsondec.d \
./include/rapidjson1/thirdparty/ultrajson/ultrajsonenc.d 


# Each subdirectory must supply rules for building sources it contributes
include/rapidjson1/thirdparty/ultrajson/%.o: ../include/rapidjson1/thirdparty/ultrajson/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


