################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/proj.win32/Win32InputBox.cpp 

OBJS += \
./extensions/proj.win32/Win32InputBox.o 

CPP_DEPS += \
./extensions/proj.win32/Win32InputBox.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/proj.win32/Win32InputBox.o: /Users/ted/cdroid/cocos/extensions/proj.win32/Win32InputBox.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


