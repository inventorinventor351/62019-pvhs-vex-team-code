#ifndef AUTON_H
#define AUTON_H

#include <vector>

struct wayPoint {

    double leftChassis_Vel,
    rightChassis_Vel;

};

extern std::vector<wayPoint> red_flagSide_4flags_2caps;

#endif