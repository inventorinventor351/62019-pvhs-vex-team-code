#include "main.h" //DO NOT TOUCH

//Runs initialization code. This occurs as soon as the program is started. It is recommended to keep execution time for this mode under a few seconds.
void initialize() {
	
    motor_pid_s_t chassisPID = Motor::convert_pid(0, 1.0, 0.001, 0.1); //PID constants for chassis
    leftChassis1.set_pos_pid(chassisPID);
    leftChassis2.set_pos_pid(chassisPID);
    leftChassis3.set_pos_pid(chassisPID);
    rightChassis1.set_pos_pid(chassisPID);
    rightChassis2.set_pos_pid(chassisPID);
    rightChassis3.set_pos_pid(chassisPID);

    catapultEye.clear_led();

}

//Runs after initialize() and before autonomous. This is intended for competition-specific initialization routines, such as an autonomous selector on the LCD.
void competition_initialize() {



}

//Runs while the robot is in the disabled state of Field Management System or the VEX Competition Switch
void disabled() {



}