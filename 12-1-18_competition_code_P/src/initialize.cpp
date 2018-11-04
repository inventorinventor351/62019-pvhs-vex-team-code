#include "main.h" //DO NOT TOUCH

//Runs initialization code. This occurs as soon as the program is started. It is recommended to keep execution time for this mode under a few seconds.
void initialize() {
	
    motor_pid_s_t chassisPID = Motor::convert_pid(0, 1.0, 0.001, 0.1); //PID constants for chassis
    leftChassis1.set_pos_pid(chassisPID);
    leftChassis2.set_pos_pid(chassisPID);
    rightChassis1.set_pos_pid(chassisPID);
    rightChassis2.set_pos_pid(chassisPID);

    catapultEye.clear_led();

}

//Runs after initialize() and before autonomous. This is intended for competition-specific initialization routines, such as an autonomous selector on the LCD.
void competition_initialize() {

    lcd::initialize();
    lcd::set_text(0, "what is your alliance color?");
    lcd::set_text(7, "blue                            red");

    while(lcd::read_buttons() == 0) {

        if(lcd::read_buttons() == LCD_BTN_LEFT) {

            lcd::set_text(0, "what side are you on?");
            lcd::set_text(7, "flag                              cap");

            while(lcd::read_buttons() == 0) {

                if(lcd::read_buttons() == LCD_BTN_LEFT) {

                    while(lcd::read_buttons() == 0) {

                        lcd::set_text(0, "which auton do you want?");
                        lcd::set_text(7, "3 flags-1 cap    OR    1 flag-2 caps");

                        if(lcd::read_buttons() == LCD_BTN_LEFT) {

                            autonCount = 0;

                        }

                        else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

                            autonCount = 1;

                        }

                    }

                }

                else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

                    autonCount = 2;

                }

            }

        }

        else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

            lcd::set_text(0, "what side are you on?");
            lcd::set_text(7, "flag                              cap");

            while(lcd::read_buttons() == 0) {

                if(lcd::read_buttons() == LCD_BTN_LEFT) {

                    while(lcd::read_buttons() == 0) {

                        lcd::set_text(0, "which auton do you want?");
                        lcd::set_text(7, "3 flags-1 cap    OR    1 flag-2 caps");

                        if(lcd::read_buttons() == LCD_BTN_LEFT) {

                            autonCount = 3;

                        }

                        else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

                            autonCount = 4;

                        }

                    }

                }

                else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

                    autonCount = 5;

                }

            }

        }

    }

}

//Runs while the robot is in the disabled state of Field Management System or the VEX Competition Switch
void disabled() {



}