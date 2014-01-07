################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Json/lib_json/json_reader.cpp \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Json/lib_json/json_value.cpp \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Json/lib_json/json_writer.cpp 

OBJS += \
./extensions/CocoStudio/Json/lib_json/json_reader.o \
./extensions/CocoStudio/Json/lib_json/json_value.o \
./extensions/CocoStudio/Json/lib_json/json_writer.o 

CPP_DEPS += \
./extensions/CocoStudio/Json/lib_json/json_reader.d \
./extensions/CocoStudio/Json/lib_json/json_value.d \
./extensions/CocoStudio/Json/lib_json/json_writer.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/CocoStudio/Json/lib_json/json_reader.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Json/lib_json/json_reader.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/CocoStudio/Json/lib_json/json_value.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Json/lib_json/json_value.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/CocoStudio/Json/lib_json/json_writer.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Json/lib_json/json_writer.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


