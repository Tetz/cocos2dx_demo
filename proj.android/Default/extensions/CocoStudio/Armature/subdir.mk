################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Armature/CCArmature.cpp \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Armature/CCBone.cpp 

OBJS += \
./extensions/CocoStudio/Armature/CCArmature.o \
./extensions/CocoStudio/Armature/CCBone.o 

CPP_DEPS += \
./extensions/CocoStudio/Armature/CCArmature.d \
./extensions/CocoStudio/Armature/CCBone.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/CocoStudio/Armature/CCArmature.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Armature/CCArmature.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/CocoStudio/Armature/CCBone.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Armature/CCBone.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


