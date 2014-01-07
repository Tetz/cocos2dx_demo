################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/psnames/psmodule.c \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/psnames/psnames.c \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/psnames/pspic.c 

OBJS += \
./cocos2dx/platform/third_party/marmalade/freetype/src/psnames/psmodule.o \
./cocos2dx/platform/third_party/marmalade/freetype/src/psnames/psnames.o \
./cocos2dx/platform/third_party/marmalade/freetype/src/psnames/pspic.o 

C_DEPS += \
./cocos2dx/platform/third_party/marmalade/freetype/src/psnames/psmodule.d \
./cocos2dx/platform/third_party/marmalade/freetype/src/psnames/psnames.d \
./cocos2dx/platform/third_party/marmalade/freetype/src/psnames/pspic.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/platform/third_party/marmalade/freetype/src/psnames/psmodule.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/psnames/psmodule.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/marmalade/freetype/src/psnames/psnames.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/psnames/psnames.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/marmalade/freetype/src/psnames/pspic.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/psnames/pspic.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


