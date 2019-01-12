#include "main.h"

void runBro(float voltPerc) {

    deSr.move_voltage((voltPerc / 100) * 12000); 
}