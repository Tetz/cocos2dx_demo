################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/text_input_node/CCIMEDispatcher.cpp \
/Users/ted/cdroid/cocos/cocos2dx/text_input_node/CCTextFieldTTF.cpp 

OBJS += \
./cocos2dx/text_input_node/CCIMEDispatcher.o \
./cocos2dx/text_input_node/CCTextFieldTTF.o 

CPP_DEPS += \
./cocos2dx/text_input_node/CCIMEDispatcher.d \
./cocos2dx/text_input_node/CCTextFieldTTF.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/text_input_node/CCIMEDispatcher.o: /Users/ted/cdroid/cocos/cocos2dx/text_input_node/CCIMEDispatcher.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/text_input_node/CCTextFieldTTF.o: /Users/ted/cdroid/cocos/cocos2dx/text_input_node/CCTextFieldTTF.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


