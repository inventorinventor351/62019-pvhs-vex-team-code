#include "main.h"

Motor leftBase1 (18, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS); //normal motor plugged into port 1 and not reversed
Motor leftBase2 (19, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //normal motor plugged into port 2 and not reversed
Motor leftBase3 (20, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS);
Motor rightBase1 (7, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS); //normal motor plugged into port 3 and reversed
Motor rightBase2 (8, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //normal motor plugged into port 4 and reversed
Motor rightBase3 (9, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS);

Motor intake (10, MOTOR_GEARSET_18, 0); //normal motor plugged into port 5 and not reversed

Motor deSr (17, MOTOR_GEARSET_18, 0); 

Vision visn(11);


ADIEncoder distEnc (5, 6, 0); //encoder plugged into legacy ports 5 and 6 and not reversed

Controller master (CONTROLLER_MASTER);
