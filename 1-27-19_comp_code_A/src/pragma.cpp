#include "main.h"

Motor leftBase1 (18, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //normal motor plugged into port 18 and reversed
Motor leftBase2 (19, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS); //normal motor plugged into port 19 and not reversed
Motor leftBase3 (20, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //normal motor plugged into port 20 and reversed
Motor rightBase1 (7, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS); //normal motor plugged into port 7 and reversed
Motor rightBase2 (8, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //normal motor plugged into port 8 and not reversed
Motor rightBase3 (9, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS); //normal motor plugged into port 9 and reversed

Motor intake (10, MOTOR_GEARSET_18, 0); //normal motor plugged into port 10 and not reversed

Motor deSr (17, MOTOR_GEARSET_06, 0); //torke motor plugged into port 17 and not reversed

Vision visn(11); //vision sensor plugged into port 11


//ADIEncoder distEnc (5, 6, 0); //encoder plugged into legacy ports 5 and 6 and not reversed

Controller master (CONTROLLER_MASTER);
