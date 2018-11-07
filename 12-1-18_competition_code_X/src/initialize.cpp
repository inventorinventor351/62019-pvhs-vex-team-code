#include "main.h" //DO NOT TOUCH

//Runs initialization code. This occurs as soon as the program is started. It is recommended to keep execution time for this mode under a few seconds.
void initialize() {

	rightChassis1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    rightChassis2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    leftChassis1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    leftChassis2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    intake.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    shooter.set_brake_mode(E_MOTOR_BRAKE_HOLD);

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
    lcd::set_text(0, "What is your alliance color?");
    lcd::set_text(7, "Blue                            Red");

    while(lcd::read_buttons() == 0) {

        if(lcd::read_buttons() == LCD_BTN_LEFT) {

            lcd::set_text(0, "What side are you on?");
            lcd::set_text(7, "Flag                              Cap");

            while(lcd::read_buttons() == 0) {

                if(lcd::read_buttons() == LCD_BTN_LEFT) {

                    while(lcd::read_buttons() == 0) {

                        lcd::set_text(0, "Which auton do you want?");
                        lcd::set_text(7, "3 flags-1 cap    OR    1 flag-2 cap horde");

                        if(lcd::read_buttons() == LCD_BTN_LEFT) {

                            autonCount = 0;

                        }

                        else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

                            autonCount = 1;

                        }

                    }

                }

                else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

                    while(lcd::read_buttons() == 0) {

                        lcd::set_text(0, "Which auton do you want?");
                        lcd::set_text(7, "2 cap line    OR    2 cap-parking");

                        if(lcd::read_buttons() == LCD_BTN_LEFT) {

                            autonCount = 2;

                        }

                        else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

                            autonCount = 3;

                        }

                    }

                }

            }

        }

        else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

            lcd::set_text(0, "What side are you on?");
            lcd::set_text(7, "Flag                              Cap");

            while(lcd::read_buttons() == 0) {

                if(lcd::read_buttons() == LCD_BTN_LEFT) {

                    while(lcd::read_buttons() == 0) {

                        lcd::set_text(0, "Which auton do you want?");
                        lcd::set_text(7, "3 flags-1 cap    OR    1 flag-2 cap horde");

                        if(lcd::read_buttons() == LCD_BTN_LEFT) {

                            autonCount = 4;

                        }

                        else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

                            autonCount = 5;

                        }

                    }

                }

                else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

                    while(lcd::read_buttons() == 0) {

                        lcd::set_text(0, "Which auton do you want?");
                        lcd::set_text(7, "2 cap line    OR    2 cap-parking");

                        if(lcd::read_buttons() == LCD_BTN_LEFT) {

                            autonCount = 6;

                        }

                        else if(lcd::read_buttons() == LCD_BTN_RIGHT) {

                            autonCount = 7;

                        }

                    }

                }

            }

        }

    }

}


}

//Runs while the robot is in the disabled state of Field Management System or the VEX Competition Switch
void disabled() {



} // new phone who dis
