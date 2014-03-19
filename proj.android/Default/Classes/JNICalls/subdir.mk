################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/projects/MessagePlus/Classes/JNICalls/InterfaceJNI.cpp 

OBJS += \
./Classes/JNICalls/InterfaceJNI.o 

CPP_DEPS += \
./Classes/JNICalls/InterfaceJNI.d 


# Each subdirectory must supply rules for building sources it contributes
Classes/JNICalls/InterfaceJNI.o: /Users/ted/cdroid/cocos/projects/MessagePlus/Classes/JNICalls/InterfaceJNI.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


