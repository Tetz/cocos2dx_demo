################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_TGA_winrt.cpp \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_win32_winrt.cpp 

C_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_TGA.c \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_win32.c 

OBJS += \
./cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_TGA.o \
./cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_TGA_winrt.o \
./cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_win32.o \
./cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_win32_winrt.o 

C_DEPS += \
./cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_TGA.d \
./cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_win32.d 

CPP_DEPS += \
./cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_TGA_winrt.d \
./cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_win32_winrt.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_TGA.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_TGA.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_TGA_winrt.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_TGA_winrt.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_win32.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_win32.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_win32_winrt.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/winrt/angleproject/samples/gles2_book/Common/Win32/esUtil_win32_winrt.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


