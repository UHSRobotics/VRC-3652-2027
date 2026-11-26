 #include "globals.hpp"
 #include "robot/claw.hpp"
 Claw::Claw() {}
 void Claw::intake(int velocity) {
    if (DIGITAL_X){
    clawMotor.move(127);
    }
    else if (DIGITAL_B){
    clawMotor.move(-127);
    }
     
 }