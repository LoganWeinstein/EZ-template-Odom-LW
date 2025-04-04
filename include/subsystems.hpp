#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"


extern Drive chassis;

inline pros::Motor intake(7);
inline pros::MotorGroup conveyor({8,-9}); 
inline pros::Motor bullrush(10);
inline pros::Motor hook(-11);
inline pros::MotorGroup wallstake({12,-13}); 
//Radio in port 20



// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');