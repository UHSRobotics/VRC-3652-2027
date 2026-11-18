#pragma once

#include "pros/misc.hpp"

class Intake {
public:
    Intake();
    void moveForward(int velocity);
    void moveBackward(int velocity);
    void holdControl(pros::controller_digital_e_t intakeButton,pros::controller_digital_e_t outtakeButton);
    void stop();
    bool isActive() const;
    void activate();
    void deactivate();
};