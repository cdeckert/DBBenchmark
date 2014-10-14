################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../include/rapidjson1/thirdparty/yajl/src/yajl.c \
../include/rapidjson1/thirdparty/yajl/src/yajl_alloc.c \
../include/rapidjson1/thirdparty/yajl/src/yajl_buf.c \
../include/rapidjson1/thirdparty/yajl/src/yajl_encode.c \
../include/rapidjson1/thirdparty/yajl/src/yajl_gen.c \
../include/rapidjson1/thirdparty/yajl/src/yajl_lex.c \
../include/rapidjson1/thirdparty/yajl/src/yajl_parser.c \
../include/rapidjson1/thirdparty/yajl/src/yajl_tree.c \
../include/rapidjson1/thirdparty/yajl/src/yajl_version.c 

OBJS += \
./include/rapidjson1/thirdparty/yajl/src/yajl.o \
./include/rapidjson1/thirdparty/yajl/src/yajl_alloc.o \
./include/rapidjson1/thirdparty/yajl/src/yajl_buf.o \
./include/rapidjson1/thirdparty/yajl/src/yajl_encode.o \
./include/rapidjson1/thirdparty/yajl/src/yajl_gen.o \
./include/rapidjson1/thirdparty/yajl/src/yajl_lex.o \
./include/rapidjson1/thirdparty/yajl/src/yajl_parser.o \
./include/rapidjson1/thirdparty/yajl/src/yajl_tree.o \
./include/rapidjson1/thirdparty/yajl/src/yajl_version.o 

C_DEPS += \
./include/rapidjson1/thirdparty/yajl/src/yajl.d \
./include/rapidjson1/thirdparty/yajl/src/yajl_alloc.d \
./include/rapidjson1/thirdparty/yajl/src/yajl_buf.d \
./include/rapidjson1/thirdparty/yajl/src/yajl_encode.d \
./include/rapidjson1/thirdparty/yajl/src/yajl_gen.d \
./include/rapidjson1/thirdparty/yajl/src/yajl_lex.d \
./include/rapidjson1/thirdparty/yajl/src/yajl_parser.d \
./include/rapidjson1/thirdparty/yajl/src/yajl_tree.d \
./include/rapidjson1/thirdparty/yajl/src/yajl_version.d 


# Each subdirectory must supply rules for building sources it contributes
include/rapidjson1/thirdparty/yajl/src/%.o: ../include/rapidjson1/thirdparty/yajl/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


