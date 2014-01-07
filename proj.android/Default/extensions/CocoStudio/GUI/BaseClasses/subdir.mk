################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/CocoStudio/GUI/BaseClasses/UIRootWidget.cpp \
/Users/ted/cdroid/cocos/extensions/CocoStudio/GUI/BaseClasses/UIWidget.cpp 

OBJS += \
./extensions/CocoStudio/GUI/BaseClasses/UIRootWidget.o \
./extensions/CocoStudio/GUI/BaseClasses/UIWidget.o 

CPP_DEPS += \
./extensions/CocoStudio/GUI/BaseClasses/UIRootWidget.d \
./extensions/CocoStudio/GUI/BaseClasses/UIWidget.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/CocoStudio/GUI/BaseClasses/UIRootWidget.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/GUI/BaseClasses/UIRootWidget.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/CocoStudio/GUI/BaseClasses/UIWidget.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/GUI/BaseClasses/UIWidget.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


