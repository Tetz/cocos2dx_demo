################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Armature/animation/CCArmatureAnimation.cpp \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Armature/animation/CCProcessBase.cpp \
/Users/ted/cdroid/cocos/extensions/CocoStudio/Armature/animation/CCTween.cpp 

OBJS += \
./extensions/CocoStudio/Armature/animation/CCArmatureAnimation.o \
./extensions/CocoStudio/Armature/animation/CCProcessBase.o \
./extensions/CocoStudio/Armature/animation/CCTween.o 

CPP_DEPS += \
./extensions/CocoStudio/Armature/animation/CCArmatureAnimation.d \
./extensions/CocoStudio/Armature/animation/CCProcessBase.d \
./extensions/CocoStudio/Armature/animation/CCTween.d 


# Each subdirectory must supply rules for building sources it contributes
extensions/CocoStudio/Armature/animation/CCArmatureAnimation.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Armature/animation/CCArmatureAnimation.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/CocoStudio/Armature/animation/CCProcessBase.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Armature/animation/CCProcessBase.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

extensions/CocoStudio/Armature/animation/CCTween.o: /Users/ted/cdroid/cocos/extensions/CocoStudio/Armature/animation/CCTween.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


