#include "main.h"

Motor leftBase1 (1, MOTOR_GEARSET_18, 0); //normal motor plugged into port 1 and not reversed
Motor leftBase2 (2, MOTOR_GEARSET_18, 0); //normal motor plugged into port 2 and not reversed
Motor rightBase1 (3, MOTOR_GEARSET_18, 1); //normal motor plugged into port 3 and reversed
Motor rightBase2 (4, MOTOR_GEARSET_18, 1); //normal motor plugged into port 4 and reversed
Motor intk (5, MOTOR_GEARSET_18, 0); //normal motor plugged into port 5 and not reversed
Motor cplt (6, MOTOR_GEARSET_18, 0); //normal motor plugged into port 6 and not reversed

Vision intkVis (7, VISION_ZERO_CENTER); //vision sensor plugged into port 7 and (0,0) is at the center of the screen
Vision cpltVis (8, VISION_ZERO_CENTER); //vision sensor plugged into port 8 and (0,0) is at the center of the screen

ADIDigitalOut transPstn (2); //piston plugged into port 2

ADIEncoder distEnc (5, 6, 0); //encoder plugged into legacy ports 5 and 6 and not reversed
ADIEncoder yawEnc (7, 8, 0); //encoder plugged into legacy ports 7 and 8 and not reversed