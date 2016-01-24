################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/ADefensesSubsystem.cpp \
../src/Subsystems/DriveSubsystem.cpp \
../src/Subsystems/IntakeSubsystem.cpp \
../src/Subsystems/RollerSubsystem.cpp \
../src/Subsystems/ScalerSubsystem.cpp 

OBJS += \
./src/Subsystems/ADefensesSubsystem.o \
./src/Subsystems/DriveSubsystem.o \
./src/Subsystems/IntakeSubsystem.o \
./src/Subsystems/RollerSubsystem.o \
./src/Subsystems/ScalerSubsystem.o 

CPP_DEPS += \
./src/Subsystems/ADefensesSubsystem.d \
./src/Subsystems/DriveSubsystem.d \
./src/Subsystems/IntakeSubsystem.d \
./src/Subsystems/RollerSubsystem.d \
./src/Subsystems/ScalerSubsystem.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Robotics-1\workspace\Robot2016/src" -IC:\Users\Robotics-1/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


