################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/LocalStorage/LocalStorage.cpp \
/Users/ted/cdroid/cocos/extensions/LocalStorage/LocalStorageAndroid.cpp 

OBJS += \
./extensions/LocalStorage/LocalStorage.o \
./extensions/LocalStorage/LocalStorageAndroid.o 

CPP_DEPS += \
./extensions/LocalStorage/LocalStorage.d \
./extensions/LocalStorage/LocalStorageAndroid.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/LocalStorage/LocalStorage.o: /Users/ted/cdroid/cocos/extensions/LocalStorage/LocalStorage.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/LocalStorage/LocalStorageAndroid.o: /Users/ted/cdroid/cocos/extensions/LocalStorage/LocalStorageAndroid.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


