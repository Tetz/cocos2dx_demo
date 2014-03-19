################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/CocoStudio/GUI/Layouts/UILayout.cpp \
/Users/ted/cdroid/cocos/extensions/CocoStudio/GUI/Layouts/UILayoutDefine.cpp \
/Users/ted/cdroid/cocos/extensions/CocoStudio/GUI/Layouts/UILayoutParameter.cpp 

OBJS += \
./extensions/CocoStudio/GUI/Layouts/UILayout.o \
./extensions/CocoStudio/GUI/Layouts/UILayoutDefine.o \
./extensions/CocoStudio/GUI/Layouts/UILayoutParameter.o 

CPP_DEPS += \
./extensions/CocoStudio/GUI/Layouts/UILayout.d \
./extensions/CocoStudio/GUI/Layouts/UILayoutDefine.d \
./extensions/CocoStudio/GUI/Layouts/UILayoutParameter.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/CocoStudio/GUI/Layouts/UILayout.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/GUI/Layouts/UILayout.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/CocoStudio/GUI/Layouts/UILayoutDefine.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/GUI/Layouts/UILayoutDefine.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/CocoStudio/GUI/Layouts/UILayoutParameter.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/GUI/Layouts/UILayoutParameter.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


