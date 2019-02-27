#include "main.h"

void initialize() {

    delay(1350);
    //Task goGetYaw (getYaw, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "angular position task");
    Task cpltGo (cpltControl, (void*)"PROS", TASK_PRIORITY_DEFAULT - 1, TASK_STACK_DEPTH_DEFAULT - 1, "catapult control task");

}

int autonCount = 0;

void lcdScroll() {

    if(autonCount > 3) {

        autonCount = 0;

    }

    else if(autonCount < 0) {

        autonCount = 3;

    }

    switch(autonCount) {

        case 0:
            lcd::set_text(1, "RED   FLAG    SIDE");
            lcd::set_text(2, "6 flags");
            lcd::set_text(3, "2 caps");
            lcd::set_text(4, "no parking");
            break;

        case 1:
            lcd::set_text(1, "RED   CAP    SIDE");
            lcd::set_text(2, "2 flags");
            lcd::set_text(3, "2 caps");
            lcd::set_text(4, "yes parking");
            break;

        case 2:
            lcd::set_text(1, "BLUE   FLAG    SIDE");
            lcd::set_text(2, "6 flags");
            lcd::set_text(3, "2 caps");
            lcd::set_text(4, "no parking");
            break;

        case 3:
            lcd::set_text(1, "BLUE   CAP    SIDE");
            lcd::set_text(2, "2 flags");
            lcd::set_text(3, "2 caps");
            lcd::set_text(4, "yes parking");
            break;

        default:
            lcd::set_text(1, "HOW DID YOU MESS UP KARL");
            lcd::set_text(2, "HOW DID YOU MESS UP KARL");
            lcd::set_text(3, "HOW DID YOU MESS UP KARL");
            lcd::set_text(4, "HOW DID YOU MESS UP KARL");
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

void competition_initialize() {

    lcd::initialize();
    lcd::set_text(0, "choose auton");
    lcdScroll();
    lcd::register_btn0_cb(on_left_pressed);
    lcd::register_btn1_cb(on_center_pressed);
    lcd::register_btn2_cb(on_right_pressed);

}

void disabled() {



}