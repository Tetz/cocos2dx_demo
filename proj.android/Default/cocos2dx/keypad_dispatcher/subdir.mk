################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/keypad_dispatcher/CCKeypadDelegate.cpp \
/Users/ted/cdroid/cocos/cocos2dx/keypad_dispatcher/CCKeypadDispatcher.cpp 

OBJS += \
./cocos2dx/keypad_dispatcher/CCKeypadDelegate.o \
./cocos2dx/keypad_dispatcher/CCKeypadDispatcher.o 

CPP_DEPS += \
./cocos2dx/keypad_dispatcher/CCKeypadDelegate.d \
./cocos2dx/keypad_dispatcher/CCKeypadDispatcher.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/keypad_dispatcher/CCKeypadDelegate.o: /Users/ted/cdroid/cocos/cocos2dx/keypad_dispatcher/CCKeypadDelegate.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/keypad_dispatcher/CCKeypadDispatcher.o: /Users/ted/cdroid/cocos/cocos2dx/keypad_dispatcher/CCKeypadDispatcher.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


