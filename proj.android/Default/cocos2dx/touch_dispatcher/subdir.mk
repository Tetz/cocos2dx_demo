################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/touch_dispatcher/CCTouch.cpp \
/Users/ted/cdroid/cocos/cocos2dx/touch_dispatcher/CCTouchDispatcher.cpp \
/Users/ted/cdroid/cocos/cocos2dx/touch_dispatcher/CCTouchHandler.cpp 

OBJS += \
./cocos2dx/touch_dispatcher/CCTouch.o \
./cocos2dx/touch_dispatcher/CCTouchDispatcher.o \
./cocos2dx/touch_dispatcher/CCTouchHandler.o 

CPP_DEPS += \
./cocos2dx/touch_dispatcher/CCTouch.d \
./cocos2dx/touch_dispatcher/CCTouchDispatcher.d \
./cocos2dx/touch_dispatcher/CCTouchHandler.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/touch_dispatcher/CCTouch.o: /Users/ted/cdroid/cocos/cocos2dx/touch_dispatcher/CCTouch.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/touch_dispatcher/CCTouchDispatcher.o: /Users/ted/cdroid/cocos/cocos2dx/touch_dispatcher/CCTouchDispatcher.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/touch_dispatcher/CCTouchHandler.o: /Users/ted/cdroid/cocos/cocos2dx/touch_dispatcher/CCTouchHandler.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


