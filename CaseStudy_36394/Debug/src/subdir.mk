################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bill.cpp \
../src/Customer.cpp \
../src/Exception.cpp \
../src/Maintainance.cpp \
../src/Oil.cpp \
../src/Part.cpp \
../src/Service.cpp \
../src/ServiceRequest.cpp \
../src/ServiceStation.cpp \
../src/Vehicle.cpp \
../src/main.cpp 

OBJS += \
./src/Bill.o \
./src/Customer.o \
./src/Exception.o \
./src/Maintainance.o \
./src/Oil.o \
./src/Part.o \
./src/Service.o \
./src/ServiceRequest.o \
./src/ServiceStation.o \
./src/Vehicle.o \
./src/main.o 

CPP_DEPS += \
./src/Bill.d \
./src/Customer.d \
./src/Exception.d \
./src/Maintainance.d \
./src/Oil.d \
./src/Part.d \
./src/Service.d \
./src/ServiceRequest.d \
./src/ServiceStation.d \
./src/Vehicle.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


