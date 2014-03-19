################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/kazmath/src/GL/mat4stack.c \
/Users/ted/cdroid/cocos/cocos2dx/kazmath/src/GL/matrix.c 

OBJS += \
./cocos2dx/kazmath/src/GL/mat4stack.o \
./cocos2dx/kazmath/src/GL/matrix.o 

C_DEPS += \
./cocos2dx/kazmath/src/GL/mat4stack.d \
./cocos2dx/kazmath/src/GL/matrix.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/kazmath/src/GL/mat4stack.o: /Users/ted/cdroid/cocos/cocos2dx/kazmath/src/GL/mat4stack.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/kazmath/src/GL/matrix.o: /Users/ted/cdroid/cocos/cocos2dx/kazmath/src/GL/matrix.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


