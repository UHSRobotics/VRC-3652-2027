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

        void tick() {
            if (controller.get_digital(DIGITAL_R2)) {
                catches();
            } else
            if (controller.get_digital(DIGITAL_R1)) {
                open();
            } else {
                clawMotor.move_velocity(0);
            }
        }
};