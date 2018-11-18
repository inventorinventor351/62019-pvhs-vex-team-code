#include "main.h" //DO NOT TOUCH
#include <vector>

struct wayPoint {

    double leftChassis_Vel,
    rightChassis_Vel;

};

std::vector<wayPoint> red_flagSide_4flags_2caps;

wayPoint initWayPoint(double leftChassis_Vel, double rightChassis_Vel) {

    return {leftChassis_Vel, rightChassis_Vel};

}

//Runs initialization code. This occurs as soon as the program is started. It is recommended to keep execution time for this mode under a few seconds.
void initialize() {
	


}

//Runs after initialize() and before autonomous. This is intended for competition-specific initialization routines, such as an autonomous selector on the LCD.
void competition_initialize() {



}

//Runs while the robot is in the disabled state of Field Management System or the VEX Competition Switch
void disabled() {



}