################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/platform/ios/CCLock.cpp 

OBJS += \
./cocos2dx/platform/ios/CCLock.o 

CPP_DEPS += \
./cocos2dx/platform/ios/CCLock.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/platform/ios/CCLock.o: /Users/ted/cdroid/cocos/cocos2dx/platform/ios/CCLock.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


