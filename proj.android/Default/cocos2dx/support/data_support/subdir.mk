################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/support/data_support/ccCArray.cpp 

OBJS += \
./cocos2dx/support/data_support/ccCArray.o 

CPP_DEPS += \
./cocos2dx/support/data_support/ccCArray.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/support/data_support/ccCArray.o: /Users/ted/cdroid/cocos/cocos2dx/support/data_support/ccCArray.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


