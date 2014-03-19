################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/menu_nodes/CCMenu.cpp \
/Users/ted/cdroid/cocos/cocos2dx/menu_nodes/CCMenuItem.cpp 

OBJS += \
./cocos2dx/menu_nodes/CCMenu.o \
./cocos2dx/menu_nodes/CCMenuItem.o 

CPP_DEPS += \
./cocos2dx/menu_nodes/CCMenu.d \
./cocos2dx/menu_nodes/CCMenuItem.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/menu_nodes/CCMenu.o: /Users/ted/cdroid/cocos/cocos2dx/menu_nodes/CCMenu.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/menu_nodes/CCMenuItem.o: /Users/ted/cdroid/cocos/cocos2dx/menu_nodes/CCMenuItem.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


