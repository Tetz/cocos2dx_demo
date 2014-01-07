################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/AssetsManager/AssetsManager.cpp 

OBJS += \
./extensions/AssetsManager/AssetsManager.o 

CPP_DEPS += \
./extensions/AssetsManager/AssetsManager.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/AssetsManager/AssetsManager.o: /Users/ted/cdroid/cocos/extensions/AssetsManager/AssetsManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


