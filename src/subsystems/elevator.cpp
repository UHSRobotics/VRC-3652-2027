#include "../../include/robot/elevator.hpp"
#include "../../include/globals.hpp"

Elevator::Elevator() {}

float elevator_height = height_conversion_factor * rotation_sensor.get_position();

void Elevator::elevator_movement(float change){
    float setpoint = elevator_height+change;
    if (setpoint > elevator_rotation_max_setpoint*height_conversion_factor || setpoint < elevator_rotation_min_setpoint){
        return;
    }
    while (elevator_height < setpoint * (1-margin_of_error) && elevator_height > setpoint * (1+margin_of_error)){
        if (elevator_height < setpoint)
        {
            elevator.move_velocity(127);
        }
        else if (elevator_height > setpoint)
        {
            elevator.move_velocity(-127);
        }
        else{
            elevator.move_velocity(0);
        }
    }
}
