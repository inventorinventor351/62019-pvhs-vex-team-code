#include "main.h" //DO NOT TOUCH

//Runs initialization code. This occurs as soon as the program is started. It is recommended to keep execution time for this mode under a few seconds.
void initialize() {

	rightChassis1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    rightChassis2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    leftChassis1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    leftChassis2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    intake.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    shooter.set_brake_mode(E_MOTOR_BRAKE_HOLD);

}

//Runs after initialize() and before autonomous. This is intended for competition-specific initialization routines, such as an autonomous selector on the LCD.
void competition_initialize() {



}

//Runs while the robot is in the disabled state of Field Management System or the VEX Competition Switch
void disabled() {



} // new phone who dis
