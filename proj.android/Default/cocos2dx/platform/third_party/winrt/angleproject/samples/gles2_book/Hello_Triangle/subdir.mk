################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Hello_Triangle/Hello_Triangle.c 

OBJS += \
./cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Hello_Triangle/Hello_Triangle.o 

C_DEPS += \
./cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Hello_Triangle/Hello_Triangle.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Hello_Triangle/Hello_Triangle.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Hello_Triangle/Hello_Triangle.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


