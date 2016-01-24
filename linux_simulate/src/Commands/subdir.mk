################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/ADefensesGoToAngle.cpp \
../src/Commands/AutoDoNothing.cpp \
../src/Commands/IntakeIn.cpp \
../src/Commands/IntakeOut.cpp \
../src/Commands/OperatorDrive.cpp \
../src/Commands/RollerExtract.cpp \
../src/Commands/RollerSuck.cpp \
../src/Commands/ScalerDeploy.cpp \
../src/Commands/ScalerRetract.cpp 

OBJS += \
./src/Commands/ADefensesGoToAngle.o \
./src/Commands/AutoDoNothing.o \
./src/Commands/IntakeIn.o \
./src/Commands/IntakeOut.o \
./src/Commands/OperatorDrive.o \
./src/Commands/RollerExtract.o \
./src/Commands/RollerSuck.o \
./src/Commands/ScalerDeploy.o \
./src/Commands/ScalerRetract.o 

CPP_DEPS += \
./src/Commands/ADefensesGoToAngle.d \
./src/Commands/AutoDoNothing.d \
./src/Commands/IntakeIn.d \
./src/Commands/IntakeOut.d \
./src/Commands/OperatorDrive.d \
./src/Commands/RollerExtract.d \
./src/Commands/RollerSuck.d \
./src/Commands/ScalerDeploy.d \
./src/Commands/ScalerRetract.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/%.o: ../src/Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Robotics-1\workspace\Robot2016/src" -IC:\Users\Robotics-1/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


