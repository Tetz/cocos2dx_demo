################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/support/zip_support/ZipUtils.cpp \
/Users/ted/cdroid/cocos/cocos2dx/support/zip_support/ioapi.cpp \
/Users/ted/cdroid/cocos/cocos2dx/support/zip_support/unzip.cpp 

OBJS += \
./cocos2dx/support/zip_support/ZipUtils.o \
./cocos2dx/support/zip_support/ioapi.o \
./cocos2dx/support/zip_support/unzip.o 

CPP_DEPS += \
./cocos2dx/support/zip_support/ZipUtils.d \
./cocos2dx/support/zip_support/ioapi.d \
./cocos2dx/support/zip_support/unzip.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/support/zip_support/ZipUtils.o: /Users/ted/cdroid/cocos/cocos2dx/support/zip_support/ZipUtils.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/support/zip_support/ioapi.o: /Users/ted/cdroid/cocos/cocos2dx/support/zip_support/ioapi.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/support/zip_support/unzip.o: /Users/ted/cdroid/cocos/cocos2dx/support/zip_support/unzip.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

