#include "main.h"

void runCplt(float voltPerc) {

    cplt.move_voltage((voltPerc / 100) * 12000);

}

void cpltShoot() {

int number; 
int setpoint;
PID cpltShoot = initPID(0,0,0,0,0,0,0,00);

while(cpltPot.get_value() > number) {

cplt.move_voltage(12000);

}

while(cpltPot.get_value() > setpoint) {
cpltShoot.error = setpoint - cpltPot.get_value();
cplt.move_voltage(runPID(&cpltShoot));

}