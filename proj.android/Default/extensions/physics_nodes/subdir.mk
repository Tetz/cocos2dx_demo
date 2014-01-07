################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/physics_nodes/CCPhysicsDebugNode.cpp \
/Users/ted/cdroid/cocos/extensions/physics_nodes/CCPhysicsSprite.cpp 

OBJS += \
./extensions/physics_nodes/CCPhysicsDebugNode.o \
./extensions/physics_nodes/CCPhysicsSprite.o 

CPP_DEPS += \
./extensions/physics_nodes/CCPhysicsDebugNode.d \
./extensions/physics_nodes/CCPhysicsSprite.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/physics_nodes/CCPhysicsDebugNode.o: /Users/ted/cdroid/cocos/extensions/physics_nodes/CCPhysicsDebugNode.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/physics_nodes/CCPhysicsSprite.o: /Users/ted/cdroid/cocos/extensions/physics_nodes/CCPhysicsSprite.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


