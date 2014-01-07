################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Reader/GUIReader.cpp \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Reader/SceneReader.cpp 

OBJS += \
./extensions/CocoStudio/Reader/GUIReader.o \
./extensions/CocoStudio/Reader/SceneReader.o 

CPP_DEPS += \
./extensions/CocoStudio/Reader/GUIReader.d \
./extensions/CocoStudio/Reader/SceneReader.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/CocoStudio/Reader/GUIReader.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Reader/GUIReader.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/CocoStudio/Reader/SceneReader.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Reader/SceneReader.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


