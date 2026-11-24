#include "../../include/robot/intake.hpp"
#include "../../include/globals.hpp"

Intake::Intake() {
    isIntakeActive = false;
}

void Intake::moveForward(int velocity) {
    intakeMotor.move(velocity);
}

void Intake::moveBackward(int velocity) {
    intakeMotor.move(-velocity);
}

void Intake::stop() {
    intakeMotor.move(0);
}

bool Intake::isActive() const {
    return isIntakeActive;
}

void Intake::activate() {
    isIntakeActive = true;
    moveForward(127);
}

void Intake::deactivate() {
    isIntakeActive = false;
    stop();
}

void Intake::holdControl(
    bool in, 
    bool out) {
    if (in) 
    {
        activate();
    }
    else if (out) 
    {
        isIntakeActive = true;
        moveBackward(127);
    }
    else 
    {
        deactivate();
    }
}