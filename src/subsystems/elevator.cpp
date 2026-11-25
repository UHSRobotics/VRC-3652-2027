#include "../../include/robot/elevator.hpp"
#include "../../include/globals.hpp"

Elevator::Elevator() {}

void Elevator::elevator_movement(bool UP){
    if (elevatorTopSensor.get_value() || elevatorBottomSensor.get_value()){
        elevator.move_velocity(0);
    }
	else if (UP)
	{
		elevator.move_velocity(127);
	}
	else
    {
        elevator.move_velocity(-127);
    }
}
