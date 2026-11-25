#include "../../include/robot/elevator.hpp"
#include "../../include/globals.hpp"

#define UPPER_DIGITAL_SENSOR_PORT 1 // define port
#define LOWER_DIGITAL_SENSOR_PORT 2 // define port


Elevator::Elevator() {}

void Elevator::elevator_movement(bool UP){
    pros::ADIDigitalIn button_up (UPPER_DIGITAL_SENSOR_PORT);
    pros::ADIDigitalIn button_down (LOWER_DIGITAL_SENSOR_PORT);
    if (UP)
    {
        while(!button_up.get_value())
        {
        elevator.move_velocity(127);
        }
        elevator.move_velocity(0);
    }
    else
    {
        while(!button_down.get_value())
        {
        elevator.move_velocity(-127);
        }
        elevator.move_velocity(0);
    }
}
