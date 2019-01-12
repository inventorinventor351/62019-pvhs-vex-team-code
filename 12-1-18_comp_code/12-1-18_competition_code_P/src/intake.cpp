#include "main.h"

void runintake(int speed, int time) {
    intake.move_velocity(speed);
    delay(time);
    intake.move_velocity(0);
}

void loadBall(int time) {

    intakePiston1.set_value(1);
    intakePiston2.set_value(1);
    delay(time);
    intakePiston1.set_value(0);
    intakePiston2.set_value(0);

}