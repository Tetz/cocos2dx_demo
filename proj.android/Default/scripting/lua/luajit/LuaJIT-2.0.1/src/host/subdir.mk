################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm.c \
/Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_asm.c \
/Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_fold.c \
/Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_lib.c \
/Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_peobj.c \
/Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/minilua.c 

OBJS += \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm.o \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_asm.o \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_fold.o \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_lib.o \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_peobj.o \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/minilua.o 

C_DEPS += \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm.d \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_asm.d \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_fold.d \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_lib.d \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_peobj.d \
./scripting/lua/luajit/LuaJIT-2.0.1/src/host/minilua.d 


# Each subdirectory must supply rules for building sources it contributes
scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm.o: /Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_asm.o: /Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_asm.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_fold.o: /Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_fold.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_lib.o: /Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_lib.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_peobj.o: /Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/buildvm_peobj.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scripting/lua/luajit/LuaJIT-2.0.1/src/host/minilua.o: /Users/ted/cdroid/cocos/scripting/lua/luajit/LuaJIT-2.0.1/src/host/minilua.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


