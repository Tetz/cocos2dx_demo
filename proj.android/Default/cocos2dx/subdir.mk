################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/CCCamera.cpp \
/Users/ted/cdroid/cocos/cocos2dx/CCConfiguration.cpp \
/Users/ted/cdroid/cocos/cocos2dx/CCDirector.cpp \
/Users/ted/cdroid/cocos/cocos2dx/CCScheduler.cpp \
/Users/ted/cdroid/cocos/cocos2dx/cocos2d.cpp 

C_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/ccFPSImages.c 

OBJS += \
./cocos2dx/CCCamera.o \
./cocos2dx/CCConfiguration.o \
./cocos2dx/CCDirector.o \
./cocos2dx/CCScheduler.o \
./cocos2dx/ccFPSImages.o \
./cocos2dx/cocos2d.o 

C_DEPS += \
./cocos2dx/ccFPSImages.d 

CPP_DEPS += \
./cocos2dx/CCCamera.d \
./cocos2dx/CCConfiguration.d \
./cocos2dx/CCDirector.d \
./cocos2dx/CCScheduler.d \
./cocos2dx/cocos2d.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/CCCamera.o: /Users/ted/cdroid/cocos/cocos2dx/CCCamera.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/CCConfiguration.o: /Users/ted/cdroid/cocos/cocos2dx/CCConfiguration.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/CCDirector.o: /Users/ted/cdroid/cocos/cocos2dx/CCDirector.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/CCScheduler.o: /Users/ted/cdroid/cocos/cocos2dx/CCScheduler.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/ccFPSImages.o: /Users/ted/cdroid/cocos/cocos2dx/ccFPSImages.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/cocos2d.o: /Users/ted/cdroid/cocos/cocos2dx/cocos2d.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


