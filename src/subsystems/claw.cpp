#include <claw.hpp>
#include <globals.hpp>

class Claw {
    public:
        void catches() {
            clawMotor.move_velocity(127);
        }

        void open() {
            clawMotor.move_velocity(-127);
        }

        void tick(bool catchButton, bool openButton) {
            if (catchButton) {
                catches();
            } else
            if (openButton) {
                open();
            } else {
                clawMotor.move_velocity(0);
            }
        }
};