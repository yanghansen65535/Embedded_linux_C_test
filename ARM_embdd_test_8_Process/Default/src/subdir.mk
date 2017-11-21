################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SP_test1_open_close.c \
../src/process_test1.c \
../src/process_test2_exit.c \
../src/process_test3_pipe.c \
../src/process_test4_shm.c \
../src/test_main.c \
../src/thread_test1_create.c \
../src/thread_test2_wait.c 

OBJS += \
./src/SP_test1_open_close.o \
./src/process_test1.o \
./src/process_test2_exit.o \
./src/process_test3_pipe.o \
./src/process_test4_shm.o \
./src/test_main.o \
./src/thread_test1_create.o \
./src/thread_test2_wait.o 

C_DEPS += \
./src/SP_test1_open_close.d \
./src/process_test1.d \
./src/process_test2_exit.d \
./src/process_test3_pipe.d \
./src/process_test4_shm.d \
./src/test_main.d \
./src/thread_test1_create.d \
./src/thread_test2_wait.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


