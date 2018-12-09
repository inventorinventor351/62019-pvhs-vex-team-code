#include "main.h"

void runCatapult(float voltPerc) {

    cplt.move_voltage((voltPerc / 100) * 12000);

}