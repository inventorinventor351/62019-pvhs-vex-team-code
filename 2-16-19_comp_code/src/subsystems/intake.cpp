#include "main.h"

void runIntake(float voltPerc) {

    intk.move_voltage((voltPerc / 100) * 12000);

}