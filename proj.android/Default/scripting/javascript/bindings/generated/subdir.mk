################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/scripting/javascript/bindings/generated/jsb_cocos2dx_auto.cpp \
/Users/ted/cdroid/cocos/scripting/javascript/bindings/generated/jsb_cocos2dx_extension_auto.cpp \
/Users/ted/cdroid/cocos/scripting/javascript/bindings/generated/jsb_cocos2dx_studio_auto.cpp 

OBJS += \
./scripting/javascript/bindings/generated/jsb_cocos2dx_auto.o \
./scripting/javascript/bindings/generated/jsb_cocos2dx_extension_auto.o \
./scripting/javascript/bindings/generated/jsb_cocos2dx_studio_auto.o 

CPP_DEPS += \
./scripting/javascript/bindings/generated/jsb_cocos2dx_auto.d \
./scripting/javascript/bindings/generated/jsb_cocos2dx_extension_auto.d \
./scripting/javascript/bindings/generated/jsb_cocos2dx_studio_auto.d 


# Each subdirectory must supply rules for building sources it contributes
scripting/javascript/bindings/generated/jsb_cocos2dx_auto.o: /Users/ted/cdroid/cocos/scripting/javascript/bindings/generated/jsb_cocos2dx_auto.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scripting/javascript/bindings/generated/jsb_cocos2dx_extension_auto.o: /Users/ted/cdroid/cocos/scripting/javascript/bindings/generated/jsb_cocos2dx_extension_auto.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scripting/javascript/bindings/generated/jsb_cocos2dx_studio_auto.o: /Users/ted/cdroid/cocos/scripting/javascript/bindings/generated/jsb_cocos2dx_studio_auto.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


