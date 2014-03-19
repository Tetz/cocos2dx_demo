################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/base_nodes/CCAtlasNode.cpp \
/Users/ted/cdroid/cocos/cocos2dx/base_nodes/CCGLBufferedNode.cpp \
/Users/ted/cdroid/cocos/cocos2dx/base_nodes/CCNode.cpp 

OBJS += \
./cocos2dx/base_nodes/CCAtlasNode.o \
./cocos2dx/base_nodes/CCGLBufferedNode.o \
./cocos2dx/base_nodes/CCNode.o 

CPP_DEPS += \
./cocos2dx/base_nodes/CCAtlasNode.d \
./cocos2dx/base_nodes/CCGLBufferedNode.d \
./cocos2dx/base_nodes/CCNode.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/base_nodes/CCAtlasNode.o: /Users/ted/cdroid/cocos/cocos2dx/base_nodes/CCAtlasNode.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/base_nodes/CCGLBufferedNode.o: /Users/ted/cdroid/cocos/cocos2dx/base_nodes/CCGLBufferedNode.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/base_nodes/CCNode.o: /Users/ted/cdroid/cocos/cocos2dx/base_nodes/CCNode.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


