#include "main.h"
#include "subsystems.hpp"

void intake(int speed) {

    if (speed > 0)
        intake.move(speed);
        conveyor.move(speed);

    if (speed > 0)
        intake.move(speed);
        conveyor.move(speed);

    if (speed = 0)
        intake.move(speed);
        conveyor.move(speed);
}

bool intakeRunning = false; // Tracks if intake is running forward
bool reverseMode = false;   // Tracks if LEFT was pressed to reverse intake/conveyor

void intakecontrol() {
    // Press X: Run intake & conveyor forward
    if (master.get_digital_new_press(DIGITAL_R2) && !intakeRunning) {
        intake.move(127);
        conveyor.move(127);
        intakeRunning = true;
        reverseMode = false; // Disable reverse mode
    } 
    
    // Press LEFT: Enable reverse mode (intake forward, conveyor backward)
   
    else if (master.get_digital_new_press(DIGITAL_R1) && !reverseMode) {
        intake.move(127);  // Intake moves forward
        conveyor.move(-127); // Conveyor moves backward
        reverseMode = true; // Set reverse mode
        intakeRunning = false; // Ensure forward mode is off
    }

    
    // Press A: Stop everything (resets both modes)
    else if (master.get_digital_new_press(DIGITAL_A)) {
        intake.move(0);
        conveyor.move(0);
        intakeRunning = false;
        reverseMode = false;
    }
}

int main() {
    while (true) {
        intakecontrol();  // Continuously check for intake control input
        pros::delay(20);  // Small delay for stability
    }
}