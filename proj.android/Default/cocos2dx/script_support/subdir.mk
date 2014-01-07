################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/script_support/CCScriptSupport.cpp 

OBJS += \
./cocos2dx/script_support/CCScriptSupport.o 

CPP_DEPS += \
./cocos2dx/script_support/CCScriptSupport.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/script_support/CCScriptSupport.o: /Users/ted/cdroid/cocos/cocos2dx/script_support/CCScriptSupport.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


