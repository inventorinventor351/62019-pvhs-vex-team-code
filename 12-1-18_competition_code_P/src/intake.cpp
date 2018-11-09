#include "main.h"

void runintake(int speed, int time) {
    intake.move_velocity(speed);
    delay(time);
    intake.move_velocity(0);
}