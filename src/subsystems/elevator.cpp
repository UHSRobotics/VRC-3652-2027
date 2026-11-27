#include "../../include/robot/elevator.hpp"
#include "../../include/globals.hpp"

Elevator::Elevator() {
    setpoint = 0;
    previous_change = 0;
}

void Elevator::elevator_movement(float change, float speed){
    if (change == 0)
    {
        elevator.move_velocity(0);
        previous_change = 0;
        return;
    }
    float elevator_position = rotation_sensor.get_position();
    float elevator_height = height_conversion_factor * elevator_position;
    float maximum_height = elevator_rotation_max_setpoint * height_conversion_factor;
    float minimum_height = elevator_rotation_min_setpoint * height_conversion_factor;

    if (previous_change == 0 || (previous_change > 0 && change < 0) || (previous_change < 0 && change > 0))
    {
        setpoint = elevator_height + change;
    }

    previous_change = change;
    if (setpoint > maximum_height)
    {
        setpoint = maximum_height;
    }
    else if (setpoint < minimum_height)
    {
        setpoint = minimum_height;
    }

    if (change > 0 && elevator_height < setpoint * (1 - margin_of_error))
    {
        elevator.move_velocity(speed);
    }
    else if (change < 0 && elevator_height > setpoint * (1 + margin_of_error))
    {
        elevator.move_velocity(-speed);
    }
    else
    {
        elevator.move_velocity(0);
        previous_change = 0;
    }
}