#include "main.h" //DO NOT TOUCH

//Runs initialization code. This occurs as soon as the program is started. It is recommended to keep execution time for this mode under a few seconds.

void initialize(){

	rightChassis1.set_brake_mode(E_MOTOR_BRAKE_COAST);
    rightChassis2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    leftChassis1.set_brake_mode(E_MOTOR_BRAKE_COAST);
    leftChassis2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
    shooter.set_brake_mode(E_MOTOR_BRAKE_COAST);

    shooterEye.set_zero_point(E_VISION_ZERO_CENTER);

    intakeLift.set_value(0);
    intakeLiftCap.set_value(0);
    
}

int autonCount = 0;

void lcdScroll() {

    if(autonCount < 0) {

        autonCount = 5;

    }

    else if(autonCount > 7) {

        autonCount = 0;

    }

    switch(autonCount) {

            case 0:
                lcd::set_text(1, "RED flag side");
                lcd::set_text(2, "3 flags");
                lcd::set_text(3, "1 cap");
                break;

            case 1:
                lcd::set_text(1, "RED flag side");
                lcd::set_text(2, "1 flags");
                lcd::set_text(3, "2 caps");
                break;

            case 2:
                lcd::set_text(1, "RED cap side");
                lcd::set_text(2, "1 flags");
                lcd::set_text(3, "2 cap");
                break;

            case 3:
                lcd::set_text(1, "RED cap side");
                lcd::set_text(2, "1 flags");
                lcd::set_text(3, "2 cap line");
                break;

            case 4:
                lcd::set_text(1, "BLUE flag side");
                lcd::set_text(2, "3 flags");
                lcd::set_text(3, "1 cap");
                break;

            case 5:
                lcd::set_text(1, "BLUE flag side");
                lcd::set_text(2, "1 flag");
                lcd::set_text(3, "2 caps");
                break;

            case 6:
                lcd::set_text(1, "BLUE cap side");
                lcd::set_text(2, "1 flags");
                lcd::set_text(3, "2 cap");
                break;

            case 7:
                lcd::set_text(1, "BLUE cap side");
                lcd::set_text(2, "1 flags");
                lcd::set_text(3, "2 cap line");
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

    /*lcd::initialize();
    lcd::set_text(0, "choose auton");
    lcdScroll();
    lcd::register_btn0_cb(on_left_pressed);
    lcd::register_btn1_cb(on_center_pressed);
    lcd::register_btn2_cb(on_right_pressed);*/

    lcd::set_text(0, "Merry Chrismas and a Happy New Year");

}


//Runs while the robot is in the disabled state of Field Management System or the VEX Competition Switch
void disabled() {



} // new phone who dis
