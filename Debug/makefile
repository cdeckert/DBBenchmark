################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Tests/subdir.mk
-include src/Layout/subdir.mk
-include src/subdir.mk
-include include/rapidjson1/thirdparty/yajl/src/subdir.mk
-include include/rapidjson1/thirdparty/ultrajson/subdir.mk
-include include/rapidjson1/thirdparty/jsoncpp/src/test_lib_json/subdir.mk
-include include/rapidjson1/thirdparty/jsoncpp/src/lib_json/subdir.mk
-include include/rapidjson1/thirdparty/jsoncpp/src/jsontestrunner/subdir.mk
-include include/rapidjson1/test/unittest/subdir.mk
-include include/rapidjson1/test/perftest/subdir.mk
-include include/rapidjson1/example/tutorial/subdir.mk
-include include/rapidjson1/example/simplewriter/subdir.mk
-include include/rapidjson1/example/simplereader/subdir.mk
-include include/rapidjson1/example/simpledom/subdir.mk
-include include/rapidjson1/example/serialize/subdir.mk
-include include/rapidjson1/example/prettyauto/subdir.mk
-include include/rapidjson1/example/pretty/subdir.mk
-include include/rapidjson1/example/messagereader/subdir.mk
-include include/rapidjson1/example/condense/subdir.mk
-include include/rapidjson1/example/capitalize/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: DBBenchmark

# Tool invocations
DBBenchmark: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o "DBBenchmark" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) DBBenchmark
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
