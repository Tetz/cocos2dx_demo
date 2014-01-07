################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/ted/cdroid/cocos/cocos2dx/particle_nodes/CCParticleBatchNode.cpp \
/Users/ted/cdroid/cocos/cocos2dx/particle_nodes/CCParticleExamples.cpp \
/Users/ted/cdroid/cocos/cocos2dx/particle_nodes/CCParticleSystem.cpp \
/Users/ted/cdroid/cocos/cocos2dx/particle_nodes/CCParticleSystemQuad.cpp 

OBJS += \
./cocos2dx/particle_nodes/CCParticleBatchNode.o \
./cocos2dx/particle_nodes/CCParticleExamples.o \
./cocos2dx/particle_nodes/CCParticleSystem.o \
./cocos2dx/particle_nodes/CCParticleSystemQuad.o 

CPP_DEPS += \
./cocos2dx/particle_nodes/CCParticleBatchNode.d \
./cocos2dx/particle_nodes/CCParticleExamples.d \
./cocos2dx/particle_nodes/CCParticleSystem.d \
./cocos2dx/particle_nodes/CCParticleSystemQuad.d 


# Each subdirectory must supply rules for building sources it contributes
cocos2dx/particle_nodes/CCParticleBatchNode.o: /Users/ted/cdroid/cocos/cocos2dx/particle_nodes/CCParticleBatchNode.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/particle_nodes/CCParticleExamples.o: /Users/ted/cdroid/cocos/cocos2dx/particle_nodes/CCParticleExamples.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/particle_nodes/CCParticleSystem.o: /Users/ted/cdroid/cocos/cocos2dx/particle_nodes/CCParticleSystem.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cocos2dx/particle_nodes/CCParticleSystemQuad.o: /Users/ted/cdroid/cocos/cocos2dx/particle_nodes/CCParticleSystemQuad.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


