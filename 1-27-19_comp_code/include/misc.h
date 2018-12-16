#ifndef MATH_H
#define MATH_H

int sgn(double x); //inputs a double and outputs its sign (+ or -) as an int

struct PID { //a holder for multiple values used in PID

    double error,
    integral,
    derivative,
    prevError,
    kP, kI, kD; //PID constants
    bool useP, useI, useD; //0 to disable certain terms, 1 to enable

};

PID initPID(bool useP, bool useI, bool useD, double kP, double kI, double kD); //gives a created PID struct its values

double runPID(PID *pid); //inputs a PID struct, does the actual PID math, then outputs a double

#endif