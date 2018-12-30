#include "main.h"

Motor leftBase1 (1, MOTOR_GEARSET_18, 0); //normal motor plugged into port 1 and not reversed
Motor leftBase2 (2, MOTOR_GEARSET_18, 1); //normal motor plugged into port 2 and not reversed
Motor leftBase3 (3,MOTOR_GEARSET_18, 0); //normal motor plugged into port 3 and not reversed
Motor rightBase1 (4, MOTOR_GEARSET_18, 1); //normal motor plugged into port 3 and reversed
Motor rightBase2 (5, MOTOR_GEARSET_18, 0); //normal motor plugged into port 4 and reversed
Motor rightBase3 (6, MOTOR_GEARSET_18, 1); //normal motor plugged into port 5 and reversed

Motor capFlip (6, MOTOR_GEARSET_18, 0); //normal motor plugged into port 5 and not reversed

Motor arm (7, MOTOR_GEARSET_18, 0); //normal motor pluged into port 5 and not reversed

ADIEncoder distEnc (5, 6, 0); //encoder plugged into legacy ports 5 and 6 and not reversed

Controller master (CONTROLLER_MASTER);