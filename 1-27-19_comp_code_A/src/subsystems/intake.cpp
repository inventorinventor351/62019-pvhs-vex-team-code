#include "main.h"

void runIntake(float voltPerc) {

    intake.move_voltage((voltPerc / 100) * 12000); 

}