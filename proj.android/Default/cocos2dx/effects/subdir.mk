################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/effects/CCGrabber.cpp \
/Users/ted/cdroid/cocos/cocos2dx/effects/CCGrid.cpp 

OBJS += \
./cocos2dx/effects/CCGrabber.o \
./cocos2dx/effects/CCGrid.o 

CPP_DEPS += \
./cocos2dx/effects/CCGrabber.d \
./cocos2dx/effects/CCGrid.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/effects/CCGrabber.o: /Users/ted/cdroid/cocos/cocos2dx/effects/CCGrabber.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/effects/CCGrid.o: /Users/ted/cdroid/cocos/cocos2dx/effects/CCGrid.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


