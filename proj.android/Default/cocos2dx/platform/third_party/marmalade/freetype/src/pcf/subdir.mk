################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcf.c \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfdrivr.c \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfread.c \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfutil.c 

OBJS += \
./cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcf.o \
./cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfdrivr.o \
./cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfread.o \
./cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfutil.o 

C_DEPS += \
./cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcf.d \
./cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfdrivr.d \
./cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfread.d \
./cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfutil.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcf.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcf.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfdrivr.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfdrivr.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfread.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfread.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfutil.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/pcf/pcfutil.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


