################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/support/component/CCComponent.cpp \
/Users/ted/cdroid/cocos/cocos2dx/support/component/CCComponentContainer.cpp 

OBJS += \
./cocos2dx/support/component/CCComponent.o \
./cocos2dx/support/component/CCComponentContainer.o 

CPP_DEPS += \
./cocos2dx/support/component/CCComponent.d \
./cocos2dx/support/component/CCComponentContainer.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/support/component/CCComponent.o: /Users/ted/cdroid/cocos/cocos2dx/support/component/CCComponent.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/support/component/CCComponentContainer.o: /Users/ted/cdroid/cocos/cocos2dx/support/component/CCComponentContainer.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


