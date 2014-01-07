################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdf.c \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdfdrivr.c \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdflib.c 

OBJS += \
./cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdf.o \
./cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdfdrivr.o \
./cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdflib.o 

C_DEPS += \
./cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdf.d \
./cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdfdrivr.d \
./cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdflib.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdf.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdf.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdfdrivr.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdfdrivr.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdflib.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/freetype/src/bdf/bdflib.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


