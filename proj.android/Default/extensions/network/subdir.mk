################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/network/HttpClient.cpp \
/Users/ted/cdroid/cocos/extensions/network/WebSocket.cpp 

OBJS += \
./extensions/network/HttpClient.o \
./extensions/network/WebSocket.o 

CPP_DEPS += \
./extensions/network/HttpClient.d \
./extensions/network/WebSocket.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/network/HttpClient.o: /Users/ted/cdroid/cocos/extensions/network/HttpClient.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/network/WebSocket.o: /Users/ted/cdroid/cocos/extensions/network/WebSocket.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


