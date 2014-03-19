################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Json/CSContentJsonDictionary.cpp \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Json/DictionaryHelper.cpp 

OBJS += \
./extensions/CocoStudio/Json/CSContentJsonDictionary.o \
./extensions/CocoStudio/Json/DictionaryHelper.o 

CPP_DEPS += \
./extensions/CocoStudio/Json/CSContentJsonDictionary.d \
./extensions/CocoStudio/Json/DictionaryHelper.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/CocoStudio/Json/CSContentJsonDictionary.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Json/CSContentJsonDictionary.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/CocoStudio/Json/DictionaryHelper.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Json/DictionaryHelper.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


