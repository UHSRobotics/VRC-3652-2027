#include "../../include/robot/drivetrain.hpp"
#include "../../include/globals.hpp"
void ClawMotor::clawMotor(){
	if (controller.get_digital(DIGITAL_L1)){
		clawMotor.move_velocity(127);
	}else if (controller.get_digital(DIGITAL_R1)){
		clawMotor.move_velocity(-127);
	}else{
		clawMotor.move_velocity(0);
	}
}