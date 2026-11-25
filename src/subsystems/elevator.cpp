#include "include/elevator.hpp"
#include "../include/globals.hpp"
#include "main.h"

// #define pros::Motor_Group elevatorMotors({elevatorMotor0, elevatorMotor1});

void handleElevator(void) {
	if (controller.get_digital(DIGITAL_UP)) {
		elevatorMotors.move(127);
		handleElevatorSenser();
	} else if (controller.get_digital(DIGITAL_DOWN)) {
		elevatorMotors.move(127);
		handleElevatorSenser();
	}
}
