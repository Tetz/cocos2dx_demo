################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/libtiff/headers/tif_stream.cxx 

OBJS += \
./cocos2dx/platform/third_party/marmalade/libtiff/headers/tif_stream.o 

CXX_DEPS += \
./cocos2dx/platform/third_party/marmalade/libtiff/headers/tif_stream.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/platform/third_party/marmalade/libtiff/headers/tif_stream.o: /Users/ted/cdroid/cocos/cocos2dx/platform/third_party/marmalade/libtiff/headers/tif_stream.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


