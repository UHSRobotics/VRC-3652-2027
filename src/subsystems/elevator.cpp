#include "../../include/robot/elevator.hpp"
#include "../../include/globals.hpp"

Elevator::Elevator() {}

void Elevator::elevator_movement(bool UP, bool DOWN){
    if (UP)
    {
        elevator.move_velocity(127);
    }
    else if (DOWN)
    {
        elevator.move_velocity(-127);
    }
    else{
        elevator.move_velocity(0);
    }
}
