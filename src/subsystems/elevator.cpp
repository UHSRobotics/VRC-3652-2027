#include "../../include/robot/elevator.hpp"
#include "../../include/globals.hpp"

Elevator::Elevator() {}

void Elevator::elevator_movement(bool UP){
    if (UP)
    {
        elevator.move_velocity(127);
    }
    else
    {
        elevator.move_velocity(-127);
    }
}
