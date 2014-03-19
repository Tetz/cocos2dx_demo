################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/draw_nodes/CCDrawNode.cpp \
/Users/ted/cdroid/cocos/cocos2dx/draw_nodes/CCDrawingPrimitives.cpp 

OBJS += \
./cocos2dx/draw_nodes/CCDrawNode.o \
./cocos2dx/draw_nodes/CCDrawingPrimitives.o 

CPP_DEPS += \
./cocos2dx/draw_nodes/CCDrawNode.d \
./cocos2dx/draw_nodes/CCDrawingPrimitives.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/draw_nodes/CCDrawNode.o: /Users/ted/cdroid/cocos/cocos2dx/draw_nodes/CCDrawNode.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/draw_nodes/CCDrawingPrimitives.o: /Users/ted/cdroid/cocos/cocos2dx/draw_nodes/CCDrawingPrimitives.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


