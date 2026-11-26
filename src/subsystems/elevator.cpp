#include "../../include/robot/elevator.hpp"
#include "../../include/globals.hpp"

Elevator::Elevator() {
    elevator.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void Elevator::elevator_movement(bool UP, bool DOWN){
    if (UP)
    {
        elevator.move_velocity(127);
        elevator.brake();
    }
    else if (DOWN)
    {
        elevator.move_velocity(-127);
        elevator.brake();
    }
    else{
        elevator.move_velocity(0);
    }
}
