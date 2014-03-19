################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/support/user_default/CCUserDefault.cpp \
/Users/ted/cdroid/cocos/cocos2dx/support/user_default/CCUserDefaultAndroid.cpp 

OBJS += \
./cocos2dx/support/user_default/CCUserDefault.o \
./cocos2dx/support/user_default/CCUserDefaultAndroid.o 

CPP_DEPS += \
./cocos2dx/support/user_default/CCUserDefault.d \
./cocos2dx/support/user_default/CCUserDefaultAndroid.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/support/user_default/CCUserDefault.o: /Users/ted/cdroid/cocos/cocos2dx/support/user_default/CCUserDefault.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/support/user_default/CCUserDefaultAndroid.o: /Users/ted/cdroid/cocos/cocos2dx/support/user_default/CCUserDefaultAndroid.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


