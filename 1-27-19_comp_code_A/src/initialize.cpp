#include "main.h" //DO NOT TOUCH

//Runs initialization code. This occurs as soon as the program is started. It is recommended to keep execution time for this mode under a few seconds.
void initialize() {
	
	rightBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
    rightBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    rightBase3.set_brake_mode(E_MOTOR_BRAKE_COAST);
    leftBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
    leftBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    leftBase3.set_brake_mode(E_MOTOR_BRAKE_COAST);
    intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
    deSr.set_brake_mode(E_MOTOR_BRAKE_HOLD);

    visn.set_zero_point(E_VISION_ZERO_CENTER);

    
}

int autonCount = 0;

void lcdScroll() {

    if(autonCount < 0) {

        autonCount = 4;

    }

    else if(autonCount > 4) {

        autonCount = 0;

    }

    switch(autonCount) {

            case 0:
                lcd::set_text(1, "BLUE flag side");
                break;

            case 1:
                lcd::set_text(1, "BLUE cap side");
                break;

            case 2:
                lcd::set_text(1, "RED flag side");
                break;

            case 3:
                lcd::set_text(1, "RED cap side");
                break;

            case 4:
                lcd::set_text(1, "Skills LMAO");
                break;


        }

}

void on_left_pressed() {

    autonCount--;
    lcdScroll();

}

void on_center_pressed() {

    autonCount = autonCount;
    lcd::shutdown();

}

void on_right_pressed() {

    autonCount++;
    lcdScroll();

}


//Runs after initialize() and before autonomous. This is intended for competition-specific initialization routines, such as an autonomous selector on the LCD.
void competition_initialize() {
       
    lcd::initialize();
    lcd::set_text(0, "choose auton");
    lcdScroll();
    lcd::register_btn0_cb(on_left_pressed);
    lcd::register_btn1_cb(on_center_pressed);
    lcd::register_btn2_cb(on_right_pressed);


}

//Runs while the robot is in the disabled state of Field Management System or the VEX Competition Switch
void disabled() {



}