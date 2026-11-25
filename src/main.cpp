#include "main.h"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	pros::lcd::register_btn1_cb(on_center_button);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::MotorGroup left_mg({1, -2, 3});
	pros::MotorGroup right_mg({-4, 5, -6});
	pros::Motor elevator(7);
	elevator.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	while (true) {
		int dir = master.get_analog(ANALOG_LEFT_Y);
		int turn = master.get_analog(ANALOG_RIGHT_X);
		left_mg.move(dir - turn);
		right_mg.move(dir + turn);

		if (master.get_digital(DIGITAL_R1)) {
			elevator.move(127);
		} else if (master.get_digital(DIGITAL_R2)) {
			elevator.move(-127);
		} else {
			elevator.brake();
		}

		pros::delay(20);
	}
}