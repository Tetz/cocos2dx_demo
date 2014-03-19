################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/shaders/CCGLProgram.cpp \
/Users/ted/cdroid/cocos/cocos2dx/shaders/CCShaderCache.cpp \
/Users/ted/cdroid/cocos/cocos2dx/shaders/ccGLStateCache.cpp \
/Users/ted/cdroid/cocos/cocos2dx/shaders/ccShaders.cpp 

OBJS += \
./cocos2dx/shaders/CCGLProgram.o \
./cocos2dx/shaders/CCShaderCache.o \
./cocos2dx/shaders/ccGLStateCache.o \
./cocos2dx/shaders/ccShaders.o 

CPP_DEPS += \
./cocos2dx/shaders/CCGLProgram.d \
./cocos2dx/shaders/CCShaderCache.d \
./cocos2dx/shaders/ccGLStateCache.d \
./cocos2dx/shaders/ccShaders.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/shaders/CCGLProgram.o: /Users/ted/cdroid/cocos/cocos2dx/shaders/CCGLProgram.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/shaders/CCShaderCache.o: /Users/ted/cdroid/cocos/cocos2dx/shaders/CCShaderCache.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/shaders/ccGLStateCache.o: /Users/ted/cdroid/cocos/cocos2dx/shaders/ccGLStateCache.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/shaders/ccShaders.o: /Users/ted/cdroid/cocos/cocos2dx/shaders/ccShaders.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


