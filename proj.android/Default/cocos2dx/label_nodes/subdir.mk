################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/label_nodes/CCLabelAtlas.cpp \
/Users/ted/cdroid/cocos/cocos2dx/label_nodes/CCLabelBMFont.cpp \
/Users/ted/cdroid/cocos/cocos2dx/label_nodes/CCLabelTTF.cpp 

OBJS += \
./cocos2dx/label_nodes/CCLabelAtlas.o \
./cocos2dx/label_nodes/CCLabelBMFont.o \
./cocos2dx/label_nodes/CCLabelTTF.o 

CPP_DEPS += \
./cocos2dx/label_nodes/CCLabelAtlas.d \
./cocos2dx/label_nodes/CCLabelBMFont.d \
./cocos2dx/label_nodes/CCLabelTTF.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/label_nodes/CCLabelAtlas.o: /Users/ted/cdroid/cocos/cocos2dx/label_nodes/CCLabelAtlas.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/label_nodes/CCLabelBMFont.o: /Users/ted/cdroid/cocos/cocos2dx/label_nodes/CCLabelBMFont.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/label_nodes/CCLabelTTF.o: /Users/ted/cdroid/cocos/cocos2dx/label_nodes/CCLabelTTF.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


