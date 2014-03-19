################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/tests/compiler_tests/ExpressionLimit_test.cpp \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/tests/compiler_tests/VariablePacker_test.cpp 

OBJS += \
./cocos2dx/platform/third_party/winrt/angleproject/tests/compiler_tests/ExpressionLimit_test.o \
./cocos2dx/platform/third_party/winrt/angleproject/tests/compiler_tests/VariablePacker_test.o 

CPP_DEPS += \
./cocos2dx/platform/third_party/winrt/angleproject/tests/compiler_tests/ExpressionLimit_test.d \
./cocos2dx/platform/third_party/winrt/angleproject/tests/compiler_tests/VariablePacker_test.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/platform/third_party/winrt/angleproject/tests/compiler_tests/ExpressionLimit_test.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/tests/compiler_tests/ExpressionLimit_test.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/winrt/angleproject/tests/compiler_tests/VariablePacker_test.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/tests/compiler_tests/VariablePacker_test.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


