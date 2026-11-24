#pragma once

#include "pros/misc.hpp"

class Intake {
public:
    Intake();
    void moveForward(int velocity);
    void moveBackward(int velocity);
    void holdControl(bool in, bool out);
    void stop();
    bool isActive() const;
    void activate();
    void deactivate();
};