#include "main.h"

Controller master (CONTROLLER_MASTER); //master controller

//V5 Components
Motor leftBase1 (1, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES); 
Motor leftBase2 (2, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
Motor rightBase1 (3, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
Motor rightBase2 (4, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
Motor leftLift (5, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
Motor rightLift (6, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);

Vision coneVis1(7, VISION_ZERO_CENTER);
Vision coneVis2(8, VISION_ZERO_CENTER);


//Legacy Components
ADIEncoder yawEnc(2, 3);
ADIDigitalOut liftPstn1(4);
ADIDigitalOut liftPstn2(5);