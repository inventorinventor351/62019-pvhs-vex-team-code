#include "main.h"

int sgn(double x) { //inputs a double and outputs its sign (+ or -) as an int

    return (x > 0) - (x < 0);

}

PID initPID(bool useP, bool useI, bool useD, double kP, double kI, double kD) { //gives a created PID struct its values

    return {

        0, 0, 0, 0, kP, kI, kD, useP, useI, useD;

    };

}

double runPID(PID *pid) {

    pid->integral += pid->error; //increment integral by current error
    pid->derivative = pid->error - pid->prevError; //set derivative to the delta error
    pid->prevError = pid->error; //set prevError to current error to be used for next iteration
    return (pid->error * pid->kP * pid->useP) + (pid->integral * pid->kI * pid->useI) + (pid->derivative * pid->kD * pid->useD); //calculate final value

}