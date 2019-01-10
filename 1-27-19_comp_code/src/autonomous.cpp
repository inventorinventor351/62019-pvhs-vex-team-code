#include "main.h" //DO NOT TOUCH

//Runs during the 15 second autonomous period
void autonomous() {

    //Task baseSlewRate (baseSR, NULL, (TASK_PRIORITY_DEFAULT - 1), TASK_STACK_DEPTH_DEFAULT, "Base Slew Rate");

    double distVal, diffVal;

    int count = 0;

    direction = (int)sgn((double)direction);

    PID dist = initPID(1, 0, 0, 1, 0, 0);
    PID diff = initPID(0, 0, 0, 0, 0, 0);

    distEnc.reset();
    yawEnc.reset();

    while(true) {

        dist.error = setPoint - distEnc.get_value();
        diff.error = 0 - yawEnc.get_value();

        distVal = runPID(&dist);
        diffVal = runPID(&diff);

        runLeftBase(distVal - diffVal);
        runRightBase(distVal + diffVal);

        if(!(count % 50)) {

            master.print(0, 0, "Dist: %d", distEnc.get_value());
            master.print(0, 0, "Yaw: %d", yawEnc.get_value());

        }

        cout++;

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

    //baseSlewRate.remove();
    
}