#include "main.h" //DO NOT TOUCH

//Runs during the 15 second autonomous period
void autonomous() {

    //Task baseSlewRate (baseSR, NULL, (TASK_PRIORITY_DEFAULT - 1), TASK_STACK_DEPTH_DEFAULT, "Base Slew Rate");

    moveStraight(3600, 1, 2000);

    //baseSlewRate.remove();
    
}